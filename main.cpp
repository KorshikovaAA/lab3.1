#include"Temperature.h"
#include "windows.h"
#include <cassert>
#include <vector>
using namespace std;
char Scale[]="CKF";
int
main() {
	size_t count;
	cerr << "Vvedite kolichestvo peremennyh:\n";
	cin >> count;
	vector<Temperature>element(count);
	cerr << "Vvedite " << count << " elementov:\n";
	for (size_t i = 0; i < count; i++) {
		cin >> element[i];
		if (cin.fail())
		{
			return -1;
		}
		convert(element[i], 'K');
	}
	size_t col_count;
	cerr << "\nVvedite chislo stolbtsov:\n";
	cin >> col_count;
	cerr << "\n";
	double min = element[0].temp, max = element[0].temp;
	for (Temperature x : element) {
		if (x.temp < min) {
			min = x.temp;
		}
		if (x.temp > max) {
			max = x.temp;
		}
	}

	vector<size_t> bins(col_count, 0);
	for (Temperature x : element) {
		size_t index = (size_t)((x.temp - min) / (max - min) * col_count);
		if (x.temp == max) {
			index--;
		}
		bins[index]++;
	}
	float maxbins;
	double koef;
	size_t j;
	maxbins = bins[0];
	for (float x : bins) {
		if (maxbins < x)
			maxbins = x;
	}
	koef = 1;
	if (maxbins > 76)
		koef = (double)(1 - (maxbins - 76) / (maxbins));

	cerr << "Gistograma:\n";
	cout << "+";
	for (j = 1; j <= count + 4; j++) {
		cout << "-";
	}
	cout << "+" << '\n';
	for (int i = 0; i < col_count; i++) {
		if (i > 0)
			cout << "\n";
		if (bins[i] >= 100) {
			cout << "|" << bins[i] << "|";
		}
		else
			if (bins[i] >= 10)
				cout << "| " << bins[i] << "|";
			else
				cout << "|  " << bins[i] << "|";
		for (j = 0; j <= count-1; j++) {
			if (j < bins[i] * koef) {
				cout << "*";
			}
			else cout << " ";
			if (j == count-1) {
				cout << "|";
			}
		}
		
	}
        cout << "\n+";
        for (j = 1; j <= count+4; j++) {
            cout << "-";
        }
        cout << "+" << '\n';
		Sleep(100000);
		return (0);
}