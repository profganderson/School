using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSConsoleAssignment
{
    class SoccerTeam : Team
    {
        public int draw;
        public int goalsFor;
        public int goalsAgainst;
        public int differential;
        public int points;

        public SoccerTeam (string name, int points)
        {
            this.name = name;
            this.points = points;
        }

        //
        // PRINT
        // Prints the team's info in the format Position | Name | Points
        //
        // params
        //      int position - the team's relative rank
        //
        // return
        //      void; prints the result directly to the console
        //
        public void print (int position)
        {
            // Padding of 25 to match main class.
            Console.Write("\n" + Convert.ToString(position).PadRight(24, ' ') + 
                name.PadRight(25, ' ') + Convert.ToString(points).PadRight(25, ' '));
        }
    }
}
