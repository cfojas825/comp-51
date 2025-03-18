#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Car{
    public:
    string model, make;
    double originalPrice, currentPrice;
    bool isOwned_; 
    int year;
    

    Car(const string &mk, const string &md, int yr) {
        model = md;
        year = yr;
        make = mk; 
        isOwned_ = false; 
        originalPrice = 10000;
        currentPrice = 10000;

    }
    string getCarInfo(){
        return to_string(year) + " " + make + " " + model;
    }
    bool buyCar(double &userMoney) {
        if(!isOwned_ && userMoney >= currentPrice){
            userMoney -= currentPrice;
            isOwned_ = true;
             reducePriceByTenPercentOfOriginal();
            return true;

        }
        return false;
    }
    bool sellCar(double &userMoney){
        if(isOwned_){
            isOwned_ = false;
            userMoney += currentPrice; 
             reducePriceByTenPercentOfOriginal();
            return true;
        }
            return false;
    }
    void reducePriceByTenPercentOfOriginal(){
        currentPrice -= 0.10 * originalPrice;
        if (currentPrice < 0) {
            currentPrice = 0;
        }
    }
        
};
    

int main(){
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    double userMoney = 100000;

    Car car1("Porsche", "911", 2019); 
    Car car2("Acura", "Integra", 2024);
    Car car3("BMW", "M5 Competition", 2025);

    for (int i = 1; i <= 10; ++i) {
        std::cout << "\n--- Transaction " << i << " ---\n";
        int carIndex_ = std::rand() % 3;

        int action_ = std::rand() % 2;
        
        Car *selectedCar_;
        if (carIndex_ == 0) selectedCar_ = &car1;
        else if (carIndex_ == 1) selectedCar_ = &car2;
        else selectedCar_ = &car3;

        if (action_ == 0) {
            if(selectedCar_->buyCar(userMoney)) {
                cout << "Bought " << selectedCar_->getCarInfo() << " for $" << selectedCar_ -> currentPrice << endl;
            } else {
                cout << "Couldn't buy " << selectedCar_->getCarInfo() << "(already owned or insufficent funds)" << endl;
            }

            
        } else {
            if (selectedCar_->sellCar(userMoney)){
                cout << "Sold " << selectedCar_ ->getCarInfo() << " for " << selectedCar_->currentPrice << endl;
            cout << " Couldn't Sell " << selectedCar_->getCarInfo() << "( not currently owned)." << endl;
            }
        }

    cout << " The money left: $" << userMoney << endl;
    }

    cout << "\n\n--- Final Report After 10 Transactions ---\n";
 cout << "User Balance: $ " << userMoney << endl;
 
 cout << " Car 1: " << car1.getCarInfo() << endl; 
 cout << " Original Price: $" << car1.originalPrice << endl;
 cout << " Current Price: $" << car1.currentPrice << endl;
 cout << " Currently Owned? " << (car1.isOwned_? " Yes " : " No ") << "\n\n";
 
 cout << " Car 2: " << car2.getCarInfo() << endl; 
 cout << " Original Price: $" << car2.originalPrice << endl;
 cout << " Current Price: $" << car2.currentPrice << endl;
 cout << " Currently Owned? " << (car2.isOwned_? " Yes " : " No ") << "\n\n";

 cout << " Car 3: " << car3.getCarInfo() << endl; 
 cout << " Original Price: $" << car3.originalPrice << endl;
 cout << " Current Price: $" << car3.currentPrice << endl;
 cout << " Currently Owned? " << (car3.isOwned_? " Yes " : " No ") << "\n\n";
   
    return 0;
}
