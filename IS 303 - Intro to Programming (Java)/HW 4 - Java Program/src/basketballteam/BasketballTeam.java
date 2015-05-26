/*
 * Author: Andy Mockler
 * Description: Basketball Team; Simulates a basketball season.
 * Date: Feb 13, 2015
 */
package basketballteam;

import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.Random;

class Team {
    // Instance variables
    String teamName;
    int wins;
    int losses;
    int totalPointsFor;
    int totalPointsAgainst;
    double winLossPct;
    
    // Constructor initializes variables
    void Team() {
        wins = 0;
        losses = 0;
        totalPointsFor = 0;
        totalPointsAgainst = 0;
        winLossPct = 0;
    }
    
    void updateInfo(int teamScore, int opponentScore, int gamesPlayed) {
        totalPointsFor += teamScore;
        totalPointsAgainst += opponentScore;
        winLossPct = (double)wins / (double)gamesPlayed;
    }
}

public class BasketballTeam {

    public static void main(String[] args) {
        // Make some objects
        Scanner scanner = new Scanner(System.in);
        Random random = new Random(); // random.nextInt(101)
        DecimalFormat decimalFormat = new DecimalFormat("#.000"); // decimalFormat.format(<#decimal>)
        
        // Initialize Games Played counter; create team object
        int gamesPlayed = 0;
        Team team = new Team();
        
        // Ask if they want to play
        System.out.println("Do you want to play the game? (Y/N)");
        String wantToPlay = scanner.nextLine();
        
        // Make sure they enter Y, y, N or n
        while (!(wantToPlay.equalsIgnoreCase("Y") || wantToPlay.equalsIgnoreCase("N"))) {
            System.out.println("Please enter Y or N: ");
            wantToPlay = scanner.nextLine();
        }
        
        // If they start playing, make a team
        if (wantToPlay.equalsIgnoreCase("Y")) {
            System.out.println("What is your team's name?");
            team.teamName = scanner.nextLine();
        }
        
        // Start looping as long as they answer Y
        while (wantToPlay.equalsIgnoreCase("Y")) {
            
            // Get opponent name
            System.out.println("What is your opponent's name?");
            String opponent = scanner.nextLine();
            
            // Generate random scores up to 100
            int opponentScore = random.nextInt(101);
            int teamScore = random.nextInt(101);
            
            // Add 5 points to whichever team is the home team
            if (gamesPlayed % 2 == 0) {
                teamScore += 5;
            } else {
                opponentScore += 5;
            }
            
            // Handle overtime
            int otPlayed = 0;
            while ( teamScore == opponentScore ) {
                teamScore += random.nextInt(16);
                opponentScore += random.nextInt(16);
                otPlayed++;
            }
            
            gamesPlayed++;
            
            // Output & update team object
            System.out.println("\n" + team.teamName + " " + teamScore);
            System.out.println(opponent + " " + opponentScore);
            if (otPlayed > 0) System.out.println("OT " + otPlayed);
            if ( teamScore > opponentScore ) {
                System.out.println(team.teamName + " Wins\n");
                team.wins++;
            }
            else {
                System.out.println(opponent + " Wins\n");
                team.losses++;
            }
            team.updateInfo(teamScore, opponentScore, gamesPlayed);
            
            // Ask if they want to keep playing
            System.out.println("Do you want to keep playing (Y/N)?");
            wantToPlay = scanner.nextLine();
            while ( !(wantToPlay.equalsIgnoreCase("Y") || wantToPlay.equalsIgnoreCase("N")) ) {
                System.out.println("Please enter Y or N: ");
                wantToPlay = scanner.nextLine();
            }
        }
        
        if (gamesPlayed > 0) {
            System.out.println();
            System.out.println("Team Name \t W  \t L  \t Pct  \tPoints For \tPoints Against");
            System.out.println("_________ \t___ \t___ \t_____ \t__________ \t______________");
            System.out.println(team.teamName + " \t\t " + team.wins + " \t " + team.losses + " \t" + decimalFormat.format(team.winLossPct) + " \t    " + team.totalPointsFor + " \t\t" + team.totalPointsAgainst);
        }
        
        System.out.println("\nThanks for playing!");
        
    }
    
}
