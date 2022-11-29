// Harjoitustyo
// Hotellinvarausjarjestelma

#include<iostream>
#include<iomanip>
#include<string>
#include<stdio.h>
#include<limits> 

using std::cout;
using std::cin;
using std::endl;
using std::string; 
using std::getline;


/* TODO

    int input validation
    
    roomnumbers random between 30-70

    price random between 80-100

*/


// Vakiot
const int HUONEIDEN_LKM = 300;
const int MIN_VARAUKSEN_KESTO = 0;
const int MAX_VARAUKSEN_KESTO = 45;
const int HINTA_PER_YO = 100;

// Tietueet
struct HotelliVaraukset
{
    string varaajan_koko_nimi = "Matti Malli";
    int huoneen_numero = 0, varauksen_kesto = 0;
};

// Funktioiden prototyypit
bool onkoHuoneVarattu(const HotelliVaraukset &Varaukset, int fvarattava_huone);
HotelliVaraukset luoVaraus(HotelliVaraukset &Varaukset, int fvarattava_huone);
void tulostaVaraus(const HotelliVaraukset &Varaukset);

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    HotelliVaraukset varaukset[HUONEIDEN_LKM];

    // varattava_huone syotetta varten
    int varattava_huone, count = 0; 
    char valikko;

    cout << "Tervetuloa!!" << endl;
    cout << "Mitä haluaisitte tehdä?" << endl << endl;

    // Valikko
    do{

        cout << "#1 Varata uuden huoneen " << endl << "#0 Poistua ohjelmasta " << endl << ": ";
        cin >> valikko;
        cout << endl;

        switch (valikko)
        {
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

                cin.clear();
                cin.ignore();

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
        case '0':

            cout << "Kiitoksia käynnistä ja tervetuloa uudelleen!" << endl;
            break;
        default:

            // Jos syote ei ole 1 tai 0
            cout << "Valitettavasti valitsemanne valinta ei ole käytössä." << endl;
            cout << endl;
            break;
        }

    // Tarkistetaan syote, jos 0, poistutaan muuten jatketaan
    }
    while (valikko != '0'); 

    return 0;
}


// Funktiolla luodaan varaus. Viitataan tiedot "main":ssa olevan taulukon "count" tietueeseen
HotelliVaraukset luoVaraus(HotelliVaraukset &Varaukset, int fvarattava_huone){
    
    char fvalikko;

    // Asetetaan syotetty huone tietueeseen
    Varaukset.huoneen_numero = fvarattava_huone;

    // Tulostetaan kyseinen huone taulukosta ja kysytaan majoituksen kesto
    cout << "Hienoa! Huone " << Varaukset.huoneen_numero << " on varattu teille. " << endl;
    cout << endl;

    ajanvaraus:

    cout << "Kuinka monta yötä haluatte majoittua? " << endl << ": ";
    cin >> Varaukset.varauksen_kesto;
    cout << endl;

    // Jos alle nolla tai yli 45 kysytaan uudelleen
    if (Varaukset.varauksen_kesto <= MIN_VARAUKSEN_KESTO)
    {
        cout << "Varaamme huoneita vähintään yhdeksi yöksi. " << endl << endl;
        goto ajanvaraus;

    } else if (Varaukset.varauksen_kesto > MAX_VARAUKSEN_KESTO)
    {
        cout << "Valitettavasti emme voi varata huoneita 45 päivää enempää kerralla. " << endl << endl;
        goto ajanvaraus;

    }
    
    nimenanto:

    cout << "Millä nimellä varaus tallennetaan? " << endl << ": ";
    getline (cin, Varaukset.varaajan_koko_nimi);
    cout << endl; 

    nimisyote:

    cout << "Kiitoksia! Annoitte nimen: " << Varaukset.varaajan_koko_nimi << ". " << endl; 
    cout << "Onko nimi oikein? 1 = Kyllä, 2 = Ei, haluan antaa sen uudelleen. " << endl << ": ";
    cin >> fvalikko;
    cout << endl;

    switch (fvalikko)
    {
    case '1':

        cout << endl;
        break;
    case '2':

        goto nimenanto;
        break;
    default:

        cout << "Valitettavasti valitsemanne valinta ei ole käytössä." << endl;
        cout << endl;
        goto nimisyote;
        break;
    }


    return Varaukset;
}


// Funktio tarkistaa onko huone jo varattu
bool onkoHuoneVarattu(const HotelliVaraukset &Varaukset, int fvarattava_huone){

    // Jos huone on varattu palautetaan true
    if (Varaukset.huoneen_numero == fvarattava_huone)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}

// Funktio tulostaa syotetyn varauksen tiedot seka laskee varauksen hinnan
void tulostaVaraus(const HotelliVaraukset &Varaukset){

    cout << "\tHienoa! Tässä on syottämäsi varauksen tiedot" << endl << endl;
    cout << "\tVaraajan nimi: " << Varaukset.varaajan_koko_nimi << endl;
    cout << "\tVaratun huoneen numero: " << Varaukset.huoneen_numero << endl;
    cout << "\tVarauksen kesto: " << Varaukset.varauksen_kesto << " yötä." << endl;
    // Lasketaan oiden maara * "HINTA_PER_YO"
    cout << "\tVarauksenne loppusumma: " << Varaukset.varauksen_kesto * HINTA_PER_YO << " euroa." << endl << endl;
}