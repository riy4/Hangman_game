#include <iostream>
#include <string>
#include <vector>

void drawHangman(int incorrectGuesses) {
    std::cout << "   +---+" << std::endl;
    std::cout << "   |   |" << std::endl;

    if (incorrectGuesses > 0) {
        std::cout << "   O   |" << std::endl;
    } else {
        std::cout << "       |" << std::endl;
    }

    if (incorrectGuesses == 2) {
        std::cout << "   |   |" << std::endl;
    } else if (incorrectGuesses == 3) {
        std::cout << "  /|   |" << std::endl;
    } else if (incorrectGuesses >= 4) {
        std::cout << "  /|\\  |" << std::endl;
    } else {
        std::cout << "       |" << std::endl;
    }

    if (incorrectGuesses == 5) {
        std::cout << "  /    |" << std::endl;
    } else if (incorrectGuesses >= 6) {
        std::cout << "  / \\  |" << std::endl;
    } else {
        std::cout << "       |" << std::endl;
    }

    std::cout << "       |" << std::endl;
    std::cout << "=========" << std::endl;
}

void printWordState(const std::vector<bool>& guessedLetters, const std::string& word) {
    for (std::size_t i = 0; i < word.length(); ++i) {
        if (guessedLetters[i]) {
            std::cout << word[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

bool isWordGuessed(const std::vector<bool>& guessedLetters) {
    for (bool guessed : guessedLetters) {
        if (!guessed) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string word;
    int maxAttempts = 6;
    int incorrectGuesses = 0;
    std::vector<bool> guessedLetters;

    std::cout << "Welcome to Hangman! Enter the word to be guessed: ";
    std::cin >> word;

    guessedLetters.resize(word.length(), false);

    while (incorrectGuesses < maxAttempts) {
        std::cout << "Guessed word state: ";
        printWordState(guessedLetters, word);

        char guess;
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        bool foundGuess = false;

        for (std::size_t i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                guessedLetters[i] = true;
                foundGuess = true;
            }
        }

        if (!foundGuess) {
            ++incorrectGuesses;
            std::cout << "Incorrect guess!" << std::endl;
            drawHangman(incorrectGuesses);
        }

        if (isWordGuessed(guessedLetters)) {
            std::cout << "Congratulations! You guessed the word correctly: " << word << std::endl;
            break;
        }
    }

    if (incorrectGuesses == maxAttempts) {
        std::cout << "Sorry, you lost! The word was: " << word << std::endl;
    }

    return 0;
}

