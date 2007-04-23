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
	private static final Pattern QUESTION_PATTERN = 
		Pattern.compile("^question;(.*?);(.*)$");
	private static final String ASSERT_COMMAND = "(assert (%s))";
	private static final String RETRACT_COMMAND = "(assert (cancel %s))";
	
	private JClips jClips;
	private List<String> facts;
	
	public ClipsManager()
	{
		this.jClips = JClips.getInstance();
		this.jClips.init();
		this.jClips.addObserver(this);
		this.facts = new ArrayList<String>();
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
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public void reset()
	{
		facts.clear();
		jClips.reset();
		jClips.run();
	}
	
	public void run()
	{
		jClips.run();
	}
	
	public void assertFact(String fact)
	{
		facts.add(fact);
		jClips.executeCommand(String.format(ASSERT_COMMAND, fact));
		jClips.run();
	}
	
	public void retractFact()
	{
		if (!facts.isEmpty())
		{
			String fact = facts.remove(facts.size()-1);
			jClips.executeCommand(String.format(RETRACT_COMMAND, fact));
			jClips.run();			
		}
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
