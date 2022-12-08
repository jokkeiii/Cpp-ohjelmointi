// harjoitustyo.h header tiedosto
#pragma once
#include<string>

// Vakiot
const int VARAUKSEN_KESTO_MIN = 0;
const int VARAUKSEN_KESTO_MAX = 45;
const int HUONEIDEN_MAARA_MAX = 300;
const int HUONEIDEN_MAARA_MIN = 40;
const int HINTA_YKSIO = 100;
const int HINTA_KAKSIO = 80;

// Tietueet
struct HuoneVaraukset
{
    std::string varaajan_koko_nimi = "Tyhjä";
    int huoneen_numero = 0, varauksen_kesto = 0, varaus_numero = 0;
};


// Funktioiden prototyypit
bool onkoHuoneVarattu(const HuoneVaraukset &Varaukset, int fvarattava_huone);
HuoneVaraukset luoVaraus(HuoneVaraukset &Varaukset, int fvarattava_huone);
void tulostaVaraus(const HuoneVaraukset &Varaukset, int hinta_per_yo);
int randHuoneidenMaara();
float randAlennuksenMaara();
int randHuoneenNumero(int huoneiden_maara);
int randVarausNumero(HuoneVaraukset &Varaukset, int huoneiden_maara);