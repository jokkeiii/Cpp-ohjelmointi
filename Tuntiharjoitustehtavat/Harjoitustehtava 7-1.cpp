// 7. Tunti Viope 7 - 1
// Ohjelma palauttaa kayttajan syotteesta x * x

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// Aliohjelma Nelio palauttaa x * x
int Nelio(int x) { 
    return x * x;
}

int main() {
    int num, tulos; 

    // Kysytaan kayttajalta syote lukuna
    cout << "Anna luku, jonka nelio lasketaan: "; 
    cin >> num;

    // Tulostetaan suoraan kutsutun aliohjelman tulos 
    cout << "Luvun Nelio on: " << Nelio(num) << endl;
    
    return 0;
}
