// 8. Tunti Viope 8 - 1
// Koodin toiminta selitettyna lyhyesti

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

unsigned long KertomaFunktio(int num){
    
    // Muuttuja tulosta varten
    unsigned long Kertoma = 1; 

    // Looppi laskee kertoman syotteen kertaa
    for (int i = 0; i < num; i++){

        // Luku kertaa (i + 1) eli kertomaan lisataan 
        Kertoma = Kertoma * (i + 1); 
    }
    
    return Kertoma;
}
int main() {
    setlocale(LC_ALL, "fi_FI");

    // Muutujien esittely
    int luku;
    unsigned long tulos; 

    // Syotteen kysyminen
    cout << "Anna kokonaisluku välille 0 - 16" << endl; 
    cin >> luku; 

    // Asetetaan aliohjelman tulos muuttujaan
    tulos = KertomaFunktio(luku);

    // Tulostetaan tekstit, luku ja tulos
    cout << "Luvun " << luku << " kertoma on " << tulos << endl; 

    return 0;
}
