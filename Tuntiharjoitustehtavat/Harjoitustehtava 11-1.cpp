// 11. Tunti Viope 11 - 1
// Ohjelma muuttaa roomalaiset numerot kymmenjarjestelman luvuiksi

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int roomalaisnumeroMuunnin(string x){


}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    string roomalainen_num;

    cout << "Roomalainen luku, jonka desimaaliarvon haluat tietää? ";
    getline(cin, roomalainen_num);

    cout << "Desimaalimuodossa roomalainen luku " << roomalainen_num << " on " << roomalaisnumeroMuunnin(roomalainen_num);

    return 0;
}
