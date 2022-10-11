// 6. Tunti Viope 6 - 4
// Koodin toiminta selitettyna lyhyesti

#include<iostream>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::setlocale;
using std::sqrt;
using std::log;
using std::exp;

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    char i;
    float luku;

	while (i != 'L')
    {
        cout << "Valitse laskutoimitus (1=neliöjuuri, 2=log, 3=exp ja 4=tan, L=lopetus): ";
        cin >> i;
        if (i == '1')
        {
            cout << "Syötä luku: ";
            cin >> luku;
            cout << "Syöttämäsi luvun neliöjuuri on " << sqrt(luku) << endl;
        }
        else if (i == '2')
        {
            cout << "Syötä luku: ";
            cin >> luku;
            cout << "Syöttämäsi luvun logaritmi on " << log(luku) << endl;
        }
        else if (i == '3')
        {
            cout << "Syötä luku: ";
            cin >> luku;
            cout << "Syöttämäsi luvun exp on " << exp(luku) << endl;   
        }
    }
    
    return 0;
}
