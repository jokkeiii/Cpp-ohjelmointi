// 5. Tunti Viope 5 - 3
// Silmukalla lukujen kysyminen ja lopussa summa

#include<iostream>

using std::cout;
using std::cin;

int main() {

	int n, summa;

        // Toteutetaan kunnes while(n>0) on false eli kayttaja syottaa "0"
       do 
       {
            cout << "anna yhteenlaskettavat luvut (kun haluat lopettaa laita luvuksi 0): "; 
            cin >> n;
            // Kysytaan numero ja lisataan se summaan
            summa += n;
            // Testataan antoiko kayttaja muun kuin "0"
       } while (n > 0);
    // Tulostetaan syotettyjen numeroiden summa
    cout << "lukujen summa: " << summa;
    
    return 0;
}