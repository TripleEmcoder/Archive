package gardener;

import java.net.URL;
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
		
		JPanel formPanel = new JPanel(new SpringLayout());
		for (String label : labels)
		{
			JLabel l = new JLabel(label, JLabel.TRAILING);
			formPanel.add(l);
			JTextField textField = new JTextField(20);
			l.setLabelFor(textField);
			formPanel.add(textField);
			fields.put(label.toLowerCase(), textField);
		}

		SpringUtilities.makeCompactGrid(formPanel, labels.length, 2, // rows, cols
				6, 6, // initX, initY
				20, 10); // xPad, yPad

		add(formPanel);
	}
	
	public void setPlant(Plant plant)
	{
		URL imgURL = SI.class.getResource("plants/" + plant.getLatinName() + ".jpg");
		if (imgURL != null)
			System.err.println(imgURL.getPath());
		for (String label : fields.keySet())
		{
			fields.get(label).setText(plant.getProperty(label));
		}
	}
}
