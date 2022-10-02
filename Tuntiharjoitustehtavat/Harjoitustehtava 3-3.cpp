#include<iostream> // Linkataan mukaan syote- ja tulostuskaskyt

using namespace std; // Otetaan nimiavaruus kayttoon

int main() {
	float letter_weight;
	cout << "Anna kirjeen paino grammoina: "; // Kysytaan muuttujaan arvo
	cin >> letter_weight;

	if (letter_weight <= 50)
		cout << "Kirjeen lahetyksen hinta kotimaassa on 0.6 euroa";

	else if (letter_weight <= 100)
	{
		cout << "Kirjeen lahetyksen hinta kotimaassa on 0.9 euroa";
	}

	else if (letter_weight <= 250)
	{
		cout << "Kirjeen lahetyksen hinta kotimaassa on 1.3 euroa";
	}

	else if (letter_weight <= 500)
	{
		cout << "Kirjeen lahetyksen hinta kotimaassa on 2.1 euroa";
	}

	else if (letter_weight <= 1000)
	{
		cout << "Kirjeen lahetyksen hinta kotimaassa on 3.1 euroa";
	}

	else if (letter_weight <= 2000)
	{
		cout << "Kirjeen lahetyksen hinta kotimaassa on 5.5 euroa";
	}

	else
	{
		cout << "Lahetys on liian painava kirjeeksi!";
	}

	return 0;
}
