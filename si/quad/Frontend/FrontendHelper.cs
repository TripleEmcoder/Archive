using System;
using System.Collections.Generic;
using System.Text;

using System.Drawing;
using System.Reflection;
using System.Windows.Forms;

using Quad.Backend;

namespace Quad.Frontend
{
    public static class FrontendHelper
    {
        private static Dictionary<Player, Image> images;

        static FrontendHelper()
        {
            images = new Dictionary<Player, Image>();
            images[Player.None] = LoadImage("None.bmp");
            images[Player.White] = LoadImage("White.bmp");
            images[Player.Black] = LoadImage("Black.bmp");
        }

        private static Image LoadImage(string name)
        {
            Assembly assembly = Assembly.GetExecutingAssembly();
            name = assembly.GetName().Name + "." + name;
            return Image.FromStream(assembly.GetManifestResourceStream(name));
        }

        public static Dictionary<Player, Image> Images
        {
            get { return images; }
        }

        public static RadioButton GetCheckedRadioButton(Control.ControlCollection controls)
        {
            foreach (Control control in controls)
                if (((RadioButton)control).Checked)
                    return (RadioButton)control;

            return null;
        }
    }
}
