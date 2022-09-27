#include<iostream> // Linkataan mukaan sy�te- ja tulostusk�skyt

using namespace std; // Otetaan nimiavaruus k�ytt��n

int main() {
	float pituus1, pituus2; //Esitell��n muuttujat

	cout << "Anna ensimmaisen henkilon pituus(cm): "; //Kysyt��n muuttujaan arvo
	cin >> pituus1;

	cout << "Anna toisen henkilon pituus(cm): "; //Kysyt��n toiseen muuttujaan arvo
	cin >> pituus2;

	if (pituus1 > pituus2) {	//Verrataan onko ensimm�inen suurempi kuin toinen
		cout << pituus1;		//Jos true tulostaa ensimm�isen muutujan arvon
	}
	else {						//Jos false tulostaa toisen muuttujan arvon
		cout << pituus2;
	}
	return 0;
}
