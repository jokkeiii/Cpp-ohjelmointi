// harjoitustyo.h header tiedosto
#pragma once
#include <string>

// Vakiot
// Minini varauksen kesto, ei voi olla alle 1 yota
const int VARAUKSEN_KESTO_MIN = 1;
// Maksimi varauksen kesto, ei varata yli 45 yoksi
const int VARAUKSEN_KESTO_MAX = 45;
// Maksimi huoneiden maara, jotka voivat olla kaytossa
const int HUONEIDEN_MAARA_MAX = 300;
// Minimi huoneiden maara, jotka voivat olla kaytossa
const int HUONEIDEN_MAARA_MIN = 40;
// Yhden hengen huoneen hinta per yo
const int HINTA_YKSIO = 100;
// Kahden hengen huoneen hinta per yo
const int HINTA_KAKSIO = 80;

// Tietueet
// Huonevarauksien tietue
struct HuoneVaraukset
{
    // Sisaltaa nimen, huoneen numeron, varauksen keston oiden maarana
    // seka varausnumeron
    std::string varaajan_koko_nimi = "Tyhjä";
    int huoneen_numero = 0, varauksen_kesto = 0, varaus_numero = 0;
};

// Funktioiden prototyypit
// Tarkistetaan onko syotetty huone jo varattu
bool onkoHuoneVarattu(HuoneVaraukset Varaukset, int f_varattava_huone, int huoneiden_maara);
// Luodaan syotetylle taulukon paikalle tietueeseen varauksen tiedot
HuoneVaraukset luoVaraus(HuoneVaraukset &Varaukset, int f_varattava_huone);
// Tulostetaan syotetyn taulukon paikan tietueen varauksen tiedot
void tulostaVaraus(const HuoneVaraukset &Varaukset, int huoneiden_maara, int alennus_kerroin);
// Arvotaan parillinen huoneiden maara, valilta HUONE_MAARA_MAX - HUONE_MAARA_MIN
int randHuoneidenMaara();
// Arvotaan alennuksen maara 0%, 10% tai 20%
float randAlennuksenMaara();
// Arvotaan kayttajalle satunnainen huoneen numero saatavilla olevista huoneista
int randHuoneenNumero(int huoneiden_maara);
// Arvotaan syotetylle taulukon paikalle tietueeseen varausnumero
int randVarausNumero(HuoneVaraukset &Varaukset, int huoneiden_maara);
// Haetaan varauksia joko nimella tai varausnumerolla