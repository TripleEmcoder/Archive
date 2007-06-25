using System;
using System.Collections.Generic;
using System.Text;

using System.Windows.Forms;

namespace Quad.Frontend
{
    public static class FrontendHelper
    {
        public static RadioButton GetCheckedRadioButton(Control.ControlCollection controls)
        {
            foreach (Control control in controls)
                if (((RadioButton)control).Checked)
                    return (RadioButton)control;

            return null;
        }
    }
}
