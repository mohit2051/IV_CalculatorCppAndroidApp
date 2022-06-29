package com.example.impliedvolatilitycalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.impliedvolatilitycalculator.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'impliedvolatilitycalculator' library on application startup.
    static {
        System.loadLibrary("impliedvolatilitycalculator");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        double K=0.0,S=0.0,r=0.0,T=0.0,V=0.0;
        Bundle bundle = getIntent().getExtras();
        if(bundle != null) {
             K = Double.parseDouble(bundle.getString("K"));
             S = Double.parseDouble(bundle.getString("S"));
             r = Double.parseDouble(bundle.getString("r"));
             T = Double.parseDouble(bundle.getString("T"));
             V = Double.parseDouble(bundle.getString("V"));

        }

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        //tv.setText(stringFromJNI());
        try {
            tv.setText("Implied Volatility = " + String.valueOf(impliedVolCalc(1,S,K,r,T,V)));
        }
        catch (Exception e) {
            Log.e("Failed", e.toString());
            e.printStackTrace();
        }
    }

    /**
     * A native method that is implemented by the 'impliedvolatilitycalculator' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native double impliedVolCalc(int i, double S, double K, double r, double T, double C_M);
}