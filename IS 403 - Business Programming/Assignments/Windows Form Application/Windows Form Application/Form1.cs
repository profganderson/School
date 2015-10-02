using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace Windows_Form_Application
{
    public partial class Form1 : Form
    {
        private Dictionary<string, int> dictionary;
        private Stack<string> stack;
        private Queue<string> queue;
        private int numDefaultItems = 2000;
        
        public Form1()
        {
            dictionary = new Dictionary<string, int>();
            stack = new Stack<string>();
            queue = new Queue<string>();

            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {
            // Not used
        }

        private void createDefaultDictionary_Click(object sender, EventArgs e)
        {
            // Load up the dictionary with some # default items
            // Insert them into the listbox
            for (int i = 0; i < numDefaultItems; i++)
            {
                string text = "NewFile" + (i + 1);
                dictionary.Add(text, i);
                dictionaryBox.Items.Add(text);
            }
        }

        private void label4_Click(object sender, EventArgs e)
        {
            // Not used
        }

        private void addCaller_Click(object sender, EventArgs e)
        {
            // Get the name from the input
            string name = callerName.Text;

            // Make sure you're not adding empty strings
            if (name != "")
            {
                // Add the name to the list box
                callersWaiting.Items.Add(name);

                // Reset the input
                callerName.Text = "";
                callerName.Focus();
            }
        }

        private void clearCallers_Click(object sender, EventArgs e)
        {
            // Clear out the callers listbox
            callersWaiting.Items.Clear();
            callerName.Focus();
        }

        private void addDefaultsToQueueAndStack_Click(object sender, EventArgs e)
        {
            // Load up the data structures with the values
            for (int i = 0; i < numDefaultItems; i++)
            {
                string item = "NewFile" + (i + 1);

                queue.Enqueue(item);
                stack.Push(item);
            }

            // Add the items to the listboxes using foreach loops
            foreach (string item in stack)
            {
                stackBox.Items.Add(item);
            }

            foreach (string item in queue)
            {
                queueBox.Items.Add(item);
            }
        }

        // Function that uses an enumerator to add items to listboxes
        // in their correct order
        private void addCallersToBox(ListBox box, Object container)
        {
            // Get the container time e.g. Stack, Queue
            Type containerType = container.GetType();
            
            // Add the items to the data structure
            foreach ( string caller in callersWaiting.Items )
            {
                if ( containerType == queue.GetType() )
                {
                    queue.Enqueue(caller);
                }
                else if ( containerType == stack.GetType() )
                {
                    stack.Push(caller);
                }
            }

            // Create an enumerator and walk through the data structure,
            // pulling out and adding values in their correct order
            IEnumerator<string> enumerator;
            if ( containerType == queue.GetType() )
            {
                enumerator = queue.GetEnumerator();
                while (enumerator.MoveNext())
                {
                    string name = enumerator.Current;
                    box.Items.Add(name);
                }
            }
            else if ( containerType == stack.GetType() )
            {
                enumerator = stack.GetEnumerator();
                while (enumerator.MoveNext())
                {
                    string name = enumerator.Current;
                    box.Items.Add(name);
                }
            }
        }

        private void addCallersToQueue_Click(object sender, EventArgs e)
        {
            // Call the add callers function
            addCallersToBox(queueBox, queue);
        }

        private void addCallersToStack_Click(object sender, EventArgs e)
        {
            // Call the add callers function
            addCallersToBox(stackBox, stack);
        }

        private void popQueue_Click(object sender, EventArgs e)
        {
            // Pops the top item off of the queue and removes
            // the first item from the listbox
            if (queueBox.Items.Count > 0)
            {
                queueBox.Items.RemoveAt(0);
                queue.Dequeue();
            }
            else
            {
                // Show a messagebox if the listbox is empty
                MessageBox.Show("Queue is Empty");
            }
        }

        private void popStack_Click(object sender, EventArgs e)
        {
            // Check if the listbox is empty
            if (stackBox.Items.Count > 0)
            {
                // Pop from the stack, remove first listbox item
                stackBox.Items.RemoveAt(0);
                stack.Pop();
            }
            else
            {
                // If empty, show a message
                MessageBox.Show("Stack is Empty");
            }
        }

        private void queueSearchButton_Click(object sender, EventArgs e)
        {
            // Start a stopwatch
            System.Diagnostics.Stopwatch stopwatch = new System.Diagnostics.Stopwatch();
            stopwatch.Start();

            // Get the search term from the input
            string searchTerm = queueSearchInput.Text;

            // Search for the term and then stop the stopwatch
            bool itemExists = queue.Contains(searchTerm);
            stopwatch.Stop();

            // If it exists, show the elapsed time, otherwise show 'not found'
            if (itemExists)
                queueSearchTime.Text = stopwatch.Elapsed.ToString();
            else
                queueSearchTime.Text = "Not Found";
        }

        private void stackSearchButton_Click(object sender, EventArgs e)
        {
            // Start the stopwatch
            System.Diagnostics.Stopwatch stopwatch = new System.Diagnostics.Stopwatch();
            stopwatch.Start();

            // Get the search term from the input
            string searchTerm = stackSearchInput.Text;

            // Search for the term and then stop the stopwatch
            bool itemExists = stack.Contains(searchTerm);
            stopwatch.Stop();

            // If it exists, show the elapsed time, otherwise show 'not found'
            if (itemExists)
                stackSearchTime.Text = stopwatch.Elapsed.ToString();
            else
                stackSearchTime.Text = "Not Found";
        }

        private void clearQueue_Click(object sender, EventArgs e)
        {
            // Clear data structure and list box
            queue.Clear();
            queueBox.Items.Clear();
        }

        private void clearStack_Click(object sender, EventArgs e)
        {
            // Clear data structure and list box
            stack.Clear();
            stackBox.Items.Clear();
        }

        private void closeWindow_Click(object sender, EventArgs e)
        {
            // Close the window
            this.Close();
        }

        private void dictionarySearchButton_Click(object sender, EventArgs e)
        {
            // Start the stopwatch
            System.Diagnostics.Stopwatch stopwatch = new System.Diagnostics.Stopwatch();
            stopwatch.Start();

            // Get the search term
            string searchTerm = dictionarySearchInput.Text;

            // Find the item and stop the watch
            bool itemExists = dictionary.ContainsKey(searchTerm);
            stopwatch.Stop();

            // If it was found, show the elapsed time, otherwise 'not found'
            if (itemExists)
                dictionarySearchTime.Text = stopwatch.Elapsed.ToString();
            else
                dictionarySearchTime.Text = "Not Found";
        }

        private void clearDictionary_Click(object sender, EventArgs e)
        {
            // Clear data structure and list box
            dictionary.Clear();
            dictionaryBox.Items.Clear();
        }

        private void clearAll_Click(object sender, EventArgs e)
        {
            // Clear data structures
            stack.Clear();
            queue.Clear();
            dictionary.Clear();

            // Clear out all listboxes
            stackBox.Items.Clear();
            queueBox.Items.Clear();
            dictionaryBox.Items.Clear();
            callersWaiting.Items.Clear();

            // Clear out inputs
            queueSearchInput.Text = "";
            stackSearchInput.Text = "";
            dictionarySearchInput.Text = "";
            callerName.Text = "";
        }
    }
}
