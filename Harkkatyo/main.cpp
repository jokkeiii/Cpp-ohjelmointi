// Harjoitustyo
// Hotellinvarausjarjestelma

#include<iostream>
#include<iomanip>
#include<string>
// Header tiedosto
#include "harjoitustyo.h"

using std::cout;
using std::cin;
using std::endl;
using std::string; 
using std::getline;


/* TODO
    
    arvo huoneen numero vapaana olevista huoneista

    rand lkm ja hinta globaaleiksi?

*/


int main() {
    setlocale(LC_ALL, "fi_FI");

    // Luodaan objekti luokasta varausMuuttujat ja kutsutaan consturct
    // funktiota arvoilla 0
    varausMuuttujat varausten_muuttujat(0, 0);

    cout << "Huoneiden määrä on " << varausten_muuttujat.huoneiden_lkm << endl << endl;
    cout << "Hinta on " << varausten_muuttujat.hinta_per_yo << endl << endl;

    // Taulukko tietueesta
    HuoneVaraukset varaukset[HUONEIDEN_LKM];
    // varattava_huone syotetta varten
    int varattava_huone, count = 0; 
    // Valikon muuttuja
    char valikko;
    // Huoneennumeron valikkomuuttuja
    char varaus_valinta;

    cout << "Tervetuloa!!" << endl;

    // Valikko
    do{
        // Kysytaan kayttajalta valikon valinta
        cout << "Mitä haluaisitte tehdä?" << endl << endl;
        
        cout << "#1 Varata uuden huoneen " << endl;
        cout << "#0 Poistua ohjelmasta " << endl << ": ";
        cin >> valikko;
        cout << endl;

        // Valikko testit
        switch (valikko)
        {
        // Jos 1 varataan huone
        case '1':
            
            // Goto merkki jos tuleva valinta ei oikea
            HuoneenNumeroPaatos:

            cout << "Haluatteko valita itse huoneen numeron vai antaa koneen päättää puolestanne? " << endl;
            cout << endl << "#1 Valitsen itse huoneen numeron " << endl;
            cout << "#2 Annan koneen päättää huoneen numeron " << endl << ": "; 
            cin >> varaus_valinta;

            switch (varaus_valinta)
            {
            // Kayttaja valitsee itse huoneen numeron
            case '1':
                
                // Tyhjennetaan syote valimuisti, jotta
                // valtetaan numeroiden jatkuminen seuraavaan syotteeseen
                cin.clear();
                cin.ignore(1000,'\n');

                /* TODO

                    tee tasta funktio
                
                */

                // Kayttajan om valintainen huonenumeron varaus
                KayttajaVaraus:

                cout << "Minkä huoneen haluatte varata? (1-" << HUONEIDEN_LKM << ")" << endl << ": ";
                cin >> varattava_huone;
                cout << endl; 

                // Syotteentarkastus. Jos annettu syote ei ole numero, se on 0
                // tai yli huoneiden lkm, kysytaan kayttajalta syote uudelleen
                if (cin.fail())
                {
                    cout << "Antamanne syöte ei ole hyväksytty numero välilä 1-" << HUONEIDEN_LKM << "." << endl;
                    cout << endl;
                    
                    // Tyhjennetaan syote valimuisti
                    cin.clear();
                    cin.ignore(1000,'\n');

                    goto KayttajaVaraus;

                }else if (varattava_huone <= 0 || varattava_huone > HUONEIDEN_LKM)
                {
                    cout << "Valitettavasti meillä ei ole syöttämäänne huonetta tällä hetkellä käytössä." << endl;
                    cout << endl;

                    goto KayttajaVaraus;
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
                        goto KayttajaVaraus;
                    }
                }
                
                
                break;

            // Kayttaja antaa koneen valita huoneensa numeron
            case '2':
                
                // Goto rand valitsee huoneen numeron
                KoneVaraus:
                varattava_huone = randHuoneenNumero();

                // Silmukalla testataan jokaisen taulukon paikan tietue
                for (int i = 0; i < HUONEIDEN_LKM; i++)
                {   
                    // Jos funktio palauttaa true, eli huone on varattu
                    if(onkoHuoneVarattu(varaukset[i], varattava_huone))
                    {
                        // Palataan merkkiin varaus
                        goto KoneVaraus;
                    }
                }
                
                break;

            // Jos vaara valinta, while palauttaa takaisin alkuun
            default:
                // Jos syote ei ole 1 tai 2
                cout << endl << "Valitettavasti valitsemanne valinta ei ole käytössä." << endl;
                cout << endl;

                // Tyhjennetaan syote valimuisti
                cin.clear();
                cin.ignore(1000,'\n');
                
                goto HuoneenNumeroPaatos;

                break;
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

            cout << endl << "Kiitoksia käynnistä ja tervetuloa uudelleen!" << endl << endl;
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

