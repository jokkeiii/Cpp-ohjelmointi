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

    // Jos alle yksi 
    } else if (Varaukset.varauksen_kesto < VARAUKSEN_KESTO_MIN)
    {
        cout << "Valitettavasti emme voi varata huoneita 1 yötä vähempää." << endl;
        cout << endl;

        goto ajanvaraus;
    // jos yli 45 kysytaan uudelleen
    } else if (Varaukset.varauksen_kesto > VARAUKSEN_KESTO_MAX)
    {
        cout << "Valitettavasti emme voi varata huoneita 45 yötä enempää kerralla. " << endl << endl;
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

    // Silmukkaa ajetaan kunnes rand antaa tulokseksi parillisen yli 40 ja alle 300
    do
    {   
        // Randin antama tulos jaetaan HUONEIDEN_MAARA_MAX, jonka jakojaannos + 1 asetetaan muuttujaan
        // jakojaannos + 1, jotta voidaan paasta HUONEIDEN_MAARA_MAX lukuun eika jakojaannos jaa maksimissaan HUONEIDEN_MAARA_MAX - 1
        f_huoneiden_lkm = rand() % HUONEIDEN_MAARA_MAX + 1;
    
    // Jos tulos on pariton tai alle HUONEIDEN_MAARA_MIN tai yli HUONEIDEN_MAARA_MAX toistetaan silmukka
    } while ((f_huoneiden_lkm % 2) != 0 || f_huoneiden_lkm < HUONEIDEN_MAARA_MIN || f_huoneiden_lkm > HUONEIDEN_MAARA_MAX);

    // Palautetaan "suodatettu" tulos
    return f_huoneiden_lkm;
}


// Funktio tuottaa satunnaisen hinnan valilla 80-100

float randAlennuksenMaara(){
    // Randin siemennys, randin vakio yliajetaan ajasta
    srand(time(NULL)); 
    
    int temp_numero = 0;
    float f_alennus_kerroin = 0;
    
    // Silmukkaa ajetaan kunnes rand antaa tulokseksi yli 80 ja alle 100
    temp_numero = rand() % 3 + 1; 

    // Jos 3 alennus on 20%
    if (temp_numero == 3)
    {
        return f_alennus_kerroin = 0.8;

    } // Jos 2 alennus on 10%
    else if (temp_numero == 2)
    {   
        return f_alennus_kerroin = 0.9;

    } // Jos 1 ei alennusta, kerroin on 1
    else
    {
        return f_alennus_kerroin = 1;
    }
     
}

// Arvotaan huoneen numero 1 - huoneiden_maara
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
    
    // Jos tulos on alle 1 tai yli huoneiden_maara toistetaan silmukka
    } while (f_huone_numero < 1 || f_huone_numero > huoneiden_maara);

    // Palautetaan "suodatettu" tulos
    return f_huone_numero;
}

// Varauksien haku nimella tai varausnumerolla
int randVarausNumero(HuoneVaraukset &Varaukset, int huoneiden_maara){
    int f_varaus_numero;

    // Randin siemennys, randin vakio yliajetaan ajasta
    srand(time(NULL));

    // Luodaan uusi ja testataan aiemmat varausnumerot
    do
    {   
        // Arvotaan numero seka testataan etta numero on 10000-99999
        do
        {   
            // Kerrotaan ensin kymmenella, jotta saadaan tarpeeksi suuria numeroita
            f_varaus_numero = rand() * 10 % 99999;

        // Jos tulos on alle 10000 tai yli 99999
        } while (f_varaus_numero < 10000 || f_varaus_numero > 99999);

        // Silmukalla testataan jokaisen taulukon paikan tietue
        for (int i = 0; i < huoneiden_maara; i++)
        {   
            // Jos ehto on true, eli numero on jo kaytossa
            if(Varaukset.varaus_numero == f_varaus_numero)
            {   
                // Asetetaan arvo nollaksi
                f_varaus_numero = 0;
            }
        }
    // Jos muuttujan arvo on nolla aloitetaan alusta
    } while (f_varaus_numero != 0);
    
    return f_varaus_numero;
}