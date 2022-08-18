# include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "names.h"


 int main (void) {
/*enumerate die sides; */
typedef enum { SIDE , RAZORBACK , TROTTER , SNOUTER , JOWLER } Position;
 const Position pig[7] = {
 SIDE ,
 SIDE ,
 RAZORBACK ,
 TROTTER ,
 SNOUTER ,
 JOWLER ,
 JOWLER
 };
 /*ask for number of players; */
 int input = 0;
 printf("How Many Players? ");
 scanf("%d",&input);
 /*if number of players is not between 2 and 10 inclusive, default to 2 else use input;*/
 if (input > 10 || input < 2){
    fprintf(stderr," Invalid number of players. Using 2 instead.\n");
    input = 2;
 
 }
 /*ask for seed;
if seed is not between 0 and INTMAX, use 2022;
*/
 uint seed = -1;
 printf("Random Seed: ");
 scanf("%d",&seed);
 if (seed <= 0 || seed >= UINT_MAX){
	 fprintf(stderr,"Invalid random seed. Using 2022 instead.\n");
    seed = 2022;
 }
 srandom(seed);
 /*copy names from names.h to array called players else use input;*/
 int i;
 char *players[input];
for (i = 0;i < input; ++i){
    players[i] = strdup(names[i]);
}
int j;
int max_score = 0 ;
/*create array of scores with value 0;*/
int scores[input];
for (j = 0;j < input; ++j){
    scores[j] = 0;
    
}
int p = 0;
while (max_score < 100){
/*start game*/
    int dpos = 0;
    printf("%s rolls the pig ...",players[p]);
    do {
	/* generates random number, enumerates, and then assigns points*/
        int die = (random () % 7);
        dpos = pig[die];
        if (dpos == 1){
            printf(" pig lands on its back");
            scores[p] += 10;
           /* printf(" %d",scores[p]);*/
        }
        else if (dpos == 2){
            printf(" pig lands upright");
            scores[p] += 10;
           /* printf(" %d",scores[p]);*/
            
        }
        else if (dpos == 3){
            printf(" pig lands on its snout");
            scores[p] += 15;
           /* printf(" %d",scores[p]);*/
            
        }
        else if (dpos == 4){
            printf(" pig lands on its ear");
            scores[p] += 5;
           /* printf(" %d",scores[p]);*/
            
        }
        else{
            printf(" pig lands on its side\n");
        }
	/* check if player has won and print message*/
        if (scores[p] >=100){
            /*printf("%d",max_score);
            printf("%d",scores[p]);*/
            printf("\n");
            fprintf(stdout,"%s wins with %d points! \n",players[p],scores[p]);
            return 0;
        }
        } while (dpos != 0);
    if (p < input-1){
        p += 1;
    }
    else {
        p = 0;
    }
    int m;
    for (m = 0;m < input; ++m){
        if (max_score > scores[m]){
            max_score = scores[m];
        }
    }
}
    

}

