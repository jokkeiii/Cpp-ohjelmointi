// 8. Tunti Viope 8 - 3
// Koodin toiminta selitettyna lyhyesti

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

unsigned long Fibonacci(int x){

    if((x==1)||(x==0)) {
    
        return(x);
    }

    // Jos x >= 2 lasketaan x-1 + x-2
    return(Fibonacci(x-1)+Fibonacci(x-2));
}


int main() {
    setlocale(LC_ALL, "fi_FI");
    
    int syote; 
    unsigned long fibonacci_num; 

    cout << "Anna fibonaccin lukujen maara: ";
    cin >> syote; 
    cout << endl; 

    cout << "Fibonnacci Sarja : "; 

    for (int i = 0; i < syote; i++){
        // 
        fibonacci_num = Fibonacci(i); 
        cout << " " << fibonacci_num;
    }
    

    return 0;
}
