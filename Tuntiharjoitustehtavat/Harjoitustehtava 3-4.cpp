#include<iostream> // Linkataan mukaan syote- ja tulostuskaskyt

using namespace std; // Otetaan nimiavaruus kayttaan

int main() {
	char op;
	float eka, toka, summa, erotus, tulo, osamaara;

	cout << "Valitse laskutoimitus (+ - * /): ";
	cin >> op;

	cout << "Anna luku: ";
	cin >> eka;

	cout << "Anna toinen luku: ";
	cin >> toka;

	if (op == '*')
	{
		tulo = eka * toka;
		cout << "Lukujen tulo on " << tulo;
	}
	else if (op == '/')
	{
		osamaara = eka / toka;
		cout << "Lukujen osamaara on " << osamaara;
	}
	else if (op == '+')
	{
		summa = eka + toka;
		cout << "Lukujen summa on " << summa;
	}
	else
	{
		erotus = eka - toka;
		cout << "Lukujen erotus on " << erotus;
	}
	return 0;
}
