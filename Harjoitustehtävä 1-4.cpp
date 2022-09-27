#include<iostream> // Linkataan mukaan sy�te- ja tulostusk�skyt

using namespace std; // Otetaan nimiavaruus k�ytt��n

int main() { // P��ohjelma alkaa
	int eka_luku, toka_luku, erotus, tulo; // Muuttujien esittely
	cout << "Syota 1. luku: ";
	cin >> eka_luku; // Kysyt��n k�ytt�j�lt� ensimm�inen luku
	cout << "Syota 2. luku: ";
	cin >> toka_luku; // Kysyt��n k�ytt�j�lt� toinen luku
	erotus = eka_luku - toka_luku; // Lasketaan lukujen erotus
	tulo = eka_luku * toka_luku; // Lasketaan lukujen tulo
	cout << "Lukujen erotus on " << erotus << "\nLukujen tulo on " << tulo; // Tulostus

	return 0; // T�m� on sama kuin EXIT_SUCCESS eli ohjelma on toiminut ja poistunut
} // P��ohjelma loppuu
