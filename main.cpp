#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <algorithm>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::string choices[] = {"rock", "paper", "scissors"};
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "## Welcome to Rock..Paper..Scissors! ##" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Please chose now between Rock, Paper or Scissors !" << std::endl;
    std::string userChoice;
    std::getline(std::cin, userChoice);

    std::transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);

    bool isValidChoice = false;
    for (const std::string& choice : choices) {
        std::string lowercaseChoice = choice;
        std::transform(lowercaseChoice.begin(), lowercaseChoice.end(), lowercaseChoice.begin(), ::tolower);
        if (userChoice == lowercaseChoice) {
            isValidChoice = true;
            break;
        }
    }

    if (isValidChoice) {
        std::cout << "You chose " << userChoice << std::endl;
        int computerChoiceIndex = std::rand() % 3;
        std::string computerChoice = choices[computerChoiceIndex];
        if (userChoice == computerChoice) {
            std::cout << "Computer chose " << computerChoice << ".." << std::endl;
            std::cout << "It's a tie, You will win next time !" << std::endl;
            } else if (
                (userChoice == "rock" && computerChoice == "scissors") ||
                (userChoice == "paper" && computerChoice == "rock") ||
                (userChoice == "scissors" && computerChoice == "paper")
                ) {
                    std::cout << "Computer chose " << computerChoice << "." << std::endl;
                    std::cout << "You win !" << std::endl;
                } else {
                    std::cout << "Computer chose " << computerChoice << "." << std::endl;
                    std::cout << "Sadly you lost... Next time maybe !" << std::endl;
                    }
        } else {
            std::cout << "Please choose only between: rock, paper, scissors." << std::endl;
        }
    return 0;
}