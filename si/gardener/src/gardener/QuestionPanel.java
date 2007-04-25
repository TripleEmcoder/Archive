package gardener;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

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
		questionLabel.setAlignmentX(CENTER_ALIGNMENT);
		// questionLabel.setBorder(BorderFactory.createEmptyBorder(0, 20, 0,
		// 0));

		radioPanel = new JPanel();
		// radioPanel.setLayout(new BoxLayout(radioPanel, BoxLayout.PAGE_AXIS));
		// radioPanel.setLayout(new GridLayout(0,1));
		// radioPanel.setMinimumSize(new Dimension(350,200));
		radioPanel.setAlignmentX(CENTER_ALIGNMENT);

		// radioPanel.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 0));

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
		if (e.getActionCommand() == "next")
		{
			SI.clipsManager.sendAnswer(SI.questionPanel.getAnswer());
		}
		else if (e.getActionCommand() == "previous")
		{
			SI.historyPanel.removeLastElement();
			SI.questionPanel.clearQuestion();
			SI.clipsManager.cancelLastAnswer();
		}
		else if (e.getActionCommand() == "restart")
		{
			SI.historyPanel.removeAllElements();
			SI.plantListPanel.removeAllElements();
			SI.questionPanel.clearQuestion();
			SI.clipsManager.reset();
		}
		else
		{
			next.setEnabled(true);
		}
	}

	public void clearQuestion()
	{
		questionLabel.setText("");
		group.clearSelection();
		radioPanel.removeAll();
		next.setEnabled(false);
		previous.setEnabled(false);
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

		next.setEnabled(false);
		previous.setEnabled(!SI.historyPanel.isEmpty());
	}
}
