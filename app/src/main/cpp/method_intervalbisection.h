//
// Created by Mohit on 28-06-2022.
//inspired from C++ Design Patterns and derivative pricing - Mark S. Joshi
//

#ifndef IMPLIED_VOLATILITY_CALCULATOR_METHOD_INTERVALBISECTION_H
#define IMPLIED_VOLATILITY_CALCULATOR_METHOD_INTERVALBISECTION_H

#include <cmath>

//function template has been created to find x when modulus of difference of p(x) - y is less than epsilon
// initial interval is (a,b)

// The function parameters are Target y, left interval, and right interval value
// Also Tolerance and Function object which has type T
template<typename T>
double intervalBisection(double yFinTarget, double a, double b, double epsilon, T p) {

//creating initial half value in the middle and finding y of p(x)
    double x = 0.5 * (a + b);
    double y = p(x);

//we keep on performing the process of dividing the intervals into much small halves until the difference between
//y and yFinTarget is less than epsilon.
    int count = 0;
    while (fabs(y - yFinTarget) > epsilon)
    {
        //check if y is less than the target then update the initial interval
        if (y < yFinTarget) {
            a = x;
        }
        //check if y is greater than the target then update the last interval
        if (y > yFinTarget) {
            b = x;
        }
        x = 0.5 * (a + b); //get mid-point
        y = p(x);
        count++;
        //if no root found after 1000 iterations return 0
        if(count > 10000)
            return 0.0;
    }

    return x;
}

#endif //IMPLIED_VOLATILITY_CALCULATOR_METHOD_INTERVALBISECTION_H
