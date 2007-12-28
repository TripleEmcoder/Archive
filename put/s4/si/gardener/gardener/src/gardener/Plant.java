package gardener;

import java.util.HashMap;
import java.util.Map;

public class Plant
{
	private String latinName;
	private Map<String, String> properties;

	public Plant(String name)
	{
		latinName = name;
		properties = new HashMap<String, String>();
	}
	
	public void setProperty(String name, String value)
	{
		properties.put(name, value);
	}
	
	public String getProperty(String name)
	{
		return properties.get(name);
	}

	public String getLatinName()
	{
		return latinName;
	}
}
