// 6. Tunti Viope 6 - 2
// Vapaasti putoavan kappaleen nopeus sekunneitain

#include<iostream>

using std::cout;
using std::cin;
using std::endl; 

int main() {
    int sek;
    float tulos;

    // Kysytaan kayttajalta syöte
    cout << "anna aika sekunneissa: ";
    cin >> sek;

    cout << "Aika\tNopeus(km/h)" << endl;   

    // Silmukalla tulostetaan ja lasketaan tulokset
    // Silmukka toteutuu "sek" kertaa ja alkaa nollasta
    for (int i = 0; i <= sek; i++) 
    {
        tulos = i * 9.81 * 3.6;
        cout << i << "\t" << tulos << endl;
    }
    
	
    return 0;
}
