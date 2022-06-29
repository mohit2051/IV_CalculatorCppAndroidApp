#include <jni.h>
#include <string>

#include "black_scholes.h"
#include "interval_bisection.h"
#include "newton_raphson.h"
#include <iostream>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_impliedvolatilitycalculator_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jdouble JNICALL
Java_com_example_impliedvolatilitycalculator_MainActivity_impliedVolCalc(
        JNIEnv* env,
        jobject, jint methodOption, jdouble spotPrice, jdouble strikePrice, jdouble riskFreeRate,
        jdouble timeToMaturity, jdouble optionPrice) {

    // First we create the parameter list
    double numericalMethod  = methodOption;

    double S = spotPrice;  // Underlying spot price
    double K = strikePrice;  // Strike price
    double r = riskFreeRate;   // Risk-free rate (5%)
    double T = timeToMaturity;    // One year until expiry
    double C_M = optionPrice; // Option market price

    // Create the Black-Scholes Call functor
    BlackScholesCall bsc(S, K, r, T);

    // Interval Bisection parameters
    double low_vol = 0.05;
    double high_vol = 0.35;
    double epsilon = 0.001;
    // Newton Raphson Parameter
    double init = 1;  // Our guess impl. vol of 30%
    double sigma;
    if (numericalMethod == 1) {
        // Calculate the implied volatility
        sigma = interval_bisection(C_M, low_vol, high_vol, epsilon, bsc);

        // Output the values
        std::cout << "IB method - Implied Vol: " << sigma << std::endl;
    }
    else if(numericalMethod == 2) {
        sigma = newton_raphson<BlackScholesCall, &BlackScholesCall::option_price, &BlackScholesCall::option_vega>(C_M, init, epsilon, bsc);
    }

    else
    {
        sigma = 0.0;
    }

    return sigma;
}