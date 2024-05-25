#include <iostream>

int intToSquare(int a){
    return a*a;
}

int main (){
    int a, b;

    std::cout << "\nWhat number would you like to square?\n";
    std::cin >> a;

    std::cout << "\nThe square of " << a << " is " << intToSquare(a) << ".\n"; 

    system("pause");
    return 0;
}

