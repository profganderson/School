/*
 * 
 * Author      : Andy Mockler
 * Date        : 14 September 2015
 * Description : Program for IS403 Console Application
 *               Asks user for number of teams they wish to enter. Prompts user
 *               to enter team names & number of points. Sorts teams by points
 *               and prints them out in descending order.
 * 
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSConsoleAssignment
{

    class Program
    {
        //
        // UPPERCASE FIRST
        // Capitalizes the first character of a string
        //
        // params
        //      s - the string to be capitalized
        //
        // return
        //      string - a string with the first character capitalized
        //
        static string UppercaseFirst(string s)
        {
            // Check for empty string
            if (string.IsNullOrEmpty(s))
                return string.Empty;
            else
                return char.ToUpper(s[0]) + s.Substring(1);
        }

        static int getValidInt(string message)
        {
            string input;
            int validInt = 0;
            bool validInput = false;
            while (!validInput)
            {
                // Check for valid integer input and loop until input is valid
                Console.Write(message);
                input = Console.ReadLine();
                try
                {
                    validInt = Convert.ToInt32(input);
                    validInput = true;
                }
                catch { }
            }

            return validInt;
        }

        static void Main(string[] args)
        {
            var teams = new List<SoccerTeam>();
            string input; // To use for reading lines in. The variable should be immediately transferred away from input to avoid being overridden.
            
            // Get the number of soccer teams
            int numTeams = getValidInt("How many teams? ");

            // Get each team's information
            for (int i = 0; i < numTeams; i++)
            {
                string name;
                int points;

                // Get the team's name
                Console.Write("\n\nEnter Team " + (i + 1) + "'s name: ");
                input = Console.ReadLine();
                name = UppercaseFirst(input);

                // Get the team's points
                points = getValidInt("\nEnter " + name + "'s points: ");

                // Add the team to the teams list
                var team = new SoccerTeam(name, points);
                teams.Add(team);
            }

            // Sort the teams by points
            teams = teams.OrderByDescending(t => t.points).ToList();

            Console.WriteLine("\n\nHere is the sorted list:\n");

            // Print Column Headings
            Console.Write("\nPosition".PadRight(25, ' ') + "Name".PadRight(25, ' ') + "Points".PadRight(25, ' '));
            Console.Write("\n--------".PadRight(25, ' ') + "----".PadRight(25, ' ') + "------".PadRight(25, ' '));

            int position = 1;
            foreach ( var t in teams ) {
                t.print(position);
                position++;
            }

            Console.ReadLine();
        }
    }
}
