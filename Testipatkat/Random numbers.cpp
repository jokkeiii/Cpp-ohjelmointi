// Eri tapoja satunnaistaa numeroita

#include<iostream>
#include<random>
#include<cstdlib>

using namespace std;

void firstRandom(){
    random_device rand;
    uniform_int_distribution<int> dist(1,40);
    
    for (auto i = 0; i < 7; i++)
    {
        cout << dist(rand) << "   "; 
    }

}

void secondRandom(){

    for (int i = 1; i < 15; i++)
    {
        cout << rand() % 40 + 1 << endl;
    }
    
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    // firstRandom();

    secondRandom();

    return 0;
}
