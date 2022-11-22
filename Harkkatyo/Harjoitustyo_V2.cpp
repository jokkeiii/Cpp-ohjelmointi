// Harjoitustyo
// Hotellinvarausjarjestelma

#include<iostream>
#include<iomanip>
#include<string>
#include<stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string; 

/* TODO

    Huonevaraus funktio

    onkoHuoneVarattu funktio
    
*/

// Funktioiden prototyypit
bool onkoHuoneVarattu(const HotelliVaraukset, int);
HotelliVaraukset luoVaraus(HotelliVaraukset, int);


// Vakiot
const int HUONEIDEN_LKM = 300;


// Tietueet
struct HotelliVaraukset
{
    string varaajan_nimi;
    int huoneen_numero, varauksen_kesto;
};


int main() {
    setlocale(LC_ALL, "fi_FI");
    
    HotelliVaraukset varaukset[HUONEIDEN_LKM] = {0};

    // varattava_huone syotetta varten
    int varattava_huone, count = 0; 
    char valikko;

    cout << "Tervetuloa!!" << endl;
    cout << "Mitä haluaisitte tehdä?" << endl << endl;

    // Valikko
    do{

        cout << R"(#1 Varata uuden huoneen \n#0 Poistua ohjelmasta \n: )";
        cin >> valikko;

        switch (valikko)
        {
        case '1':
            
            // Goto merkki 
            varaus:

            cout << "Minkä huoneen haluatte varata? (1-300) : ";
            cin >> varattava_huone;

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
            

            // Laskuri taulukkoon tallentamista varten
            count++;

            break;
        case '0':

            cout << "Kiitoksia käynnistä ja tervetuloa uudelleen!" << endl;
            break;
        default:

            cout << "Valitettavasti valitsemanne valinta ei ole käytössä." << endl;
            cout << endl;
            break;
        }

    // Tarkistetaan syote, jos 0, poistutaan muuten jatketaan
    }
    while (valikko != '0'); 

    return 0;
}


// Funktiolla luodaan varaus. Viitataan tiedot "main":ssa olevaan taulukkoon
HotelliVaraukset luoVaraus(HotelliVaraukset &tempVaraukset, int tempcount){
    
    int varattava_huone;

    // Tulostetaan kyseinen huone taulukosta ja kysytaan majoituksen kesto
    cout << "Hienoa! Huone " << varatut_huoneet[count] << " on varattu teille. " << endl;
    cout << endl;
    cout << "Kuinka monta yötä haluatte majoittua? ";
    cin >> varauksen_kesto;


    // Syotteentarkastus, jos alle nolla tai yli 45 kysytaan uudelleen
    cout << "Varaamme huoneita vähintään yhdeksi yöksi. " << endl << endl;
    cout << "Kuinka monta yötä haluatte majoittua? ";
    cin >> varauksen_kesto;

    cout << "Valitettavasti emme voi varata huoneita 45 päivää enempää kerralla. " << endl << endl;
    cout << "Kuinka monta yötä haluatte majoittua? ";
    cin >> varauksen_kesto;
    

    // Lasketaan majoituksen hinta ja tulostetaan se
    cout << endl;
    cout << "Tämä selvä!" << endl << "Majoituksen hinnaksi tulee: " << varauksen_kesto * 100 << " euroa." << endl << endl;

    return tempVaraukset;
}


// Funktio tarkistaa onko huone jo varattu
bool onkoHuoneVarattu(const HotelliVaraukset &tempVaraukset, int tempvarattava_huone){

    if (tempVaraukset.huoneen_numero == tempvarattava_huone)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}