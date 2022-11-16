// Harjoitustyö
// Koodin toiminta selitettyna lyhyesti

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int varaus;

    cout << "Hei ja tervetuloa hotelliin! " << endl;
    cout << endl << "Haluatko varata huoneen? 1 = kyllä, 0 = ei:";
    cin >> varaus;

    return 0;
}
