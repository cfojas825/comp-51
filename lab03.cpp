#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
int main(){
    int playerGuess, computerChoice, guessedCorrectly;
    std::srand(std::time(0));
    computerChoice = std::rand() % 100 + 1;
    char playAgain;
    
    do {
    bool guessedCorrectly = false;
    
    std::cout << "Hi! Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "You will have 5 guesses, so choose wisely.";
 
 for (int i = 0; i < 5; i++) {
    std::cout << " Guess your number here: ";
    std::cin >> playerGuess;
    
    if(playerGuess == computerChoice){
        std::cout << " Congratulations! You guessed the number."<<std::endl;
        guessedCorrectly = true;
        break;
    
     } else if(playerGuess > computerChoice) {
         std::cout << "Too high! Guess Again!";
    
    
    } else { 
         std::cout << "Too low! Don't give up!" << std::endl;
    }
              if(i < 4){
                std:: cout << " You only have " << (4 - i) << " attempts left, choose carefully!";
            }
         }
         if(!guessedCorrectly) {
             std::cout << "Unfournately you are out of attempts the correct number was " << computerChoice <<".";
            }
            std::cout << " Would you like to play again Y/N: ";
            std::cin >> playAgain;
         
    } while (playAgain == 'Y' || playAgain == 'y');
        
        std::cout << "Thank you for playing! Come back if you're feeling lucky..";
    
    return 0;
}
