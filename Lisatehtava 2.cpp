// 2. Tunti - Lisatehtava 2
// Valuuttamuunnin
// TODO
#include<iostream>

using namespace	std;

int main() {

	float annettu_valuutta, muunnos, eur_usd, usd_eur, eur_gbp, gbp_eur, usd_gbp, gbp_usd;	// Esitellaan muuttujat syotteita varten
	char syote_yksikko, muunnos_yksikko;	// Esitellaan muuttujat jaottelua varten

	eur_usd = 0.9756;	// Asetetaan arvot muuttujiin
	usd_eur = 1.0253;

	eur_gbp = 0.8817;
	gbp_eur = 1.134;

	usd_gbp = 0.9039;
	gbp_usd = 1.1064;

	
	cout << "Valitse muunnettavan valuutan yksikkoa merkitseva kirjain:\n(e = euro, d = usd, p = gbp):";
	cin >> syote_yksikko;	// Asetetaan kayttajan syote muuttujaan

	cout << "Valitse yksikko muunnosta varten:\n(e = euro, d = usd, p = gbp)\nHUOM! Tuloksen yksikko ei voi olla sama kuin muunnettavan!:\n";
	cin >> muunnos_yksikko;	// Asetetaan kayttajan syote toiseen muuttujaan


	if (syote_yksikko == muunnos_yksikko) {	// Tarkistetaan ettei annetut yksikot ole samoja
		cout << "Virhe! Asetetut yksikot eivat voi olla sama!";
	}
	
	// if (syote_yksikko == 'e') {
	//	cout << "Anna muunnettava luku euroissa:";	
	// } 
}