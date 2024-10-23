#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> storage;

// Rounds given value to nearest whole number
double round(double d) {
    return floor(d + 0.5);
}

// Welcome Message Print statement called at start of program
void welcomeMessage() {
    printf("Welcome to my . . . \n");
    printf("  _____      _            _       _             \n");
    printf(" / ____|    | |          | |     | |            \n");
    printf("| |     __ _| | ___ _   _| | __ _| |_ ___  _ __ \n");
    printf("| |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__|\n");
    printf("| |___| (_| | | (__| |_| | | (_| | || (_) | |   \n");
    printf(" \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|   \n");
    printf("Made by Matthew Class :D\n\n");
}

// Either can store value into history or be called to view previous calculations
void history(int ch, double val = 0) {
    printf("\n");
    switch(ch) {
        case 1: // Store value into storage
            storage.push_back(val);
            break;
        case 2: // View storage
            if(storage.size() == 0)
                printf("[ ]\n");
            else {
                printf("[");
                for(int i = 0; i < storage.size(); i++) {
                    if(i % 10 == 0)
                        printf("\n");
                    printf("%f ", storage[i]);
                }
                printf("\b]\n");
            }
            break;
        default: // Invalid input
            break;
    }
}

void calculate() {
    double n1, n2, res;
    char op;
    printf("\nDirections: (1)Enter a numerical value. (2)Click enter (3)Enter your operator (4)Enter 2nd numerical value (5)Repeat from (2) as necessary or click type S to save to history and reset. . .\n");
    std::cin >> n1;
    std::cin >> op;
    std:: cin >> n2;

    // Switch case to cover different operations
    switch(op) {
        case('+'):
            res = n1 + n2;
            break;
        case('-'):
            res = n1 - n2;
            break;
        case('*'):
            res = n1 * n2;
            break;
        case('/'):
            res = n1 / n2;
            break;
        case('%'):
            int tmp1, tmp2;
            tmp1 = int(round(n1));
            tmp2 = int(round(n2));
            res = tmp1 % tmp2;
            break;
        case('^'):
            res = pow(n1, n2);
            break;
        default:
            printf("Invalid input\n");
            break;
    }

    printf("%f\n\n", res);
    history(1, res);
}

// NEED TO DO
// Gives help on what the calculator can do
void help() {
    printf("\nhelp help help\n");
}

// Prints the menu options for the user
void mainMenu() {
    int input;
    bool ck = true;
    while(ck) {
        printf("\nPlease enter value for menu options. . .\n");
        printf("1: Calculate\n");
        printf("2: History\n");
        printf("3: Help\n");
        printf("4: Exit\n");
        std::cin >> input;
        
        switch(input) {
            case 1: // Calculate
                calculate();
                break;
            case 2: // History
                history(2);
                break;
            case 3: // Help
                help();
                break;
            case 4: // Exit
                ck = false;
                break;
            default:
                printf("Invalid input. Please try again!\n\n");
                break;
        }
    }
}

int main() {
    welcomeMessage();
    mainMenu();
}
                                                