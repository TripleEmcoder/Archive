namespace Quad.Frontend
{
    partial class PlayerTypeSelectionControl
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.humanRadioButton = new System.Windows.Forms.RadioButton();
            this.computerRadioButton = new System.Windows.Forms.RadioButton();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.computerRadioButton);
            this.groupBox1.Controls.Add(this.humanRadioButton);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(120, 75);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Rodzaj";
            // 
            // humanRadioButton
            // 
            this.humanRadioButton.AutoSize = true;
            this.humanRadioButton.Location = new System.Drawing.Point(6, 19);
            this.humanRadioButton.Name = "humanRadioButton";
            this.humanRadioButton.Size = new System.Drawing.Size(69, 17);
            this.humanRadioButton.TabIndex = 0;
            this.humanRadioButton.TabStop = true;
            this.humanRadioButton.Text = "Cz³owiek";
            this.humanRadioButton.UseVisualStyleBackColor = true;
            this.humanRadioButton.CheckedChanged += new System.EventHandler(this.humanRadioButton_CheckedChanged);
            // 
            // computerRadioButton
            // 
            this.computerRadioButton.AutoSize = true;
            this.computerRadioButton.Location = new System.Drawing.Point(6, 47);
            this.computerRadioButton.Name = "computerRadioButton";
            this.computerRadioButton.Size = new System.Drawing.Size(70, 17);
            this.computerRadioButton.TabIndex = 1;
            this.computerRadioButton.TabStop = true;
            this.computerRadioButton.Text = "Komputer";
            this.computerRadioButton.UseVisualStyleBackColor = true;
            this.computerRadioButton.CheckedChanged += new System.EventHandler(this.computerRadioButton_CheckedChanged);
            // 
            // PlayerTypeSelectionControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox1);
            this.Name = "PlayerTypeSelectionControl";
            this.Size = new System.Drawing.Size(120, 75);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton computerRadioButton;
        private System.Windows.Forms.RadioButton humanRadioButton;
    }
}
