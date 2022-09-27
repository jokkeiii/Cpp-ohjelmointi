#include<iostream> // Linkataan mukaan sy�te- ja tulostusk�skyt

using namespace std; // Otetaan nimiavaruus k�ytt��n

int main() {
	float laina, korko, korko_kerroin, vuosi, korko_summa; //Esitell��n muuttujat

	cout << "Syota lainan maara(euroa) :"; //Kysyt��n muuttujaan arvo
	cin >> laina;

	cout << "Syota korkoprosentti: "; //Kysyt��n muuttujaan arvo
	cin >> korko;

	cout << "Syota laina-aika (vuosia): "; //Kysyt��n muuttujaan arvo
	cin >> vuosi;
	korko_kerroin = korko / 100;
	korko_summa=laina*korko_kerroin*vuosi; //Lasketaan kysyttyjen arvojen perusteella korkojen m��r�

	cout << "Lainan korot laina-ajalta ovat " << korko_summa << " euroa."; //Tulostetaan laskettu arvo

	return 0;
}
