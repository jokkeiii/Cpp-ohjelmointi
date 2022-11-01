// 7. Tunti Viope 7 - 3
// Koodin toiminta selitettyna lyhyesti

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

float MatkanHinta(float, float, float);

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    float matka, kulutus, hinta;

    cout << "Anna autolla ajettava matka kilometrina: ";
    cin >> matka;

    cout << "Anna auton polttoaineen kulutus sadalla kilometrilla: "; 
    cin >> kulutus;

    cout << "Anna polttoaineen hinta: "; 
    cin >> hinta; 

    cout << "Autolla ajettavan matkan polttoainekulut ovat: " << MatkanHinta(matka, kulutus, hinta) << " euroa." << endl;

    return 0;
}

float MatkanHinta(float km, float e_kulutus, float litra_hinta){
    return km / 100 * e_kulutus * litra_hinta;
}