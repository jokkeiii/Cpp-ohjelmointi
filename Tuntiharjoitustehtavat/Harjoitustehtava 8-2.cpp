// 8. Tunti Viope 8 - 2
// Ohjelma, jossa on haluttua merkkia halutun maaran ruudulle tulostava void()-tyyppinen aliohjelma

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// Funktio tulostaa syotetyn merkin
void jono(char x){
    cout << x;
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int maara;
    char merkki; 

    cout << "Montako merkkiä haluat?    ";
    cin >> maara; 

    cout << "Mikä merkki tulostetaan?    ";
    cin >> merkki; 

    cout << endl;

    // Silmukka suorittaa funktion kutsun "maara" kertaa
    for (int i = 0; i < maara; i++){
        
        jono(merkki);
    }

    return 0;
}
