//
// Created by Mohit on 28-06-2022.
//

#include "black_scholes_model.h"
#include "black_scholes_prices.h"

// defining black scholes model parent class with black-scholes parameter
BlackScholesModel::BlackScholesModel(double S_, double K_,double r_, double T_) : S(S_), K(K_), r(r_), T(T_) {}
BlackScholesModel::~BlackScholesModel(){}

// defining black scholes model call child class with parameters
BlackScholesModelCall::BlackScholesModelCall(double S_, double K_,double r_, double T_) : BlackScholesModel(S_,K_,r_,T_ ) {}
BlackScholesModelCall::~BlackScholesModelCall() = default;

//operator overloading for functor of call_price
double BlackScholesModelCall::operator()(double sigma) const
{
    return callPrice(S, K, r, sigma, T);
}

// defining black scholes model call child class with parameters
BlackScholesModelPut::BlackScholesModelPut(double S_, double K_, double r_, double T_) : BlackScholesModel(S_, K_, r_, T_) {}
BlackScholesModelPut::~BlackScholesModelPut() = default;

//operator overloading for functor of put_price
double BlackScholesModelPut::operator()(double sigma) const
{
    return putPrice(S, K, r, sigma, T);
}

// renaming from operator() to option_price() for call option
double BlackScholesModelCall::optionPrice(double sigma) const {
    return callPrice(S, K, r, sigma, T);
}

// this method  has been added, which calls call_vega to get the actual or real price
double BlackScholesModelCall::optionVega(double sigma) const {
    return callVega(S, K, r, sigma, T);
}

// renaming from operator() to option_price() for put option
double BlackScholesModelPut::optionPrice(double sigma) const {
    return putPrice(S, K, r, sigma, T);
}

// New method added for put option, which calls call_vega
// to obtain the real price. The put vega and call vega are the same. So, we are just reusing it
double BlackScholesModelPut::optionVega(double sigma) const {
    return callVega(S, K, r, sigma, T);
}