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

    varausten lopettaminen, kun kaikki huonetyypin huoneet ovat jo varattu

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
    // Huonetyypin valinta
    int huone_tyyppi_valinta;
    // Huoneennumeron valikkomuuttuja
    char varaus_valinta;
    // Huonetyyppi saatavuus tarkastamiseen
    bool kaikki_huoneet_varattu = false;

    cout << "Tervetuloa Hotelli Perustolaan!!" << endl;

    // Paavalikko
    do{
        
        // Kysytaan kayttajalta valikon valinta
        cout << "Mitä haluaisitte tehdä?" << endl << endl;
        
        cout << "#1 Varata uuden huoneen " << endl;
        cout << "#2 Hakea varauksia varausnumerolla " << endl;
        cout << "#0 Poistua ohjelmasta " << endl << ": ";
        cin >> valikko;
        cout << endl;

        // Numerontarkastus syotteesta eli jos syote ei ole numero
        if (cin.fail())
        {
            // Jos syote ei ole numero
            cout << "Valitettavasti valitsemanne valinta ei ole käytössä." << endl;
            cout << endl;

            // Tyhjennetaan syote valimuisti, jotta vaara syote ei tuota silmukkaa
            cin.clear();
            cin.ignore(1000,'\n');
        
        // Jos syote on numero
        }else 
        {
        
            // Paavalikko testit
            switch (valikko)
            {
            // Jos 1 varataan huone
            case 1:
                
                // Tyhjennetaan syote valimuisti, jotta edellinen syote ei vuoda seuraavaan syotteeseen
                cin.clear();
                cin.ignore(1000,'\n');

                // Testataan onko kaikki huonetyypin huoneet varattuna
                do
                {
                    // Kysytaan kayttajalta huonetyyppi 1 vai 2 hengen huone
                    do
                    {

                        cout << "Haluatteko varata \n\n#1 yhden hengen vai \n#2 kahden hengen huoneen? " << endl;
                        cout << ": ";
                        cin >> huone_tyyppi_valinta;

                        // Tarkastetaan, etta syote on numero
                        if (cin.fail() || (huone_tyyppi_valinta != 1 && huone_tyyppi_valinta != 2))
                        {
                            // Jos syote ei ole numero
                            cout << endl << "Valitettavasti valitsemanne valinta ei ole käytössä." << endl;
                            cout << endl;

                        }

                        // Tyhjennetaan syote valimuisti, jotta edellinen syote ei tuota silmukkaa
                        cin.clear();
                        cin.ignore(1000, '\n');

                        // Jos huone_tyyppi_valinta ei ole 1 tai 2 
                    } while (huone_tyyppi_valinta != 1 && huone_tyyppi_valinta != 2);
                    
                    // Tarkastetaan funktiolla ettei jokainen huonetyypin huone ole jo varattuna  
                    if (onkoTyypinHuoneetVarattu(varaukset, huoneiden_maara, huone_tyyppi_valinta))
                    {
                        cout << "\nValitettavasti kaikki " << huone_tyyppi_valinta << " hengen huoneet ovat jo varattuna. \n";

                        // Asetetaan muuttuja true, jota do while testaa
                        kaikki_huoneet_varattu = true;

                    } else
                    {
                        // Asetetaan muuttuja false, jotta voidaan jatkaa ohjelmaa
                        kaikki_huoneet_varattu = false;
                    }
                    

                } while(kaikki_huoneet_varattu);

                // Kyseisen valikon paluumerkki
                HuoneenNumeroPaatos:

                cout << "\nHaluatteko valita itse huoneen numeron vai antaa koneen arpoa huoneen numeronne? " << endl;
                cout << "\n#1 Valitsen itse huoneen numeron " << endl;
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

                    // Kayttajan omavalintainen huonenumeron varaus
                    KayttajaVaraus:

                    // Jos kayttaja haluaa yhden hengen huoneen
                    if (huone_tyyppi_valinta == 1)
                    {   
                        // Yhden hengen huoneet ovat ensimmainen puolisko huoneista eli huoneiden_maara / 2
                        cout << endl << "Minkä huoneen haluatte varata? (1-" << huoneiden_maara / 2 << ")" << endl << ": ";
                        cin >> varattava_huone;
                        cout << endl;

                        // Syotteentarkastus. Jos annettu syote ei ole numero, se on alle 1
                        // tai yli yhden hengen huoneiden numeroiden, kysytaan kayttajalta syote uudelleen
                        if (cin.fail())
                        {
                            cout << "Antamanne syöte ei ole hyväksytty numero välilä 1-" << huoneiden_maara / 2 << "." << endl;
                            cout << endl;
                            
                            // Tyhjennetaan syote valimuisti
                            cin.clear();
                            cin.ignore(1000,'\n');

                            goto KayttajaVaraus;

                        }else if (varattava_huone < 1 || varattava_huone > (huoneiden_maara / 2))
                        {
                            cout << "Valitettavasti meillä ei ole syöttämäänne yhden hengen huonetta tällä hetkellä käytössä." << endl;
                            cout << endl;

                            goto KayttajaVaraus;
                        }
                        
                        // Jos funktio palauttaa true, eli huone on varattu
                        if(onkoHuoneVarattu(varaukset, varattava_huone, huoneiden_maara))
                        {
                            cout << "Valitettavasti huone " << varattava_huone << " on jo varattu." << endl;
                            cout << endl;

                            // Palataan merkkiin varaus
                            goto KayttajaVaraus;
                        }

                    // Jos kayttaja haluaa kahden hengen huoneen
                    }else 
                    {
                        cout << endl << "Minkä huoneen haluatte varata? (" << huoneiden_maara / 2 + 1 << "-" << huoneiden_maara << ")" << endl << ": ";
                        cin >> varattava_huone;
                        cout << endl;

                        // Syotteentarkastus. Jos annettu syote ei ole numero, se on alle kahden hengen huoneiden numerot
                        // tai yli huoneiden_maara, kysytaan kayttajalta syote uudelleen
                        if (cin.fail())
                        {
                            cout << "Antamanne syöte ei ole hyväksytty numero välilä " << huoneiden_maara / 2 + 1 << "-" << huoneiden_maara << "." << endl;
                            cout << endl;
                            
                            // Tyhjennetaan syote valimuisti
                            cin.clear();
                            cin.ignore(1000,'\n');

                            goto KayttajaVaraus;

                        }else if (varattava_huone <= (huoneiden_maara / 2) || varattava_huone > huoneiden_maara)
                        {
                            cout << "Valitettavasti meillä ei ole syöttämäänne huonetta tällä hetkellä käytössä." << endl;
                            cout << endl;

                            goto KayttajaVaraus;
                        }
                        
                        // Jos funktio palauttaa true, eli huone on varattu
                        if(onkoHuoneVarattu(varaukset, varattava_huone, huoneiden_maara))
                        {
                            cout << "Valitettavasti huone " << varattava_huone << " on jo varattu." << endl;
                            cout << endl;

                            // Palataan merkkiin varaus
                            goto KayttajaVaraus;
                        }
                    }

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
                    if(onkoHuoneVarattu(varaukset, varattava_huone, huoneiden_maara))
                    {
                        cout << "Valitettavasti huone " << varattava_huone << " on jo varattu." << endl;
                        cout << endl;

                        // Palataan merkkiin varaus
                        goto KayttajaVaraus;
                    }
                    
                    
                    break;

                // Kayttaja antaa koneen valita huoneensa numeron
                case '2':
                    
                    // Goto arpafunktio valitsee huoneen numeron
                    KoneVaraus:

                    varattava_huone = randHuoneenNumero(huoneiden_maara, huone_tyyppi_valinta);
 
                    // Jos funktio palauttaa true, eli huone on varattu
                    if(onkoHuoneVarattu(varaukset, varattava_huone, huoneiden_maara))
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
                luoVaraus(varaukset[count], varattava_huone, huoneiden_maara, alennus_kerroin);
                
                // Lopuksi luodaan satunnainen varausnumero funktiolla
                varaukset[count].varaus_numero = randVarausNumero(varaukset, huoneiden_maara);
                
                // Tulostetaan varauksen tiedot
                tulostaVaraus(varaukset[count], alennus_kerroin);
                
                // Laskuri taulukkoon tallentamista varten
                count++;
                
                break;
            // Jos paavalikon valinta on 2 
            case 2:
                
                // Tarkastetaan onko yhtakaan varausta viela tehty,
                // jos count = 0, ei varauksia ole tehty
                if (count == 0)
                {
                    cout << "Yhtäkään varausta ei ole vielä tehty! " << endl << endl;

                // Jos varauksia on jo tehty kutsutaan funktiota, jolla kayttaja voi hakea varauksia
                } else
                {
                    varausHaku(varaukset, huoneiden_maara, alennus_kerroin);
                }
                
                break;

            // Jos 0 poistutaan ohjelmasta
            case 0:

                cout << endl << "Kiitoksia käynnistä ja tervetuloa uudelleen!" << endl << endl;
                break;

            // Jos vaara valinta, while palauttaa takaisin alkuun
            default:

                // Jos syote ei ole 1, 2 tai 0
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
