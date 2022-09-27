#include<iostream> // Linkataan mukaan sy�te- ja tulostusk�skyt

using namespace std; // Otetaan nimiavaruus k�ytt��n

int main() {
	float kanta, korkeus, ala; //Esitell��n muuttujat
	
	cout << "Anna kolmion kanta metreina: "; //Kysyt��n muuttujaan arvo
	cin >> kanta;
	
	cout << "Anna kolmion korkeus metreina: ";//Kysyt��n muuttujaan arvo
	cin >> korkeus;
	
	ala = kanta * korkeus / 2; //Lasketaan kysyttyjen arvojen perusteella pinta-ala
	
	cout << "Kolmion pinta-ala on " << ala; //Tulostetaan laskettu pinta-ala
	
	return 0;
}
