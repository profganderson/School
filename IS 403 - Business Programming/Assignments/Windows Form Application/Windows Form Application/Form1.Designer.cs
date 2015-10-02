namespace Windows_Form_Application
{
    partial class Form1
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.addDefaultsToQueueAndStack = new System.Windows.Forms.Button();
            this.callersWaiting = new System.Windows.Forms.ListBox();
            this.label2 = new System.Windows.Forms.Label();
            this.clearCallers = new System.Windows.Forms.Button();
            this.addCaller = new System.Windows.Forms.Button();
            this.callerNameLabel = new System.Windows.Forms.Label();
            this.callerName = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.clearDictionary = new System.Windows.Forms.Button();
            this.dictionarySearchTime = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.dictionarySearchButton = new System.Windows.Forms.Button();
            this.dictionarySearchInput = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.dictionaryBox = new System.Windows.Forms.ListBox();
            this.createDefaultDictionary = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.popQueue = new System.Windows.Forms.Button();
            this.clearQueue = new System.Windows.Forms.Button();
            this.queueSearchTime = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.queueSearchButton = new System.Windows.Forms.Button();
            this.queueSearchInput = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.queueBox = new System.Windows.Forms.ListBox();
            this.addCallersToQueue = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.popStack = new System.Windows.Forms.Button();
            this.clearStack = new System.Windows.Forms.Button();
            this.stackSearchTime = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.stackSearchButton = new System.Windows.Forms.Button();
            this.stackSearchInput = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.stackBox = new System.Windows.Forms.ListBox();
            this.addCallersToStack = new System.Windows.Forms.Button();
            this.closeWindow = new System.Windows.Forms.Button();
            this.clearAll = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.addDefaultsToQueueAndStack);
            this.groupBox1.Controls.Add(this.callersWaiting);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.clearCallers);
            this.groupBox1.Controls.Add(this.addCaller);
            this.groupBox1.Controls.Add(this.callerNameLabel);
            this.groupBox1.Controls.Add(this.callerName);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(402, 244);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Set up caller list";
            // 
            // addDefaultsToQueueAndStack
            // 
            this.addDefaultsToQueueAndStack.Location = new System.Drawing.Point(156, 201);
            this.addDefaultsToQueueAndStack.Name = "addDefaultsToQueueAndStack";
            this.addDefaultsToQueueAndStack.Size = new System.Drawing.Size(194, 23);
            this.addDefaultsToQueueAndStack.TabIndex = 6;
            this.addDefaultsToQueueAndStack.Text = "Add Defaults to Queue / Stack";
            this.addDefaultsToQueueAndStack.UseVisualStyleBackColor = true;
            this.addDefaultsToQueueAndStack.Click += new System.EventHandler(this.addDefaultsToQueueAndStack_Click);
            // 
            // callersWaiting
            // 
            this.callersWaiting.FormattingEnabled = true;
            this.callersWaiting.Location = new System.Drawing.Point(156, 48);
            this.callersWaiting.Name = "callersWaiting";
            this.callersWaiting.Size = new System.Drawing.Size(194, 147);
            this.callersWaiting.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(153, 28);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(77, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Callers Waiting";
            // 
            // clearCallers
            // 
            this.clearCallers.Location = new System.Drawing.Point(6, 104);
            this.clearCallers.Name = "clearCallers";
            this.clearCallers.Size = new System.Drawing.Size(100, 23);
            this.clearCallers.TabIndex = 3;
            this.clearCallers.Text = "Clear Callers";
            this.clearCallers.UseVisualStyleBackColor = true;
            this.clearCallers.Click += new System.EventHandler(this.clearCallers_Click);
            // 
            // addCaller
            // 
            this.addCaller.Location = new System.Drawing.Point(6, 75);
            this.addCaller.Name = "addCaller";
            this.addCaller.Size = new System.Drawing.Size(100, 23);
            this.addCaller.TabIndex = 2;
            this.addCaller.Text = "Add Caller";
            this.addCaller.UseVisualStyleBackColor = true;
            this.addCaller.Click += new System.EventHandler(this.addCaller_Click);
            // 
            // callerNameLabel
            // 
            this.callerNameLabel.AutoSize = true;
            this.callerNameLabel.Location = new System.Drawing.Point(6, 29);
            this.callerNameLabel.Name = "callerNameLabel";
            this.callerNameLabel.Size = new System.Drawing.Size(67, 13);
            this.callerNameLabel.TabIndex = 1;
            this.callerNameLabel.Text = "Caller Name:";
            this.callerNameLabel.Click += new System.EventHandler(this.label1_Click);
            // 
            // callerName
            // 
            this.callerName.AcceptsReturn = true;
            this.callerName.Location = new System.Drawing.Point(6, 48);
            this.callerName.Name = "callerName";
            this.callerName.Size = new System.Drawing.Size(100, 20);
            this.callerName.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.clearDictionary);
            this.groupBox2.Controls.Add(this.dictionarySearchTime);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.dictionarySearchButton);
            this.groupBox2.Controls.Add(this.dictionarySearchInput);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.dictionaryBox);
            this.groupBox2.Controls.Add(this.createDefaultDictionary);
            this.groupBox2.Location = new System.Drawing.Point(420, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(402, 244);
            this.groupBox2.TabIndex = 7;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Dictionary Example";
            // 
            // clearDictionary
            // 
            this.clearDictionary.Location = new System.Drawing.Point(229, 180);
            this.clearDictionary.Name = "clearDictionary";
            this.clearDictionary.Size = new System.Drawing.Size(100, 23);
            this.clearDictionary.TabIndex = 7;
            this.clearDictionary.Text = "Clear Dictionary";
            this.clearDictionary.UseVisualStyleBackColor = true;
            this.clearDictionary.Click += new System.EventHandler(this.clearDictionary_Click);
            // 
            // dictionarySearchTime
            // 
            this.dictionarySearchTime.AutoSize = true;
            this.dictionarySearchTime.Location = new System.Drawing.Point(242, 159);
            this.dictionarySearchTime.Name = "dictionarySearchTime";
            this.dictionarySearchTime.Size = new System.Drawing.Size(0, 13);
            this.dictionarySearchTime.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(229, 139);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(82, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "Search Results:";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // dictionarySearchButton
            // 
            this.dictionarySearchButton.Location = new System.Drawing.Point(229, 107);
            this.dictionarySearchButton.Name = "dictionarySearchButton";
            this.dictionarySearchButton.Size = new System.Drawing.Size(100, 23);
            this.dictionarySearchButton.TabIndex = 4;
            this.dictionarySearchButton.Text = "Search";
            this.dictionarySearchButton.UseVisualStyleBackColor = true;
            this.dictionarySearchButton.Click += new System.EventHandler(this.dictionarySearchButton_Click);
            // 
            // dictionarySearchInput
            // 
            this.dictionarySearchInput.Location = new System.Drawing.Point(229, 80);
            this.dictionarySearchInput.Name = "dictionarySearchInput";
            this.dictionarySearchInput.Size = new System.Drawing.Size(100, 20);
            this.dictionarySearchInput.TabIndex = 3;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(226, 59);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(59, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Search for:";
            // 
            // dictionaryBox
            // 
            this.dictionaryBox.FormattingEnabled = true;
            this.dictionaryBox.Location = new System.Drawing.Point(23, 59);
            this.dictionaryBox.Name = "dictionaryBox";
            this.dictionaryBox.Size = new System.Drawing.Size(175, 160);
            this.dictionaryBox.TabIndex = 1;
            // 
            // createDefaultDictionary
            // 
            this.createDefaultDictionary.Location = new System.Drawing.Point(23, 29);
            this.createDefaultDictionary.Name = "createDefaultDictionary";
            this.createDefaultDictionary.Size = new System.Drawing.Size(175, 23);
            this.createDefaultDictionary.TabIndex = 0;
            this.createDefaultDictionary.Text = "Create Default Dictionary";
            this.createDefaultDictionary.UseVisualStyleBackColor = true;
            this.createDefaultDictionary.Click += new System.EventHandler(this.createDefaultDictionary_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.popQueue);
            this.groupBox3.Controls.Add(this.clearQueue);
            this.groupBox3.Controls.Add(this.queueSearchTime);
            this.groupBox3.Controls.Add(this.label7);
            this.groupBox3.Controls.Add(this.queueSearchButton);
            this.groupBox3.Controls.Add(this.queueSearchInput);
            this.groupBox3.Controls.Add(this.label8);
            this.groupBox3.Controls.Add(this.queueBox);
            this.groupBox3.Controls.Add(this.addCallersToQueue);
            this.groupBox3.Location = new System.Drawing.Point(12, 262);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(402, 244);
            this.groupBox3.TabIndex = 8;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Queue Example";
            // 
            // popQueue
            // 
            this.popQueue.Location = new System.Drawing.Point(229, 29);
            this.popQueue.Name = "popQueue";
            this.popQueue.Size = new System.Drawing.Size(75, 23);
            this.popQueue.TabIndex = 8;
            this.popQueue.Text = "Pop";
            this.popQueue.UseVisualStyleBackColor = true;
            this.popQueue.Click += new System.EventHandler(this.popQueue_Click);
            // 
            // clearQueue
            // 
            this.clearQueue.Location = new System.Drawing.Point(229, 181);
            this.clearQueue.Name = "clearQueue";
            this.clearQueue.Size = new System.Drawing.Size(100, 23);
            this.clearQueue.TabIndex = 7;
            this.clearQueue.Text = "Clear Queue";
            this.clearQueue.UseVisualStyleBackColor = true;
            this.clearQueue.Click += new System.EventHandler(this.clearQueue_Click);
            // 
            // queueSearchTime
            // 
            this.queueSearchTime.AutoSize = true;
            this.queueSearchTime.Location = new System.Drawing.Point(242, 160);
            this.queueSearchTime.Name = "queueSearchTime";
            this.queueSearchTime.Size = new System.Drawing.Size(0, 13);
            this.queueSearchTime.TabIndex = 6;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(229, 140);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(82, 13);
            this.label7.TabIndex = 5;
            this.label7.Text = "Search Results:";
            // 
            // queueSearchButton
            // 
            this.queueSearchButton.Location = new System.Drawing.Point(229, 107);
            this.queueSearchButton.Name = "queueSearchButton";
            this.queueSearchButton.Size = new System.Drawing.Size(100, 23);
            this.queueSearchButton.TabIndex = 4;
            this.queueSearchButton.Text = "Search";
            this.queueSearchButton.UseVisualStyleBackColor = true;
            this.queueSearchButton.Click += new System.EventHandler(this.queueSearchButton_Click);
            // 
            // queueSearchInput
            // 
            this.queueSearchInput.Location = new System.Drawing.Point(229, 80);
            this.queueSearchInput.Name = "queueSearchInput";
            this.queueSearchInput.Size = new System.Drawing.Size(100, 20);
            this.queueSearchInput.TabIndex = 3;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(226, 59);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(59, 13);
            this.label8.TabIndex = 2;
            this.label8.Text = "Search for:";
            // 
            // queueBox
            // 
            this.queueBox.FormattingEnabled = true;
            this.queueBox.Location = new System.Drawing.Point(23, 59);
            this.queueBox.Name = "queueBox";
            this.queueBox.Size = new System.Drawing.Size(175, 160);
            this.queueBox.TabIndex = 1;
            // 
            // addCallersToQueue
            // 
            this.addCallersToQueue.Location = new System.Drawing.Point(23, 29);
            this.addCallersToQueue.Name = "addCallersToQueue";
            this.addCallersToQueue.Size = new System.Drawing.Size(175, 23);
            this.addCallersToQueue.TabIndex = 0;
            this.addCallersToQueue.Text = "Add Callers to Queue";
            this.addCallersToQueue.UseVisualStyleBackColor = true;
            this.addCallersToQueue.Click += new System.EventHandler(this.addCallersToQueue_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.popStack);
            this.groupBox4.Controls.Add(this.clearStack);
            this.groupBox4.Controls.Add(this.stackSearchTime);
            this.groupBox4.Controls.Add(this.label10);
            this.groupBox4.Controls.Add(this.stackSearchButton);
            this.groupBox4.Controls.Add(this.stackSearchInput);
            this.groupBox4.Controls.Add(this.label11);
            this.groupBox4.Controls.Add(this.stackBox);
            this.groupBox4.Controls.Add(this.addCallersToStack);
            this.groupBox4.Location = new System.Drawing.Point(420, 262);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(402, 244);
            this.groupBox4.TabIndex = 9;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Stack Example";
            // 
            // popStack
            // 
            this.popStack.Location = new System.Drawing.Point(229, 29);
            this.popStack.Name = "popStack";
            this.popStack.Size = new System.Drawing.Size(75, 23);
            this.popStack.TabIndex = 8;
            this.popStack.Text = "Pop";
            this.popStack.UseVisualStyleBackColor = true;
            this.popStack.Click += new System.EventHandler(this.popStack_Click);
            // 
            // clearStack
            // 
            this.clearStack.Location = new System.Drawing.Point(229, 181);
            this.clearStack.Name = "clearStack";
            this.clearStack.Size = new System.Drawing.Size(100, 23);
            this.clearStack.TabIndex = 7;
            this.clearStack.Text = "Clear Stack";
            this.clearStack.UseVisualStyleBackColor = true;
            this.clearStack.Click += new System.EventHandler(this.clearStack_Click);
            // 
            // stackSearchTime
            // 
            this.stackSearchTime.AutoSize = true;
            this.stackSearchTime.Location = new System.Drawing.Point(242, 160);
            this.stackSearchTime.Name = "stackSearchTime";
            this.stackSearchTime.Size = new System.Drawing.Size(0, 13);
            this.stackSearchTime.TabIndex = 6;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(229, 140);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(82, 13);
            this.label10.TabIndex = 5;
            this.label10.Text = "Search Results:";
            // 
            // stackSearchButton
            // 
            this.stackSearchButton.Location = new System.Drawing.Point(229, 107);
            this.stackSearchButton.Name = "stackSearchButton";
            this.stackSearchButton.Size = new System.Drawing.Size(100, 23);
            this.stackSearchButton.TabIndex = 4;
            this.stackSearchButton.Text = "Search";
            this.stackSearchButton.UseVisualStyleBackColor = true;
            this.stackSearchButton.Click += new System.EventHandler(this.stackSearchButton_Click);
            // 
            // stackSearchInput
            // 
            this.stackSearchInput.Location = new System.Drawing.Point(229, 80);
            this.stackSearchInput.Name = "stackSearchInput";
            this.stackSearchInput.Size = new System.Drawing.Size(100, 20);
            this.stackSearchInput.TabIndex = 3;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(226, 59);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(59, 13);
            this.label11.TabIndex = 2;
            this.label11.Text = "Search for:";
            // 
            // stackBox
            // 
            this.stackBox.FormattingEnabled = true;
            this.stackBox.Location = new System.Drawing.Point(23, 59);
            this.stackBox.Name = "stackBox";
            this.stackBox.Size = new System.Drawing.Size(175, 160);
            this.stackBox.TabIndex = 1;
            // 
            // addCallersToStack
            // 
            this.addCallersToStack.Location = new System.Drawing.Point(23, 29);
            this.addCallersToStack.Name = "addCallersToStack";
            this.addCallersToStack.Size = new System.Drawing.Size(175, 23);
            this.addCallersToStack.TabIndex = 0;
            this.addCallersToStack.Text = "Add Callers to Stack";
            this.addCallersToStack.UseVisualStyleBackColor = true;
            this.addCallersToStack.Click += new System.EventHandler(this.addCallersToStack_Click);
            // 
            // closeWindow
            // 
            this.closeWindow.Location = new System.Drawing.Point(844, 208);
            this.closeWindow.Name = "closeWindow";
            this.closeWindow.Size = new System.Drawing.Size(75, 23);
            this.closeWindow.TabIndex = 10;
            this.closeWindow.Text = "Close";
            this.closeWindow.UseVisualStyleBackColor = true;
            this.closeWindow.Click += new System.EventHandler(this.closeWindow_Click);
            // 
            // clearAll
            // 
            this.clearAll.Location = new System.Drawing.Point(844, 291);
            this.clearAll.Name = "clearAll";
            this.clearAll.Size = new System.Drawing.Size(75, 23);
            this.clearAll.TabIndex = 11;
            this.clearAll.Text = "Clear All";
            this.clearAll.UseVisualStyleBackColor = true;
            this.clearAll.Click += new System.EventHandler(this.clearAll_Click);
            // 
            // Form1
            // 
            this.AcceptButton = this.addCaller;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(958, 575);
            this.Controls.Add(this.clearAll);
            this.Controls.Add(this.closeWindow);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Data Structures";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label callerNameLabel;
        private System.Windows.Forms.TextBox callerName;
        private System.Windows.Forms.Button addDefaultsToQueueAndStack;
        private System.Windows.Forms.ListBox callersWaiting;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button clearCallers;
        private System.Windows.Forms.Button addCaller;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button createDefaultDictionary;
        private System.Windows.Forms.Button clearDictionary;
        private System.Windows.Forms.Label dictionarySearchTime;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button dictionarySearchButton;
        private System.Windows.Forms.TextBox dictionarySearchInput;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ListBox dictionaryBox;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button popQueue;
        private System.Windows.Forms.Button clearQueue;
        private System.Windows.Forms.Label queueSearchTime;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button queueSearchButton;
        private System.Windows.Forms.TextBox queueSearchInput;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ListBox queueBox;
        private System.Windows.Forms.Button addCallersToQueue;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button popStack;
        private System.Windows.Forms.Button clearStack;
        private System.Windows.Forms.Label stackSearchTime;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Button stackSearchButton;
        private System.Windows.Forms.TextBox stackSearchInput;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.ListBox stackBox;
        private System.Windows.Forms.Button addCallersToStack;
        private System.Windows.Forms.Button closeWindow;
        private System.Windows.Forms.Button clearAll;

    }
}

