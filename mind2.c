#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


int level = 0;
int number_of_players;
int game_over = FALSE;

int main(){

    // Game Info
    printf("Enter number of players: ");
    scanf("%d",&number_of_players);

    // Rounds Loop
    while(!game_over){
        level++;
        int played[100] = {FALSE};

        printf("LEVEL %d\n",level);

        int hand[level];
        
        // Round Info
        printf("Enter your cards: ");
        for(int i=0; i<level; i++){
            scanf("%d",&hand[i]);
        }
        // Turns Loop
        for(int i=0; i<number_of_players; i++){

            int highest_played = 0;
            for(int i=99; i>=0; i--){
                if(played[i]){
                    highest_played = i+1;
                }
            }

            int lowest_in_hand = hand[0];
            for(int j=0; j<level; j++){
                if(!played[hand[j]] && hand[j]>lowest_in_hand){
                    lowest_in_hand = hand[j];
                }
            }

            int gap = (lowest_in_hand-highest_played)-1;

            int number_played = 0;
            for(int j=0; j<100; j++){
                number_played += played[j];
            }

            int number_played_by_others = 0;
            for(int j=0; j<100; j++){
                if(played[j]){
                    int in_hand = FALSE;
                    for(int k=0; k<level; k++){
                        if(j==hand[k]){
                            in_hand = TRUE;
                        }
                    }
                    if(!in_hand){
                        number_played_by_others += 1;
                    }
                }
            }

            int number_in_other_hands = (level*(number_of_players-1))-number_played_by_others;
            int pool_size = 100 - highest_played;

            float odds = 1;
            for(int j=0; j<number_in_other_hands; j++){
                float delta = odds*(double)gap/(double)pool_size;
                odds = odds - delta;
                pool_size -= 1;
            }

            printf("Odds your card is the next highest: %.2f%%\n",odds*100);

            int next_card;
            printf("Enter card played: ");
            scanf("%d",&next_card);
            played[next_card] = TRUE;

            printf("Pile: [");
            for(int j=0; j<100; j++){
                if(played[j]){
                    printf("%d ",j);
                }
            }
            printf("]\n");
        }
    }

    return 0;
}
