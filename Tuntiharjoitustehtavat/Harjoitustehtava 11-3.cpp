// 11. Tunti Viope 11 - 3
// Lotto-ohjelma

#include<iostream>
#include<random>

using std::cout;
using std::cin;
using std::endl;

void lottoKone(int &lottorivi[7], int &bonus[3]){

}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int lottorivi[7] = {0}, bonus[3] = {0};
    char valikko;

    cout << "Tervetuloa helppoon lottoon, voiton saaminen on helppoa!" << endl << endl;

    menu:

    cout << "Mitä haluaisit tehdä? (Syötä numero 1-4)" << endl;
    cout << "1: Katso palkintosummat " << endl;
    cout << "2: Pelaa koneen arpomalla rivillä" << endl;
    cout << "3: Pelaa omilla numeroilla" << endl;
    cout << "4: Lopeta pelaaminen" << endl;

    cin >> valikko;

    cout << endl;

    // Valikon vaihtoehdot
    switch (valikko)
    {
    case '1':

        cout << "Numeroita + lisänumeroita oikein\tVoittosumma" << endl;
        cout << "7\t\t\t\t\t10 000 000 e" << endl;
        cout << "6+1\t\t\t\t\t1 000 000 e" << endl;
        cout << "6\t\t\t\t\t100 000 e" << endl;
        cout << "5\t\t\t\t\t2000 e" << endl;
        cout << "4\t\t\t\t\t50 e" << endl;
        cout << "3+1\t\t\t\t\t10 e" << endl;
        cout << "2\t\t\t\t\t2 e" << endl;
        cout << "1\t\t\t\t\t1 e" << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        goto menu;

        break;
    case '2':

        // Kutsutaan funktiota taulukoilla(ovat viela tyhjat)
        lottoKone(lottorivi[7], bonus[3]);

        break;
    case '3':
    
        cout << "Valitettavasti valitsemasi vaihtoehto ei ole vielä käytössä. " << endl;

        goto menu;
        break;
    case '4':
    
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "Tervetuloa uudestaan.";

        break;
    default:

        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "\tValitettavasti valitsemasi vaihtoehto ei ole käytössä. " << endl << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;

        goto menu;
    }

    return 0;
}
