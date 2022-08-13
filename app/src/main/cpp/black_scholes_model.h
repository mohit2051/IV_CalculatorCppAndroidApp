//
// Created by Mohit on 28-06-2022.
//

#ifndef IMPLIED_VOLATILITY_CALCULATOR_BLACK_SCHOLES_MODEL_H
#define IMPLIED_VOLATILITY_CALCULATOR_BLACK_SCHOLES_MODEL_H

// setting the black-scholes model class
class BlackScholesModel {
protected:
    double S;  // Underlying security price
    double K;  // strike price
    double r;  // risk free rate
    double T;  // time to expiration

//initializing the methods that we will implement in the source file
public:
    BlackScholesModel(double S_, double K_, double r_, double T_);
    virtual ~BlackScholesModel();
    virtual double operator()(double sigma) const = 0;

};

//setting the black-scholes model call child class
class BlackScholesModelCall: public BlackScholesModel {
public:
    BlackScholesModelCall(double S_, double K_, double r_, double T_);
    virtual ~BlackScholesModelCall();
    virtual double operator()(double sigma) const;
    double optionPrice(double sigma) const;
    double optionVega(double sigma) const;

};

//setting up the black-scholes model put class
class BlackScholesModelPut : public BlackScholesModel {
public:
    //initializing methods which we will implement in the source file
    BlackScholesModelPut(double S_, double K_, double r_, double T_);
    virtual ~BlackScholesModelPut();
    virtual double operator()(double sigma) const;
    double optionPrice(double sigma) const;
    double optionVega(double sigma) const;

};

#endif //IMPLIED_VOLATILITY_CALCULATOR_BLACK_SCHOLES_MODEL_H
