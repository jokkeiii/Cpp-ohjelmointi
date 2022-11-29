// 11. Tunti Viope 11 - 1
// Ohjelma muuttaa roomalaiset numerot desimaaliluvuksi

#include<iostream>
#include<string>

using namespace std;

int arvo(char x){
    
    if (x == 'I'){

        return 1;
    }
    if (x == 'V'){

        return 5;
    }
    if (x == 'X'){

        return 10;
    }
    if (x == 'L'){

        return 50;
    }
    if (x == 'C'){

        return 100;
    }
    if (x == 'D'){

        return 500;
    }
    if (x == 'M'){

        return 1000;
    }
    
    return -1;

}

int roomalaisDesimaaliksi(string& str)
{

    int tulos = 0;
 
    for (int i = 0; i < str.length(); i++) {
        
        // Otetaan "str[i]":n arvo
        int s1 = arvo(str[i]);
 
        if (i + 1 < str.length()) {
            // Otetaan "str[i+1]":n arvo
            int s2 = arvo(str[i + 1]);
 
            // Vertaillaan molempia
            if (s1 >= s2) {
                // Nykyinen symboli on 
                // suurempi tai yhtasuurikuin
                // seuraava symboli
                tulos = tulos + s1;
            }
            else {
                // Nykyinen symboli on pienempi
                // kuin seuraava symboli
                tulos = tulos + s2 - s1;
                i++;
            }
        }
        else {
            tulos = tulos + s1;
        }
    }

    return tulos;
}
 
int main() {
    setlocale(LC_ALL, "fi_FI");

    string roomalainen_num;
    int desimaali;

    cout << "Roomalainen luku, jonka desimaaliarvon haluat tietää? ";
    getline(cin, roomalainen_num);

    desimaali = roomalaisDesimaaliksi(roomalainen_num);

    cout << "Desimaalimuodossa roomalainen luku " << roomalainen_num << " on " << desimaali << endl;

    return 0;
}
