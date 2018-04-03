#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
using namespace std;
char Scale[]="CKF";

struct Temperature{
double temp;
char scale;
};

istream & operator >> (istream&in, Temperature&Temp);
istream & operator >> (istream&in, Temperature&Temp){
    in>>Temp.temp;
    in>>Temp.scale;
}
void test_temperature_input(){
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

double convert (const Temperature& Temp, char scale_to){
    double Kelvins;
    Kelvins=Temp.temp;
    switch (Temp.scale){
    case 'C': Kelvins+=273;
        break;
    case 'F': Kelvins=((9.0/5)*(Temp.temp-273)+32);
        break;

    }
}
int
main(){
   test_temperature_input();

   /* size_t number;
    cerr << "Vvedite kolichestvo peremennyh:\n";
    cin >> number;
    size_t st;
    cerr << "\nVvedite kolichestvo stolbcov:\n";
    cin >> st;

    vector <double> X(number);
    cerr << "\nVvedite massiv X:\n";
    for (int i = 0; i<number; i++)
        cin >> X[i];

    double min, max;
    min = X[0];
    max = X[0];
    for (double x : X) {
        if (x < min)
            min = x;
        if (x> max)
            max = x;
    }

    vector <size_t> col_count(st, 0);
    for (double x : X) {
        size_t index = (size_t)((x - min) / (max - min)*st);
        if (x == max) {
            index = index - 1;
        }
        col_count[index] = col_count[index] + 1;
    }
    cerr << "\nGistograma:\n";


    cout << "+";
    for (int j = 1; j<=(number+4); j++) {
        cout << "-";
    }
    cout << "+"<< '\n';


    for (int i = 0; i < st; i++) {
        if (col_count[i] < 10) {
            cout << "|" << "  " << col_count[i] <<"|";
        }
        if (col_count[i] > 10 && col_count[i] < 100) {
            cout << "|" << " " << col_count[i] <<"|";
        }
        if (col_count[i] >= 100 && col_count[i] < 1000) {
            cout << "|" << col_count[i] <<"|";
        }
        if (col_count[i] == 0) {
            cout << "*";
        }

        for (int j = 0; j < (number+5); j++){
            if (j < col_count[i]) {
                cout << "*";
            }
            else cout << " ";

            if (j == (number-1) && col_count[i] != 0) {
                cout << "|";
            }
            if (j == (number - 2) && col_count[i] == 0) {
                cout << "|";
            }
        }
        if (col_count[i] > 74) {
            break;
        }
        cout << '\n';
    }
    cout << "+";
    for (int j = 1; j<= (number + 4); j++) {
        cout << "-";
    }
    cout << "+" << '\n'; */
    return 0;
}