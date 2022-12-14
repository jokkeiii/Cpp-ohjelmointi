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
HuoneVaraukset luoVaraus(HuoneVaraukset &Varaukset, int f_varattava_huone, int huoneiden_maara, float alennus_kerroin){
    
    char f_valikko;

    // Asetetaan syotetty huone tietueeseen
    Varaukset.huoneen_numero = f_varattava_huone;

    // Tulostetaan kyseinen huone taulukosta ja kysytaan majoituksen kesto
    cout << "Hienoa! Huone " << Varaukset.huoneen_numero << " on varattu teille. " << endl;
    cout << endl;

    // Tallennetaan huoneen tyyppi tietueeseen
    // Jos huoneen numero on alle huoneiden_maara / 2, se on yhden hengen huone
    if (Varaukset.huoneen_numero  <= (huoneiden_maara / 2))
    {
        Varaukset.huone_tyyppi = 1;

    // Jos huoneen numero on yli huoneiden_maara / 2, se on kahden hengen huone
    }else
    {
        Varaukset.huone_tyyppi = 2;
    }
    
    // Varauksen kesto
    AjanVaraus:

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
        
        // Palataan kysymaan syote uudelleen
        goto AjanVaraus;

    // Jos alle yksi 
    } else if (Varaukset.varauksen_kesto < VARAUKSEN_KESTO_MIN)
    {
        cout << "Valitettavasti emme voi varata huoneita 1 yötä vähempää." << endl;
        cout << endl;

        // Palataan kysymaan syote uudelleen
        goto AjanVaraus;

    // jos yli 45 kysytaan uudelleen
    } else if (Varaukset.varauksen_kesto > VARAUKSEN_KESTO_MAX)
    {
        cout << "Valitettavasti emme voi varata huoneita 45 yötä enempää kerralla. " << endl << endl;
        
        // Palataan kysymaan syote uudelleen
        goto AjanVaraus;

    // Jos syote on ok, tulostetaan annettu varauksen kesto
    }else
    {
        cout << "Kiitoksia! Varauksenne on " << Varaukset.varauksen_kesto << " yötä." << endl << endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }

    // Kysytaan kayttajalta nimi
    NimenAnto:

    cout << "Millä nimellä varaus tallennetaan? (Antakaa nimenne ilman ääkkösiä!)" << endl << ": ";
    getline (cin, Varaukset.varaajan_koko_nimi);
    cout << endl; 

    // Tulostetaan syote ja varmistetaan kayttajalta etta nimi on oikein
    NimiSyote:

    // Kysytaan kayttajalta onko annettu nimi oikein vai haluaako antaa sen uudelleen
    cout << "Kiitoksia! Annoitte nimen: " << Varaukset.varaajan_koko_nimi << endl; 
    cout << "Onko nimi oikein? 1 = Kyllä, 2 = Ei, haluan antaa sen uudelleen. " << endl << ": ";
    cin >> f_valikko;
    cout << endl;

    // Testataan kayttajan syote
    switch (f_valikko)
    {
    case '1':
        // Jos nimi on oikein jatketaan ohjelmaa
        cout << endl;
        break;
    case '2':
        // Tyhjennetaan syote valimuisti
        cin.clear();
        cin.ignore(1000,'\n');

        // Palataan kysymaan syote uudelleen
        goto NimenAnto;

        break;
    default:
        // Jos syote ei ole 1 tai 2
        cout << "Valitettavasti valitsemanne valinta ei ole käytössä." << endl;
        cout << endl;
        
        // Tyhjennetaan syote valimuisti
        cin.clear();
        cin.ignore(1000,'\n');
        
        // Siirrytaan takaisin kysymaan syote
        goto NimiSyote;

        break;
    }
    
    // Lasketaan varauksen summa
    // Jos yhden hengen huone
    if (Varaukset.huone_tyyppi == 1)
    {
        // Loppusumma = varauksen kesto oina * yhden hengen huoneen hinta * mahdollinen alennus 
        Varaukset.loppu_summa = Varaukset.varauksen_kesto * HINTA_YKSIO * alennus_kerroin;

    // Jos kahden hengen huone
    }else
    {
        // Loppusumma = varauksen kesto oina * yhden hengen huoneen hinta * mahdollinen alennus 
        Varaukset.loppu_summa = Varaukset.varauksen_kesto * HINTA_KAKSIO * alennus_kerroin;
    }
    
    // Palautetaan tietueeseen tallennetut tiedot mainin taulukkoon
    return Varaukset;
}


// Funktio tarkistaa onko huone jo varattu
bool onkoHuoneVarattu(HuoneVaraukset Varaukset[], int f_varattava_huone, int huoneiden_maara){

    // Silmukalla testataan jokaisen taulukon paikan tietue
    for (int i = 0; i < huoneiden_maara; i++)
    {  
        // Jos huone on varattu palautetaan true
        if (Varaukset[i].huoneen_numero == f_varattava_huone)
        {
            return true;
        }
    }

    // Jos taulukosta ei loydy samaa huonetta varattuna palautetaan false
    return false;
}


// Funktio tulostaa syotetyn varauksen tiedot seka laskee varauksen hinnan
void tulostaVaraus(const HuoneVaraukset &Varaukset, float alennus_kerroin){
    
    // Tulostetaan tietueesta huonevarauksen tiedot
    cout << "\tHienoa! Tässä on syottämäsi varauksen tiedot: " << endl << endl;
    cout << "\tVaraajan nimi: " << Varaukset.varaajan_koko_nimi << endl;
    cout << "\tVarausnumero: " << Varaukset.varaus_numero << endl;
    cout << "\tVaratun huoneen numero: " << Varaukset.huoneen_numero << endl;
    cout << "\tVaratun huoneen koko: " << Varaukset.huone_tyyppi << " hengen huone" << endl;
    cout << "\tVarauksen kesto: " << Varaukset.varauksen_kesto << " yötä" << endl;
    cout << "\tVarauksenne loppusumma: " << Varaukset.loppu_summa << " euroa" << endl;
    
    // Jos alennus_kerroin ei ole 1 
    if (alennus_kerroin != 1)
    {   
        // Tulostetaan peraan alennuksen maara
        cout << "\tVarauksenne alennus on " << (1 - alennus_kerroin ) * 100 << "% " << endl << endl;
    } else
    {
        cout << endl;
    }
    
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


// Arvotaan kayttajalle huoneen numero 
int randHuoneenNumero(int huoneiden_maara, int huone_tyyppi){
    
    // Randin siemennys, randin vakio yliajetaan ajasta
    srand(time(NULL));
    
    int f_huone_numero = 0;

    // Jos huonetyyppi on 1 eli yhden hengen huone
    if (huone_tyyppi == 1)
    {
        // Silmukkaa ajetaan kunnes jatkuu...
        do
        {   
            // Randin antama tulos jaetaan huoneiden_maara, jonka jakojaannos + 1 asetetaan muuttujaan
            // jakojaannos + 1, jotta voidaan paasta huoneiden_maara lukuun eika jakojaannos jaa maksimissaan -1 siita
            f_huone_numero = rand() % huoneiden_maara + 1;
        
        // ...jatkuu tulos on alle 1 tai yli huoneiden_maara toistetaan silmukka
        } while (f_huone_numero < 1 || f_huone_numero > (huoneiden_maara / 2));

    // Jos huonetyyppi on 2 eli kahden hengen huone
    }else
    {
        // Silmukkaa ajetaan kunnes jatkuu...
        do
        {   
            // Randin antama tulos jaetaan huoneiden_maara, jonka jakojaannos + 1 asetetaan muuttujaan
            // jakojaannos + 1, jotta voidaan paasta huoneiden_maara lukuun eika jakojaannos jaa maksimissaan -1 siita
            f_huone_numero = rand() % huoneiden_maara + 1;
        
        // ...jatkuu tulos on alle huoneiden_maara / 2 tai yli huoneiden_maara toistetaan silmukka
        } while (f_huone_numero <= (huoneiden_maara / 2) || f_huone_numero > huoneiden_maara);

    }
    
    // Palautetaan "suodatettu" tulos
    return f_huone_numero;
}


// Arvotaan syotetylle taulukon paikalle tietueeseen varausnumero
int randVarausNumero(HuoneVaraukset Varaukset[], int huoneiden_maara){

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
            if(Varaukset[i].varaus_numero == f_varaus_numero)
            {   
                // Asetetaan arvo nollaksi
                f_varaus_numero = 0;
            }
        }

    // Jos muuttujan arvo on nolla aloitetaan alusta
    } while (f_varaus_numero == 0);
    
    return f_varaus_numero;
}


// Haetaan varauksia varausnumerolla
void varausHaku(HuoneVaraukset Varaukset[], int huoneiden_maara, float alennus_kerroin){
    int haku_numero = 0, uusi_haku_valinta = 0;
    bool haku_onnistunut = false;

    cout << "\nHei! ";

    // Hakuvalinnan silmukka
    do
    {
        cout << "\n\nAnna haettavan varauksen varausnumero\n: ";
        cin >> haku_numero;

        // Syotteentarkastus. Jos annettu syote ei ole numero, se on alle 10 000
        // tai yli 99 999, kysytaan kayttajalta syote uudelleen
        if (cin.fail() || haku_numero < 10000 || haku_numero > 99999)
        {
            cout << " \nAntamanne syöte ei ole hyväksytty numero välillä 10 000-99 999" << endl;
            cout << endl;
            
            // Tyhjennetaan syote valimuisti
            cin.clear();
            cin.ignore(1000,'\n');

            haku_numero = 0;
        // Jos syote on oikein
        } else
        {
            // Haetaan taulukosta kyseista varausta
            for (int i = 0; i < huoneiden_maara; i++)
            {   
                // Jos varaus loytyy
                if (Varaukset[i].varaus_numero == haku_numero)
                {   
                    cout << endl;
                    // Tulostetaan varauksen tiedot
                    tulostaVaraus(Varaukset[i], alennus_kerroin);
                    // Asetetaan haku_onnistunut true
                    haku_onnistunut = true;
                    // ja poistutaan silmukasta
                    break;
                }
            }

            // Jos haku_onnistunut on false
            if (haku_onnistunut == false)
            {
                // Tulostetaan ettei varauksia ole loytynyt 
                cout << "\nValitettavasti syotetylla varausnumerolla ei löytynyt yhtäkään varausta. \n";
                
            }
            // Kysytaan haluaako kayttaja jatkaa hakemista
            do
            {
                cout << "\nHaluatteko jatkaa varausten hakemista? \n";
                cout << "\n#1 Haluan tehdä uuden haun \n#2 Haluan lopettaa varausten hakemisen \n: ";
                cin >> uusi_haku_valinta;
                cout << endl;

                // Syotteentarkastus. Jos annettu syote ei ole numero, se on alle 1
                // tai yli 2, kysytaan kayttajalta syote uudelleen
                if (cin.fail() || (uusi_haku_valinta < 1 && uusi_haku_valinta > 2))
                {
                    cout << " \nAntamanne syöte ei ole hyväksytty numero 1 tai 2 \n\n";

                    // Tyhjennetaan syote valimuisti
                    cin.clear();
                    cin.ignore(1000,'\n');

                    uusi_haku_valinta = 0;

                // Jos valinta on 1
                }else if(uusi_haku_valinta == 1)
                {   
                    // Asetetaan alkuperainen haku_numero 0, jolloin ensimmainen valikko silmukka jatkaa
                    haku_numero = 0;
                }

                // Jos valinta on 2, poistutaan funktiosta ja paaohjelma jatkaa

            // Jos uusi_haku_valinta on 0, jatketaan silmukkaa
            } while (uusi_haku_valinta == 0);
            
        }

    // Jos haku_numero on 0
    } while (haku_numero == 0);
    
}


// Tarkistetaan onko syotetyn huonetyypin huoneita viela vapaana
bool onkoTyypinHuoneetVarattu(HuoneVaraukset Varaukset[], int huoneiden_maara, int huone_tyyppi){

    // Muuttuja johon lasketaan, montako huonetta huonetyypilla on varattuna
    int count = 0;

    // Testataan taulukon jokaisen (0-huoneiden_maara) paikan tietueesta 
    // onko huone_tyyppi sama mika annettiin
    for (int i = 0; i < huoneiden_maara; i++)
    {
        if (Varaukset[i].huone_tyyppi == huone_tyyppi)
        {
            // Jos tietueesta loytyy sama huonetyyppi lisataan laskuriin 1
            count++;
        } 
    }

    // Jos laskurin summa on sama kuin huonetyypin huoneiden maara (huoneiden_maara / 2)
    // on kaikki huonetyypin huoneet varattuna
    if (count == (huoneiden_maara/2))
    {   
        // eli palautetaan true (kaikki huonetyypin huoneet ovat varattuina)
        return true;
    // Muuten palautetaan false eli huonetyypin huoneita on viela vapaana
    } else
    {
        return false;
    }
}
