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


// Funktiolla luodaan varaus. Viitataan tiedot "main":ssa olevan taulukon "i" tietueeseen
HuoneVaraukset luoVaraus(HuoneVaraukset &Varaukset, int fvarattava_huone){
    
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
    
    // Syotteentarkastus. Jos annettu syote ei ole numero, se on <= 0
    // tai yli 300, kysytaan kayttajalta syote uudelleen
    if (cin.fail())
    {
        cout << "Antamanne syöte ei ole hyväksytty numero! " << endl;
        cout << endl;

        // Tyhjennetaan syote valimuisti
        cin.clear();
        cin.ignore(1000,'\n');

        goto ajanvaraus;

        // Jos alle nolla 
    } else if (Varaukset.varauksen_kesto <= VARAUKSEN_KESTO_MIN)
    {
        cout << "Valitettavasti meillä ei ole syöttämäänne huonetta tällä hetkellä käytössä." << endl;
        cout << endl;

        goto ajanvaraus;
        // tai yli 45 kysytaan uudelleen
    } else if (Varaukset.varauksen_kesto > VARAUKSEN_KESTO_MAX)
    {
        cout << "Valitettavasti emme voi varata huoneita 45 päivää enempää kerralla. " << endl << endl;
        goto ajanvaraus;

    }else
    {
        cout << "Kiitoksia! Varauksenne on " << Varaukset.varauksen_kesto << " yötä." << endl << endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }

    // Kysytaan kayttajalta etu ja sukunimi
    nimenanto:

    cout << "Millä nimellä varaus tallennetaan? (Antakaa nimenne ilman ääkkösiä!)" << endl << ": ";
    getline (cin, Varaukset.varaajan_koko_nimi);
    cout << endl; 

    // Tulostetaan syote ja varmistetaan kayttajalta etta nimi on oikein
    nimisyote:

    cout << "Kiitoksia! Annoitte nimen: " << Varaukset.varaajan_koko_nimi << endl; 
    cout << "Onko nimi oikein? 1 = Kyllä, 2 = Ei, haluan antaa sen uudelleen. " << endl << ": ";
    cin >> fvalikko;
    cout << endl;

    // Testataan kayttajan syote
    switch (fvalikko)
    {
    case '1':
        // Jos nimi on oikein jatketaan ohjelmaa
        cout << endl;
        break;
    case '2':
        // Tyhjennetaan syote valimuisti
        cin.clear();
        cin.ignore(1000,'\n');

        goto nimenanto;

        break;
    default:
        // Jos syote ei ole 1 tai 2
        cout << "Valitettavasti valitsemanne valinta ei ole käytössä." << endl;
        cout << endl;
        
        // Tyhjennetaan syote valimuisti
        cin.clear();
        cin.ignore(1000,'\n');
        
        // Siirrytaan takaisin kysymaan syote
        goto nimisyote;

        break;
    }


    return Varaukset;
}


// Funktio tarkistaa onko huone jo varattu
bool onkoHuoneVarattu(const HuoneVaraukset &Varaukset, int fvarattava_huone){

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
void tulostaVaraus(const HuoneVaraukset &Varaukset, int hinta_per_yo){

    cout << "\tHienoa! Tässä on syottämäsi varauksen tiedot: " << endl << endl;
    cout << "\tVaraajan nimi: " << Varaukset.varaajan_koko_nimi << endl;
    cout << "\tVaratun huoneen numero: " << Varaukset.huoneen_numero << endl;
    cout << "\tVarauksen kesto: " << Varaukset.varauksen_kesto << " yötä" << endl;
    // Lasketaan oiden maara * "HINTA_PER_YO"
    cout << "\tVarauksenne loppusumma: " << Varaukset.varauksen_kesto * hinta_per_yo << " euroa" << endl << endl << endl;
}


// Funktio tuottaa satunnaisen huonemaaran valilla 30-70
int randHuoneidenMaara(){
    // Randin siemennys, randin vakio yliajetaan ajasta
    srand(time(NULL));
    
    int f_huoneiden_lkm = 0;

    // Silmukkaa ajetaan kunnes rand antaa tulokseksi yli 30 ja alle 70
    do
    {   
        // Randin antama tulos jaetaan 70, jonka jakojaannos + 1 asetetaan muuttujaan
        // jakojaannos + 1, jotta voidaan paasta 70 eika jakojaannos jaa maksimissaan 69
        f_huoneiden_lkm = rand() % RAND_HUONE_MAX + 1;
    
    } while (!(f_huoneiden_lkm >= RAND_HUONE_MIN && f_huoneiden_lkm <= RAND_HUONE_MAX));

    // Palautetaan "suodatettu" tulos
    return f_huoneiden_lkm;
}


// Funktio tuottaa satunnaisen hinnan valilla 80-100

int randHuoneHinta(){
    // Randin siemennys, randin vakio yliajetaan ajasta
    srand(time(NULL)); 
    
    int f_hinta_per_yo = 0;
    
    // Silmukkaa ajetaan kunnes rand antaa tulokseksi yli 80 ja alle 100
    do
    {
        f_hinta_per_yo = rand() % RAND_HINTA_MAX + 1; 

    } while (!(f_hinta_per_yo >= RAND_HINTA_MIN && f_hinta_per_yo <= RAND_HINTA_MAX));

    // Palautetaan "suodatettu" tulos
    return f_hinta_per_yo;
}

//
int randHuoneenNumero(int huoneiden_maara){
    // Randin siemennys, randin vakio yliajetaan ajasta
    srand(time(NULL));
    
    int f_huone_numero = 0;

    // Silmukkaa ajetaan kunnes rand antaa tulokseksi yli 30 ja alle 70
    do
    {   
        // Randin antama tulos jaetaan huoneiden_maara, jonka jakojaannos + 1 asetetaan muuttujaan
        // jakojaannos + 1, jotta voidaan paasta huoneiden_maara lukuun eika jakojaannos jaa maksimissaan -1 siita
        f_huone_numero = rand() % huoneiden_maara + 1;
    
    } while (!(f_huone_numero >= 1 && f_huone_numero <= huoneiden_maara));

    // Palautetaan "suodatettu" tulos
    return f_huone_numero;
}