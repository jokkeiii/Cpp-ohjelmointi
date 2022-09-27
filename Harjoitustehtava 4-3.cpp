// 4. Tunti - Viope 4 - 3 
// Tulosteen tulostaminen syotteen n kertaa seka lukujonon 1-15 tulostaminen
#include<iostream>

using namespace std;

int main() {
	
    int luku, n = 1, h = 1;

    cout << "Anna luku: ";
    cin >> luku;

    while (n <= luku)
    {
        cout << "Hello World!" << endl;
        n++;
    }

    while (h <= 15)
    {
        cout<< h++ << " ";
    }
    
	return 0;
}