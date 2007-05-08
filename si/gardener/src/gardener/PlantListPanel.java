package gardener;

import java.util.List;

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

	public void valueChanged(ListSelectionEvent e)
	{
		if (!e.getValueIsAdjusting())
		{
			System.err.println("valueChanged(ListSelectionEvent e)");
			ListSelectionModel lsm = (ListSelectionModel)e.getSource();
			if (!lsm.isSelectionEmpty())
			{
				String plantname = (String)listModel.get(lsm.getMinSelectionIndex());
				Plant plant = SI.plantFinder.find(plantname);
				SI.plantInfoPanel.setPlant(plant);
			}
			else
			{
				SI.plantInfoPanel.clearPlant();
			}
		}
	}

	public void updateList(List<String> newList)
	{
		Object o = list.getSelectedValue();
		removeAllElements();
		for (String s : newList)
			addElement(s);
	}
	
}
