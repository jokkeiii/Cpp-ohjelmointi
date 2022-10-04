#include <iostream>

using namespace std;

int main()
{
	
	float tyylipisteet = 0, tuomaripisteet;

		for (int i = 1; i < 6; i++)
		{
			cout << "Anna " << i << ". Tuomarin pisteet: ";
			cin >> tuomaripisteet; // Tassa kysytaan yksittaisen tuomarin pisteet
			if (tuomaripisteet < 0 || tuomaripisteet > 20)
				i--;
			else
				tyylipisteet += tuomaripisteet;
		}
	return 0;
}