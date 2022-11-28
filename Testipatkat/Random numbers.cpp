// Eri tapoja satunnaistaa numeroita

#include<iostream>
#include<random>

using std::cout;
using std::cin;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;

int main() {
    setlocale(LC_ALL, "fi_FI");
    
    random_device rand;
    uniform_int_distribution<int> dist(1,9);
    
    for (auto i = 0; i < 10; i++)
    {
        cout << dist(rand) << " ";
    }

    return 0;
}
