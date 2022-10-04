// 5. Tunti Viope 5 - 3
// Silmukalla lukujen kysyminen ja lopussa summa

#include<iostream>

using std::cout;
using std::cin;

int main() {
	int n = 0; 
        do
        {
            cout << "anna yhteenlaskettavat luvut (kun haluat lopettaa laita luvuksi 0): ";
            cin >> n;

        } while (n > 0);
    cout << n;
    
    return 0;
}