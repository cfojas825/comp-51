#include <iostream>

int main() { 
    int temperature; 
    double budget; 
    int weatherCode; 
    std::cout << "Put current temperature (in degrees): "; 
    std::cin >> temperature; 
    std::cout<< "Enter your budget (dollars): "; 
    std::cin >> budget; 
    std::cout<< "1 for sunny, 2 for rainy, 3 for cloudy: "; 
    std::cin >> weatherCode; 
    
    if (weatherCode == 1 && temperature > 75) { 
        if (budget > 20) { 
        std::cout<< "Go to the beach!" << std::endl; 
    
    } else { 
        std::cout << "Have a picnic." << std::endl; 
    } 
     } else if (weatherCode == 2) {  
        if (budget > 15){ 
        std::cout<< "Go to a museum." << std::endl; 
    } else { 
        std::cout << "Watch a movie at home." << std::endl; 
    } 


} else if (weatherCode == 3 || temperature < 60) { 
    std::cout<< "Visit a coffee shop." << std::endl; 
    
     } else { 
        std::cout << "Invalid input. Please try again." << std::endl; 
    }
return 0;
}