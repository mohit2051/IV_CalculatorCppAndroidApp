package com.example.impliedvolatilitycalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Color;
import android.graphics.PorterDuff;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.example.impliedvolatilitycalculator.databinding.ActivityMainBinding;
import com.google.android.material.button.MaterialButton;

public class LoginPageActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login_page);

        //defining variables and identifying them by their ids
        EditText username = (EditText) findViewById(R.id.username);
        EditText password = (EditText) findViewById(R.id.password);

        MaterialButton loginbtn = (MaterialButton) findViewById(R.id.loginbtn);

        //admin pwd check
        loginbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //check if password is correct
                if(username.getText().toString().equals("admin123") && password.getText().toString().equals("admin123")){

                    //creating an intent to move to the next page if login is successful
                    Intent intent = new Intent(LoginPageActivity.this, NumericalMethodActivity.class);
                    startActivity(intent);
                }
                //else password is incorrect
                else {

                    //setting a toast message for Login failed in red color
                    Toast toast = Toast.makeText(LoginPageActivity.this, "LOGIN FAILED !!!", Toast.LENGTH_LONG);
                    TextView textView = toast.getView().findViewById(android.R.id.message);
                    textView.setTextColor(Color.WHITE);
                    textView.setTextSize(25);
                    toast.getView().getBackground().clearColorFilter();
                    toast.getView().getBackground().setColorFilter(Color.RED, PorterDuff.Mode.DARKEN);
                    toast.show();
                }
            }
        });
    }
}