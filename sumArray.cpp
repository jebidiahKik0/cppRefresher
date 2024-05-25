# include <iostream>

int main(){
    int sum;
    int sumArray[5] = {10, 2, 3, 4, 5};
    
    for(int i = 0; i < 5; i++){
        sum += sumArray[i];
    }
    std::cout << "\nThe sum is " << sum << " .\n";


    system("pause");
    return 0;
}