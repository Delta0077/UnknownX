#include <iostream>
#include<ctime>


void PrintIntroduction(int Difficulty)
{
    //Print Welcome messages to the terminal
    std::cout << "Welcome to UnknownX";
    std::cout << std::endl;
    std::cout << "You are a top class programmer, so you have been hired by a multinational criminal organization for breaking into a level " << Difficulty  ;
    std::cout << std::endl;
    std::cout << "secure swiss bank's strong room.....\nEnter the correct code combination to unlock and loot the vaults.......\n\n";
    
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    //print CodeSum and CodeProduct of a,b,c
    
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to give: "<<CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct<<std::endl;

    // Store player guess
    int GuessA,GuessB,GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    //std::cout << "You entered: " <<GuessA <<GuessB <<GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct= GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum==CodeSum && GuessProduct==CodeProduct)
    {
        std::cout << "*** Good job agent! You have unlocked a vault! Keep going ***\n\n";
        
        return true;
    }
    else {
        std::cout << "*** You entered wrong code! Try again! ***\n\n";
        return false;
    }
}


int main()

{
    srand(time(NULL));// create new random sequence based on time of day
    int LevelDifficulty=1;
    int const MaxLevel = 5 ;

    while (LevelDifficulty <= MaxLevel) // Loop continues untill all levels are completed
    {
        
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();//Clear any errors
        std::cin.ignore();//Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "Congratulations You have completed all levels.....";

    return 0;
}