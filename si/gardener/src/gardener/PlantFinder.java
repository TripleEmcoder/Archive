package gardener;

import java.io.File;
import java.io.IOException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class PlantFinder
{
	Document document;

	public PlantFinder(String filename)
	{
		super();
		DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        //factory.setValidating(true);   
        //factory.setNamespaceAware(true);
        try {
           DocumentBuilder builder = factory.newDocumentBuilder();
           document = builder.parse( new File(filename) );
 
        } catch (SAXException sxe) {
           // Error generated during parsing)
           Exception  x = sxe;
           if (sxe.getException() != null)
               x = sxe.getException();
           x.printStackTrace();

        } catch (ParserConfigurationException pce) {
            // Parser with specified options can't be built
            pce.printStackTrace();

        } catch (IOException ioe) {
           // I/O error
           ioe.printStackTrace();
        }
        
        //System.err.println(document.getElementsByTagName("plant").item(0).
        NodeList plants = document.getElementsByTagName("plant");
        for (int i = 0; i < plants.getLength()/20; ++i)
        {
        	Node plant = plants.item(i);
        	System.err.println(plant.getAttributes().getNamedItem("name").getNodeValue());
        	NodeList properties = plant.getChildNodes();
        	for (int j = 0; j < properties.getLength(); ++j)
        	{
        		Node property = properties.item(j);
        		if (property.getNodeName() == "property")
        		{
        			String name = 
        				property.getAttributes().getNamedItem("name").getNodeValue();
        			String value = 
        				property.getAttributes().getNamedItem("value").getNodeValue();
        			System.err.println(name+" = "+value);
        		}
        	}
        	
        }
	}
	

}
