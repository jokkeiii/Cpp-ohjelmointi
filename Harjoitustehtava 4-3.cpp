// 4. Tunti - Viope 4 - 3 
// Tulosteen tulostaminen syotteen n kertaa seka lukujonon 1-15 tulostaminen
#include<iostream>

using namespace std;

int main() {
	
    int luku, n = 1, h = 1; // Esitellaan muuttujat: syotte = luku, seka n ja h joiden avulla maaritetaan silmukan pituus

    cout << "Anna luku: ";
    cin >> luku;

    while (n <= luku) // Silmukka toistetaan "luku" kertaa
    {
        cout << "Hello World!" << endl; // Tulostetaan jonka jalkeen lisataan tarkistuslukuun yksi
        n++;
    }

    while (h <= 15) // Silmukka tulostaa lukujonon 1-15, koska h on alussa 1 ja siihen tulee + 1 joka silmukan lopussa
    {
        cout<< h++ << " ";
    }
    
	return 0;
}