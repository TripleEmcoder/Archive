package gardener;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import java.util.HashMap;
import java.util.Map;

import javax.imageio.ImageIO;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SpringLayout;

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
					URL imgURL = SI.class
							.getResource("plants/" + name + ".jpg");
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

	private static final long serialVersionUID = 1L;

	private ImagePanel imagePanel;

	private Map<String, JTextField> fields;

	public PlantInfoPanel()
	{
		fields = new HashMap<String, JTextField>();
		imagePanel = new ImagePanel();

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

		SpringUtilities.makeCompactGrid(formPanel, labels.length, 2, // rows,
				// cols
				6, 6, // initX, initY
				20, 10); // xPad, yPad

		add(imagePanel);
		add(formPanel);
	}

	public void setPlant(Plant plant)
	{
		//System.err.println(String.format("setPlant(%s)", plant.getLatinName()));
		imagePanel.setImage(ImageLoader.getImage(plant.getLatinName()));

		for (String label : fields.keySet())
		{
			fields.get(label).setText(plant.getProperty(label));
		}
	}
	
	public void clearPlant()
	{
		
	}
}
