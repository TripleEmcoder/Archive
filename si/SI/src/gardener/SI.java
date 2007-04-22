package gardener;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.Border;

public class SI
{
	private class ActionHandler implements ActionListener
	{

		public void actionPerformed(ActionEvent e)
		{
			if (e.getActionCommand() == "next")
			{
				if (questionPanel.isAnswerSelected())
					clipsManager.assertFact(questionPanel.getFact());
			}
			else if (e.getActionCommand() == "previous")
			{
				
			}
			else if (e.getActionCommand() == "restart")
			{
				historyPanel.removeAllQuestions();
				questionPanel.clearQuestion();
				clipsManager.reset();
			}
		}

	}

	private static QuestionPanel questionPanel;
	private static HistoryPanel historyPanel;
	private static JButton next, previous, restart;
	private static ClipsManager clipsManager;
		
	private static void createAndShowGUI()
	{
		JFrame frame = new JFrame("Gardener");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setBounds(100, 100, 800, 600);
		
		Border blackline = BorderFactory.createLineBorder(Color.black);
		ActionHandler actionHandler = new SI().new ActionHandler();

		Container pane = frame.getContentPane();
		pane.setLayout(new FlowLayout());
		
		historyPanel.setPreferredSize(new Dimension(500-10, 350-10));
		historyPanel.setBorder(blackline);
		
		JPanel imagePanel = new JPanel();
		imagePanel.setPreferredSize(new Dimension(300-10, 350-10));
		imagePanel.setBorder(blackline);
		
		questionPanel.setPreferredSize(new Dimension(500-10, 200-10));
		questionPanel.setBorder(blackline);
		
		JPanel buttonPanel = new JPanel();
		buttonPanel.setPreferredSize(new Dimension(300-10, 200-10));
		buttonPanel.setBorder(blackline);
		buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.PAGE_AXIS));
		
		next = new JButton("next");
		next.addActionListener(actionHandler);
		next.setActionCommand("next");
		previous = new JButton("previous"); 
		previous.addActionListener(actionHandler);
		previous.setActionCommand("previous");
		restart = new JButton("restart");
		restart.addActionListener(actionHandler);
		restart.setActionCommand("restart");
		
		buttonPanel.add(Box.createVerticalGlue());
		buttonPanel.add(restart);
		buttonPanel.add(Box.createVerticalGlue());
		buttonPanel.add(previous);
		buttonPanel.add(Box.createVerticalGlue());
		buttonPanel.add(next);
		buttonPanel.add(Box.createVerticalGlue());
		
		pane.add(historyPanel);
		pane.add(imagePanel);
		pane.add(questionPanel);
		pane.add(buttonPanel);
		
		frame.setVisible(true);
	}
	
	public static void main(String[] args)
	{		
		historyPanel = new HistoryPanel();
		questionPanel = new QuestionPanel();
		clipsManager = new ClipsManager(questionPanel, historyPanel);
		
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				createAndShowGUI();
			}
		});
		
		clipsManager.load("test.clp");
	}

}
