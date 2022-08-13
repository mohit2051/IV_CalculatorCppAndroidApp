#include <jni.h>
#include <string>

#include "black_scholes_model.h"
#include "method_intervalbisection.h"
#include "method_newtonraphson.h"
#include <iostream>

//defining the string method for jni call for testing jni call
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_impliedvolatilitycalculator_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
//defining the jni environment setup for calling C++ method
extern "C" JNIEXPORT jdouble JNICALL
Java_com_example_impliedvolatilitycalculator_MainActivity_impliedVolCalc(
        JNIEnv* env,
        jobject, jint methodOption, jdouble spotPrice, jdouble strikePrice, jdouble riskFreeRate,
        jdouble timeToMaturity, jdouble optionPrice, jint optionType) {

    // First we create the parameter list
    int numericalMethod  = methodOption;
    int optionTypeInt = optionType;

    // initializing all the black-scholes parameter values and the option market price
    double S = spotPrice;  // Underlying spot price
    double K = strikePrice;  // Strike price
    double r = riskFreeRate;   // Risk-free rate (5%)
    double T = timeToMaturity;    // One year until expiry
    double optionPriceVal = optionPrice; // Option market price

    // Create the Black-Scholes Call functor
    BlackScholesModelCall bsmc(S, K, r, T);

    // Create the Black-Scholes Call functor
    BlackScholesModelPut bsmp(S, K, r, T);

    // Parameters of Interval Bisection
    double lowVol = 0.005;
    double highVol = 1;
    double epsilon = 0.001;
    // Parameters of Newton-Raphson
    double initial = 1;  // Our guess impl. vol of 30%
    double sigma;

    // Calculating the implied vol using interval bisection
    if (numericalMethod == 1) {


        //call option
        if(optionTypeInt == 1) {
            sigma = intervalBisection(optionPriceVal, lowVol, highVol, epsilon, bsmc);
        }
        //put option
        else{
            sigma = intervalBisection(optionPriceVal, lowVol, highVol, epsilon, bsmp);
        }

    }
    // Calculating the implied vol using Newton Raphson
    else if(numericalMethod == 2) {

        //call option
        if(optionTypeInt == 1){
            sigma = newtonRaphson<BlackScholesModelCall, &BlackScholesModelCall::optionPrice, &BlackScholesModelCall::optionVega>(optionPriceVal, initial, epsilon, bsmc);
        }
        //put option
        else{
            sigma = newtonRaphson<BlackScholesModelPut, &BlackScholesModelPut::optionPrice, &BlackScholesModelPut::optionVega>(optionPriceVal, initial, epsilon, bsmp);
        }

    }
    //incase of exception when no such numerical method matches
    else
    {
        sigma = 0.0;
    }
    //rounding implied vol to four digits
    sigma = round( sigma * 10000.0 ) / 10000.0;

    return sigma;
}