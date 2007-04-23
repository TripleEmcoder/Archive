package gardener;

import java.util.HashMap;
import java.util.Map;

public class Plant
{
	private Map<String, String> properties;

	public Plant()
	{
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
}
