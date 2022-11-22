// Harjoitustyo
// Hotellinvarausjarjestelma

#include<iostream>
#include<iomanip>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string; 

/* TODO

    Huonevaraus omaksi funktioksi

    Varauksen tallennus structina
    
*/

// Funktioiden prototyypit

// Vakiot
const int HUONEIDEN_LKM = 300;


int main() {
    setlocale(LC_ALL, "fi_FI");
    
    // varattava_huone ja varauksen kesto: syotetta varten
    int varattava_huone, varauksen_kesto, count = 0; 
    int varatut_huoneet[HUONEIDEN_LKM] = { 0 };
    char valikko;

    cout << "Tervetuloa!!" << endl;
    cout << "Mitä haluaisitte tehdä?" << endl << endl;

    // Valikko
    do{
        
        // Tarkistetaan onko kaikki 300 huonetta varattu 
        if (count < 299)
        {
            
            cout << R"(Jos haluatte varata uuden huoneen valitkaa " V " , jos haluatte poistua valitkaa " X " : )" << endl;
            cin >> valikko; 

            // Tarkistetaan syote, jos V, suoritetaan varaus
            if (valikko == 'V' || valikko == 'v')
            {   
                cout << "Minkä huoneen haluatte varata? (1-300) : ";
                cin >> varattava_huone;

                // TODO 
                // Tee tasta funktio
                
                // Syotteen tarkistus valilla 1-300
                if (varattava_huone >= 1 && varattava_huone <= 300)
                {
                    
                    // Silmukka jolla tarkastetaan onko annettu huone jo varattu
                    for (int i = 0; i < 300; i++)
                    {
                        // Jos huone on jo varattu kysytaan uusi huone
                        if (varattava_huone == varatut_huoneet[i])
                        {
                            cout << "Huone " << varattava_huone << " on valitettavasti jo varattu." << endl; 

                            cout << endl;

                            cout << "Minkä huoneen haluatte varata? (1-300) : ";
                            cin >> varattava_huone;
                        }
                        
                    }
                }

                // Asetetaan varattu huone taulukkoon
                varatut_huoneet[count] += varattava_huone;

                // Tulostetaan kyseinen huone taulukosta ja kysytaan majoituksen kesto
                cout << "Hienoa! Huone " << varatut_huoneet[count] << " on varattu teille. " << endl;
                cout << endl;
                cout << "Kuinka monta yötä haluatte majoittua? ";
                cin >> varauksen_kesto;

                // Syotteentarkastus, jos alle nolla tai yli 45 kysytaan uudelleen
                if (varauksen_kesto <= 0)
                {
                    cout << "Varaamme huoneita vähintään yhdeksi yöksi. " << endl << endl;
                    cout << "Kuinka monta yötä haluatte majoittua? ";
                    cin >> varauksen_kesto;

                }else if (varauksen_kesto >= 45)
                {
                    cout << "Valitettavasti emme voi varata huoneita 45 päivää enempää kerralla. " << endl << endl;
                    cout << "Kuinka monta yötä haluatte majoittua? ";
                    cin >> varauksen_kesto;
                }
                
                
                // Lasketaan majoituksen hinta ja tulostetaan se
                cout << endl;
                cout << "Tämä selvä!" << endl << "Majoituksen hinnaksi tulee: " << varauksen_kesto * 100 << " euroa." << endl << endl;

                // Laskuri taulukkoon tallentamista varten
                count++;
            }
            
        }
        else
        {
            cout << "Valitettavasti kaikki huoneemme on tällä hetkellä varattuina. " << endl << "Kiitos ja näkemiin! ";

            valikko = 'x';
        }

    // Tarkistetaan syote, jos p, poistutaan muuten jatketaan
    }
    while (!(valikko == 'x' || valikko == 'X')); 

    
    
    
    return 0;
}