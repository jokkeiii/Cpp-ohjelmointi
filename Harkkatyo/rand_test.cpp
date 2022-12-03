#include<iostream>
using namespace std;

int main(){

    srand(time(NULL));
    
    int f_hinta_per_yo;
    
    do
    {
        f_hinta_per_yo = rand() % 100 + 1;

        cout << endl << f_hinta_per_yo << endl;
    
    } while (f_hinta_per_yo < 30 || f_hinta_per_yo > 70);
    
    cout << endl << "Final is " << f_hinta_per_yo << endl << endl;
    
    return 0;
}