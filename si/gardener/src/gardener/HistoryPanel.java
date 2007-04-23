package gardener;

import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.ListSelectionModel;

public class HistoryPanel extends JPanel
{
	private static final long serialVersionUID = 1L;
	private DefaultListModel listModel;
	private JList list;
		
	public HistoryPanel()
	{
		super(new GridLayout(1,1));
		
		listModel = new DefaultListModel();
		
		list = new JList(listModel);
		list.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		add(list);
	}
	
	public void addQuestion(String question, String answer)
	{
		listModel.addElement(question + " " + answer);
	}
	
	public void removeQuestion()
	{
		listModel.removeElement(listModel.lastElement());
	}
	
	public void removeAllQuestions()
	{
		listModel.removeAllElements();
	}
	
	public boolean isEmpty()
	{
		return listModel.isEmpty();		
	}
}
