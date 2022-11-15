// 9. Tunti Viope 9 - 3
// Alkuluku vai ei

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

bool alkuluku(int n){

    // Jos luku on alle 2, palautetaan false
    if (n < 2)
    {
        return false;
    }

    // Testataan luvun jakamista
    for (int i = 2; i < n; i++)
    {
        // Jos jakojaannosta ei tule, palautetaan false
        if (n % i == 0)
        {
            return false;
        }
        
    }
    
    return true;
}

int main() {
    setlocale(LC_ALL, "fi_FI");

    // Silmukka kutsuu aliohjelmaa luvuilla 0-1000
    for (int i = 0; i < 1000; i++)
    {
        // Jos aliohjelman palautus true, tulostetaan kyseinen luku
        if (alkuluku(i) == true)
        {
            cout << i << ", ";
        }
    
    }
    

    return 0;
}
