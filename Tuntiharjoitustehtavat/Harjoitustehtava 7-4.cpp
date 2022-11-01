// 7. Tunti Viope 7 - 4
// Yksinkertainen palkkalaskija. Laskee normituntien palkan seka mahdolliset ylityon palkan mukaan.

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// Aliohjelman header
int palkka(int);

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int tehdyt_tunnit; 

    cout << "Anna viikon tyotunnit: ";
    cin >> tehdyt_tunnit;

    // Tulostetaan aliohjelman tulos tekstin kanssa
    cout << "Viikon palkkasi on: " << palkka(tehdyt_tunnit) << " euroa." << endl;

    return 0;
}

int palkka(int x) {
    int tulos; 

    // Jos tunnit ovat normituntien rajoissa lasketaan peruspalkka
    if (x <= 40)
    {
        return x * 10;
    }
    // Jos tunneissa on ylitoita lasketaan normipalkka ja lisataan tulokseen ylitoiden palkka
    else if (x > 40)
    {   
        tulos = 40 * 10 + (x - 40) * 15;
        return tulos;
    }

}