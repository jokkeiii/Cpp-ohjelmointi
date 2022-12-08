#include<iostream>
using namespace std;

int main(){

    // Randin siemennys, randin vakio yliajetaan ajasta
    srand(time(NULL));
    
    int f_huoneiden_lkm = 0;

    // Silmukkaa ajetaan kunnes rand antaa tulokseksi yli 30 ja alle 70
    do
    {   
        // Randin antama tulos jaetaan 70, jonka jakojaannos + 1 asetetaan muuttujaan
        // jakojaannos + 1, jotta voidaan paasta 70 eika jakojaannos jaa maksimissaan 69
        f_huoneiden_lkm = rand() % 70 + 1;
    
    } while (!(f_huoneiden_lkm >= 30 && f_huoneiden_lkm <= 70));


    return 0;
}