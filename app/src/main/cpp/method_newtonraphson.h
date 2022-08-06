//
// Created by DELL on 28-06-2022.
//

#ifndef IMPLIED_VOLATILITY_CALCULATOR_METHOD_NEWTONRAPHSON_H
#define IMPLIED_VOLATILITY_CALCULATOR_METHOD_NEWTONRAPHSON_H

#include <cmath>

template<typename T, double (T::*p)(double) const, double (T::*p_prime)(double) const>
double newton_raphson(double yFinTarget, double init, double epsilon, const T& rootFunc)
{
    // Setting the initial value of option price and the volatility
    // initial price of the option and initial volatility in the market
    double y = (rootFunc.*p)(init);
    double x = init;                  // initial volatility in the market

    // When y and y_finTaget are not close enough then we take the vega of the option and again calculate a new call option price
    // based on the best possible approximation for that particular volatility value
    while (fabs(y - yFinTarget) > epsilon) {
        double d_x = (rootFunc.*p_prime)(x);
        x += (yFinTarget - y) / d_x;
        y = (rootFunc.*p)(x);
    }
    return x;
}

#endif //IMPLIED_VOLATILITY_CALCULATOR_METHOD_NEWTONRAPHSON_H
