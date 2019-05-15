#include <stdio.h>
#include <stdlib.h>

float probabilityLowestInHand(int n_played,int last_card, int card, int n_players, int level){
    float probability = 1;
    int range = (card-last_card)-1;
    int pool = 100-(n_played + level);
    
    for(int i=0; i<n_players-1; i++){
        float delta = probability*(double)range/(double)pool;
        probability = probability - delta;
        pool -= 1;
    }

    return probability;    
}

int main(){
    int n_players;
    int str[100];
    int card;
    int card_played = 0;
    int level = 1;
    int n_played;
    float probability;

    printf("  :::::::::::   :::    :::       ::::::::::              :::   :::       :::::::::::     ::::    :::     ::::::::: \n\
     :+:       :+:    :+:       :+:                    :+:+: :+:+:          :+:         :+:+:   :+:     :+:    :+: \n\
    +:+       +:+    +:+       +:+                   +:+ +:+:+ +:+         +:+         :+:+:+  +:+     +:+    +:+  \n\
   +#+       +#++:++#++       +#++:++#              +#+  +:+  +#+         +#+         +#+ +:+ +#+     +#+    +:+   \n\
  +#+       +#+    +#+       +#+                   +#+       +#+         +#+         +#+  +#+#+#     +#+    +#+    \n\
 #+#       #+#    #+#       #+#                   #+#       #+#         #+#         #+#   #+#+#     #+#    #+#     \n\
###       ###    ###       ##########            ###       ###     ###########     ###    ####     #########       \n\n");

    printf("Enter number of players: ");
    scanf("%d",&n_players);

    printf("Enter your card: ");
    scanf("%d",&card);

    for(int i=0; i < n_players; i++){
        printf("Odds: %.0f%% \n", 100*probabilityLowestInHand(n_played, card_played, card, n_players, level));

        printf("Enter card played: ");
        scanf("%d",&card_played);

        printf("Survived? [y/n] ");
        char c;
        scanf(" %c",&c);
        if(c=='n'){
            int skipped;
            printf("How many cards skipped: ");
            scanf("%d",&skipped);
            n_played += skipped;
            continue;
        }

    }

    return 0;
}
