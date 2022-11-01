// 7. Tunti Viope 7 - 2
// Suorakaiteen pinta-alan laskeminen aliohjelmalla

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int Suorakaide(int x, int y){
    return x * y;
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int leveys, korkeus;

    cout << "Anna suorakaiteen korkeus: ";
    cin >> korkeus;

    cout << "Anna suorakaiteen leveys: ";
    cin >> leveys;

    cout << "Laskettu pinta-ala on: " << Suorakaide(korkeus, leveys) << endl;

    return 0;
}
