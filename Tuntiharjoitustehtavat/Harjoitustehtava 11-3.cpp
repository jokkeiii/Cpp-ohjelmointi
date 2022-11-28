// 11. Tunti Viope 11 - 3
// Lotto-ohjelma

#include<iostream>
#include<ctime>

using namespace std;

// Vakio lottonumeroiden maaraan
const int NUMEROIDEN_MAARA = 10;

void lottoKone(int &lottorivi[NUMEROIDEN_MAARA]){
    
    
}

void lottorivinTarkastus(int lottorivi[NUMEROIDEN_MAARA]){

    cout << "Lottorivisi on: ";
        
        for (int i = 0; i < 7; i++)
        {
            cout << lottorivi[i] << ", ";
            
        }
        cout << "ja bonusnumerot ";
        for (int i = 7; i < NUMEROIDEN_MAARA; i++)
        {
            if (i == 9)
            {
                cout << lottorivi[i] << ", ";
            }else
            {
                cout << lottorivi[i] << " ";
            }
            
        }

}


int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int lottorivi[NUMEROIDEN_MAARA] = {0};
    char valikko = '';

    cout << "Tervetuloa helppoon lottoon, voiton saaminen on helppoa!" << endl << endl;

    while (true)
    {
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

            break;
        case '2':

            // Kutsutaan funktiota taulukoilla(ovat viela tyhjat)
            lottoKone(lottorivi[NUMEROIDEN_MAARA]);
            
            lottorivinTarkastus(lottorivi[NUMEROIDEN_MAARA]);
            
            break;
        case '3':
        
            cout << "Valitettavasti valitsemasi vaihtoehto ei ole vielä käytössä. " << endl;

            break;
        case '4':
        
            cout << "--------------------------------------------------------------------------------" << endl << endl;
            cout << "Tervetuloa uudestaan.";

            break;
        default:

            cout << "--------------------------------------------------------------------------------" << endl << endl;
            cout << "\tValitettavasti valitsemasi vaihtoehto ei ole käytössä. " << endl << endl;
            cout << "--------------------------------------------------------------------------------" << endl << endl;

            break;
        }
    }

    

    return 0;
}
