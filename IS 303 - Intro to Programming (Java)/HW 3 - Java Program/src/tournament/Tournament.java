/*
 * Author: Andy Mockler
 * Description: Program to generate random basketball tournament results.
 * Date: Feb 2, 2015
 */
package tournament;

import java.util.*;

public class Tournament {

    public static void main(String[] args) {
        // Create Scanner and Random Objects
        Scanner oScan = new Scanner(System.in); 
        Random random = new Random();
        
        // Declare some variables
        int homeWins = 0;
        int homeLoss = 0;
        
        // Get home team name
        System.out.println("Who is the home team? ");
        String homeName = oScan.nextLine();
        
        // Get number of games in season
        System.out.println("How many games are in the season? ");
        int numberOfGames = oScan.nextInt();
        
        // Flush the buffer
        oScan.nextLine(); 
        
        // Loops through games based on user input
        int i; // Create counter
        for(i = 0; i < numberOfGames; i++)
        {
            // Get opponent's name
            System.out.println("Who is the opponent? ");
            String awayName = oScan.nextLine();
            
            // Generate scores
            int homeScore = random.nextInt(100);
            int awayScore = random.nextInt(100);
            
            // Break ties
            while(homeScore == awayScore)
            {
                homeScore = random.nextInt(100);
                awayScore = random.nextInt(100);
            }
            
            String result;
            // Update home record
            if ( homeScore > awayScore ) 
            {
                homeWins++;
                result = "Win";
            }
            else
            {
                homeLoss++;
                result = "Lose";
            }
            
            // Output Game Results
            System.out.println("\n" + homeName + "\t" + homeScore );
            System.out.println(awayName + "\t" + awayScore );
            System.out.println(result + "\n");
        } // End For loop
        
        // Output home team record
        System.out.println(homeName + " " + homeWins + "-" + homeLoss);
        
        double winPercent = (double)homeWins / (double)numberOfGames;
        // Determine March Madness, NIT, See you...
        if ( winPercent >= .75 ) 
        {
            System.out.println("March Madness");
        }
        else if ( winPercent >= .5 && winPercent < .75 )
        {
            System.out.println("NIT Tournament");
        }
        else 
        {
            System.out.println("See you next year");
        }
    }   
}