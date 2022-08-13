//
// Created by Mohit on 28-06-2022.
// inspired from https://www.quantstart.com/articles/
//

#ifndef IMPLIED_VOLATILITY_CALCULATOR_BLACK_SCHOLES_PRICES_H
#define IMPLIED_VOLATILITY_CALCULATOR_BLACK_SCHOLES_PRICES_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

// pdf(probability density function) - standard normal
double normPdf(const double z) {
    return (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * z * z);
}

//cdf (cumulative distribution function) which is defined for
// standard normal distribution
double normCdf(const double z) {
    double k = 1.0 / (1.0 + 0.2316419 * z);
    double kSum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

    if (z >= 0.0) {
        return (1.0 - (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * z * z) * kSum);
    }
    else {
        return 1.0 - normCdf(-z);
    }
}


// calculating d_j where j is 1 or 2. Found when finding closed form solution in
// Black Scholes model for European Vanilla option
double d_j(const int j, const double S, const double K, const double r, const double sigma, const double T) {
    return (log(S / K) + (r + (pow(-1, j - 1)) * 0.5 * sigma * sigma) * T) / (sigma * (pow(T, 0.5)));
}


//calculating the call price using the black-scholes model analytical solution for European option
//paramters S, K, r, T
double callPrice(const double S, const double K, const double r, const double sigma, const double T) {
    return (S * normCdf(d_j(1, S, K, r, sigma, T)) - K * exp(-r * T) * normCdf(d_j(2, S, K, r, sigma, T)));
}

//calculating the put price using the black-scholes model analytical solution for European option
//paramters S, K, r, T
double putPrice(const double S, const double K, const double r, const double sigma, const double T) {
    return (K * exp(-r * T) * normCdf((-1) * d_j(2, S, K, r, sigma, T)) - S * normCdf((-1) * d_j(1, S, K, r, sigma, T)));
}

//computing vega using the equation
double callVega(const double S, const double K, const double r, const double sigma, const double T) {
    return S * sqrt(T) * normPdf(d_j(1, S, K, r, sigma, T));
}


#endif //IMPLIED_VOLATILITY_CALCULATOR_BLACK_SCHOLES_PRICES_H
