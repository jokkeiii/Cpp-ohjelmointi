#include<iostream>
using namespace std;

int main(){

    // Randin siemennys, randin vakio yliajetaan ajasta
    srand(time(NULL)); 
    
    int f_hinta_per_yo;
    
    // Silmukkaa ajetaan kunnes rand antaa tulokseksi yli 80 tai alle 100
    do
    {
        f_hinta_per_yo = rand() % 100;

        cout << endl << f_hinta_per_yo << endl;

    } while (f_hinta_per_yo < 80 || f_hinta_per_yo > 100);

    cout << endl << "Final is " << f_hinta_per_yo << endl << endl;
    
    return 0;
}