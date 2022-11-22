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
    
*/

// Funktioiden prototyypit
bool onkoHuoneVarattu(const HotelliVaraukset);
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

    // varattava_huone ja varauksen kesto: syotetta varten
    int count = 0; 
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
            
            // Kutsutaan funktiota, jolla luodaan varaus
            luoVaraus(varaukset[count], count);


            // Laskuri taulukkoon tallentamista varten
            count++;

            break;
        case '0':

            cout << "Kiitoksia käynnistä ja tervetuloa uudelleen!" << endl;
            break;
        default:

            cout << "Valitettavasti valitsemanne merkki ei ole käytössä." << endl;
            cout << endl;
            break;
        }

    // Tarkistetaan syote, jos p, poistutaan muuten jatketaan
    }
    while (valikko != '0'); 

    
    
    
    return 0;
}

// Funktiolla luodaan varaus. Viitataan tiedot "main":ssa olevaan taulukkoon
HotelliVaraukset luoVaraus(HotelliVaraukset &tempVaraukset, int count){



    return tempVaraukset;
}


bool onkoHuoneVapaa(const HotelliVaraukset &tempVaraukset){

    if (/* condition */)
    {
        return false;
    } 
    else
    {
        return true;
    }
    
}