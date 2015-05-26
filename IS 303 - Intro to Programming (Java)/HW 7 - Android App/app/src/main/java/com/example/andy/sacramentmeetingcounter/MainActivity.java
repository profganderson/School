/*

    Name: Andy Mockler
    Date: April 8, 2015
    Description: Sacrament Meeting Counter Android App. Increments/Decrements a counter for 1, 5, and 10
                 to aid in counting things (namely people in Sacrament meeting). Can also send an
                 email containing the final count.

 */

package com.example.andy.sacramentmeetingcounter;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;
import android.widget.EditText;
import android.content.Intent;
import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

import org.w3c.dom.Text;


public class MainActivity extends ActionBarActivity {

    // changeCount
    // Method to change the counter textbox by the amount passed.
    public void changeCount(int amount) {
        // Get the counter text box & its value
        TextView txtCount = (TextView)findViewById(R.id.txtCount);
        String sCount = (String)txtCount.getText();
        int count = Integer.parseInt(sCount);

        // Add the given amount to the counter
        count+=amount;

        // Update the text box. Set to 0 if less than 0.
        if (count > 0)
            txtCount.setText( String.valueOf(count) );
        else
            txtCount.setText("0");
    }

    //********************************************************************************

    //
    // Methods for buttons +1, +5, +10, -1, -5, -10
    //

    public void addOne(View view) {
        changeCount(1);
    }

    public void addFive(View view) {
        changeCount(5);
    }

    public void addTen(View view) {
        changeCount(10);
    }

    public void minusOne(View view) {
        changeCount(-1);
    }

    public void minusFive(View view) {
        changeCount(-5);
    }

    public void minusTen(View view) {
        changeCount(-10);
    }

    //
    // Method for the Reset Button
    //
    public void reset(View view) {
        // Reset the Counter
        TextView txtCount = (TextView)findViewById(R.id.txtCount);
        txtCount.setText("0");

        // Clear out the email box
        EditText inputEmail = (EditText)findViewById(R.id.inputEmail);
        inputEmail.setText("");
    }

    //********************************************************************************

    // Email Stuff
    public void sendEmail(View view) {

        // Find the email address and the count
        EditText inputEmail = (EditText)findViewById(R.id.inputEmail);
        TextView txtCount = (TextView)findViewById(R.id.txtCount);

        // Get today's date and format it
        DateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy");
        Date today = new Date();
        String date = dateFormat.format(today);

        // Email Content
        String to = String.valueOf(inputEmail.getText());
        String message = String.valueOf(txtCount.getText()) + " people in attendance today!";
        String subject = "Meeting Count - " + date;

        Intent i = new Intent(Intent.ACTION_SEND);
        i.putExtra(Intent.EXTRA_EMAIL,new String[]{to});
        i.putExtra(Intent.EXTRA_SUBJECT,subject);
        i.putExtra(Intent.EXTRA_TEXT,message);
        i.setType("meassge/rfc822");
        startActivity(Intent.createChooser(i,"choose:"));
    }

    //********************************************************************************


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
