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

    RadioGroup radioGroup;
    RadioButton radioButton;
    TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_numerical_method);

        radioGroup = findViewById(R.id.radio_group);
        textView = findViewById(R.id.text_view_selected);

        MaterialButton buttonConfirm = findViewById(R.id.confirm);
        buttonConfirm.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int radioId = radioGroup.getCheckedRadioButtonId();
                radioButton = findViewById(radioId);

                String numericalMethod = radioButton.getText().toString();
                Intent intent = new Intent(getApplicationContext(), CalculatorActivity.class);

                intent.putExtra("numerical_method", numericalMethod);

                startActivity(intent);

                //textView.setText("Your choice: " + radioButton.getText());
            }
        });
    }
}