// 8. Tunti Viope 8 - 4
// Koodin toiminta selitettyna lyhyesti

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string VuorokaudenAika(int x){

    // Jos aika on joidenkin kahden valissa return kyseinen vuorokaudenaika
    if (x >= 6 && x <= 11)
    {
        return "aamu";
    }else if (x >= 12 && x <= 16)
    {
        return "päivä";
    }else if (x >= 17 && x <= 22)
    {
        return "ilta"; 
    }else
    {
        return "yö";
    }
      
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int kellon_aika;
    string paivan_aika;

    cout << "Anna kellonaika tunneissa (0-23): "; 
    cin >> kellon_aika; 

    // Kutsutaan funktio parametrina syote ja tulostetaan sen palautus
    cout << "Hetki päivästä on " << VuorokaudenAika(kellon_aika);
    return 0;
}
