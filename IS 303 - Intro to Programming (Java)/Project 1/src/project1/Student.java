/*
 * Name: Andy Mockler
 * Date: 28 February 2015
 * Description: IS303 Project 1; Student Class.
 */
package project1;

import java.text.DecimalFormat;

// Student class

class Student extends Person
{
    // Instance variables
    private double homeworkAvg;
    private double quizAvg;
    private double projectAvg;
    private double testAvg;
    private double finalGrade;
    private String letterGrade;
    
    // Constructor if no params are passed
    Student() { calcGrade(); }
    
    // Constructor if params are passed
    Student(String firstName, String lastName, double homeworkAvg, double quizAvg, double projectAvg, double testAvg)
    {
        super(firstName, lastName); // Person constructor
        this.homeworkAvg = homeworkAvg;
        this.quizAvg = quizAvg;
        this.projectAvg = projectAvg;
        this.testAvg = testAvg;
        calcGrade(); // Calculates and sets average and letter grade
    }
    
    private void calcGrade()
    {
        // Calculate grade
        double grade = (this.homeworkAvg * 0.15) + (this.quizAvg * 0.05) + (this.projectAvg * 0.4) + (this.testAvg * .4);
        
        // If..else to figure out letter grade
        String letter;
        if (grade >= 90)
        {
            letter = "A";
        }
        else if (grade < 90 && grade >= 80)
        {
            letter = "B";
        }
        else if (grade < 80 && grade >= 70)
        {
            letter = "C";
        }
        else if (grade < 70 && grade >= 60)
        {
            letter = "D";
        }
        else
        {
            letter = "F";
        }
        
        // Set dinal grade and letter grade
        this.finalGrade = grade;
        this.letterGrade = letter;
    }
    
    // Mutator (setter) for homework average
    void setHomeworkAvg(double homeworkAvg)
    {
        this.homeworkAvg = homeworkAvg;
    }
    
    // Mutator (setter) for quiz average
    void setQuizAvg(double quizAvg)
    {
        this.quizAvg = quizAvg;
    }
    
    // Mutator (setter) for project average
    void setProjectAvg(double projectAvg)
    {
        this.projectAvg = projectAvg;
    }
    
    // Mutator (setter) for test average
    void setTestAvg(double testAvg)
    {
        this.testAvg = testAvg;
    }
    
    // Prints out the final grade percent and the final letter grade
    void displayGrade()
    {
        // Formatting Decimals later on
        DecimalFormat decimalFormat = new DecimalFormat("#.00"); // decimalFormat.format(@decimal)
        System.out.println("Final Grade Percent: " + decimalFormat.format(finalGrade) );
        System.out.println("Final Letter Grade: " + letterGrade );
    }
}