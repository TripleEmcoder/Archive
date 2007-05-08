package gardener;

import java.awt.GridLayout;

import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;

public class ListPanel extends JPanel
{
	private static final long serialVersionUID = 1L;
	protected DefaultListModel listModel;
	protected JList list;
	private boolean numbered;

	public ListPanel(boolean numbered)
	{
		super(new GridLayout(1, 1));

		this.numbered = numbered;
		listModel = new DefaultListModel();
		list = new JList(listModel);
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

		JScrollPane listScroller = new JScrollPane(list);

		add(listScroller);
	}

	public void addElement(String element)
	{
		if (numbered)
			element = Integer.toString(listModel.getSize() + 1) + ". "
					+ element;
		listModel.addElement(element);
	}

	public void removeLastElement()
	{
		listModel.removeElement(listModel.lastElement());
	}

	public void removeAllElements()
	{
		listModel.removeAllElements();
	}

	public boolean isEmpty()
	{
		return listModel.isEmpty();
	}
}
