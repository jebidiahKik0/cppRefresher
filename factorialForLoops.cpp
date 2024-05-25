#include <iostream>

int main(){
    //Initalize Variables Needed
    int number; 
    unsigned long long factorial = 1;

    //Ask and take in a number
    std::cout << "Please enter a number: \n";
    std::cin >> number;


    //loop to determin factorial
    for(int i = number; i >= 1; i--){
        std::cout << i;
        factorial *=i;
    }
    //print answer
    std::cout << "\nThe factorial of " << number << " is " << factorial << ".\n";




    system("pause");
    return 0;
}