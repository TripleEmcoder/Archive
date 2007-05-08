package gardener;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.imageio.ImageIO;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.ScrollPaneConstants;
import javax.swing.SpringLayout;
import javax.swing.text.JTextComponent;

public class PlantInfoPanel extends JPanel
{
	private static class ImageLoader
	{
		private static Map<String, BufferedImage> images = new HashMap<String, BufferedImage>();

		public static BufferedImage getImage(String name)
		{
			if (!images.containsKey(name))
			{
				try
				{
					URL imgURL = SI.class.getResource("plants/" + name + ".jpg");
					if (imgURL == null)
					{
						throw new FileNotFoundException();
					}
					BufferedImage img = null;
					img = ImageIO.read(imgURL);
					images.put(name, img);
				}
				catch (IOException e)
				{
					images.put(name, null);
				}
			}

			return images.get(name);
		}

	}

	private class ImagePanel extends JPanel
	{
		private static final long serialVersionUID = 1L;
		private BufferedImage img;

		public ImagePanel()
		{
			super();
		}

		public Dimension getPreferredSize()
		{
			return new Dimension(200, 200);
		}

		public void paint(Graphics g)
		{
			if (img != null)
			{
				g.drawImage(img, 0, 0, this.getWidth(), this.getHeight(), null);
			}
			else
			{
				g.clearRect(0, 0, this.getWidth(), this.getHeight());
			}
		}

		public void setImage(BufferedImage img)
		{
			this.img = img;
			this.repaint();
		}
	}

	private class FieldProperty
	{
		public String label;
		public int rows, cols;

		public FieldProperty(String label, int rows, int cols)
		{
			super();
			this.label = label;
			this.rows = rows;
			this.cols = cols;
		}
	}

	private static final long serialVersionUID = 1L;

	private ImagePanel imagePanel;

	private Map<String, JTextComponent> fields;

	public PlantInfoPanel()
	{
		fields = new HashMap<String, JTextComponent>();
		imagePanel = new ImagePanel();
		List<FieldProperty> fieldProperties = new ArrayList<FieldProperty>();

		fieldProperties.add(new FieldProperty("Nazwa", 1, 20));
		fieldProperties.add(new FieldProperty("Rodzina", 1, 20));
		fieldProperties.add(new FieldProperty("Pochodzenie", 1, 20));
		fieldProperties.add(new FieldProperty("Rozmiary", 2, 20));
		fieldProperties.add(new FieldProperty("Podlewanie", 2, 20));
		fieldProperties.add(new FieldProperty("Nawo¿enie", 1, 20));
		fieldProperties.add(new FieldProperty("Stanowisko", 1, 20));
		fieldProperties.add(new FieldProperty("Kwiaty", 2, 20));
		fieldProperties.add(new FieldProperty("Ciekawe cechy", 5, 20));

		JPanel formPanel = new JPanel(new SpringLayout());
		for (FieldProperty field : fieldProperties)
		{
			JLabel l = new JLabel(field.label, JLabel.TRAILING);
			formPanel.add(l);
			JTextArea textField = new JTextArea(field.rows, field.cols);
			textField.setLineWrap(true);
			textField.setWrapStyleWord(true);
			textField.setEditable(false);
			JScrollPane scrollPane = new JScrollPane(textField,
					ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,
					ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
			l.setLabelFor(textField);
			formPanel.add(scrollPane);
			fields.put(field.label.toLowerCase(), textField);
		}

		SpringUtilities.makeCompactGrid(formPanel, fieldProperties.size(), 2,
				20, 6, 20, 10);

		add(imagePanel);
		add(formPanel);
	}

	public void setPlant(Plant plant)
	{
		if (plant != null)
		{
			imagePanel.setImage(ImageLoader.getImage(plant.getLatinName()));

			for (String label : fields.keySet())
			{
				fields.get(label).setText(plant.getProperty(label));
				fields.get(label).setCaretPosition(0);
			}
		
		}
		else
		{
			clearPlant();
		}
	}

	public void clearPlant()
	{
		imagePanel.setImage(null);

		for (JTextComponent t : fields.values())
		{
			t.setText(null);
		}
	}
}
