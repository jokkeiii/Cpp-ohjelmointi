// 10. Tunti Viope 10 - 2
// Koodin toiminta selitettyna lyhyesti

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Tietue valtioiden tiedoista
struct Valtio 
{
    string nimi, johtaja;
    int asukasluku, pinta_ala;
};

// Vakio tietueen taulukkoa varten
const int VALTIOIDEN_LKM = 2;

int main() {
    setlocale(LC_ALL, "fi_FI");

    // Luodaan tietue Valtio kayttoon ja tehdaan siita taulukko
    Valtio kaikki_valtiot[VALTIOIDEN_LKM];

    // Syote kayttajalta
    for (int i = 0; i < VALTIOIDEN_LKM; i++)
    {
        cout << "Anna valtion " << (i + 1) << " nimi: ";
        cin >> kaikki_valtiot[i].nimi;

        cout << "Anna valtion " << (i + 1) << " asukasluku: ";
        cin >> kaikki_valtiot[i].asukasluku;

        cout << "Anna valtion " << (i + 1) << " pinta-ala: ";
        cin >> kaikki_valtiot[i].pinta_ala;

        cout << "Anna valtion " << (i + 1) << " johtaja: ";
        cin >> kaikki_valtiot[i].johtaja;

        cout << endl;
    }
    
    // Syotteen tulostus
    for (int i = 0; i < VALTIOIDEN_LKM; i++)
    {
        cout << "Valtio numero " << (i +1) << endl;

        cout << "Nimi: " << kaikki_valtiot[i].nimi << endl;

        cout << "Asukasluku: " << kaikki_valtiot[i].asukasluku << endl;

        cout << "Pinta-ala: " << kaikki_valtiot[i].pinta_ala << endl;

        cout << "Johtaja: " << kaikki_valtiot[i].johtaja << endl;

        cout << endl;
    }
    

    return 0;
}
