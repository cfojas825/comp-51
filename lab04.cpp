#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
int rollDie() {
    return (rand() % 6 ) + 1; // generating a random number 1-6
   
    }

int rollMultipleDice(int numberOfDice) {    // returning the total sum and the use of function to roll dice :)
    int _total = 0;
    for (int i = 0; i < numberOfDice; i++){
        int _roll = rollDie(); // uses the rand % 6 
        std::cout << "Rolled: " << _roll << std::endl;
        _total  += _roll;
    }
    return _total;
}
int playRound(){      // uses the rollMultiple dice function, also a function to play a round and return the result of it 
    std::cout << "It's the player's turn.... "<< std::endl;
    int _playerTotal = rollMultipleDice(2);

    
    std::cout << "Ouuu.. its the computer's turn... " << std::endl;
    int _computerTotal = rollMultipleDice(2);

    if( _playerTotal < _computerTotal){
        std::cout << "Good Job you win this round!"<<std::endl;
        return 1;

    }else if (_playerTotal == _computerTotal){
        std::cout << "Woah a draw, interesting....."<<std::endl;
        return 0; 
    }else{
        std::cout << "Im sorry but you lose this round"<<std::endl;
        return -1;
    }
}

int shop(int currentScore){          // this is the shop, where the player chooses their option and shows the score 
    
    std::cout << "Hi! Welcome to the Shop! What Would you like to purchase?" << " Your current score is: " << currentScore << std::endl;
    std::cout << "Shop " <<std::endl;
    std::cout << "1. Add +5 points (Cost: 5 points)" <<std::endl;
    std::cout << "2. Add +15 points (Cost: 10 points)"<<std::endl;
    std::cout << "3. Exit Shop -_-"<<std::endl;
    std::cout << "Enter your choice: ";


    int choice_;
    std::cin >> choice_;

    if(choice_ == 1 ) {
        if(currentScore >= 5){
        currentScore -= 5;
        currentScore += 5;
        std::cout <<" Awesome! you gained 5 points! "<<std::endl;
    } else { 
        std::cout<< " Sorry, you don't have enough points for this purchase :( "<<std::endl;
    }
     } else if (choice_ == 2){
        if(currentScore >= 10){
        currentScore += 15;
        currentScore -= 10;
        std::cout << "Woah! you gained 15 points!"<<std::endl;
        }
        } else if (choice_ == 3){
            std::cout << "Exiting shop -_-"<<std::endl;
        } else {
            std::cout <<" Sorry, you don't have enough points for this purchase :( "<<std::endl;
    
        }
        return currentScore;
}


    
    


void displayStatistics( int totalRounds, int wins, int draws, int losses, int finalScore) {   // displaying player stats from the dice game 
    std::cout << "   Game Over!  ";
    std::cout <<"Round Played: " << totalRounds <<std::endl;
    std::cout << "Wins: " << wins << "  | Draws:  " << draws << " | Losses: " << losses <<std::endl;
    std::cout << "Final Score: " << finalScore <<std::endl;
    

    if(wins > losses){           // Just something extra 
        std::cout<< "\n OMG YOU ARE THE CHAMPION!!!!!!!\n";
    }else if ( wins == losses){
        std::cout << "\nOH MY IT WAS A TOUGH MATCH\n";
    
    }else{
        std::cout<< " Dang better luck next time bud"<<std::endl;
    }

    std::cout << "Thanks for playing, come test your luck again if you're feeling lucky...";

}

int main(){
    srand(time(0)); // number generator 

    int _score1 = 0;                // variables for the score, rounds played, stats like wins, draws, and losses
    int _rounds = 0;
    int wins_ = 0, draws_ = 0, losses_ = 0; 

    char playAgain_ = 'y';

   do {     // This is where it starts 
    _rounds++;
    std::cout << "Round..." << _rounds << " Begins!!!!"<<std::endl;
   
   std::cout<< "Would you like to visit the shop? (y/n): "; 
   char playerShopChoice;
   std::cin >> playerShopChoice;
   
   if (playerShopChoice == 'y' || playerShopChoice == 'Y'){
    _score1 = shop(_score1);
   }
    
   int result_ = playRound();     // uses the function 


    if(result_ == 1){
        _score1+= 20;
        wins_++;
   
    } else if (result_ == 0) {
        _score1 += 5;
        draws_++;
    }else{
        losses_++; // keeps in track of the losses and increases every time player loses 
    }

    std::cout<< " Current score right now is: "<< _score1 << std::endl;

    std::cout <<" Would you like to play another round....? (y/n): ";
    std::cin>>playAgain_;
}
 while (playAgain_ == 'y' || playAgain_ == 'Y');

    displayStatistics(_rounds, _score1, wins_, losses_, draws_);    // uses the function to display the stats 
   return 0;
}