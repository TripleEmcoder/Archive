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
    public partial class EvaluatorSelectionControl : UserControl
    {
        public EvaluatorSelectionControl()
        {
            InitializeComponent();

            foreach (Evaluator evaluator in BackendHelper.Evaluators)
            {
                RadioButton selector = new RadioButton();

                selector.Text = evaluator.Name;
                selector.Tag = evaluator;

                flowLayoutPanel1.Controls.Add(selector);
            }

            ((RadioButton)flowLayoutPanel1.Controls[0]).Checked = true;
        }

        public Evaluator Evaluator
        {
            get { return (Evaluator)FrontendHelper.GetCheckedRadioButton(flowLayoutPanel1.Controls).Tag; }
        }
    }
}
