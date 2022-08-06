package com.example.impliedvolatilitycalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

import com.example.impliedvolatilitycalculator.databinding.ActivityMainBinding;
import com.google.android.material.button.MaterialButton;

import org.w3c.dom.Text;

public class CalculatorActivity extends AppCompatActivity {

    RadioGroup radioGroup;
    RadioButton radioButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calculator);

        //identifying variables by id set in the front end
        radioGroup = findViewById(R.id.radio_group);

        //defining variable and identifying by their ids set in xml file
        EditText strikePrice = (EditText) findViewById(R.id.strikePrice);
        EditText spotPrice = (EditText) findViewById(R.id.spotPrice);
        EditText riskFreeRate = (EditText) findViewById(R.id.riskFreeRate);
        EditText timeToMaturity = (EditText) findViewById(R.id.timeToMaturity);
        EditText optionPrice = (EditText) findViewById(R.id.optionPrice);

        MaterialButton calculateBtn = (MaterialButton) findViewById(R.id.calculateBtn);
        //fetching the intent of the current class
        Intent intent = getIntent();

        //reading the key value passed from the previous class
        String numericalMethod = intent.getStringExtra("numerical_method");

        calculateBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                int radioId = radioGroup.getCheckedRadioButtonId();
                radioButton = findViewById(radioId);

                String optionType = radioButton.getText().toString();

                //setting the values in the variables read from the edit text in xml
                double K = Double.parseDouble(strikePrice.getText().toString());
                double S = Double.parseDouble(spotPrice.getText().toString());
                double r = Double.parseDouble(riskFreeRate.getText().toString());
                double T = Double.parseDouble(timeToMaturity.getText().toString());
                double V = Double.parseDouble(optionPrice.getText().toString());

                //creating a bundle to pass multiple values from this class to main class
                Bundle bundle  = new Bundle();

                //adding all the values as key value pair to be passed to mainactivity class
                bundle.putString("numerical_method",String.valueOf(numericalMethod));
                bundle.putString("K",String.valueOf(K));
                bundle.putString("S",String.valueOf(S));
                bundle.putString("r",String.valueOf(r));
                bundle.putString("T",String.valueOf(T));
                bundle.putString("V",String.valueOf(V));
                bundle.putString("option_type", String.valueOf(optionType));

                //creating intent object and sending values to next class
                Intent intent = new Intent(CalculatorActivity.this, MainActivity.class);
                intent.putExtras(bundle);
                startActivity(intent);




            }
        });

    }
}