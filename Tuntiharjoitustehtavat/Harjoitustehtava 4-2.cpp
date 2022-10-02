// 4. Tunti - Viope 4 - 2
// Lampotilayksikkomuunnin - Celsius/Fahrenheit
#include<iostream>

using namespace std;

int main() {
    float heat;
    char yksikko;

    cout << "Syota lampotila: ";
    cin >> heat;

    cout << "Syota yksikko (C = Celsius tai F = Fahrenheit): ";
    cin >> yksikko;

    if (yksikko == 'C' || yksikko == 'c')
    {
        cout << heat << " Celsius = " << heat * 1.8 + 32 << " F";
    }
    else if (yksikko == 'F' || yksikko == 'f')
    {
        cout << heat << " Fahrenheit = " << (heat - 32) / 1.8 << " Celsius";
    }
    else
    cout << "Jokin meni vikaan :(";
    
    
    return 0;
}