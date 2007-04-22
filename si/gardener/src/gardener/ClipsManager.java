package gardener;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URL;
import java.util.Observable;
import java.util.Observer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import jclips.JClips;

public class ClipsManager implements Observer
{
	private static final Pattern QUESTION_PATTERN = 
		Pattern.compile("^question;(.*?);(.*)$");
	
	private JClips jClips;
	private QuestionPanel questionPanel;
	private HistoryPanel historyPanel;

	public ClipsManager(QuestionPanel questionPanel, HistoryPanel historyPanel)
	{
		this.questionPanel = questionPanel;
		this.historyPanel = historyPanel;
		this.jClips = JClips.getInstance();
		this.jClips.init();
		this.jClips.addObserver(this);
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
			jClips.reset();
			jClips.run();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public void reset()
	{
		jClips.reset();
		jClips.run();
	}
	
	public void assertFact(String fact)
	{
		jClips.executeCommand(String.format("(assert (%s))", fact));
		jClips.run();
	}
	
	public void update(Observable o, Object arg)
	{
		String message = (String)arg;
		Matcher questionMatcher = QUESTION_PATTERN.matcher(message);
		if (questionMatcher.find())
		{
			if (questionPanel.isAnswerSelected())
				historyPanel.addQuestion(
						questionPanel.getQuestion(), questionPanel.getAnswer());
			questionPanel.setQuestion(questionMatcher.group(1),questionMatcher.group(2));											
		}
	}

}
