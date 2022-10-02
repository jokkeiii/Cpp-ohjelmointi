// 4. Tunti - Viope 4 - 1
// Yksinkertainen verolaskuri
// Tampereella asuva maksaa kunnallisveroa bruttotuloistaan tänä vuonna 19.75%.
//  Lisäksi valtiolle menee tuloveroa, jonka määrä riippuu tuloista seuraavan taulukon mukaisesti:
/* 
Verotettava ansiotulo, euroa	Vero alarajan kohdalla, euroa	Vero alarajan ylittavasta tulon osasta,  %
16 900—25 300	                8	                            6,25
25 300—41 200	                533	                            17,5
41 200—71 400	                3 315,50	                    21,5
71 400—	                        10 174	                        31,5 
*/

#include<iostream>              // cin-cout kirjaston linkkaaminen

using namespace std;            // Nimiavaruus standard kaytossa

int main() {
    
    float tulot, kunta_vero = 0.1975, yht_verot; // Tarvittavat muuttujat

    cout << "Syota tulosi: " << endl; // Kysytaan kayttajalta tulot
    cin >> tulot;

    if (tulot >= 16900 && tulot < 25300) // Jos tulot ovat ensimmaisen vero-osan rajoissa
    {
        yht_verot = (tulot - 16900) * 0.0625 + 8 + (tulot * kunta_vero); // Lasketaan alarajan ylimenevasta osasta verot ja lisataan euromaaraan verot alarajan kohdalla
        cout << "Sinun pitaa maksaa " << yht_verot << " euroa veroa."; 
    }
    else if (tulot >= 25300 && tulot < 41200) // Jos tulot ovat toisen vero-osan rajoissa
    {
        yht_verot = (tulot - 16900) * 0.175 + 533 + (tulot * kunta_vero); 
        cout << "Sinun pitaa maksaa " << yht_verot << " euroa veroa.";
    }
    else if (tulot >= 41200 && tulot < 71400) // Jos tulot ovat ensimmaisen vero-osan rajoissa
    {
        yht_verot = (tulot - 16900) * 0.215 + 3315.5 + (tulot * kunta_vero); 
        cout << "Sinun pitaa maksaa " << yht_verot << " euroa veroa.";
    }
    else if (tulot >= 71400) // Jos tulot ovat ensimmaisen vero-osan rajoissa
    {
        yht_verot = (tulot - 71400) * 0.315 + 10174 + (tulot * kunta_vero); 
        cout << "Sinun pitaa maksaa " << yht_verot << " euroa veroa.";
    }
    else // Jos tulot ovat alle ensimmaisen vero-osan rajan 
    {
       yht_verot = tulot * kunta_vero; // Jatetaan ansiotuloverot huomioimatta ja lasketaan ainoastaan kunnallisvero
        cout << "Sinun pitaa maksaa " << yht_verot << " euroa veroa.";
    }
    
    
    

    return 0;
}