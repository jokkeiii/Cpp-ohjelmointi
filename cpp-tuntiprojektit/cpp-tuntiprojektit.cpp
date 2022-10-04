#include <iostream>

using namespace std;

int main()
{
	
	float tyylipisteet = 0, tuomaripisteet;

	do 
	{
		for (int i = 1; i < 6; i++)
		{
			cout << "Anna" << i << ". Tuomarin pisteet: ";
			cin >> tuomaripisteet;

		}
	} while (true);

	return 0;
}