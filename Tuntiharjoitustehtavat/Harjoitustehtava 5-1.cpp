// 5. Tunti - Viope 5 - 1 
// Parillisten lukujonon tulostus while-silmukalla
// Ensimmainen ratkaisu:

/*
#include<iostream>

using std::cout;
using std::cin;

int main() {
	int i = 2;
	do
    {
        cout << " " << i++ << " ";
        i++;
    } while (i <= 50);
    
	return 0;
} */

// Toinen ratkaisu:

#include<iostream>

using std::cout;
using std::cin;

int main() {
	int n = 1;
        while (n <= 50)
        {
            if (n % 2 == 0)
            {
                cout << " " << n << " ";
            }
            n++;
        }
        
    
	return 0;
}