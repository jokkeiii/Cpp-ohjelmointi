// 11. Tunti Viope 11 - 3
// Lotto-ohjelma

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    char valikko;

    cout << "Tervetuloa helppoon lottoon, voiton saaminen on helppoa!" << endl << endl;

    menu:

    cout << "Mitä haluaisit tehdä? (Syötä numero 1-4)" << endl;
    cout << "1: Katso palkintosummat " << endl;
    cout << "2: Pelaa koneen arpomalla rivillä" << endl;
    cout << "3: Pelaa omilla numeroilla" << endl;
    cout << "4: Lopeta pelaaminen" << endl;

    cin >> valikko;

    return 0;
}
