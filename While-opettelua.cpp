// Do-While loopin käytön opettelua 
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace	std;

int main() {
	int luku1, luku2, luku3; // Kolme kokonaislukua
	double keskiarvo;
	char jatketaan; // Kysytään ohjelman jatkaminen

	do {
		do {
			cout << "Anna kolme lukua? (luku>0)\n";
			cin >> luku1 >> luku2 >> luku3;

		} while (luku1 <= 0 || luku2 <= 0 || luku3 <= 0);
		
		keskiarvo = (luku1 + luku2 + luku3) / 3.0;
		cout << fixed << showpoint << setprecision(2) << keskiarvo;
		cout << keskiarvo << endl;

		cout << "Luku 1 potenssiin luku 2 on :" << pow(luku1, luku2) << endl;

		cout << "Jatkekaanko (K/k)?";
		cin >> jatketaan;
	} while (jatketaan == 'K' || jatketaan == 'k');

	return 0;
}