//
// Created by DELL on 28-06-2022.
//

#ifndef IMPLIED_VOLATILITY_CALCULATOR_BLACK_SCHOLES_MODEL_H
#define IMPLIED_VOLATILITY_CALCULATOR_BLACK_SCHOLES_MODEL_H

class BlackScholesModel {
protected:
    double S;  // Underlying asset price
    double K;  // Strike price
    double r;  // Risk-free rate
    double T;  // Time to maturity

public:
    BlackScholesModel(double _S, double _K, double _r, double _T);
    virtual ~BlackScholesModel();
    virtual double operator()(double sigma) const = 0;

};

class BlackScholesModelCall: public BlackScholesModel {
public:
    BlackScholesModelCall(double _S, double _K, double _r, double _T);
    virtual ~BlackScholesModelCall();
    virtual double operator()(double sigma) const;
    double option_price(double sigma) const;
    double option_vega(double sigma) const;

};

class BlackScholesModelPut : public BlackScholesModel {
public:
    BlackScholesModelPut(double _S, double _K, double _r, double _T);
    virtual ~BlackScholesModelPut();
    virtual double operator()(double sigma) const;
    double option_price(double sigma) const;
    double option_vega(double sigma) const;

};

#endif //IMPLIED_VOLATILITY_CALCULATOR_BLACK_SCHOLES_MODEL_H
