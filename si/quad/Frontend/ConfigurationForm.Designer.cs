namespace Quad.Frontend
{
    partial class ConfigurationForm
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.playerConfigurationControl2 = new Quad.Frontend.PlayerConfigurationControl();
            this.playerConfigurationControl1 = new Quad.Frontend.PlayerConfigurationControl();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.button1.Location = new System.Drawing.Point(12, 212);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "OK";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.button2.Location = new System.Drawing.Point(93, 212);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 1;
            this.button2.Text = "Anuluj";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // playerConfigurationControl2
            // 
            this.playerConfigurationControl2.Location = new System.Drawing.Point(12, 112);
            this.playerConfigurationControl2.Name = "playerConfigurationControl2";
            this.playerConfigurationControl2.Player = Quad.Backend.Player.Black;
            this.playerConfigurationControl2.PlayerType = Quad.Backend.PlayerType.Computer;
            this.playerConfigurationControl2.Size = new System.Drawing.Size(376, 94);
            this.playerConfigurationControl2.TabIndex = 3;
            // 
            // playerConfigurationControl1
            // 
            this.playerConfigurationControl1.Location = new System.Drawing.Point(12, 12);
            this.playerConfigurationControl1.Name = "playerConfigurationControl1";
            this.playerConfigurationControl1.Player = Quad.Backend.Player.White;
            this.playerConfigurationControl1.PlayerType = Quad.Backend.PlayerType.Human;
            this.playerConfigurationControl1.Size = new System.Drawing.Size(376, 94);
            this.playerConfigurationControl1.TabIndex = 2;
            // 
            // ConfigurationForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(400, 247);
            this.Controls.Add(this.playerConfigurationControl2);
            this.Controls.Add(this.playerConfigurationControl1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "ConfigurationForm";
            this.Text = "ConfigurationForm";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private PlayerTypeSelectionControl playerTypeControl1;
        private PlayerTypeSelectionControl playerTypeControl2;
        private PlayerConfigurationControl playerConfigurationControl1;
        private PlayerConfigurationControl playerConfigurationControl2;

    }
}