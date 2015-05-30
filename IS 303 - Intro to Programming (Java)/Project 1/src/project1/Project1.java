/*
 * Name: Andy Mockler
 * Date: 28 February 2015
 * Description: IS303 Project 1
 */
package project1;

import java.util.*;

public class Project1 {
    
    public static void main(String[] args) {
        // Create scanners for double, int, string
        Scanner dScan = new Scanner(System.in);
        Scanner iScan = new Scanner(System.in);
        Scanner sScan = new Scanner(System.in);
        
        // Create an empty array here to make this available to all choices.
        // Initialize with new Student[0] so that I can use .length to check if 
        // a class list exists yet before searching.
        Student students[] = null;
        
        // Declare user choice variable outside scope of loop for use in while condition.
        int userChoice;
        
        do
        {
            // Output menu
            System.out.println("\nPlease Choose an Option: ");
            System.out.println("1. New Class List");
            System.out.println("2. Search for a Student");
            System.out.println("3. Exit");
            // Get user choice
            userChoice = iScan.nextInt();
            
            // Control program flow based on choice
            // If 1, make a class list
            if (userChoice == 1)
            {
                // Get the size of the array and create it
                System.out.print("\nHow many students would you like to enter? ");
                int numStudents = iScan.nextInt();
                students = new Student[numStudents];
                
                // Create x student objects for number the user wants to enter
                for (int i = 0; i < numStudents; i++)
                {
                    System.out.println("\nEnter Student " + (i+1));
                    
                    // Get first name
                    System.out.print("First Name: ");
                    String firstName = sScan.nextLine();
                    
                    // Get last name
                    System.out.print("Last Name: ");
                    String lastName = sScan.nextLine();
                    
                    // Get homework average
                    System.out.print("Homework Average: ");
                    double homeworkAvg = dScan.nextDouble();
                    
                    // Get quiz average
                    System.out.print("Quiz Average: ");
                    double quizAvg = iScan.nextDouble();
                    
                    // Get project average
                    System.out.print("Project Average: ");
                    double projectAvg = iScan.nextDouble();
                    
                    // Get test average
                    System.out.print("Test Average: ");
                    double testAvg = iScan.nextDouble();
                    
                    // Create the student object
                    students[i] = new Student(firstName, lastName, homeworkAvg, quizAvg, projectAvg, testAvg);
                }
            }
            else if (userChoice == 2)
            {
                if ( students == null ) {
                    System.out.println("\nPlease enter a class list before searching for students.\n");
                } else {
                    System.out.println("\nOk. Let's search for a student.");
                    
                    // Get last name to search for
                    System.out.print("Last Name: ");
                    String lastName = sScan.nextLine();
                    
                    // Get first name to search for
                    System.out.print("First Name: ");
                    String firstName = sScan.nextLine();

                    // Create a person object out of the first name and last name.
                    // This will let me call .getName() on the person object in
                    // comparing it to students while searching.
                    Person student = new Person(firstName, lastName);

                    // Loop through all the students in the class list until
                    // you find the user being searched for
                    boolean studentFound = false;
                    int i = 0;
                    while (studentFound == false)
                    {
                        if(students[i].getName().equalsIgnoreCase(student.getName()))
                        {
                            System.out.println("\n" + students[i].getName());
                            students[i].displayGrade();
                            studentFound = true;
                        } else {
                            // Exit the loop if you run out of students in the list.
                            if ( i == students.length - 1 ) {
                                System.out.println("\nUnfortunately, we couldn't find that student.\n");
                                studentFound = true;
                            } else {
                                i++;
                            }
                        }
                    }
                }
            }
        } while (userChoice != 3); // Loop until user decides to exit
        System.out.println("\nThank you!");
    }   
}



// TODO
// Check if they enter 0 or other invalid number for number of students.
// Make sure the average prints out pretty