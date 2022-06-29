package com.example.impliedvolatilitycalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.example.impliedvolatilitycalculator.databinding.ActivityMainBinding;
import com.google.android.material.button.MaterialButton;

import org.w3c.dom.Text;

public class CalculatorActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calculator);

        EditText strikePrice = (EditText) findViewById(R.id.strikePrice);
        EditText spotPrice = (EditText) findViewById(R.id.spotPrice);
        EditText riskFreeRate = (EditText) findViewById(R.id.riskFreeRate);
        EditText timeToMaturity = (EditText) findViewById(R.id.timeToMaturity);
        EditText optionPrice = (EditText) findViewById(R.id.optionPrice);

        MaterialButton calculateBtn = (MaterialButton) findViewById(R.id.calculateBtn);

//        TextView message = (TextView) findViewById(R.id.message123);

        calculateBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
//                String str = strikePrice.getText().toString();
//                float f = Float.parseFloat(str);
//                double d = Double.parseDouble(str);
                double K = Double.parseDouble(strikePrice.getText().toString());
                double S = Double.parseDouble(spotPrice.getText().toString());
                double r = Double.parseDouble(riskFreeRate.getText().toString());
                double T = Double.parseDouble(timeToMaturity.getText().toString());
                double V = Double.parseDouble(optionPrice.getText().toString());

                Bundle bundle  = new Bundle();

                bundle.putString("K",String.valueOf(K));
                bundle.putString("S",String.valueOf(S));
                bundle.putString("r",String.valueOf(r));
                bundle.putString("T",String.valueOf(T));
                bundle.putString("V",String.valueOf(V));

                Intent intent = new Intent(CalculatorActivity.this, MainActivity.class);
                intent.putExtras(bundle);
                startActivity(intent);



//                fetching the values of the edit text
//                String x = String.valueOf(S) +"blalala"+ String.valueOf(K);
//                message.setText(x);
//                Toast.makeText(CalculatorActivity.this,"Welcome to Android!",Toast.LENGTH_LONG).show();

            }
        });

    }
}