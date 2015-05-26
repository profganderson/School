/*
 * Author: Andy Mockler
 * Date: April 13, 2015
 * Description: Basketball Team Class. Inherits from Team. Adds a status to
                indicate post-season team fate and a method to determine
                that status.
 */

/**
 *
 * @author Andy
 */
public class BasketballTeam extends Team {
    private String status;
    
    public BasketballTeam(String name) {
        super(name);
    }
    
    public String getStatus() {
        // Determine the current status
        if (this.getWins() >= 20)
            this.status = "March Madness";
        else if (this.getWins() >= 15)
            this.status = "NIT";
        else
            this.status = "See you next year";

        return status;
    }
    
    public void setStatus(String status) {
        this.status = status;
    }
}
