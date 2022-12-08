// harjoitustyo.h header tiedosto
#pragma once
#include<string>

// Vakiot
const int MIN_VARAUKSEN_KESTO = 0;
const int MAX_VARAUKSEN_KESTO = 45;
const int HUONEIDEN_LKM = 300;
const int HINTA_PER_YO = 100;

// Luokat
class varausMuuttujat
{
public:

    // Muuttujat huoneiden maksimimaaralle
    int huoneiden_lkm = 0;
    // seka huoneen hinta per yo
    int hinta_per_yo = 0;
    
    // Construct funktio maarittaa hinnan per yo seka huoneiden maaran
    varausMuuttujat(int hinta_per_yo, int huoneiden_lkm){
        
        int temp = 0;

        // Randin siemennys, randin vakio yliajetaan ajasta
        srand(time(NULL)); 
        
        // Silmukkaa ajetaan kunnes rand antaa tulokseksi yli 80 ja alle 100
        do
        {
            int i = 0;
            temp = rand() % 100;
            std::cout << "hinta " << temp << ", "<< i++ << std::endl;
            hinta_per_yo += temp;

        } while (hinta_per_yo >= 80 && hinta_per_yo <= 100);
        
        temp = 0;
        
        // Silmukkaa ajetaan kunnes rand antaa tulokseksi yli 30 ja alle 70
        do
        {
            temp = 0;
            int i = 0;
            temp = rand() % 70;
            std::cout << "huoneet " << temp << ", "<< i++ << std::endl;
            huoneiden_lkm += temp;

        } while (!(huoneiden_lkm >= 30 && huoneiden_lkm <= 70));

    }
    
};

// Tietueet
struct HuoneVaraukset
{
    std::string varaajan_koko_nimi = "Tyhjä";
    int huoneen_numero = 0, varauksen_kesto = 0;
};


// Funktioiden prototyypit
bool onkoHuoneVarattu(const HuoneVaraukset &Varaukset, int fvarattava_huone);
HuoneVaraukset luoVaraus(HuoneVaraukset &Varaukset, int fvarattava_huone);
void tulostaVaraus(const HuoneVaraukset &Varaukset);
int randHuoneidenMaara();
int randHuoneHinta();
int randHuoneenNumero();
