//
// Created by DELL on 28-06-2022.
//

#include "black_scholes_model.h"
#include "black_scholes_prices.h"


BlackScholesModel::BlackScholesModel(double _S, double _K,double _r, double _T) : S(_S), K(_K), r(_r), T(_T) {}
BlackScholesModel::~BlackScholesModel(){}

BlackScholesModelCall::BlackScholesModelCall(double _S, double _K,double _r, double _T) : BlackScholesModel(_S,_K,_r,_T ) {}
BlackScholesModelCall::~BlackScholesModelCall() = default;

double BlackScholesModelCall::operator()(double sigma) const
{
    return call_price(S, K, r, sigma, T);
}

BlackScholesModelPut::BlackScholesModelPut(double _S, double _K, double _r, double _T) : BlackScholesModel(_S, _K, _r, _T) {}
BlackScholesModelPut::~BlackScholesModelPut() = default;

double BlackScholesModelPut::operator()(double sigma) const
{
    return put_price(S, K, r, sigma, T);
}

// Renamed from operator() to option_price()
double BlackScholesModelCall::option_price(double sigma) const {
    return call_price(S, K, r, sigma, T);
}

// New method added, which calls call_vega
// to obtain the actual price
double BlackScholesModelCall::option_vega(double sigma) const {
    return call_vega(S, K, r, sigma, T);
}

// Renamed from operator() to option_price()
double BlackScholesModelPut::option_price(double sigma) const {
    return put_price(S, K, r, sigma, T);
}

// New method added for put option, which calls call_vega
// to obtain the actual price. The put vega and call vega are the same. So, we are just reusing it
double BlackScholesModelPut::option_vega(double sigma) const {
    return call_vega(S, K, r, sigma, T);
}