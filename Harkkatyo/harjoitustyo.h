// harjoitustyo.h header tiedosto

// Funktioiden prototyypit
bool onkoHuoneVarattu(const HotelliVaraukset &Varaukset, int fvarattava_huone);
HotelliVaraukset luoVaraus(HotelliVaraukset &Varaukset, int fvarattava_huone);
void tulostaVaraus(const HotelliVaraukset &Varaukset);
int randHuoneidenMaara();
int randHuoneHinta();
