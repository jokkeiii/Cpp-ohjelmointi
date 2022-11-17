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

    cout << endl << huone;
    
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int varattava_huone; 
    int varatut_huoneet[300] = { 0 };
    char valikko;

    cout << "Tervetuloa!!" << endl;
    cout << "Mitä haluaisitte tehdä?" << endl;


    do
    {
        
        cout << R"(Jos haluatte varata huoneen valitkaa " V " , jos haluatte poistua valitkaa " P " : )";
        cin >> valikko; 

        if (valikko == 'V' || valikko == 'v')
        {
            cout << "Minkä huoneen haluatte varata? (1-300) : ";
            // Ei toimi!
            cin << HuoneenVaraus();
        }
        
    }while (valikko != 'P' || valikko != 'p')

    
    
    
    return 0;
}
