#include<iostream> // Linkataan mukaan sy�te- ja tulostusk�skyt

using namespace std; // Otetaan nimiavaruus k�ytt��n

int main() {
	float hissin_painoraja, huuman1, huuman2, huuman3, huuman4, huuman_yht; //Esitell��n muuttujat

	cout << "Anna hissin painoraja kiloissa: "; //Kysyt��n muuttujaan arvo
	cin >> hissin_painoraja;

	cout << "Anna matkustaja 1 paino kiloissa: "; //Kysyt��n toiseen muuttujaan arvo
	cin >> huuman1;

	cout << "Anna matkustaja 2 paino kiloissa: "; //Kysyt��n kolmanteen muuttujaan arvo
	cin >> huuman2;

	cout << "Anna matkustaja 3 paino kiloissa: "; //Kysyt��n nelj�nteen muuttujaan arvo
	cin >> huuman3;

	cout << "Anna matkustaja 4 paino kiloissa: "; //Kysyt��n viidenteen muuttujaan arvo
	cin >> huuman4;

	huuman_yht = huuman1 + huuman2 + huuman3 + huuman4;

	if (huuman_yht > hissin_painoraja) {	//Verrataan onko ensimm�inen suurempi kuin toinen
		cout << "Ylipainoa, hissia ei saa kayttaa!";		//Jos true tulostaa merkkijonon

	}
	return 0;
}
