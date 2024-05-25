#include <iostream>

int main(){

    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i = 0; i < 10; i++){
        std::cout << numbers[i] << "\n";
    }

    system("pause");
    return 0;
}