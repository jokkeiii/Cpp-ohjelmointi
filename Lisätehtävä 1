// HUOM! Kyseinen tehtävä kesken!

#include<iostream> // Linkataan mukaan sy�te- ja tulostusk�skyt

using namespace std; // Otetaan nimiavaruus k�ytt��n

void ala_ohjelma() {

	//Esitell��n muuttujat

	int lainan_maara, laina_aika;
	float korko, korko_kertoimena, tasa_era;

	//Kysyt��n muuttujaan arvo
	cout << "Anna lainan m��r� (euroissa): ";
	cin >> lainan_maara;

	//Kysyt��n toiseen muuttujaan arvo
	cout << "Anna lainan korkoprosentti: ";
	cin >> korko;

	// Muunnetaan korkoprosentti, jotta voidaan k�ytt�� sit� laskuissa
	// korko_kertoimena = korko / 100;

	//Kysyt��n kolmanteen muuttujaan arvo
	cout << "Anna lainan takaisinmaksuaika: ";
	cin >> laina_aika;

	tasa_era = (((1 + korko / 100) ^ laina_aika * korko / 100) / ((1 + korko / 100) ^ laina_aika - 1)) * lainan_maara;

}
