#include<iostream> // Linkataan mukaan sy�te- ja tulostusk�skyt

using namespace std; // Otetaan nimiavaruus k�ytt��n

int main() {
	int eka, toka, kolmas;

	cout << "Anna luku: "; // Kysyt��n muuttujaan arvo
	cin >> eka;

	cout << "Anna toinen luku: "; // Kysyt��n muuttujaan arvo
	cin >> toka;

	cout << "Anna viela kolmas luku: "; // Kysyt��n muuttujaan arvo
	cin >> kolmas;

	if (eka > toka && eka > kolmas)
		cout << "Ensimmainen luku oli suurin!";
	if (toka > kolmas)
		cout << "Toinen luku oli suurin!";
	else
	{
		cout << "Kolmas luku oli suurin!";
	}
	return 0;
}
