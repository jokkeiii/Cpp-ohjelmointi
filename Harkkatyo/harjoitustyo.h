// harjoitustyo.h header tiedosto
#pragma once
#include<string>

// Vakiot
const int MIN_VARAUKSEN_KESTO = 0;
const int MAX_VARAUKSEN_KESTO = 45;
const int HUONEIDEN_MAX_LKM = 300;

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
