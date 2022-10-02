// Huomionarvoista lisatehtavien numeroinnissa: Tama on ensimmainen lisatehtava jonka olen tehnyt. Kuitenkin tehtava on jo neljas tunneilla vastaan tullut.
#include<iostream>
#include<cmath>

using namespace	std;

int main() {

	char op;
	float eka, toka;
	cout << "Valitse laskutoimitus:\n(+ - * /)\nTAI\n(s = sin, c = cos, t = tan, e = exp, l = log, r = square root, p = power)\n:";
	cin >> op;
	
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == 'p')
	{
		cout << "Anna luku: ";
		cin >> eka;

		cout << "Anna toinen luku: ";
		cin >> toka;

		if (op == '*')
		{
			cout << "Lukujen tulo on " << eka * toka;
		}
		else if (op == '/')
		{
			cout << "Lukujen osamaara on " << eka / toka;
		}
		else if (op == '+')
		{
			cout << "Lukujen summa on " << eka + toka;
		}
		else if (op == '-')
		{
			cout << "Lukujen erotus on " << eka - toka;
		}
		else
		{
			cout << "Ensimmainen luku toisen luvun potenssiin on " << pow(eka, toka);
		}
	}
	else
	{
		cout << "Anna kaytettava luku: ";
		cin >> eka;

		if (op == 's')
		{
			cout << "Luvun sini on " << sin(eka);
		}

		else if (op == 'c')
		{
			cout << "Luvun cosini on " << cos(eka);
		}

		else if (op == 't')
		{
			cout << "Luvun tangentti on " << tan(eka);
		}

		else if (op == 'e')
		{
			cout << "Luku on exp " << exp(eka);
		}

		else if (op == 'l')
		{
			cout << "Luvun logaritmi on " << log(eka);
		}

		else if (op == 'r')
		{
			cout << "Luvun neliojuuri on " << sqrt(eka);
		}
		
	}
	return 0;
}
