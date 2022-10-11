// 6. Tunti Viope 6 - 3
// Koodin toiminta selitettyna lyhyesti

#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using std::cout;
using std::cin;
using std::endl; 
using std::string;
using std::setlocale;

int main() {
    setlocale(LC_ALL, "fi_FI");

    string etu, suku, osoite, knro, pnro, kunta;

    cout << "Syötä etunimi: ";
    cin >> etu;

    cout << "Syötä sukunimi: ";
    cin >> suku;
	
    cout << "Syötä osoite: ";
    cin >> osoite;

    cout << "Syötä katunumero: ";
    cin >> knro;

    cout << "Syötä postinumero: ";
    cin >> pnro;

    cout << "Syötä kunta: ";
    cin >> kunta;

    cout << "Osoitteesi on: " << etu << " " << suku << " " << osoite << " " << knro << " " << pnro << " " << kunta << endl;

    if (etu < suku)
    {
        cout << "Etunimesi on aakkosissa ensin ja sen pituus on: " << etu.length();
    }
    else
    {
        cout << "Sukunimesi on aakkosissa ensin ja sen pituus on: " << suku.length();
    }
    

    return 0;
}
