// x. Tunti Viope x - y
// Koodin toiminta selitettyna lyhyesti

#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "fi_FI");

    string etunimi1, etunimi2;
    int luku, summa;
    float keskiarvo, neliojuuri;

	for (int i = 1; i < 6; i++)
    {
        cout << "Anna " << i << ". luku: ";
        cin >> luku;
        summa += luku;
    }

    // Lasketaan keskiarvo
    keskiarvo = static_cast <double>(summa) / 5;

    cout << "Lukujen keskiarvo on: " << fixed<<setprecision(2) << keskiarvo << endl;

    cout << "Keskiarvon neliöjuuri on " << sqrt(keskiarvo) << endl;
    
    cout << "Anna 1. etunimi: ";
    cin >> etunimi1;

    cout << "Anna 2. etunimi: ";
    cin >> etunimi2;

    if(etunimi1<etunimi2){
        cout << "Etunimi 1 on aikaisemmin aakkosissa ja sen pituus on " << etunimi1.length();
    }
    else{
        cout << "Etunimi 2 on aikaisemmin aakkosissa ja sen pituus on " << etunimi2.length();
    }

    return 0;
}
