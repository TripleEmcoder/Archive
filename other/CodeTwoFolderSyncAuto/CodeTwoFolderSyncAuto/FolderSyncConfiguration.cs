using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using White.Core;
using White.Core.InputDevices;
using White.Core.UIItems;
using White.Core.UIItems.Finders;
using White.Core.UIItems.MenuItems;
using White.Core.UIItems.TreeItems;
using White.Core.UIItems.WindowItems;
using White.Core.WindowsAPI;
using White.Core.UIItems.TableItems;

namespace CodeTwoFolderSyncAuto
{
    class FolderSyncConfiguration
    {
        public FolderSyncConfiguration()
        {

        }

        public IEnumerable<string[]> GetAvailableFolders()
        {
            Application application = Application.Attach("outlook");
            Window mainWindow = application.GetWindows()[0];
            mainWindow.Keyboard.HoldKey(KeyboardInput.SpecialKeys.LEFT_ALT);
            mainWindow.Keyboard.Enter("T");
            mainWindow.Keyboard.Enter("O");
            mainWindow.Keyboard.LeaveKey(KeyboardInput.SpecialKeys.LEFT_ALT);

            //Window options = application.GetWindow("Options");
            Window optionsWindow = application.GetWindows()[1];
            optionsWindow.Tabs[0].SelectTabPage("CodeTwo FoldersSync Addin");
            optionsWindow.Get<Button>("Add...").Click();

            //Window pair = application.GetWindow("New synchronized group");
            Window pairWindow = application.GetWindows()[2];
            pairWindow.Get<Button>("Browse...").Click();

            //Window folders = application.GetWindow("Select a folder");
            Window foldersWindow = application.GetWindows()[3];
            Tree foldersTree = foldersWindow.Get<Tree>();

            foreach (TreeNode node in foldersTree.Nodes)
                foreach (string[] path in GetNodes(node, new List<string>()))
                    yield return path;

            foldersWindow.Close();
            pairWindow.Close();
            optionsWindow.Close();

            application.ApplicationSession.Save();
        }

        public IEnumerable<string[]> GetNodes(TreeNode parentNode, IList<string> parentPath)
        {
            parentPath.Add(parentNode.Name);
            yield return parentPath.ToArray();

            //parentNode.Expand();
            parentNode.Select();
            Keyboard.Instance.PressSpecialKey(KeyboardInput.SpecialKeys.RIGHT);
            Thread.Sleep(500);
            
            foreach (TreeNode childNode in parentNode.Nodes)
                foreach (string[] childPath in GetNodes(childNode, parentPath))
                    yield return childPath;

            //parentNode.Collapse();
            parentNode.Select();
            Keyboard.Instance.PressSpecialKey(KeyboardInput.SpecialKeys.LEFT);
            Thread.Sleep(500);

            parentPath.RemoveAt(parentPath.Count - 1);
        }

        public IEnumerable<KeyValuePair<string[], string[]>> GetSyncPairs()
        {
            Application application = Application.Attach("outlook");
            Window mainWindow = application.GetWindows()[0];
            mainWindow.Keyboard.HoldKey(KeyboardInput.SpecialKeys.LEFT_ALT);
            mainWindow.Keyboard.Enter("T");
            mainWindow.Keyboard.Enter("O");
            mainWindow.Keyboard.LeaveKey(KeyboardInput.SpecialKeys.LEFT_ALT);

            //Window options = application.GetWindow("Options");
            Window optionsWindow = application.GetWindows()[1];
            optionsWindow.Tabs[0].SelectTabPage("CodeTwo FoldersSync Addin");

            ListView pairsListView = optionsWindow.Get<ListView>();
            
            foreach (ListViewRow row in pairsListView.Rows)
                yield return new KeyValuePair<string[], string[]>(row.Cells[0].Text.Split('\\'), row.Cells[1].Text.Split('\\'));

            optionsWindow.Close();

            application.ApplicationSession.Save();
        }

        public void AddSyncPairs(IEnumerable<KeyValuePair<string[], string[]>> pairs)
        {
            Application application = Application.Attach("outlook");
            Window mainWindow = application.GetWindows()[0];
            mainWindow.Keyboard.HoldKey(KeyboardInput.SpecialKeys.LEFT_ALT);
            mainWindow.Keyboard.Enter("T");
            mainWindow.Keyboard.Enter("O");
            mainWindow.Keyboard.LeaveKey(KeyboardInput.SpecialKeys.LEFT_ALT);

            //Window optionsWindow = application.GetWindow("Options");
            Window optionsWindow = application.GetWindows()[1];
            optionsWindow.Tabs[0].SelectTabPage("CodeTwo FoldersSync Addin");

            foreach (KeyValuePair<string[], string[]> pair in pairs)
            {
                optionsWindow.Get<Button>("Add...").Click();

                //Window pairWindow = application.GetWindow("New synchronized group");
                Window pairWindow = application.GetWindows()[2];
                pairWindow.Get<Button>("Browse...").Click();
                SelectFolder(application, pair.Key);
                pairWindow.Get<Button>("Browse..").Click();
                SelectFolder(application, pair.Value);

                pairWindow.Get<Button>("OK").Click();
            }

            optionsWindow.Get<Button>("OK").Click();

            application.ApplicationSession.Save();
        }

        private void SelectFolder(Application application, string[] path)
        {
            //Window foldersWindow = application.GetWindow("Select a folder");
            Window foldersWindow = application.GetWindows()[3];
            Tree foldersTree = foldersWindow.Get<Tree>();
            TreeNode node = foldersTree.Node(path[0]);

            foreach (string name in path.Skip(1))
            {
                //node.Expand();
                node.Select();
                Keyboard.Instance.PressSpecialKey(KeyboardInput.SpecialKeys.RIGHT);
                Thread.Sleep(500);

                node = node.GetItem(name);
            }
            
            node.Select();
            foldersWindow.Get<Button>("OK").Click();
        }
    }
}
