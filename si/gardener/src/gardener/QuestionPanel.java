package gardener;

import java.awt.Component;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

import javax.swing.AbstractButton;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

public class QuestionPanel extends JPanel implements ActionListener
{
	private static final long serialVersionUID = 1L;

	private JLabel questionLabel;

	private JPanel radioPanel, buttonPanel;

	private ButtonGroup group;

	private JButton next, previous, restart;

	private Random rand;

	public QuestionPanel()
	{
		rand = new Random();

		setLayout(new BoxLayout(this, BoxLayout.PAGE_AXIS));

		group = new ButtonGroup();

		next = new JButton("Nastêpne");
		next.addActionListener(this);
		next.setActionCommand("next");

		previous = new JButton("Poprzednie");
		previous.addActionListener(this);
		previous.setActionCommand("previous");

		restart = new JButton("Restart");
		restart.addActionListener(this);
		restart.setActionCommand("restart");

		questionLabel = new JLabel();
		questionLabel.setAlignmentX(CENTER_ALIGNMENT);
		
		radioPanel = new JPanel();
		radioPanel.setAlignmentX(CENTER_ALIGNMENT);

		buttonPanel = new JPanel();
		buttonPanel.setAlignmentX(CENTER_ALIGNMENT);
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

	public void actionPerformed(ActionEvent e)
	{
		System.err.println("--- " + e.getActionCommand() + " ---");
		
		if (e.getActionCommand().equals("next"))
		{
			updateHistory();
			SI.plantListPanel.removeAllElements();
			SI.plantInfoPanel.clearPlant();
			SI.clipsManager.sendAnswer(SI.questionPanel.getAnswer());
		}
		else if (e.getActionCommand().equals("previous"))
		{
			SI.historyPanel.removeLastElement();
			SI.plantListPanel.removeAllElements();
			SI.plantInfoPanel.clearPlant();
			clearQuestion();
			SI.clipsManager.cancelLastAnswer();
		}
		else if (e.getActionCommand().equals("restart"))
		{
			SI.historyPanel.removeAllElements();
			SI.plantListPanel.removeAllElements();
			SI.plantInfoPanel.clearPlant();
			clearQuestion();
			SI.clipsManager.restart();
		}
		
		next.setEnabled(isAnswerSelected());
		previous.setEnabled(!SI.historyPanel.isEmpty());
	}

	public void clearQuestion()
	{
		questionLabel.setText("");

		group.clearSelection();
		for (Component button : radioPanel.getComponents())
			group.remove((AbstractButton) button);
		
		radioPanel.removeAll();

		next.setEnabled(isAnswerSelected());
		previous.setEnabled(!SI.historyPanel.isEmpty());
	}

	public String getAnswer()
	{
		return group.getSelection().getActionCommand();
	}

	public String getQuestion()
	{
		return questionLabel.getText();
	}

	public boolean isAnswerSelected()
	{
		return (group.getSelection() != null);
	}

	public void setQuestion(String question, String answer)
	{
		clearQuestion();

		questionLabel.setText(question);

		String[] answers = answer.split(";");

		int colCount = answers.length / 4 + 1;

		radioPanel.setLayout(new GridLayout(0, colCount));

		for (String s : answers)
		{
			JRadioButton button = new JRadioButton(s);
			button.setActionCommand(s);
			button.addActionListener(this);
			group.add(button);
			radioPanel.add(button);
		}

		JRadioButton button = (JRadioButton) radioPanel.getComponent(rand
				.nextInt(radioPanel.getComponentCount()));
		button.setSelected(true);
		
		next.setEnabled(isAnswerSelected());
		previous.setEnabled(!SI.historyPanel.isEmpty());
	}

	private void updateHistory()
	{
		if (isAnswerSelected())
			SI.historyPanel.addElement(getQuestion() + " " + getAnswer());
	}
}
