/* 40 points */
/* Define all card/deck related functions as follows:
 * make_deck: generates a new list of 52 unique cards with ranks 1-13 and suits CDHS. Returns a pointer to the head of the list. 
 *            Note: you must use malloc to create all 52 cards.
 * destroy_deck: consumes a pointer to a card. Free memory for all cards in the list.
 * shuffle: consumes a pointer to a card (expected to be the head of a list of cards). Returns a pointer to a card (the possibly new head).
 *          Randomly re-orders the cards in the list. Note; this function has been provided for you.
 * deal: consumes a pointer to a card (expected to be the head of a list of cards). Finds the last card in the list, prints its values, removes it
 *       from the list, and returns it (pointer to card). 
 * total: consumes a pointer to card. Returns the sum of the values in the list headed by the given card (note: 10,11,12, and 13 all value as 10).
 * show: consumes a pointer to card. Prints the rank and suit of all cards in the list (this may be one card) on one line. For example:
 *       11H 9S 3D 1C 1S
*/
#include "card.h"
#include <stdio.h>
#include <stdlib.h>

card* make_deck(){
    char suit[] = {'C','D','H','S'};
    card* head = NULL;
    card* temp = NULL;
    card* tail = NULL;
    for(int i = 1 ; i <= 13; i++){
        for(int j = 0; j <= 3; j++){
            temp = (card*)malloc(sizeof(card));
            temp->rank = i;
            temp->suit = suit[j];
            temp->next = NULL;
            if (head == NULL){
                head = temp;
            }else{
                tail = head;
                while(tail->next != NULL){
                    tail = tail->next;
                }
                tail->next = temp;
            } 
        }
    }
    return head;
}

void destroy_deck(card *deck) {
	card *top;
	while((top = deck) != NULL) {
	    free(top);
	    deck = deck->next;
	}
	
}

void show(card *deck) {
	card *top = deck;
	while (top->next != NULL) {
		printf("%i%c\n", top->rank, top->suit);
		top = top->next;
	}
}

card* deal(card* deck){                                 
    card* a = deck;
    while(a->next->next != NULL){
        a = a->next;
    }
    printf("%d%s ",(a->next->rank),&(a->next->suit));     
    card* b = a->next;
    a->next = NULL;
    return b;  
}

int total(card* deck){ 
  card* a = deck;
  int total;
  total = 0;
  while(a != NULL){
    if ( a->rank == 11 || a->rank == 12 || a->rank == 13){
      total += 10;
    }else{
        total += a->rank;
    }
    a = a->next;
  }
  return total;
}


/* counts the number of cards in the list headed by "deck" */
int count_deck(card *deck) {
    int count=0;
    /* No initialization required. When "deck" is NULL (zero), it's at the end. Otherwise, move to the
    next card and increment the count. No body of the for loop! */
    for(;deck;deck=deck->next,count++);
    return count;
}

/* Emulates a "riffle shuffle" of "deck". */
card *shuffle(card *deck) {
    int size = count_deck(deck);
    card *cut=deck;
    for(int i=0; i<size/2; i++){
        cut=cut->next;
    }
    /* cut is now the card 1/2 way through the deck */
    card *riffle=cut->next;
    cut->next = 0; /* deck and riffle now head separate lists */
    /* Shuffle the deck by randomly pulling a card from the head of "deck" or "riffle"
       and make it the new head of "retdeck" */
    card *retdeck=0;
    for(;deck || riffle;) { /* just like a while loop */
        card *temp;
        if(deck && (!riffle || drand48()<0.5)) {
            /* next card comes from the top of 'deck' */
            temp=deck;
            deck=deck->next;
        } else if(riffle) {
            /* next card comes from the top of 'riffle' */
            temp=riffle;
            riffle=riffle->next;
        }
        /* put the card at the top of the "retdeck" */
        temp->next=retdeck;
        retdeck=temp;
    }
    return retdeck;
}
