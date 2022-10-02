// HUOM! Kyseinen tehtava kesken!

#include<iostream> // Linkataan mukaan syote- ja tulostuskaskyt

using namespace std; // Otetaan nimiavaruus kayttaan

void ala_ohjelma() {

	//Esitellaan muuttujat

	int lainan_maara, laina_aika;
	float korko, korko_kertoimena, tasa_era;

	//Kysytaan muuttujaan arvo
	cout << "Anna lainan maara (euroissa): ";
	cin >> lainan_maara;

	//Kysytaan toiseen muuttujaan arvo
	cout << "Anna lainan korkoprosentti: ";
	cin >> korko;

	// Muunnetaan korkoprosentti, jotta voidaan kayttaa sita laskuissa
	// korko_kertoimena = korko / 100;

	//Kysytaan kolmanteen muuttujaan arvo
	cout << "Anna lainan takaisinmaksuaika: ";
	cin >> laina_aika;

	tasa_era = (((1 + korko / 100) ^ laina_aika * korko / 100) / ((1 + korko / 100) ^ laina_aika - 1)) * lainan_maara;

}
