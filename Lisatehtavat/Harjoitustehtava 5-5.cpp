// 5. Tunti Viope 5 - 5
// Koodin toiminta selitettyna lyhyesti

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    setlocale(LC_ALL, "fi_FI");

	float tyylipisteet = 0, pituus = 0, summa = 0;
    float tuomaripisteet[5];
    float max = 0, min = 20;

    // Kysytaan hypyn pituus
    cout << "Hypyn pituus: ";
    cin >> pituus;

    // Kaydaan lapi 1.-6. tuomari lapi
	for (int i = 0; i < 5; i++)
    {
        // Kysytaan yksittaisen tuomarin pisteet
		cout << "Tuomarin " << i + 1 << " pisteet: ";
		cin >> tuomaripisteet[i]; 
		
		// Jos annetut pisteet ovat alle 0 tai yli 20 
		// kysytaan kyseisen tuomarin pisteet uudelleen
		if (tuomaripisteet[i] < 0 || tuomaripisteet[i] > 20){
		    i--;
		}
        // Lisataan pisteet tyylipisteisiin
		else {
			tyylipisteet += tuomaripisteet[i];
		}
    }
    
    // Selvitetaan ja asetetaan muuttujiin taulukon min ja max arvot
    for(int i = 0; i < 5; i++){

        // Jos taulukon luku on suurempi kuin max arvo, asetetaan se muuttujaan
        if(max < tuomaripisteet[i]){
            max = tuomaripisteet[i];
        }
        // Jos taulukon luku on pienempi kuin min arvo, asetetaan se muuttujaan
        else if(min > tuomaripisteet[i]){
            min = tuomaripisteet[i];
        }
    }

    // Lasketaan ja tulostetaan lopulliset pisteet
    summa = tyylipisteet - (min + max) + 0.9 * pituus;

    cout << "Hypyn pisteet: " << summa;

    return 0;
}
