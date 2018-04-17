//
// Created by u211-15 on 03.04.2018.
//
#include <iostream>
#include"Temperature.h"
using namespace std;
istream & operator >> (istream&in, Temperature&Temp){
    in>>Temp.temp;
    in>>Temp.scale;
}
double convert (const Temperature& Temp, char scale_to){
    double Kelvins;
    if (scale_to==Temp.scale){
        return Temp.temp;
    }
    switch (Temp.scale){
    case 'C':
        Kelvins=Temp.temp+273;
        break;
    case 'F':
        Kelvins=((9.0/5)*(Temp.temp-273.15)+32);
        break;
    }
    switch (scale_to){
    case 'C':
    case 'c': return  Kelvins-273.15;
    case 'K':
    case 'k': return Kelvins;
    case 'F':
    case 'f': return ((9.0/5)*(Kelvins-273.15)+32);
    }

}
bool operator < (const Temperature& lhs, const Temperature& rhs)
{
    return convert(lhs,'K') < convert(rhs,'K');
}
Temperature operator- (const Temperature& lhs, const Temperature& rhs)
{
    Temperature ret_temp;
    ret_temp.temp=convert(lhs,'K')-convert(rhs,'K');
    ret_temp.temp='K';
    return ret_temp;
}
Temperature operator/ (const Temperature& lhs, const Temperature& rhs)
{
    Temperature ret_temp;
    ret_temp.temp=convert(lhs,'K')/convert(rhs,'K');
    ret_temp.temp='K';
    return ret_temp;
}
Temperature operator* (const Temperature& lhs, const Temperature& rhs)
{
    Temperature ret_temp;
    ret_temp.temp=convert(lhs,'K')*convert(rhs,'K');
    ret_temp.temp='K';
    return ret_temp;
}


