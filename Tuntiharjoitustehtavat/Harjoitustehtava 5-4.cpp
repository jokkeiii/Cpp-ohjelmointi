// 5. Tunti Viope 5 - 4
// While –silmukan käyttöä. Mäkihypyn pisteytys
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

    int i = 1;
	float tyylipisteet = 0, tuomaripisteet, pituus, summa = 0;

    // Kysytaan hypyn pituus
    cout << "Hypyn pituus: ";
    cin >> pituus;

    // Kaydaan lapi 1.-6. tuomari lapi
	while (i < 6)
	{
		// Kysytaan yksittaisen tuomarin pisteet
		cout << "Tuomarin " << i++ << " pisteet: ";
		cin >> tuomaripisteet; 
		
		// Jos annetut pisteet ovat alle 0 tai yli 20 
		// kysytaan kyseisen tuomarin pisteet uudelleen
		if (tuomaripisteet < 0 || tuomaripisteet > 20)
		i--;
		
        // Lisataan pisteet tyylipisteisiin
		else {
			tyylipisteet += tuomaripisteet;
		}
	}
    // Lasketaan ja tulostetaan lopulliset pisteet
    summa = tyylipisteet + 0.9*pituus;

    cout << "Hypyn pisteet: " << summa;

    return 0;
}
