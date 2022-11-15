// 9. Tunti Viope 9 - 1
// Kokonaislukutaulukkoharjoitus

#include<iostream>

using std::cout;
using std::cin;
using std::endl;


int main() {
    setlocale(LC_ALL, "fi_FI");
    
    // Kokonaislukutaulukko ja "tulos" muuttuja keskiarvoa varten
    int taulukko[10], tulos = 0;

    // Silmukka, jossa kysytaan syote ja asetetaan se taulukkoon
    for (int i = 0; i < 10; i++)
    {
        cout << "Anna tallennettava tenttitulos: ";
        cin >> taulukko[i];
    }

    // Tulosteen muotoili
    cout << endl; 

    // Tulostetaan taulukon numerot
    for (int i = 0; i < 10; i++)
    {   
        cout << "Tenttitulos " << i + 1 << " on: " << taulukko[i] << endl;
    }

    // Summataan "tulos" muuttujaan kaikki taulukon numerot
    for (int i = 0; i < 10; i++)
    {
        tulos += taulukko[i]; 
    }
    
    // Lasketaan ja tulostetaan taulukon keskiarvo float-tyyppisena
    cout << "Tenttitulosten keskiarvo on: " << tulos / 10.0;

    return 0;
}
