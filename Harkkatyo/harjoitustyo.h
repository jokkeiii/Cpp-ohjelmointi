// harjoitustyo.h header tiedosto
#pragma once
#include<string>

// Vakiot
const int VARAUKSEN_KESTO_MIN = 0;
const int VARAUKSEN_KESTO_MAX = 45;
const int HUONEIDEN_MAX_LKM = 300;
const int RAND_HUONE_MAX = 70;
const int RAND_HUONE_MIN = 30;
const int RAND_HINTA_MAX = 100;
const int RAND_HINTA_MIN = 80;

// Tietueet
struct HuoneVaraukset
{
    std::string varaajan_koko_nimi = "Tyhjä";
    int huoneen_numero = 0, varauksen_kesto = 0;
};


// Funktioiden prototyypit
bool onkoHuoneVarattu(const HuoneVaraukset &Varaukset, int fvarattava_huone);
HuoneVaraukset luoVaraus(HuoneVaraukset &Varaukset, int fvarattava_huone);
void tulostaVaraus(const HuoneVaraukset &Varaukset, int hinta_per_yo);
int randHuoneidenMaara();
int randHuoneHinta();
int randHuoneenNumero(int huoneiden_maara);
