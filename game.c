/* Contains main() and any desired helper functions to play the game as described in the instructions. Must not _define_ any of the 
 * card-related helper functions but must use thm at least as frequently as indicated below (hit means either player or dealer hit):
 * make_deck:1; shuffle:1; deal: 3+1/hit; append: 1+1/hit; total: 2+1/hit; destroy_deck: 1
 */
 /* 15 points */
#include "card.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    int game = 1;
    
    card *top = make_deck();
    
    top = shuffle(top);
    top = shuffle(top);
    top = shuffle(top);

    
    
    card* player;
    card* dealer;
    
    int plTotal = 0; 
    int dlTotal = 0;
    
    printf("Your card:\n");
    //deal two cards to player
    player = deal(top); player->next = deal(top);
    plTotal += total(player);
    player = player->next;
    printf("\nYour score:%d\n",plTotal);
    
    //deal one card to dealer
    printf("Dealer's card:\n");
    dealer = deal(top);
    dlTotal += total(dealer);
    printf("\nDealer's total:%d\n",dlTotal);
    

    char kbInput[6];
    int hit = 0;
    printf("hit or stand\n");
    scanf("%s", kbInput);
    
    
    while(strcmp(kbInput, "H") != 0
        && strcmp(kbInput, "h") != 0
        && strcmp(kbInput, "hit") != 0
        && strcmp(kbInput, "S") != 0
        && strcmp(kbInput, "s") != 0
        && strcmp(kbInput, "stand") != 0){
            
        printf("invalid input! Retry!1\n");
        printf("hit or stand\n");
        scanf("%s", kbInput);
    }
    if (strcmp(kbInput, "H") == 0
        || strcmp(kbInput, "h") == 0
        || strcmp(kbInput, "hit") == 0) {
            
    }
    
    while (strcmp(kbInput, "H") == 0
        || strcmp(kbInput, "h") == 0
        || strcmp(kbInput, "hit") == 0) {
        printf("You draw:");
	    player = deal(top);
	    plTotal += total(player);
	    player = player->next;
	    printf("\nYour score:%d\n",plTotal);
	    
	    if (plTotal > 21) {
		    printf("Lost!\n");
		    hit = 0;
		    game = 0;
		    break;
	    }
	    printf("hit or stand\n");
        scanf("%s", kbInput);
        while(strcmp(kbInput, "H") != 0
            && strcmp(kbInput, "h") != 0
            && strcmp(kbInput, "hit") != 0
            && strcmp(kbInput, "S") != 0
            && strcmp(kbInput, "s") != 0
            && strcmp(kbInput, "stand") != 0){
            printf("invalid input! Retry!2\n");
            printf("hit or stand\n");
            scanf("%s", kbInput);
        }
    }
    
    
    if(game == 1){
        printf("Dealer draw:");
        while(dlTotal < 17){
            dealer = deal(top);
            dlTotal += total(dealer);
            dealer = dealer->next;
            
        }
        printf("\nDealer's score:%d\n",dlTotal);
        if(dlTotal > 21){
            printf("Won!\n");
        }else{
            if (dlTotal >= plTotal){
                printf("Lost!\n");
            }else{
                printf("Won!\n");
                }
            }
        
        }
    destroy_deck(top);
    return 0;
}
    
    
    

















