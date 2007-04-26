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
	private static final String CANCEL_FORMAT = "cancel \"%s\"";

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

	public void reset()
	{
		answers.clear();
		jClips.reset();
	}

	public void run()
	{
		jClips.run();
	}

	public void restart()
	{
		reset();
		run();
	}

	private void assertFact(String fact)
	{
		String cmd = String.format(ASSERT_COMMAND, fact);
		System.err.println(cmd);
		jClips.executeCommand(cmd);
		System.err.println("jClips.run()");
		jClips.run();
		System.err.println("jClips.run() finished");
	}

	public void sendAnswer(String answer)
	{
		answers.add(answer);
		assertFact(String.format(ANSWER_FORMAT, answer));
	}

	public void cancelLastAnswer()
	{
		if (!answers.isEmpty())
		{
			String fact = answers.remove(answers.size() - 1);
			assertFact(String.format(CANCEL_FORMAT, fact));
		}
	}

	public void update(Observable o, Object arg)
	{
		String message = (String) arg;
		System.err.println(message);

		final Matcher finalQuestionMatcher = FINAL_QUESTION_PATTERN
				.matcher(message);
		final Matcher questionMatcher = QUESTION_PATTERN.matcher(message);
		final Matcher plantMatcher = PLANT_PATTERN.matcher(message);

		//System.err.println("Entering run");
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
		//System.err.println("Leaving run");
	}

}
