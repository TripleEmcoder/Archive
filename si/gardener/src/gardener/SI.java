package gardener;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.Border;

public class SI
{
	static QuestionPanel questionPanel;
	static HistoryPanel historyPanel;
	static ClipsManager clipsManager;
	static PlantFinder plantFinder;
		
	private static void createAndShowGUI()
	{
		JFrame frame = new JFrame("Gardener");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setBounds(100, 100, 800, 600);
		
		Border blackline = BorderFactory.createLineBorder(Color.black);
		
		Container pane = frame.getContentPane();
		pane.setLayout(new BorderLayout());
		
		JPanel leftPanel = new JPanel();
		leftPanel.setLayout(new BoxLayout(leftPanel, BoxLayout.PAGE_AXIS));
		leftPanel.setPreferredSize(new Dimension(400, 550-10));
		
		historyPanel.setPreferredSize(new Dimension(400, 350-10));
		historyPanel.setBorder(blackline);
		
		questionPanel.setPreferredSize(new Dimension(400, 200-10));
		questionPanel.setBorder(blackline);
		
		leftPanel.add(historyPanel);
		leftPanel.add(questionPanel);
		
		pane.add(leftPanel, BorderLayout.LINE_START);
				
		frame.setVisible(true);
	}
	
	public static void main(String[] args)
	{		
		historyPanel = new HistoryPanel();
		questionPanel = new QuestionPanel();
		clipsManager = new ClipsManager();
		plantFinder = new PlantFinder("plants.xml");
		
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				createAndShowGUI();
			}
		});
		
		clipsManager.load("test.clp");
		clipsManager.load("test1.clp");
		clipsManager.run();
	}

}
