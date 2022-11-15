// 9. Tunti Viope 9 - 4
// Aliohjelman viittausparametrit

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// Kysytaan kayttajalta syote ja viitataan se mainin "luku" muuttujaan
void asetaika(int& n){

    cout << "kerro ikasi: ";
    cin >> n;
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    // Muuttuja aliohjelman viittausta varten
    int luku = 0;

    // Kutsutaan aliohjelmaa viitattavalla luvulla
    asetaika(luku);

    // Tulostetaan luku
    cout << "ikasi on: " << luku;

    return 0;
}
