// Harjoitustyo
// Hotellinvarausjarjestelma

#include<iostream>
#include<iomanip>
#include<string>
// Header tiedosto
#include<harjoitustyo.h>

using std::cout;
using std::cin;
using std::endl;
using std::string; 
using std::getline;


/* TODO

    roomnumbers random between 30-70
        huoneidenMaara
    price random between 80-100
        huoneHinta
*/


// Vakiot
const int MIN_VARAUKSEN_KESTO = 0;
const int MAX_VARAUKSEN_KESTO = 45;
const int HUONEIDEN_LKM = 300;
const int HINTA_PER_YO = 100;

// Tietueet
struct HotelliVaraukset
{
    string varaajan_koko_nimi = "Matti Malli";
    int huoneen_numero = 0, varauksen_kesto = 0;
};



int main() {
    setlocale(LC_ALL, "fi_FI");
    
    // Kutsutaan funktioita, joiden paluuarvo asetetaan muuttujiin
    // Funktiot maarittavat satunnaiset huonemaarat ja hinnan per yo
    int huoneiden_maara = randHuoneidenMaara();
    int hinta_per_yo = randHuoneHinta();

    HotelliVaraukset varaukset[HUONEIDEN_LKM];

    // varattava_huone syotetta varten
    int varattava_huone, count = 0; 
    char valikko;

    cout << "Tervetuloa!!" << endl;

    // Valikko
    do{
        // Kysytaan kayttajalta valikon valinta
        cout << "Mitä haluaisitte tehdä?" << endl << endl;
        cout << "#1 Varata uuden huoneen " << endl << "#0 Poistua ohjelmasta " << endl << ": ";
        cin >> valikko;
        cout << endl;

        // Valikko testit
        switch (valikko)
        {
        // Jos 1 varataan huone
        case '1':
            
            // Goto merkki 
            varaus:

            cout << "Minkä huoneen haluatte varata? (1-300)" << endl << ": ";
            cin >> varattava_huone;
            cout << endl; 

            // Syotteentarkastus. Jos annettu syote ei ole numero, se on 0
            // tai yli 300, kysytaan kayttajalta syote uudelleen
            if (cin.fail())
            {
                cout << "Antamanne syöte ei ole hyväksytty numero välilä 1-300." << endl;
                cout << endl;
                
                // Tyhjennetaan syote valimuisti
                cin.clear();
                cin.ignore(1000,'\n');

                goto varaus;

            }else if (varattava_huone <= 0 || varattava_huone > 300)
            {
                cout << "Valitettavasti meillä ei ole syöttämäänne huonetta tällä hetkellä käytössä." << endl;
                cout << endl;

                goto varaus;
            }
            
            // Silmukalla testataan jokaisen taulukon paikan tietue
            for (int i = 0; i < HUONEIDEN_LKM; i++)
            {   
                // Jos funktio palauttaa true, eli huone on varattu
                if(onkoHuoneVarattu(varaukset[i], varattava_huone))
                {
                    cout << "Valitettavasti huone " << varattava_huone << " on jo varattu." << endl;
                    cout << endl;

                    // Palataan merkkiin varaus
                    goto varaus;
                }
            }
            
            // Kutsutaan funktiota taulukon "count" tietueella
            luoVaraus(varaukset[count], varattava_huone);
            
            // Kutsutaan funktiota tulostamaan taulukon "count" tietueen
            tulostaVaraus(varaukset[count]);

            // Laskuri taulukkoon tallentamista varten
            count++;
            
            break;

        // Jos 0 poistutaan ohjelmasta
        case '0':

            cout << "Kiitoksia käynnistä ja tervetuloa uudelleen!" << endl << endl << endl;
            break;

        // Jos vaara valinta, while palauttaa takaisin alkuun
        default:

            // Jos syote ei ole 1 tai 0
            cout << "Valitettavasti valitsemanne valinta ei ole käytössä." << endl;
            cout << endl;

            // Tyhjennetaan syote valimuisti
            cin.clear();
            cin.ignore(1000,'\n');
            
            break;
        }

    // Tarkistetaan syote, jos 0, poistutaan muuten jatketaan
    } while (valikko != '0'); 

    return 0;
}

