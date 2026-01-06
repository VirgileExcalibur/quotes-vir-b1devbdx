// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

void menu() {
    printf("\n==== Programming Quotes ====\n");
    printf("1. Random quote\n");
    printf("2. All quotes\n");
    printf("3. Add quotes\n");
    printf("4. Exit\n");
}

int main() {
    srand(time(NULL));
    int choice;
    
    while (1) {
        QuoteArray * quotes = load_quotes("quotes.txt");
        menu();
        
        printf("Choose an action (1-3): ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer
        
        switch (choice) {
            case 1:
                print_quote(random_quote(quotes));
                break;
            case 2: {
                int count;
                printf("How many quotes to display? ");
                scanf("%d", &count);
                getchar(); // clear newline from buffer
                display_quotes(quotes, count);
                break;
            }
            case 3:
                add_quote("quotes.txt", quotes);
                break;
            case 4:
                printf("Good bye...\n");
                free(quotes);
                return 0;
            default:
                printf("Invalid choice\n");
        }
        free(quotes);
    }
    
    return 0;
}