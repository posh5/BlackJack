#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MIN_VALUE 1
#define MAX_VALUE 10

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int draw_card() {
    return MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    SetConsoleTitleA("BLACKJACK - The House Always Wins");
  
    while (1) {
        printf("Made with " ANSI_COLOR_RED "\x03" ANSI_COLOR_RESET" by NSI\n");
        printf("P: Pl" ANSI_COLOR_RED "\x03" ANSI_COLOR_RESET"y\n");
        printf("E: Exit\n");
        printf("Enter your choice: ");
        char choice = getchar();
        getchar();
        if (choice == 'E' || choice == 'e') {
            exit(0);
        }
        else if (choice == 'P' || choice == 'p') {
            system("cls");
            int player_total = 0;
            int dealer_total = 0;

            // Initial
            player_total += draw_card();
            dealer_total += draw_card();
            player_total += draw_card();
            dealer_total += draw_card();

            printf(ANSI_COLOR_GREEN "Your total is: %d\n" ANSI_COLOR_RESET, player_total);
            printf(ANSI_COLOR_RED "Dealer's total is: %d\n" ANSI_COLOR_RESET, dealer_total);

            // Player
            while (1) {
                printf(ANSI_COLOR_GREEN "Hit or stand? (h/s) " ANSI_COLOR_RESET);
                char action = getchar();
                getchar();
                if (action == 's') {
                    break;
                }
                else if (action == 'h') {
                    player_total += draw_card();
                    printf(ANSI_COLOR_GREEN "Your total is now: %d\n" ANSI_COLOR_RESET, player_total);
                    if (player_total > 21) {
                        printf(ANSI_COLOR_RED "You busted!\n" ANSI_COLOR_RESET);
                        break;
                    }
                }
                else {
                    system("cls");
                }
            }

            // Dealer
            while (dealer_total < 17) {
                printf
                (ANSI_COLOR_RED "Dealer hits.\n" ANSI_COLOR_RESET);
                dealer_total += draw_card();
            }
            printf(ANSI_COLOR_RED "Dealer's total is now: %d\n" ANSI_COLOR_RESET, dealer_total);

            if (dealer_total > 21) {
                printf(ANSI_COLOR_GREEN "Dealer busted, you win!\n" ANSI_COLOR_RESET);
                Sleep(1500);
                system("cls");
            }
            else if (dealer_total > player_total) {
                printf(ANSI_COLOR_RED "Dealer wins.\n" ANSI_COLOR_RESET);
                Sleep(1500);
                system("cls");
            }
            else if (dealer_total < player_total) {
                printf(ANSI_COLOR_GREEN "You win!\n" ANSI_COLOR_RESET);
                Sleep(1500);
                system("cls");
            }
            else {
                printf("It's a tie.\n");
                Sleep(1500);
                system("cls");
            }
        }
        else {
            system("cls");
        }

    }

    while (1) {
        printf("Menu:\n");
        printf("P: Play again\n");
        printf("E: Exit\n");
        printf("Enter your choice: ");
        char choice = getchar();
        getchar();
        if (choice == 'P' || choice == 'p') {
            system("cls");
            break;
        }
        else if (choice == 'E' || choice == 'e') {
            return 0;
        }
        else {
            system("cls");
        }
    }
}
