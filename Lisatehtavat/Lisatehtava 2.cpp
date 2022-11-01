// 2. Tunti - Lisatehtava 2
// Valuuttamuunnin
// 
#include<iostream>

using namespace	std;

int main() {

	float annettu_valuutta, muunnos, eur_usd, usd_eur, eur_gbp, gbp_eur, usd_gbp, gbp_usd;	// Esitellaan muuttujat syotteita varten
	char syote_yksikko, muunnos_yksikko;	// Esitellaan muuttujat jaottelua varten

	eur_usd = 0.9756;	// Kaytetyt arvot muunnoksiin
	usd_eur = 1.0253;

	eur_gbp = 0.8817;
	gbp_eur = 1.134;

	usd_gbp = 0.9039;
	gbp_usd = 1.1064;

	do{
		// Kysytaan 
		cout << "HUOM! Tuloksen yksikko ei voi olla sama kuin muunnettavan!:\n";
		cout << "Valitse muunnettavan valuutan yksikkoa merkitseva kirjain:\n(e = euro, d = usd, p = gbp):\n";
		cin >> syote_yksikko;

		cout << "Valitse yksikko muunnosta varten:\n(e = euro, d = usd, p = gbp)\n";
		cin >> muunnos_yksikko;	// Asetetaan kayttajan syote toiseen muuttujaan
	}while (syote_yksikko == muunnos_yksikko);
	
	if (syote_yksikko == 'e') {
		cout << "Anna muunnettava luku euroissa:";
		cin >> annettu_valuutta;
			
	}
	 
}