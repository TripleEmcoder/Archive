package gardener;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;


public class QuestionPanel extends JPanel implements ActionListener
{
	public void actionPerformed(ActionEvent e)
		{
			if (e.getActionCommand() == "next")
			{
				SI.clipsManager.sendAnswer(SI.questionPanel.getAnswer());
			}
			else if (e.getActionCommand() == "previous")
			{
				SI.historyPanel.removeElement();
				SI.questionPanel.clearQuestion();
				SI.clipsManager.cancelLastAnswer();
			}
			else if (e.getActionCommand() == "restart")
			{
				SI.historyPanel.removeAllElements();
				SI.questionPanel.clearQuestion();
				SI.clipsManager.reset();
			}
			else
			{
				next.setEnabled(true);
			}
		}

	
	private static final long serialVersionUID = 1L;
	private static final Pattern ANSWER_PATTERN = Pattern.compile("(.*?)(;|$)");
	
	private JLabel questionLabel;
	
	private JPanel radioPanel, buttonPanel;
	
	private ButtonGroup group;
	
	private JButton next, previous, restart;
	
	public QuestionPanel()
	{
		setLayout(new BoxLayout(this, BoxLayout.PAGE_AXIS));
		
		group = new ButtonGroup();
		
		next = new JButton("next");
		next.addActionListener(this);
		next.setActionCommand("next");
		
		previous = new JButton("previous"); 
		previous.addActionListener(this);
		previous.setActionCommand("previous");
		
		restart = new JButton("restart");
		restart.addActionListener(this);
		restart.setActionCommand("restart");
		
		questionLabel = new JLabel();
		//questionLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
		//questionLabel.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 0));
		
		radioPanel = new JPanel();
		radioPanel.setLayout(new BoxLayout(radioPanel, BoxLayout.PAGE_AXIS));
		radioPanel.setMinimumSize(new Dimension(350,200));
		//radioPanel.setAlignmentX(Component.LEFT_ALIGNMENT);
		
		//radioPanel.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 0));
		
		buttonPanel = new JPanel();	
		//buttonPanel.setAlignmentX(Component.LEFT_ALIGNMENT);
		buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.LINE_AXIS));
		buttonPanel.add(Box.createHorizontalGlue());
		buttonPanel.add(next);
		buttonPanel.add(Box.createHorizontalGlue());
		buttonPanel.add(previous);
		buttonPanel.add(Box.createHorizontalGlue());
		buttonPanel.add(restart);
		buttonPanel.add(Box.createHorizontalGlue());
		
		add(Box.createVerticalGlue());
		add(questionLabel);
		add(Box.createVerticalGlue());
		add(radioPanel);
		add(Box.createVerticalGlue());
		add(buttonPanel);
		add(Box.createVerticalGlue());
		
		clearQuestion();
	}
	
	public void setQuestion(String question, String answers)
	{
		clearQuestion();
		
		questionLabel.setText(question);
				
		Matcher answerMatcher = ANSWER_PATTERN.matcher(answers);
		
		while (answerMatcher.find())
		{
			JRadioButton button = new JRadioButton(answerMatcher.group(1));
			button.setActionCommand(answerMatcher.group(1));
			button.addActionListener(this);
			group.add(button);
			radioPanel.add(button);
		}
		
		next.setEnabled(false);
		previous.setEnabled(!SI.historyPanel.isEmpty());
	}
	
	public void clearQuestion()
	{
		questionLabel.setText("");
		group.clearSelection();
		radioPanel.removeAll();
		next.setEnabled(false);
		previous.setEnabled(false);
	}
	
	public String getQuestion()
	{
		return questionLabel.getText();
	}
	
	public String getAnswer()
	{
		return group.getSelection().getActionCommand();
	}
	
	public boolean isAnswerSelected()
	{
		return (group.getSelection() != null);
	}
}
