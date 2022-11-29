// 11. Tunti Viope 11 - 3
// Lotto-ohjelma

#include<iostream>
#include<ctime>

using namespace std;

// Vakio lottonumeroiden maaraan
const int NUMEROIDEN_MAARA = 10;

// Funktio arpoo numeron
int numeroidenArvonta(){
    
    int uusi_numero;

    srand(time(0));

    uusi_numero = rand() % 40 + 1;

    return uusi_numero;
}

// Funktio tarkastaa lottonumerot ja tulostaa kayttajan- seka voittonumerot
void lottorivinTarkastus(int lottorivi[NUMEROIDEN_MAARA]){

    // Tulostetaan kayttajan numerot
    cout << endl << "Lottorivisi on: ";
    
    for (int i = 0; i < NUMEROIDEN_MAARA - 3; i++)
    {
        cout << lottorivi[i] << ", ";
        
    }

    cout << "ja bonusnumerot ";
    
    // ja kayttajan bonusnumerot
    for (int i = NUMEROIDEN_MAARA - 3; i < NUMEROIDEN_MAARA; i++)
    {
        if (i == 9)
        {
            cout << lottorivi[i] << ".";
        }else
        {
            cout << lottorivi[i] << ", ";
        }
        
    }

    cout << endl << endl;

    // Tulostetaan voittonumerot
    cout << "Ja voittonumerot ovat... ";
    
    for (int i = 0; i < NUMEROIDEN_MAARA - 3; i++)
    {
        cout << lottorivi[i] << ", ";
        
    }

    cout << "ja bonusnumerot ";

    // ja voittonumeroiden bonusnumerot
    for (int i = NUMEROIDEN_MAARA - 3; i < NUMEROIDEN_MAARA; i++)
    {
        if (i == 9)
        {
            cout << lottorivi[i] << ".";
        }else
        {
            cout << lottorivi[i] << ", ";
        }
        
    }

    cout << endl << endl;

    for (int i = 0; i < NUMEROIDEN_MAARA; i++)
    {
        
    }
    
    cout << "Sait 7+3 oikein! " << endl << "Olet voittanut 10000000 euroa! ";

    cout << endl << endl << "--------------------------------------------------------------------------------" << endl;

}

// Testataan onko numero
bool onkoNumeroVarattu(int lottorivi_numero, int f_uusi_numero){

    if (lottorivi_numero == f_uusi_numero)
    {
        return true;
    }else
    {
        return false;
    }
    
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int temp_numero = 0, lottorivi[NUMEROIDEN_MAARA] = {0};
    char valikko;

    cout << "Tervetuloa helppoon lottoon, voiton saaminen on helppoa!" << endl << endl;

    do
    {
        cout << "Mitä haluaisit tehdä? (Syöta numero 1-4)" << endl;
        cout << "1: Katso palkintosummat" << endl;
        cout << "2: Pelaa koneen arpomalla rivillä" << endl;
        cout << "3: Pelaa omilla numeroilla" << endl;
        cout << "4: Lopeta pelaaminen" << endl;

        cin >> valikko;

        // Valikon vaihtoehdot
        switch (valikko)
        {
        case '1':

            cout << endl;
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

            // Silmukan lopussa asetetaan arvottu ja testattu numero taulukkoon paikalle i
            for (int i = 0; i < NUMEROIDEN_MAARA; i++)
            {
                arvonta:

                // Funktiossa arvotaan numero ja paluu asetetaan muuttujaan
                temp_numero = numeroidenArvonta();
                
                // Kutsutaan funktiota taulukon jokaisella paikalla joka testaa
                // onko numero jo kaytossa
                for (int i = 0; i < NUMEROIDEN_MAARA; i++)
                {
                    // Jos funktio palauttaa true palataan takaisin kohtaan "arvonta"
                    if (onkoNumeroVarattu(lottorivi[i], temp_numero))
                    {
                        goto arvonta;
                    }

                }

                lottorivi[i] = temp_numero;
            }
            
            // Tarkastetaan ja tulostetaan lottorivi taulukon numerot
            lottorivinTarkastus(lottorivi);
            
            break;
        case '3':

            cout << endl;
            cout << "Valitettavasti valitsemasi vaihtoehto ei ole vielä käytössä. " << endl;
            cout << endl;
        
            break;
        case '4':

            cout << "--------------------------------------------------------------------------------" << endl << endl;
            cout << "Tervetuloa uudestaan." << endl;

            break;
        default:

            cout << "--------------------------------------------------------------------------------" << endl << endl;
            cout << "\tValitettavasti valitsemasi vaihtoehto ei ole käytössä. " << endl << endl;
            cout << "--------------------------------------------------------------------------------" << endl << endl;

            break;
        }
    }while(valikko != '4');

    

    return 0;
}
