package gardener;

import java.awt.Component;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

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
	
	public QuestionPanel()
	{
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

		add(Box.createVerticalStrut(10));
		add(questionLabel);
		add(Box.createVerticalGlue());
		add(radioPanel);
		add(Box.createVerticalGlue());
		add(buttonPanel);
		add(Box.createVerticalStrut(10));
	}

	public void actionPerformed(ActionEvent e)
	{
		if (e.getActionCommand().equals("next"))
		{
			updateHistory();
			SI.clipsManager.sendAnswer(SI.questionPanel.getAnswer());
		}
		else if (e.getActionCommand().equals("previous"))
		{
			SI.historyPanel.removeLastElement();
			SI.clipsManager.cancelLastAnswer();
		}
		else if (e.getActionCommand().equals("restart"))
		{
			SI.historyPanel.removeAllElements();
			SI.plantListPanel.removeAllElements();
			clearQuestion();
			SI.clipsManager.restart();
		}

		updateButtonsState();
	}

	public void clearQuestion()
	{
		questionLabel.setText("");
		clearAnswers();
		updateButtonsState();
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
		clearAnswers();

		questionLabel.setText("");
		questionLabel.setText(question);

		if (answer != null)
		{
			String[] answers = answer.split(";");

			radioPanel.setLayout(new GridLayout(0, answers.length / 4 + 1));

			for (String s : answers)
			{
				JRadioButton button = new JRadioButton(s);
				button.setActionCommand(s);
				button.addActionListener(this);
				group.add(button);
				radioPanel.add(button);
			}

			JRadioButton button = (JRadioButton) radioPanel.getComponent(radioPanel.getComponentCount()-1);
			button.setSelected(true);
		}

		updateButtonsState();
	}

	private void updateHistory()
	{
		if (isAnswerSelected())
			SI.historyPanel.addElement(getQuestion() + " " + getAnswer());
	}

	private void clearAnswers()
	{
		group.clearSelection();
		for (Component button : radioPanel.getComponents())
			group.remove((AbstractButton) button);
		radioPanel.removeAll();
	}

	private void updateButtonsState()
	{
		next.setEnabled(isAnswerSelected());
		previous.setEnabled(!SI.historyPanel.isEmpty());
	}
}
