// Harjoitustyo
// Hotellinvarausjarjestelma

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

/* TODO

1. Huoneen varaaminen

2. 


*/


int HuoneVaraus(int huone){


    
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int varattava_huone; 
    int varatut_huoneet[300] = { 0 };
    char valikko;

    cout << "Tervetuloa!!" << endl;
    cout << "Mitä haluaisitte tehdä?" << endl;


    while (true)
    {
        
        cout << R"(Jos haluatte varata huoneen valitkaa " V " , jos haluatte poistua valitkaa " P " : )";
        cin >> valikko; 

        if (valikko == 'V' || valikko == 'v')
        {
            HuoneenVaraus();
        }
        
    }
    
    
    return 0;
}
