#include"Temperature.h"
#include <cassert>
#include <vector>
using namespace std;
char Scale[]="CKF";

void test_temperature_input(){
    Temperature Temp;
    string inp="10C";
    istringstream iss(inp);
    iss>>Temp;
    assert(Temp.temp==10);
    assert(Temp.scale=='C');

    istringstream iss1("0K");
    iss1>>Temp;
    assert(Temp.temp==0);
    assert(Temp.scale=='K');

    istringstream iss2("-400F");
    iss2>>Temp;
    assert(Temp.temp==-400);
    assert(Temp.scale=='F');
};
int
main(){
   test_temperature_input();

    size_t count;
    cerr << "Vvedite kolichestvo peremennyh:\n";
    cin >> count;
    vector<double>element(count);
    cerr << "\nVvedite "<<count<<" elementov:\n";
    for (size_t i = 0; i < count; i++) {
        cin >> element[i];

    }
    size_t col_count;
        cerr << "\n chislo stolbtsov";
        cin >> col_count;
        cerr << "\n";
        double min = element[0], max = element[0];
        for (double x:element) {
            if (x < min) {
                min = x;
            }
            if (x > max) {
                max = x;
            }
        }

        vector<size_t> bins(col_count, 0);
        for (double x : element) {
            size_t index = (size_t) ((x - min) / (max - min) * col_count);
            if (x == max) {
                index--;
            }
            bins[index]++;
        }
        float maxbins;
        double koef;
        maxbins = bins[0];
        for (float x:bins) {
            if (maxbins < x)
                maxbins = x;
        }
        koef = 1;
        if (maxbins > 76)
            koef = (double) (1 - (maxbins - 76) / (maxbins));

        cerr << "\nGistograma:\n";
        cout << "+";
        for (int j = 1; j <= count * koef; j++) {
            cout << "-";
        }
        cout << "+" << '\n';


        for (int i = 0; i < col_count; i++) {
            if (i > 0)
                cout << "\n";
            if (bins[i] >= 100) {
                cout << "|" << bins[i] << "|";
            } else if (bins[i] >= 10)
                cout << "| " << bins[i] << "|";
            else
                cout << "|  " << bins[i] << "|";
            for (size_t j = 0; j < bins[i] * koef; j++) {
                cout << "*";
                cout << "|";
            }
        }
        cout << "+";
        for (int j = 1; j <= count * koef; j++) {
            cout << "-";
        }
        cout << "+" << '\n';
    return 0;
}