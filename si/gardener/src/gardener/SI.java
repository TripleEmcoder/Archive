package gardener;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.Border;
import javax.swing.border.EtchedBorder;

public class SI
{
	static QuestionPanel questionPanel;
	static ListPanel historyPanel;
	static PlantListPanel plantListPanel;
	static ClipsManager clipsManager;
	static PlantFinder plantFinder;
	static PlantInfoPanel plantInfoPanel;
	static String clipsFiles[] = { "java.clp", "tools.clp", "questions.clp",
			"rules.clp", "plants.clp", };

	private static void createAndShowGUI()
	{
		historyPanel = new ListPanel(true);
		questionPanel = new QuestionPanel();
		plantInfoPanel = new PlantInfoPanel();
		plantListPanel = new PlantListPanel();
		plantFinder = new PlantFinder("plants.xml");

		JFrame frame = new JFrame("Gardener");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setBounds(50, 50, 950, 670);

		Border lowered = BorderFactory.createEtchedBorder(EtchedBorder.LOWERED);

		Container pane = frame.getContentPane();
		pane.setLayout(new BorderLayout());

		JPanel leftPanel = new JPanel();
		leftPanel.setLayout(new BoxLayout(leftPanel, BoxLayout.PAGE_AXIS));
		leftPanel.setPreferredSize(new Dimension(540, 550 - 10));
		leftPanel.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

		JPanel rightPanel = new JPanel();
		rightPanel.setLayout(new BoxLayout(rightPanel, BoxLayout.PAGE_AXIS));
		rightPanel.setPreferredSize(new Dimension(410 - 5, 550 - 10));
		rightPanel.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

		historyPanel.setPreferredSize(new Dimension(400, 375 - 10));
		historyPanel.setBorder(BorderFactory.createCompoundBorder(BorderFactory
				.createTitledBorder(lowered, "Historia pytañ"), BorderFactory
				.createEmptyBorder(5, 5, 5, 5)));

		questionPanel.setPreferredSize(new Dimension(150, 200 - 10));
		questionPanel.setBorder(BorderFactory.createCompoundBorder(
				BorderFactory.createTitledBorder(lowered, "Pytanie"),
				BorderFactory.createEmptyBorder(5, 5, 5, 5)));

		plantListPanel.setPreferredSize(new Dimension(200, 375 - 10));
		plantListPanel.setBorder(BorderFactory.createCompoundBorder(
				BorderFactory.createTitledBorder(lowered, "Lista roœlin"),
				BorderFactory.createEmptyBorder(5, 5, 5, 5)));

		plantInfoPanel.setPreferredSize(new Dimension(200, 200-10));
		plantInfoPanel.setBorder(BorderFactory.createCompoundBorder(
				BorderFactory.createTitledBorder(lowered, "Opis roœliny"),
				BorderFactory.createEmptyBorder(5, 5, 5, 5)));

		JPanel panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.LINE_AXIS));
		panel.add(historyPanel);
		panel.add(plantListPanel);

		leftPanel.add(panel);
		leftPanel.add(questionPanel);

		rightPanel.add(plantInfoPanel);

		pane.add(leftPanel, BorderLayout.LINE_START);
		pane.add(rightPanel, BorderLayout.LINE_END);

		frame.setVisible(true);
	}

	public static void main(String[] args)
	{
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				createAndShowGUI();
				clipsManager = new ClipsManager();
				for (String filename : clipsFiles)
					clipsManager.load(filename);
				clipsManager.restart();
			}
		});
	}

}
