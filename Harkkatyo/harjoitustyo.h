// harjoitustyo.h header tiedosto
#pragma once
#include<string>

// Tietueet
struct HotelliVaraukset
{
    std::string varaajan_koko_nimi = "Matti Malli";
    int huoneen_numero = 0, varauksen_kesto = 0;
};

// Funktioiden prototyypit
bool onkoHuoneVarattu(const HotelliVaraukset &Varaukset, int fvarattava_huone);
HotelliVaraukset luoVaraus(HotelliVaraukset &Varaukset, int fvarattava_huone);
void tulostaVaraus(const HotelliVaraukset &Varaukset);
int randHuoneidenMaara();
int randHuoneHinta();
