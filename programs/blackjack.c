#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to draw a card, with Ace handling
int drawCard()
{
    int card = rand() % 13 + 1; // Generate a number between 1 and 13
    if (card > 10)
    {
        card = 10; // Face cards (Jack, Queen, King) count as 10
    }
    return card;
}

// Function to calculate total while handling aces
int calculateTotal(int cards[], int count)
{
    int total = 0, aceCount = 0;
    for (int i = 0; i < count; i++)
    {
        total += cards[i];
        if (cards[i] == 1)
        {
            aceCount++; // Count the number of Aces
        }
    }
    // If an Ace is present and using it as 11 wouldn't bust the total, treat one Ace as 11
    while (aceCount > 0 && total + 10 <= 21)
    {
        total += 10;
        aceCount--;
    }
    return total;
}

int main()
{
    int playerCards[10], dealerCards[10]; // Arrays to store player and dealer's cards
    int playerCardCount = 0, dealerCardCount = 0;
    int playerTotal, dealerTotal, playerChoice;

    srand(time(0));

    printf("Welcome to Blackjack!\n");

    // Deal two cards to the player
    playerCards[playerCardCount++] = drawCard();
    playerCards[playerCardCount++] = drawCard();
    playerTotal = calculateTotal(playerCards, playerCardCount);
    printf("Your total: %d\n", playerTotal);

    // Deal two cards to the dealer, hide one
    dealerCards[dealerCardCount++] = drawCard();
    dealerCards[dealerCardCount++] = drawCard();
    dealerTotal = calculateTotal(dealerCards, dealerCardCount);
    printf("Dealer shows: %d\n", dealerCards[0]); // Show only one card

    // Player's turn
    while (1)
    {
        printf("Do you want to (1) Hit or (2) Stand? ");
        scanf("%d", &playerChoice);

        if (playerChoice == 1)
        {
            // Hit: deal another card
            playerCards[playerCardCount++] = drawCard();
            playerTotal = calculateTotal(playerCards, playerCardCount);
            printf("Your total is now: %d\n", playerTotal);

            // Check if the player busts
            if (playerTotal > 21)
            {
                printf("You busted! Your total is over 21. Dealer wins.\n");
                return 0;
            }
        }
        else if (playerChoice == 2)
        {
            // Stand: end player's turn
            break;
        }
        else
        {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    }

    // Dealer's turn: dealer hits until total is at least 17
    printf("Dealer reveals hidden card: %d\n", dealerCards[1]);
    printf("Dealer's total: %d\n", dealerTotal);

    while (dealerTotal < 17)
    {
        dealerCards[dealerCardCount++] = drawCard();
        dealerTotal = calculateTotal(dealerCards, dealerCardCount);
        printf("Dealer drew a card. Dealer's total is now: %d\n", dealerTotal);
    }

    // Check if the dealer busts
    if (dealerTotal > 21)
    {
        printf("Dealer busted! You win!\n");
    }
    else
    {
        // Compare totals
        printf("Your total: %d, Dealer's total: %d\n", playerTotal, dealerTotal);
        if (playerTotal > dealerTotal)
        {
            printf("You win!\n");
        }
        else if (playerTotal < dealerTotal)
        {
            printf("Dealer wins!\n");
        }
        else
        {
            printf("It's a tie!\n");
        }
    }

    return 0;
}