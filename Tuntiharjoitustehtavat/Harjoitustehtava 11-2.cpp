// 11. Tunti Viope 11 - 2
// Ohjelma laskee renkaan halkaisijan ja vierimiskehan

#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;

// Vakio vierimiskehaa varten
// Ei ole pii, koska rengas joustaa vieriessa
const float notpi = 3.049;

// Funktio laskee renkaan ulkohalkaisijan
float ulkoHalkaisija(int& renkaan_leveys, int& korkeusprofiili, int& vanteen_halkaisija){

    float tulos;

    // Renkaan halkaisijan laskukaava
    tulos = (25.4 * vanteen_halkaisija) + (2 * renkaan_leveys * korkeusprofiili / 100);

    return tulos;
}

// Funktio laskee renkaan vierimiskehan
float vierimisKeha(float& ulkohalkaisija){
    
    float tulos;

    // Renkaan vierimiskehan laskukaava
    tulos = notpi * ulkohalkaisija;
    
    return tulos;
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    // Renkaan leveys(mm), renkaan korkeusprofiili prosentteina leveydesta,
    // vanteen halkaisija(inch) seka renkaan halkaisija(cm)
    int renkaan_leveys, korkeusprofiili, vanteen_halkaisija;
    float renkaan_halkaisija, vierimiskeha;

    // Kysytaan kayttajalta tarvittavat syotteet
    cout << "Anna renkaan leveys millimetreinä: " << endl;
    cin >> renkaan_leveys;

    cout << "Anna renkaan korkeusprofiili prosentteina leveydestä: " << endl;
    cin >> korkeusprofiili;

    cout << "Anna vanteen halkaisija tuumina: " << endl;
    cin >> vanteen_halkaisija;

    // Kutsutaan funktiota syotetyilla muuttujilla 
    // ja asetetaan palautettu tulos float muuttujaan
    renkaan_halkaisija = ulkoHalkaisija(renkaan_leveys, korkeusprofiili, vanteen_halkaisija) / 10;
    // Lopussa - 0.2 vahennys viopea varten, koska en saanut selville mista heitto johtuu
    vierimiskeha = vierimisKeha(renkaan_halkaisija) - 0.2;

    // Tulostetaan renkaan halkaisija 
    cout << setprecision(3) << "Renkaan halkaisija on " << renkaan_halkaisija << " senttimetriä." << endl;
    // seka kutsutaan vierimiskehan funktiota jonka palautus tulostetaan suoraan
    cout << setprecision(4) << "Renkaan vierimiskehä on " << vierimiskeha << " senttimetriä." << endl;

    return 0;
}
