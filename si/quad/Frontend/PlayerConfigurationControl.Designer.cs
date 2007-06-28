namespace Quad.Frontend
{
    partial class PlayerConfigurationControl
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.algorithmSelectionControl1 = new Quad.Frontend.AlgorithmSelectionControl();
            this.playerTypeSelectionControl1 = new Quad.Frontend.PlayerTypeSelectionControl();
            this.evaluatorSelectionControl1 = new Quad.Frontend.EvaluatorSelectionControl();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.Location = new System.Drawing.Point(3, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(33, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Brak";
            // 
            // algorithmSelectionControl1
            // 
            this.algorithmSelectionControl1.AutoSize = true;
            this.algorithmSelectionControl1.Location = new System.Drawing.Point(252, 21);
            this.algorithmSelectionControl1.Name = "algorithmSelectionControl1";
            this.algorithmSelectionControl1.Size = new System.Drawing.Size(120, 165);
            this.algorithmSelectionControl1.TabIndex = 4;
            // 
            // playerTypeSelectionControl1
            // 
            this.playerTypeSelectionControl1.Location = new System.Drawing.Point(0, 21);
            this.playerTypeSelectionControl1.Name = "playerTypeSelectionControl1";
            this.playerTypeSelectionControl1.PlayerType = Quad.Backend.PlayerType.None;
            this.playerTypeSelectionControl1.Size = new System.Drawing.Size(120, 75);
            this.playerTypeSelectionControl1.TabIndex = 3;
            this.playerTypeSelectionControl1.PlayerTypeChanged += new System.EventHandler<System.EventArgs>(this.playerTypeSelectionControl1_PlayerTypeChanged);
            // 
            // evaluatorSelectionControl1
            // 
            this.evaluatorSelectionControl1.Location = new System.Drawing.Point(126, 21);
            this.evaluatorSelectionControl1.Name = "evaluatorSelectionControl1";
            this.evaluatorSelectionControl1.Size = new System.Drawing.Size(120, 75);
            this.evaluatorSelectionControl1.TabIndex = 2;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Location = new System.Drawing.Point(126, 103);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(120, 83);
            this.groupBox1.TabIndex = 5;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Ustawienia";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(72, 19);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(36, 20);
            this.textBox1.TabIndex = 8;
            this.textBox1.Text = "4";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 22);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(63, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "G³êbokoœæ:";
            // 
            // PlayerConfigurationControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.algorithmSelectionControl1);
            this.Controls.Add(this.playerTypeSelectionControl1);
            this.Controls.Add(this.evaluatorSelectionControl1);
            this.Controls.Add(this.label1);
            this.Name = "PlayerConfigurationControl";
            this.Size = new System.Drawing.Size(376, 189);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private EvaluatorSelectionControl evaluatorSelectionControl1;
        private PlayerTypeSelectionControl playerTypeSelectionControl1;
        private AlgorithmSelectionControl algorithmSelectionControl1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label2;

    }
}
