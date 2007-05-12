package gardener;

import java.io.FileNotFoundException;
import java.net.URL;
import java.util.HashMap;
import java.util.Map;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

public class PlantFinder
{
	private Map<String, Plant> plants;

	public PlantFinder(String filename)
	{
		super();
		this.plants = new HashMap<String, Plant>();
				
		try
		{
			URL fileUrl = PlantFinder.class.getResource(filename);

			if (fileUrl == null)
			{
				throw new FileNotFoundException(filename);
			}
			DocumentBuilder builder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
			Document document = builder.parse(fileUrl.toURI().toString());
			addPlants(document.getElementsByTagName("plant"), plants);
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public Plant find(String plantName)
	{
		return plants.get(plantName);
	}

	private void addPlants(NodeList nodeList, Map<String, Plant> plants)
	{
		for (int i = 0; i < nodeList.getLength(); ++i)
		{
			Node node = nodeList.item(i);
			String plantName = node.getAttributes().getNamedItem("name").getNodeValue();
			Plant plant = new Plant(plantName);
					
			NodeList children = node.getChildNodes();
			for (int j = 0; j < children.getLength(); ++j)
			{
				Node child = children.item(j);
				if (child.getNodeName() == "property")
				{
					String name = child.getAttributes().getNamedItem("name")
							.getNodeValue();
					String value = child.getAttributes().getNamedItem("value")
							.getNodeValue();
					plant.setProperty(name, value);
				}
				else if (child.getNodeName() == "photo")
				{
					String path = child.getAttributes().getNamedItem("path")
							.getNodeValue();
					plant.setProperty("photo", path);
				}
			}
			plants.put(plantName, plant);
		}

	}
}
