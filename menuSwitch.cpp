#include <iostream>

int main(){
    int number;
    std::cout << "Please choose a dish:\n";
    std::cout << "1. Fish and Chips.\n";
    std::cout << "2. Spaghetti and Meatball\n";
    std::cout << "3. Salmon with Mango Puree\n";
    std::cout << "4. Tripe with Fishballs.\n";
    std::cout << "5. Lousiana Gumbo\n";
    std::cin >> number;
    
    switch (number){
        case 1:
            std::cout << "You have chosen Fish and Chips." << std::endl;
            break;
        case 2:
            std::cout << "You have chosen Spaghetti and Meatball" << std::endl;
            break;
        case 3:
            std::cout << "You have chosen Salmon and Mango Puree." << std::endl;
            break;
        case 4:
            std::cout << "You have chosen Tripe with Fishballs." << std::endl;
            break;
        case 5:
            std::cout << "You have chosen Lousiana Gumbo" << std::endl;
            break;
        
        default: std::cout << "Invalid Menu Choice" << std::endl;
            break;
    }


    system("pause");
    return 0;
}