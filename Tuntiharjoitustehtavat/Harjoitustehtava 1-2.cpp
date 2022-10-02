//Viope tehtava 1-2
#include<iostream> // Linkataan mukaan syote- ja tulostuskaskyt

using namespace std; // Otetaan nimiavaruus kayttaan

int main() { // Paaohjelma alkaa
	int luku; // Muuttujan esittely
	cout << "Syota luku ";
	cin >> luku; // Kysytaan kayttajalta luku
	cout << "Syotit luvun " << luku; // Tulostaa tekstijonon, luvun ja lopettaa rivin

	return 0; // Tama on sama kuin EXIT_SUCCESS eli ohjelma on toiminut ja poistunut
} // Paaohjelma loppuu