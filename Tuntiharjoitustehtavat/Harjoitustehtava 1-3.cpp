#include<iostream> // Linkataan mukaan syote- ja tulostuskaskyt

using namespace std; // Otetaan nimiavaruus kayttoon

int main() { // Paaohjelma alkaa
	
	int ika; // Muuttujan esittely

	cout << "Anna ikasi: ";

	cin >> ika; // Kysytaan kayttajalta ika

	int vanha{ ika + 50 }; // Uusi muuttuja joka on ika + 50

	cout << "50 vuoden kuluttua olet " << vanha << " vuotias"; // Tulostaa tekstijonon ja luvun
	
	return 0; // Tama on sama kuin EXIT_SUCCESS eli ohjelma on toiminut ja poistunut
} // Paaohjelma loppuu
