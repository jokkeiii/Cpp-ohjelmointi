// Eri tapoja satunnaistaa numeroita

#include<iostream>
#include<random>

using std::cout;
using std::cin;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;

void firstRandom(){
    random_device rand;
    uniform_int_distribution<int> dist(1,40);
    
    for (auto i = 0; i < 7; i++)
    {
        cout << dist(rand) << "   "; 
    }

}

void secondRandom(){
    
}

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    // firstRandom();

    secondRandom();

    return 0;
}
