#include<iostream>
using namespace std;

int main(){

    // Randin siemennys, randin vakio yliajetaan ajasta
    
    
    int f_hinta_per_yo, n = 0;
    
    // Silmukkaa ajetaan kunnes rand antaa tulokseksi yli 80 tai alle 100
    /*
    do
    {
        f_hinta_per_yo = rand() % 300;

        cout << endl << f_hinta_per_yo << endl;

    } while (f_hinta_per_yo < 80 || f_hinta_per_yo > 100);
    */
   for (int i = 0; i < 10; i++)
   {
        while (f_hinta_per_yo != 300)
        {
            srand(time(NULL));
            
            f_hinta_per_yo = rand() % 300 + 1;
            n++;
        }
    
        cout << f_hinta_per_yo << ", " << n << endl << endl;
   }
   
    // cout << endl << "Final is " << f_hinta_per_yo << endl << endl;
    
    return 0;
}