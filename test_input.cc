#include "Temperature.h"
#include <cassert>
#include <vector>
using namespace std;
int main() {
    Temperature Temp;
string inp="10C";
istringstream iss(inp);
iss >> Temp;
assert (Temp.temp==10);
assert (Temp.scale=='C');

string inp1="0K";
istringstream iss1(inp1);
iss1 >> Temp;
assert (Temp.temp==0);
assert (Temp.scale=='K');

string inp2="-400F";
istringstream iss2(inp2);
iss2 >> Temp;
assert (Temp.temp==-400);
assert (Temp.scale=='F');
};
//
// Created by u211-15 on 17.04.2018.
//

