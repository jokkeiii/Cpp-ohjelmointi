// 5. Tunti Viope 5 - 2
// While –silmukan käyttöä. Tee tiliohjelma, joka pitää yllä saldoa ja jossa voit tallettaa ja nostaa rahaa.

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

    int toiminto, saldo = 0, nosto, talletus;

	cout << "Tervetuloa!" << endl;
    cout << "Tililla on rahaa: " << saldo << " euroa" << endl;
    
    // Kysytään ensimmainen toiminta
    cout << "Valitse toiminto (1.Talleta, 2.Nosta, 3.Lopeta): ";
    cin >> toiminto;
    
    // Jos toiminto ei ole 3 eli lopetus jatketaan
    while (toiminto != 3)
    {
        // Jos toiminto on 1
        if (toiminto == 1)
        {   
            // Pyydetaan talletettava summa, asetetaan se "talletus" muuttujaan, lisataan se saldoon ja tulostetaan saldo
            cout << "Syota talletettava rahasumma: ";
            cin >> talletus;
            saldo += talletus;
            cout << "Tililla on rahaa: " << saldo << " euroa" << endl;
        }
        // Jos toiminto on 2
        if (toiminto == 2)
        {
            // Pyydetaan nostettava summa, asetetaan se "nosto" muuttujaan, vahennetaan se saldosta ja tulostetaan saldo
            cout << "Syota nostettava summa: ";
            cin >> nosto;
            saldo -= nosto;
            cout << "Tililla on rahaa: " << saldo << " euroa" << endl;
        }
        
        // Kysytaan lopussa uudestaan toiminto ja palataan "while" alkuun
        cout << "Valitse toiminto (1.Talleta, 2.Nosta, 3.Lopeta): ";
        cin >> toiminto; 
    }
    
    // Tulostetaan "Nakemiin." ja lopetetaan ohjelma
    cout << "Nakemiin.";
    
    return 0;
}
