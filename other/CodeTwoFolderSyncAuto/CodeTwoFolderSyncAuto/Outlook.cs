using System;
using System.Linq;
using White.Core;
using White.Core.UIItems;
using White.Core.UIItems.TreeItems;
using White.Core.UIItems.WindowItems;
using Debug = System.Diagnostics.Debug;

namespace CodeTwoFolderSyncAuto
{
    internal class Outlook
    {
        public void CreateFolder(string[] path)
        {
            Application application = Application.Attach("outlook");
            Window main = application.GetWindows()[0];

            Debug.WriteLine("Switching to Mail...");
            Button mail = main.Get<Button>("Mail");
            mail.Click();

            Debug.WriteLine("Finding Mail Folders...");
            Tree folders = main.Get<Tree>("Mail Folders");
            TreeNode parentNode = folders.Node(path[0]);

            foreach (string name in path.Skip(1))
            {
                TreeNode childNode = parentNode.GetItem(name);

                if (childNode == null)
                {
                    parentNode.RightClick();
                    main.Popup.Item("New Folder...");
                    return;
                }

            }

            application.ApplicationSession.Save();
        }
    }
}