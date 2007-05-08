package gardener;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Observable;
import java.util.Observer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

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
	private JClips jClips;
	private List<String> answers;

	public ClipsManager()
	{
		this.jClips = JClips.getInstance();
		this.jClips.init();
		this.jClips.addObserver(this);
		this.answers = new ArrayList<String>();
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
		jClips.reset();
		assertFact(REFRESH_FACT);
		jClips.run();
	}

	private void assertFact(String fact)
	{
		String cmd = String.format(ASSERT_COMMAND, fact);
		System.err.println(cmd);
		jClips.executeCommand(cmd);
	}

	public void sendAnswer(String answer)
	{
		answers.add(answer);
		assertFact(String.format(ANSWER_FORMAT, answer));
		assertFact(REFRESH_FACT);
		jClips.run();
	}

	public void cancelLastAnswer()
	{
		if (!answers.isEmpty())
		{
			jClips.reset();
			jClips.run();
			answers.remove(answers.size() - 1);
			for (String answer : answers)
			{
				assertFact(String.format(ANSWER_FORMAT, answer));
				jClips.run();
			}
			assertFact(REFRESH_FACT);
			jClips.run();
		}
	}

	public void update(Observable o, Object arg)
	{
		String message = (String) arg;
		//if (!message.startsWith("plant"))
			System.err.println(message);

		final Matcher finalQuestionMatcher = FINAL_QUESTION_PATTERN
				.matcher(message);
		final Matcher questionMatcher = QUESTION_PATTERN.matcher(message);
		final Matcher plantMatcher = PLANT_PATTERN.matcher(message);

		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				if (finalQuestionMatcher.matches())
				{
					SI.questionPanel.clearQuestion();
				}
				else if (questionMatcher.matches())
				{
					SI.questionPanel.setQuestion(questionMatcher.group(1),
							questionMatcher.group(2));
				}
				else if (plantMatcher.matches())
				{
					SI.plantListPanel.addElement(plantMatcher.group(1));
				}
			}
		});
	}

}
