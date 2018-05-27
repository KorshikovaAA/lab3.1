//
// Created by u211-15 on 03.04.2018.
//

//#pragma once

#ifndef UNTITLED_TEMPERATURE_H
#define UNTITLED_TEMPERATURE_H
#include <iostream>
#include <sstream>
using namespace std;
enum Scale{
    Kelvin = 'K',
    Celsus = 'C',
    Farenheit = 'F',
};
struct Temperature{
    double temp;
    char scale;
};
istream & operator >> (istream& in, Temperature& Temp);
bool operator < (const Temperature& lhs, const Temperature& rhs);
Temperature operator- (const Temperature& lhs, const Temperature& rhs);
Temperature operator/ (const Temperature& lhs, const Temperature& rhs);
Temperature operator*(const Temperature& lhs, const Temperature& rhs);
double convert (const Temperature& Temp, char scale_to);
#endif //UNTITLED_TEMPERATURE_H
