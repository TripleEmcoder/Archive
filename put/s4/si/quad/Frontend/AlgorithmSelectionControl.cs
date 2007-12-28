using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

using Quad.Backend;

namespace Quad.Frontend
{
    public partial class AlgorithmSelectionControl : UserControl
    {
        public AlgorithmSelectionControl()
        {
            InitializeComponent();

            foreach (Algorithm algorithm in BackendHelper.Algorithms)
            {
                RadioButton selector = new RadioButton();
                
                selector.Text = algorithm.Name;
                selector.Tag = algorithm;

                flowLayoutPanel1.Controls.Add(selector);
            }

            ((RadioButton)flowLayoutPanel1.Controls[0]).Checked = true;
        }

        public Algorithm Algorithm
        {
            get { return (Algorithm)FrontendHelper.GetCheckedRadioButton(flowLayoutPanel1.Controls).Tag; }
        }
    }
}
