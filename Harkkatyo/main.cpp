// Harjoitustyo
// Hotellinvarausjarjestelma

#include<iostream>
#include<iomanip>
#include<string>
// Header tiedosto "harjoitustyo.h"
#include "harjoitustyo.h"

using std::cout;
using std::cin;
using std::endl;
using std::string; 
using std::getline;


/* TODO
    
    main valikko funktioksi

    varausten hakeminen ja niiden tulostaminen 
    varausnumeron tai nimen avulla

    lopuksi poista debug coutit alusta

*/


int main() {
    // Otetaan ääkköset tulosteessa kayttoon
    setlocale(LC_ALL, "fi_FI");

    // Luodaan muuttujiin arvot satunnaisfunktioista
    // huoneiden_maara on parillinen luku valilta 40-300,
    // joka maaraa kaytettavissa olevat huoneet
    int huoneiden_maara = randHuoneidenMaara();

    // alennus_kerroin on varauksen loppusummaan tuleva alennus
    // Se voi olla 1 eli ei alennusta, 0,9 eli 10% alennus
    //  tai 0,8 eli 20% alennus
    float alennus_kerroin = randAlennuksenMaara();

    // Debuggaamista varten, muista poistaa
    cout << endl << "Huoneiden määrä on " << huoneiden_maara << endl << endl;
    cout << "Alennuskerroin on " << alennus_kerroin << endl << endl;

    // Taulukko tietueesta
    HuoneVaraukset varaukset[HUONEIDEN_MAARA_MAX];
    // varattava_huone syotetta varten
    int varattava_huone, count = 0; 
    // Paavalikon muuttuja
    int valikko;
    // Huoneennumeron valikkomuuttuja
    char varaus_valinta;

    cout << "Tervetuloa Hotelli Perustolaan!!" << endl;

    // Paavalikko
    do{
        
        // Kysytaan kayttajalta valikon valinta
        cout << "Mitä haluaisitte tehdä?" << endl << endl;
        
        cout << "#1 Varata uuden huoneen " << endl;
        cout << "#0 Poistua ohjelmasta " << endl << ": ";
        cin >> valikko;
        cout << endl;

        // Numeron tarkastus syotteesta eli jos syote ei ole numero
        if (cin.fail())
        {
            // Jos syote ei ole numero
            cout << "Valitettavasti valitsemanne valinta ei ole käytössä." << endl;
            cout << endl;

            // Tyhjennetaan syote valimuisti, jotta vaara syote ei tuota silmukkaa
            cin.clear();
            cin.ignore(1000,'\n');

        }else 
        {
        
            // Valikko testit
            switch (valikko)
            {
            // Jos 1 varataan huone
            case 1:
                // Tyhjennetaan syote valimuisti, jotta edellinen syote ei tuota silmukkaa
                cin.clear();
                cin.ignore(1000,'\n');
                
                // Kyseisen valikon paluumerkki
                HuoneenNumeroPaatos:

                cout << "Haluatteko valita itse huoneen numeron vai antaa koneen arpoa huoneen numeronne? " << endl;
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

                    cout << endl << "Minkä huoneen haluatte varata? (1-" << huoneiden_maara << ")" << endl << ": ";
                    cin >> varattava_huone;
                    cout << endl; 

                    // Syotteentarkastus. Jos annettu syote ei ole numero, se on 0
                    // tai yli huoneiden lkm, kysytaan kayttajalta syote uudelleen
                    if (cin.fail())
                    {
                        cout << "Antamanne syöte ei ole hyväksytty numero välilä 1-" << huoneiden_maara << "." << endl;
                        cout << endl;
                        
                        // Tyhjennetaan syote valimuisti
                        cin.clear();
                        cin.ignore(1000,'\n');

                        goto KayttajaVaraus;

                    }else if (varattava_huone <= 0 || varattava_huone > huoneiden_maara)
                    {
                        cout << "Valitettavasti meillä ei ole syöttämäänne huonetta tällä hetkellä käytössä." << endl;
                        cout << endl;

                        goto KayttajaVaraus;
                    }
                    
                    // Jos funktio palauttaa true, eli huone on varattu
                    if(onkoHuoneVarattu(varaukset[HUONEIDEN_MAARA_MAX], varattava_huone, huoneiden_maara))
                    {
                        cout << "Valitettavasti huone " << varattava_huone << " on jo varattu." << endl;
                        cout << endl;

                        // Palataan merkkiin varaus
                        goto KayttajaVaraus;
                    }
                    
                    
                    break;

                // Kayttaja antaa koneen valita huoneensa numeron
                case '2':
                    
                    // Goto rand valitsee huoneen numeron
                    KoneVaraus:
                    varattava_huone = randHuoneenNumero(huoneiden_maara);
 
                    // Jos funktio palauttaa true, eli huone on varattu
                    if(onkoHuoneVarattu(varaukset[HUONEIDEN_MAARA_MAX], varattava_huone, huoneiden_maara))
                    {
                        // Jos huone on varattu palataan merkkiin varaus
                        goto KoneVaraus;
                    }
                    
                    cout << endl;
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
                
                // Lopuksi luodaan satunnainen varausnumero funktiolla
                varaukset[count].varaus_numero = randVarausNumero(varaukset[HUONEIDEN_MAARA_MAX], huoneiden_maara);

                // Tulostetaan varauksen tiedot
                tulostaVaraus(varaukset[count], huoneiden_maara, alennus_kerroin);
                
                // Laskuri taulukkoon tallentamista varten
                count++;
                
                break;

            // Jos 0 poistutaan ohjelmasta
            case 0:

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
        } 

    // Tarkistetaan syote, jos 0, poistutaan muuten jatketaan
    } while (valikko != 0); 

    return 0;
}
