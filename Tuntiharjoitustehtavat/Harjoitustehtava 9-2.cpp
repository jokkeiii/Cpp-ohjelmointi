// 9. Tunti Viope 9 - 2
// Koodin toiminta selitettyna lyhyesti

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// Aliohjelma tulostaa * sademaara taulukon paikan luvun kertaa
void tulostaTahtia( int n ){
    
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    // Kokonaislukutaulukko
    int sademaara[12];

    // Kysytaan syote 12 kertaa ja asetetaan taulukkoon omalle paikall
    for (int i = 0; i < 12; i++)
    {
        cout << "Syota kuukausi " << i + 1 << " sademaara: "; 
        cin >> sademaara[i];
    }
    
    // Kutsutaan aliohjelmaa 12 kertaa, aina eri taulukon luvulla
    for (int i = 0; i < 12; i++)
    {
        tulostaTahtia( sademaara[i] );
    }
    
    return 0;
}
