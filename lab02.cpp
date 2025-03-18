#include <iostream>
#include <string> 
int main(){
    float balance = 1000.00;
    int userChoice;

   std::cout << "Welcome to Simple ATM Simulator!" << std::endl;
     while (true) { 
    std::cout << "Menu: " << std::endl;
    std::cout << "1. Check Balance" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Exit" << std::endl;
    
    std::cout << "Enter your Choice: ";
    std::cin >> userChoice;
    
    if(userChoice == 1){
        std::cout << "Your current balance is: $" << balance << std::endl;
    
    } else if(userChoice == 2) {
        float depositAmount;
            std::cout << "Enter the amount to deposit: "; 
            std::cin >> depositAmount;
            balance += depositAmount; 
         std::cout<< " Deposit successful! Your new balance is: $" << balance <<std::endl;

        } else if(userChoice == 3) {
            float withdrawAmount;
            std::cout << "Enter the amount to withdraw: "; 
            std::cin >>withdrawAmount; 
            if(withdrawAmount > balance){
            std:: cout<< "Insufficient funds" << std::endl;  

            } else { 
                balance -= withdrawAmount; 
                std::cout<<"Withdrawal successful! Your new balance is: $" << balance << std::endl;
            }
            
            
            } else if(userChoice == 4) {
                std::cout<<"Thank you for using ATM. Goodbye!";
                break;
            } else {
                std::cout<<"Invalid choice. Please try again.";
            }
         }
}