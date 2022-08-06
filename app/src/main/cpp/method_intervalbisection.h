//
// Created by DELL on 28-06-2022.
//

#ifndef IMPLIED_VOLATILITY_CALCULATOR_METHOD_INTERVALBISECTION_H
#define IMPLIED_VOLATILITY_CALCULATOR_METHOD_INTERVALBISECTION_H

#include <cmath>

//function template has been created to find x when modulus of difference of p(x) - y is less than epsilon
// initial interval is (a,b)

// The function parameters are Target y, left interval, and right interval value
// Also Tolerance and Function object which has type T
template<typename T>
double interval_bisection(double yFinTarget, double a, double b, double epsilon, T p) {

//creating initial half value in the middle and finding y of p(x)
    double x = 0.5 * (a + b);
    double y = p(x);

//we keep on performing the process of dividing the intervals into much small halves until the difference between
//y and yFinTarget is less than epsilon.
    int count = 0;
    while (fabs(y - yFinTarget) > epsilon)
    {
        if (y < yFinTarget) {
            a = x;
        }

        if (y > yFinTarget) {
            b = x;
        }

        x = 0.5 * (a + b);
        y = p(x);
        count++;
        if(count > 10000)
            return 0.0;
    }

    return x;
}

#endif //IMPLIED_VOLATILITY_CALCULATOR_METHOD_INTERVALBISECTION_H
