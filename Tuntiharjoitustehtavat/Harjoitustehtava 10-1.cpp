// 10. Tunti Viope 10 - 1
// Koodin toiminta selitettyna lyhyesti

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Opiskelija
{
    string etunimi, sukunimi, opiskelijanumero;
    int opintopisteet;
};


int main() {
    setlocale(LC_ALL, "fi_FI");
    
    Opiskelija opiskelija1; 

    cout << "Anna opiskelijan etunimi: ";
    cin >> opiskelija1.etunimi;

    cout << "Anna opiskelijan sukunimi: ";
    cin >> opiskelija1.sukunimi;

    cout << "Anna opiskelijan opiskelijanumero: ";
    cin >> opiskelija1.opiskelijanumero;

    cout << "Anna opiskelijan opintopisteet: ";
    cin >> opiskelija1.opintopisteet;


    cout << "Etunimi: " << opiskelija1.etunimi << endl;

    cout << "Sukunimi: " << opiskelija1.sukunimi << endl;

    cout << "Opiskelijanumero: " << opiskelija1.opiskelijanumero << endl;

    cout << "Opintopisteet: " << opiskelija1.opintopisteet << endl;

    return 0;
}
