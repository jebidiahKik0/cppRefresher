#include <iostream>

int main(){
    // Initializes a variable > Asks the user for input >> Recieves information
    int number;
    std::cout << "Please enter a number: ";
    std::cin >> number;

    if (number % 2 == 0){
        std::cout << "This number is EVEN.\n";
    } else{
        std::cout << "This number is ODD.\n";
    }

    system("pause");
    return 0;
}