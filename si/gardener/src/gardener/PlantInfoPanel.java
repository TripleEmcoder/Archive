package gardener;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SpringLayout;

public class PlantInfoPanel extends JPanel
{
	private static final long serialVersionUID = 1L;

	public PlantInfoPanel()
	{
		String[] labels = { "Nazwa", "Rodzina", "Rozmiary", "Podlewanie",
				"Nawo¿enie", "Stanowisko", "Kwiaty", "Ciekawe cechy" };
		int numPairs = labels.length;
		// Create and populate the panel.
		JPanel p = new JPanel(new SpringLayout());
		for (int i = 0; i < numPairs; i++)
		{
			JLabel l = new JLabel(labels[i], JLabel.TRAILING);
			p.add(l);
			JTextField textField = new JTextField(10);
			l.setLabelFor(textField);
			p.add(textField);
		}

		// Lay out the panel.
		SpringUtilities.makeCompactGrid(p, numPairs, 2, // rows, cols
				6, 6, // initX, initY
				20, 10); // xPad, yPad

		add(p);

	}
}
