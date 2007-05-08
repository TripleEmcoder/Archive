package gardener;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URL;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Observable;
import java.util.Observer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.border.CompoundBorder;
import javax.swing.border.TitledBorder;

import jclips.JClips;

public class ClipsManager implements Observer
{
	private static final Pattern FINAL_QUESTION_PATTERN = Pattern
			.compile("^question;STOP$");
	private static final Pattern QUESTION_PATTERN = Pattern
			.compile("^question;(.+?);(.+)$");
	private static final Pattern PLANT_PATTERN = Pattern
			.compile("^plant;(.+)$");

	private static final String ASSERT_COMMAND = "(assert (%s))";
	private static final String ANSWER_FORMAT = "answer \"%s\"";
	private static final String REFRESH_FACT = "refresh reassert";

	private static final String MULTIPLE_PLANTS_COMMENT = "Dziekujê. Nie mam wiêcej pytañ.";
	private static final String SINGLE_PLANT_COMMENT = "Patrz i podziwiaj. Oto Twoja Roœlina.";
	private static final String NO_PLANTS_COMMENT = "Nie znalaz³em odpowiednich roœlin. Proponujê inne hobby.";
	private JClips jClips;
	private List<String> answers, plants;
	private String currentQuestion, currentAnswers;

	public ClipsManager()
	{
		this.jClips = JClips.getInstance();
		this.jClips.init();
		this.jClips.addObserver(this);
		this.answers = new ArrayList<String>();
		this.plants = new ArrayList<String>();
	}

	public void cancelLastAnswer()
	{
		if (!answers.isEmpty())
		{
			jClips.reset();
			answers.remove(answers.size() - 1);

			for (String answer : answers)
			{
				assertFact(String.format(ANSWER_FORMAT, answer));
				jClips.run();
			}

			run();
		}
	}

	public void load(String filename)
	{
		URL fileUrl = ClipsManager.class.getResource(filename);

		try
		{
			if (fileUrl == null)
			{
				throw new FileNotFoundException(filename);
			}
			File file = new File(new URI(fileUrl.toString()));
			jClips.load(file.getPath());
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public void restart()
	{
		answers.clear();
		plants.clear();
		jClips.reset();
		run();
	}

	public void sendAnswer(String answer)
	{
		answers.add(answer);
		assertFact(String.format(ANSWER_FORMAT, answer));
		run();
	}

	public void update(Observable o, Object arg)
	{
		String message = (String) arg;

		if (!message.startsWith("plant"))
			System.err.println(message);

		final Matcher finalQuestionMatcher = FINAL_QUESTION_PATTERN
				.matcher(message);
		final Matcher questionMatcher = QUESTION_PATTERN.matcher(message);
		final Matcher plantMatcher = PLANT_PATTERN.matcher(message);

		if (finalQuestionMatcher.matches())
		{
			currentQuestion = null;
			currentAnswers = null;
		}
		else if (questionMatcher.matches())
		{
			currentQuestion = questionMatcher.group(1);
			currentAnswers = questionMatcher.group(2);
		}
		else if (plantMatcher.matches())
		{
			plants.add(plantMatcher.group(1));
		}
	}

	private void assertFact(String fact)
	{
		String cmd = String.format(ASSERT_COMMAND, fact);
		System.err.println(cmd);
		jClips.executeCommand(cmd);
	}

	private void sendInfo()
	{
		Collections.sort(plants);
		//for (String plant : plants)
		//	SI.plantListPanel.addElement(plant);
		SI.plantListPanel.updateList(plants);

		String title = String.format("Lista roœlin (%d)", plants.size());
		((TitledBorder) ((CompoundBorder) SI.plantListPanel.getBorder())
				.getOutsideBorder()).setTitle(title);
		SI.plantListPanel.repaint();

		if (currentQuestion != null && plants.size() > 1)
			SI.questionPanel.setQuestion(currentQuestion, currentAnswers);
		else if (plants.size() > 1)
			SI.questionPanel.setQuestion(MULTIPLE_PLANTS_COMMENT, null);
		else if (plants.size() == 1)
			SI.questionPanel.setQuestion(SINGLE_PLANT_COMMENT, null);
		else if (plants.size() == 0)
			SI.questionPanel.setQuestion(NO_PLANTS_COMMENT, null);
	}

	private void run()
	{
		assertFact(REFRESH_FACT);
		plants.clear();
		System.err.println("----- run() ------");
		jClips.run();
		System.err.println("----- run() finished ------");
		sendInfo();
	}

}
