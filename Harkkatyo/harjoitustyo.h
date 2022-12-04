// harjoitustyo.h header tiedosto
#pragma once
#include<string>

// Vakiot
const int MIN_VARAUKSEN_KESTO = 0;
const int MAX_VARAUKSEN_KESTO = 45;
const int HUONEIDEN_LKM = 300;
const int HINTA_PER_YO = 100;

// Tietueet
struct HotelliVaraukset
{
    std::string varaajan_koko_nimi = "Tyhjä";
    int huoneen_numero = 0, varauksen_kesto = 0;
};

// Funktioiden prototyypit
bool onkoHuoneVarattu(const HotelliVaraukset &Varaukset, int fvarattava_huone);
HotelliVaraukset luoVaraus(HotelliVaraukset &Varaukset, int fvarattava_huone);
void tulostaVaraus(const HotelliVaraukset &Varaukset);
int randHuoneidenMaara();
int randHuoneHinta();
int randHuoneenNumero();
