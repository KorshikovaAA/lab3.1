//
// Created by u211-15 on 03.04.2018.
//
#include <iostream>
#include"Temperature.h"
using namespace std;
istream & operator >> (istream& in, Temperature& Temp){
    in.setstate(ios_base::goodbit);
    in>>Temp.temp;
    in>>Temp.scale;

    switch (Temp.scale) {
        case 'K':
        case 'k':
            Temp.scale = Kelvin;
            break;
        case 'C':
        case 'c':
            Temp.scale = Celsus;
            break;
        case 'F':
        case 'f':
            Temp.scale = Farenheit;
            break;
        default:
            in.setstate(ios_base::failbit);
    }
    if(convert(Temp,'K')<0) {in.setstate(ios_base::failbit);}
    return in;
}
double convert (const Temperature& Temp, char scale_to){
    double T_Kelvins;
    if (scale_to==Temp.scale){
        return Temp.temp;
    }
    switch (Temp.scale){
    case 'C':
        T_Kelvins=Temp.temp+273.15;
        break;
    case 'F':
        T_Kelvins=((9.0/5)*(Temp.temp-273.15)+32);
        break;
    case 'K':
        T_Kelvins = Temp.temp;
        break;
    }
    switch (scale_to){
    case 'C':
    case 'c': return  T_Kelvins-273.15;
    case 'K':
    case 'k': return T_Kelvins;
    case 'F':
    case 'f': return ((9.0/5)*(T_Kelvins-273.15)+32);
    }

}
bool operator < (const Temperature& lhs, const Temperature& rhs)
{
    return convert(lhs,'K') < convert(rhs,'K');
}
bool operator < (const Temperature& lhs, const float& rhs)
{
    return convert(lhs,'K') < rhs;
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
Temperature operator*(const Temperature& lhs, const Temperature& rhs) {
    Temperature ret_temp;
    ret_temp.temp = convert(lhs, 'K') * convert(rhs, 'K');
    ret_temp.scale = 'K';
    return ret_temp;
}

