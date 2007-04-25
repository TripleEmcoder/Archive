package gardener;

import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

public class PlantListPanel extends ListPanel implements ListSelectionListener
{
	private static final long serialVersionUID = 1L;

	public PlantListPanel()
	{
		super(false);
		list.getSelectionModel().addListSelectionListener(this);
	}

	public void addElement(String element)
	{
		int index = 0;
		while (index < listModel.getSize()
				&& element.compareTo((String) listModel.get(index)) > 0)
			index++;
		listModel.add(index, element);
	}

	public void valueChanged(ListSelectionEvent e)
	{
		ListSelectionModel lsm = (ListSelectionModel)e.getSource();
		if (!e.getValueIsAdjusting() && !lsm.isSelectionEmpty())
		{
			String plantname = (String)listModel.get(lsm.getMinSelectionIndex());
			Plant plant = SI.plantFinder.find(plantname);
			SI.plantInfoPanel.setPlant(plant);
		}
	}
}
