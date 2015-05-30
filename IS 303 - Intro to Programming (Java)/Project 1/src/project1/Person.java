/*
 * Name: Andy Mockler
 * Date: 28 Febraury 2015
 * Description: IS303 Project 1; Person class as superclass for Student.
 */
package project1;

public class Person {
    protected String firstName;
    protected String lastName;
    
    // Empty constructor if no params are passed
    Person() {}
    
    // Constructor with first name and last name
    Person( String firstName, String lastName )
    {
        this.firstName = firstName;
        this.lastName = lastName;
    }
    
    // Mutator (setter) for first name
    void setFirstName(String firstName)
    {
        this.firstName = firstName;
    }
    
    // Mutator (setter) for last name
    void setLastName(String lastName)
    {
        this.lastName = lastName;
    }
    
    // Accessor (getter) for name as "Lastname, Firstname"
    String getName()
    {
        return lastName + ", " + firstName;
    }
}
