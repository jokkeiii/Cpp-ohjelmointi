#include <iostream>

using namespace std;

int main()
{
	
	float tyylipisteet = 0, tuomaripisteet;

	for (int i = 1; i < 6; i++)
	{
		// Tassa kysytaan yksittaisen tuomarin pisteet
		cout << "Anna " << i << ". Tuomarin pisteet: ";
		cin >> tuomaripisteet; 
		
		// Jos annetut pisteet ovat alle 0 tai yli 20 
		// kysytaan kyseisen tuomarin pisteet uudelleen
		if (tuomaripisteet < 0 || tuomaripisteet > 20)
		i--;
		
		else {
			tyylipisteet += tuomaripisteet;
		}
	}	
	return 0;
}