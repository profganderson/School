/*
 * Author: Andy Mockler
 * Date: April 13, 2015
 * Description: Team class. Stores team name, wins, losses, and winlosspct.
 */

/**
 *
 * @author Andy
 */
public class Team {
    protected String name;
    protected int wins;
    protected int losses;
    protected double winLossPct;

    public Team(String name) {
        this.name = name;
        this.wins = 0;
        this.losses = 0;
    }
    
    public String getName() {
        return name;
    }

    public int getWins() {
        return wins;
    }

    public int getLosses() {
        return losses;
    }

    public double getWinLossPct() {
        return winLossPct;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setWins(int wins) {
        this.wins = wins;
    }

    public void setLosses(int losses) {
        this.losses = losses;
    }

    public void setWinLossPct(double winLossPct) {
        this.winLossPct = winLossPct;
    }
    
    
    
}
