//
// Created by Mohit on 28-06-2022.
//inspired from C++ Design Patterns and derivative pricing - Mark S. Joshi
//

#ifndef IMPLIED_VOLATILITY_CALCULATOR_METHOD_NEWTONRAPHSON_H
#define IMPLIED_VOLATILITY_CALCULATOR_METHOD_NEWTONRAPHSON_H

#include <cmath>

//setting template design pattern with function pointers for p_prime
template<typename T, double (T::*p)(double) const, double (T::*p_prime)(double) const>
double newtonRaphson(double yFinTarget, double init, double epsilon, const T& rootFunc)
{
    // Setting the initial value of option price and the volatility
    // initial price of the option and initial volatility in the market
    double y = (rootFunc.*p)(init);
    double x = init;                  // initial volatility in the market

    // When y and y_finTaget are not close enough then we take the vega of the option and again calculate a new option price
    // the idea behind is the best possible approximation for that specific volatility value
    while (fabs(y - yFinTarget) > epsilon) {
        double dX = (rootFunc.*p_prime)(x);
        //we are updating the option price
        x += (yFinTarget - y) / dX;
        y = (rootFunc.*p)(x);
    }
    return x;
}

#endif //IMPLIED_VOLATILITY_CALCULATOR_METHOD_NEWTONRAPHSON_H
