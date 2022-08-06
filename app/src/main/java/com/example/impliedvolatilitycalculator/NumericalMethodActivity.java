package com.example.impliedvolatilitycalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

import com.google.android.material.button.MaterialButton;

public class NumericalMethodActivity extends AppCompatActivity {

    //defining the variables
    RadioGroup radioGroup;
    RadioButton radioButton;
    TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_numerical_method);

        //identifying variables by id set in the front end
        radioGroup = findViewById(R.id.radio_group);
        //textView = findViewById(R.id.text_view_selected);

        MaterialButton buttonConfirm = findViewById(R.id.confirm);
        //action performed when the button is clicked
        buttonConfirm.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int radioId = radioGroup.getCheckedRadioButtonId();
                radioButton = findViewById(radioId);

                //setting value which is to be sent to the next activity
                String numericalMethod = radioButton.getText().toString();
                //creating intent from this class to calculatorActivity class
                Intent intent = new Intent(getApplicationContext(), CalculatorActivity.class);

                //setting key value pair for the next activity to be able to read values
                intent.putExtra("numerical_method", numericalMethod);

                //start the intent
                startActivity(intent);

            }
        });
    }
}