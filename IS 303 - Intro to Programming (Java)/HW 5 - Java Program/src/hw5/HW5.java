/*
 * Author: Andy Mockler
 * Date: February 21, 2015
 * Description: IS303 Homework 5; Basketball games using classes and methods.
 */
package hw5;

import java.util.*;

class myTeam
{
    String teamName;
    int wins;
    int losses;
    int totalPointsFor = 0;
    int totalPointsAgainst = 0;
    double winLossPct;
    
    // get teamName
    String getTeam()
    {
        return teamName;
    }
    // set teamName
    void setTeam (String name)
    {
        teamName = name;
    }
    
    void setWinsLosses(int wins, int losses)
    {
        // Set wins and losses
        this.wins = wins;
        this.losses = losses;
        
        // Calculate winLossPct
        winLossPct = wins / (wins+losses);
    }
    
    // get wins
    int getWins()
    {
       return wins; 
    }
    
    // get losses
    int getLosses()
    {
        return losses;
    }
    
    void addPointsFor(int pointsFor)
    {
        totalPointsFor += pointsFor;
    }
    void addPointsAgainst(int pointsAgainst)
    {
        totalPointsAgainst += pointsAgainst;
    }
    
    void getAllPoints()
    {
        System.out.println("Points for " + totalPointsFor + " and Points Against " + totalPointsAgainst);
    }
}

public class HW5 {

    public static void main(String[] args) {
        // Make some Scanners
        Scanner sScan = new Scanner(System.in);
        Scanner iScan = new Scanner(System.in);
        
        // Create an array of type myTeam
        myTeam teams[] = new myTeam[3];
        
        // Fill in array
        for (int i = 0; i < teams.length; i++)
        {
            // Create the team object
            teams[i] = new myTeam();
            
            // Set the team name
            System.out.print("\nPlease enter your team's name: ");
            String name = sScan.nextLine();
            teams[i].setTeam(name);
            
            // Set the wins and losses
            System.out.print("Please enter the number of wins: ");
            int wins = iScan.nextInt();
            System.out.print("Please enter the number of losses: ");
            int losses = iScan.nextInt();
            teams[i].setWinsLosses(wins, losses); // Method also calculates win/loss percentage
            
            // Set number of points for
            System.out.print("Please enter the number of points for: ");
            int pointsFor = iScan.nextInt();
            teams[i].addPointsFor(pointsFor);
            
            // Set number of points against
            System.out.print("Please enter the number of points against: ");
            int pointsAgainst = iScan.nextInt();
            teams[i].addPointsAgainst(pointsAgainst); 
        }
        
        // Prompt user for a team name
        System.out.print("\nPlease enter the name of the team you would like to look up: ");
        String name = sScan.nextLine();
        boolean teamFound = false; // set up boolean value to flag when team is found
        int i = 0; // to iterate in the while loop
        while (teamFound == false)
        {
            // Check if we're on the right element of the array; if so, print out data
            if (teams[i].teamName.equalsIgnoreCase(name))
            {
                // Output the team's information
                System.out.println(teams[i].getTeam());
                System.out.println("W " + teams[i].getWins() + " - L " + teams[i].getLosses());
                teams[i].getAllPoints();

                teamFound = true; // Stops the loop
            } else {
                i++; // Increment to check next array element 
            }
        }
    }
    
}