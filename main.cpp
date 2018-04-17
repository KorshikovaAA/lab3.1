#include "Temperature.h"
#include <vector>
using namespace std;
char Scale[]="CKF";
int
main(){
    size_t number;
    cerr << "Vvedite kolichestvo peremennyh:\n";
    cin >> number;
    size_t st;
    cerr << "\nVvedite kolichestvo stolbcov:\n";
    cin >> st;

    vector <Temperature> X(number);
    cerr << "\nVvedite massiv X:\n";
    for (int i = 0; i<number; i++) {
        cin >> X[i];
        convert (X[i], 'K');
        if (!cin) {
            cerr << "Necorrectniyi vvod";
            return 1;
        }
    }
    double min = X[0].temp;
    double max = X[0].temp;
    for (Temperature x : X) {
        double y = convert(x, 'K');
        if (y < min) {
                min = y;
            }
        if (y > max) {
                max = y;
            }
        }
    vector<size_t> col_count(st, 0);
    for (Temperature x : X) {
        size_t index = (size_t)((x.temp - min) / (max - min) * st);
        if (x.temp == max) {
                index--;
        }
        col_count[index]++;
        }
    const size_t screen_width = 80;
    const size_t axis_width = 4;


    for (int i = 0; i < st; i++) {
        if (col_count[i] < 10) {
                cout << "|" << "  " << col_count[i] << "|";
            }
        if (col_count[i] > 10 && col_count[i] < 100) {
                cout << "|" << " " << col_count[i] << "|";
            }
        if (col_count[i] >= 100 && col_count[i] < 1000) {
                cout << "|" << col_count[i] << "|";
            }
        if (col_count[i] == 0) {
                cout << "*";
            }

        for (int j = 0; j < (number + 5); j++) {
                if (j < col_count[i]) {
                    cout << "*";
                }
                else cout << " ";

                if (j == (number - 1) && col_count[i] != 0) {
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

    return 0;
}
