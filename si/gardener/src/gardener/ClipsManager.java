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
	
	public ClipsManager()
	{
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
			if (SI.questionPanel.isAnswerSelected())
				SI.historyPanel.addQuestion(
						SI.questionPanel.getQuestion(), SI.questionPanel.getAnswer());
			SI.questionPanel.setQuestion(questionMatcher.group(1),questionMatcher.group(2));											
		}
	}

}
