package gardener;

import java.awt.GridLayout;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;


public class QuestionPanel extends JPanel
{
	private static final long serialVersionUID = 1L;
	private static final Pattern ANSWER_PATTERN = Pattern.compile("(.*?)=(.*?)(;|$)");
	
	private JLabel questionLabel;
	
	private JPanel radioPanel;
	
	private ButtonGroup group;
	
	public QuestionPanel()
	{
		questionLabel = new JLabel();
		questionLabel.setAlignmentX(LEFT_ALIGNMENT);
		questionLabel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
		
		radioPanel = new JPanel(new GridLayout(0, 1));
		radioPanel.setAlignmentX(LEFT_ALIGNMENT);
		radioPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
		
		group = new ButtonGroup();
		
		setLayout(new BoxLayout(this, BoxLayout.PAGE_AXIS));
		
		add(questionLabel);
		add(Box.createVerticalGlue());
		add(radioPanel);
		add(Box.createVerticalGlue());
	}
	
	public void setQuestion(String question, String answers)
	{
		clearQuestion();
		
		questionLabel.setText(question);
				
		Matcher answerMatcher = ANSWER_PATTERN.matcher(answers);
		
		while (answerMatcher.find())
		{
			JRadioButton button = new JRadioButton(answerMatcher.group(1));
			button.setActionCommand(answerMatcher.group(1)+"="+answerMatcher.group(2));
			group.add(button);
			radioPanel.add(button);
		}
	}
	
	public void clearQuestion()
	{
		questionLabel.setText("");
		group.clearSelection();
		radioPanel.removeAll();
	}
	
	public String getQuestion()
	{
		return questionLabel.getText();
	}
	
	public String getAnswer()
	{
		return group.getSelection().getActionCommand().split("=")[0];
	}
	
	public String getFact()
	{
		return group.getSelection().getActionCommand().split("=")[1];
	}
	
	public boolean isAnswerSelected()
	{
		return (group.getSelection() != null);
	}
}
