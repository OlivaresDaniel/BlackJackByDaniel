#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CARDS 52
#define CARD_VALUES 13
#define MAX_HAND 10

char *values[] = {"DOS", "TRES", "CUATRO", "CINCO", "SEIS", "SIETE", "OCHO", "NUEVE", "DIEZ", "J", "Q", "K", "A"};
char *suits[] = {"corazones", "diamantes", "picas", "treboles"};

struct carta {
    char *value;
    char *suit;
    int numericValue;
};

    struct carta deck[TOTAL_CARDS];
    struct carta playerHand[MAX_HAND];
    int numPlayerCards = 0;
    int playerSum = 0;
    char choice;




int main() {
    
    // Inicialización del mazo de cartas
    for (int i = 0; i < TOTAL_CARDS; i++) {
        
        // Se asignan valores, palos y valores numéricos a cada carta
        deck[i].value = values[i % CARD_VALUES];
        deck[i].suit = suits[i / CARD_VALUES];
        
        // Se utiliza un bucle para crear las 52 cartas
        if (i % CARD_VALUES < 9) {

            deck[i].numericValue = (i % CARD_VALUES) + 2;
            
        } else if (i % CARD_VALUES < 12) {

            deck[i].numericValue = 10;
            
        } else {

            deck[i].numericValue = 11;
        }
    }

    srand(time(NULL));
    for (int i = 0; i < TOTAL_CARDS; i++){
        
        int j = rand() % TOTAL_CARDS;
        struct carta temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    
    }
    
    // Se imprime un mensaje de bienvenida
    printf("Bienvenido al Blackjack!\n");

    // Se reparten las dos primeras cartas al jugador
    playerHand[numPlayerCards++] = deck[0];
    playerHand[numPlayerCards++] = deck[1];

    // Se calcula la suma total de las cartas del jugador y se imprime
    playerSum = 0;
    
    for (int i = 0; i < numPlayerCards; i++) {
            
        playerSum += playerHand[i].numericValue;
    
    }

    // Se inicia un bucle para que el jugador decida si quiere otra carta
    for (int i = 0; i < numPlayerCards; i++) {
            
        printf(" %s de %s\n", playerHand[i].value, playerHand[i].suit);
    }
    
    printf("Suma total: %d\n", playerSum);


    while (playerSum < 21) {
        
        // Se pregunta al jugador si quiere otra carta
        printf("¿Quieres otra carta? (s/n): ");
        scanf(" %c", &choice);

        // Si elige 's' (sí), se reparte otra carta y se actualiza la suma y la impresión
        if (choice == 's' || choice == 'S') {
                
            playerHand[numPlayerCards] = deck[numPlayerCards + 1];
            numPlayerCards++;
            playerSum = 0;
            
            for (int i = 0; i < numPlayerCards; i++) {
                
                playerSum += playerHand[i].numericValue;
        
            }
            
            // Si elige 'n' (no), se sale del bucle
            for (int i = 0; i < numPlayerCards; i++) {
                    
                printf(" %s de %s\n", playerHand[i].value, playerHand[i].suit);
            
            }
            
            printf("Suma total: %d\n", playerSum);
            
        } else {
            
            break;
            
        }
    }

    // Se verifica el resultado del juego y se imprime un mensaje correspondiente
    if (playerSum == 21) {
            
        printf("¡Blackjack! Has ganado.\n");
    
    } else if (playerSum > 21) {
        
        printf("Te has pasado. Fin del juego.\n");
        
    } else {
        
        printf("Te has plantado con %d. Fin del juego.\n", playerSum);
        
    }
    
    return 0;
}
