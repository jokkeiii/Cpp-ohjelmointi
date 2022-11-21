// 10. Tunti Viope 10 - 3
// Koodin toiminta selitettyna lyhyesti

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


struct Opiskelija
{
    string etunimi, sukunimi, opiskelijanumero;
    int opintopisteet;
};

// "const Opiskelija &opiskelija" Vain luku-oikeus tietueen tietoihin
void tulostaOpiskelijanTiedot(const Opiskelija &opiskelija){

    cout << "Etunimi: " << opiskelija.etunimi << endl;

    cout << "Sukunimi: " << opiskelija.sukunimi << endl;

    cout << "Opiskelijanumero: " << opiskelija.opiskelijanumero << endl;

    cout << "Opintopisteet: " << opiskelija.opintopisteet << endl;
    
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    Opiskelija opiskelija0; 

    cout << "Anna opiskelijan etunimi: ";
    cin >> opiskelija0.etunimi;

    cout << "Anna opiskelijan sukunimi: ";
    cin >> opiskelija0.sukunimi;

    cout << "Anna opiskelijan opiskelijanumero: ";
    cin >> opiskelija0.opiskelijanumero;

    cout << "Anna opiskelijan opintopisteet: ";
    cin >> opiskelija0.opintopisteet;

    // Kutsutaan tietueen tiedoilla funktiota
    tulostaOpiskelijanTiedot(opiskelija0);
    
    return 0;
}

