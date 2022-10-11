// 6. Tunti Viope 6 - 1
// Koodin toiminta selitettyna lyhyesti

#include<iostream>

using std::cout;
using std::cin;
using std::endl; 

int main() {

    for (int i = 1; i < 11; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int n = 2; n < 21; n+=2)
    {
        if (n < 19)
        {
            cout << n << ", ";
        }
        else{
            cout << n;
        }
    }
    
    
	
    return 0;
}
