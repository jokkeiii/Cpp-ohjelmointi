#include<iostream> // Linkataan mukaan sy�te- ja tulostusk�skyt

using namespace std; // Otetaan nimiavaruus k�ytt��n

int main() { // P��ohjelma alkaa
	
	int ika; // Muuttujan esittely

	cout << "Anna ikasi: ";

	cin >> ika; // Kysyt��n k�ytt�j�lt� ika

	int vanha{ ika + 50 }; // Uusi muuttuja joka on ik� + 50

	cout << "50 vuoden kuluttua olet " << vanha << " vuotias"; // Tulostaa tekstijonon ja luvun
	
	return 0; // T�m� on sama kuin EXIT_SUCCESS eli ohjelma on toiminut ja poistunut
} // P��ohjelma loppuu
*/

/*Viope teht�v� 1-2
#include<iostream> // Linkataan mukaan sy�te- ja tulostusk�skyt

using namespace std; // Otetaan nimiavaruus k�ytt��n

int main() { // P��ohjelma alkaa
	int luku; // Muuttujan esittely
	cout << "Syota luku ";
	cin >> luku; // Kysyt��n k�ytt�j�lt� luku
	cout << "Syotit luvun " << luku; // Tulostaa tekstijonon, luvun ja lopettaa rivin

	return 0; // T�m� on sama kuin EXIT_SUCCESS eli ohjelma on toiminut ja poistunut
} // P��ohjelma loppuu
