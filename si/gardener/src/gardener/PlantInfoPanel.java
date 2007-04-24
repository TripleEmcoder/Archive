package gardener;

import java.util.HashMap;
import java.util.Map;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SpringLayout;

public class PlantInfoPanel extends JPanel
{
	private static final long serialVersionUID = 1L;
	
	private Map<String, JTextField> fields;

	public PlantInfoPanel()
	{
		fields = new HashMap<String, JTextField>();
		
		String[] labels = { "Nazwa", "Rodzina", "Rozmiary", "Podlewanie",
				"Nawo¿enie", "Stanowisko", "Kwiaty", "Ciekawe cechy" };
		
		int numPairs = labels.length;
		
		JPanel p = new JPanel(new SpringLayout());
		for (String label : labels)
		{
			JLabel l = new JLabel(label, JLabel.TRAILING);
			p.add(l);
			JTextField textField = new JTextField(20);
			l.setLabelFor(textField);
			p.add(textField);
			fields.put(label.toLowerCase(), textField);
		}

		SpringUtilities.makeCompactGrid(p, numPairs, 2, // rows, cols
				6, 6, // initX, initY
				20, 10); // xPad, yPad

		add(p);
	}
	
	public void setPlant(Plant plant)
	{
		for (String label : fields.keySet())
		{
			fields.get(label).setText(plant.getProperty(label));
		}
	}
}
