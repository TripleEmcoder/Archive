package gardener;

import java.util.ArrayList;
import java.util.List;
import java.util.Observable;
import java.util.Observer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import jclips.JClips;

public class ClipsManager implements Observer
{
	private static final Pattern QUESTION_PATTERN = Pattern
			.compile("^question;(.*?);(.*)$");
	private static final Pattern PLANT_PATTERN = Pattern
			.compile("^plant;(.*)$");
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
		// URL fileUrl = ClipsManager.class.getResource(filename);
		//
		// try
		// {
		// if (fileUrl == null)
		// {
		// throw new FileNotFoundException(filename);
		// }
		// File file = new File(new URI(fileUrl.toString()));
		// jClips.load(file.getPath());
		// jClips.reset();
		// }
		// catch (Exception e)
		// {
		// e.printStackTrace();
		// }
		System.err.println("Loading: " + filename);
		jClips.load(filename);
		jClips.reset();
	}

	public void reset()
	{
		answers.clear();
		jClips.reset();
		jClips.run();
	}

	public void run()
	{
		jClips.run();
	}

	private void assertFact(String fact)
	{
		String cmd = String.format(ASSERT_COMMAND, fact);
		System.err.println(cmd);
		jClips.executeCommand(cmd);
		jClips.run();
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
		Matcher questionMatcher = QUESTION_PATTERN.matcher(message);
		Matcher plantMatcher = PLANT_PATTERN.matcher(message);
		if (questionMatcher.find())
		{
			if (SI.questionPanel.isAnswerSelected())
				SI.historyPanel.addElement(SI.questionPanel.getQuestion() + " "
						+ SI.questionPanel.getAnswer());
			SI.questionPanel.setQuestion(questionMatcher.group(1),
					questionMatcher.group(2));
		}
		else if (plantMatcher.find())
		{
			SI.plantListPanel.addElement(plantMatcher.group(1));
		}
	}

}
