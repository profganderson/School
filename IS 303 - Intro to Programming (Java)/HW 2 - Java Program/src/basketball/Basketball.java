/*
 * Author      : Andy Mockler
 * Description : IS303 Homework 2 - Basketball
 * Date        : 23 January 2015
 */
package basketball;

import java.util.*;

public class Basketball {

    public static void main(String[] args) {
        // Create Random Object
        Random rndGenerator = new Random();
 
        // BYU and Gonzaga Scores
        int iBYU = rndGenerator.nextInt( 100 );
        int iGonzaga= rndGenerator.nextInt( 100 );
        
        // Check scores for tie or winner; prints scores and winner.
        if ( iBYU == iGonzaga ) {
            System.out.println("BYU " + iBYU + "\nGonzaga " + iGonzaga + "\n\nIt was a tie");
        } else if ( iBYU > iGonzaga ) {
            System.out.println("BYU " + iBYU + "\nGonzaga " + iGonzaga + "\n\nBYU wins");
        } else {
            System.out.println("BYU " + iBYU + "\nGonzaga " + iGonzaga + "\n\nGonzaga wins");
        }
    }
    
}
