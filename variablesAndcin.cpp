#include <iostream>

int main(){

    int age, favoriteNumber;
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "What is your favorite number? ";
    std::cin >> favoriteNumber;
    std::cout << "What is your age? ";
    std::cin >> age;    
    std::cout << "Hello, " << name << ". You are " << age << 
    "years old. Your favorite number is " << favoriteNumber << ".\n";


    system("pause");
    return 0;
}