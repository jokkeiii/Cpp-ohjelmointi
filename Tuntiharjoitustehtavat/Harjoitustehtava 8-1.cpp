// 8. Tunti Viope 8 - 1
// Koodin toiminta selitettyna lyhyesti

#include<iostream>

using std::cout;
using std::cin;
using std::endl; 

int KertomaFunktio(int);

int main() {
    
    int luku, tulos;

    cout << "Anna kokonaisluku välille 0 - 16" << endl; 
    cin >> luku; 

    // Jos tulos on 0 tulostetaan virhe
    if (tulos == 0)
    {
        /* code */
    }
    
    cout << "Luvun " << luku << " kertoma on " << tulos; 
    
    return 0;
}

int KertomaFunktio(int x){ 
    // Jos x on negatiivinen tulostetaan 0
    if (x < 0)
    {
        return 0;
    }
    
}