# Pass the Pigs

## Purpose
To simulate the game *Pass the Pigs*, in which a 'pig' (die) is rolled. The game is played with 2-10 players, in which players roll the pig until it lands on its side. Each position the pig is in has a certain probability of being landed on, and a certain number of points associated with it. The game concludes when one of the players reaches 100 points.
# Layout/Structure
### main 

enumerates sides of pig  
gets inputs for number of players and seed(checks if valid)  
create a list of players and scores  
rolls pig, counts score, and rotates through players according to rules  


### names.h
stores names of players


## Pseudocode
	
	include stdio.h
	include stdlib.h
	include string.h
	include limits.h
	include names.h
	enumerate die sides;
	ask for number of players;
	if number of players is not between 2 and 10 inclusive, default to 2 else use input;
	ask for seed;
	if seed is not between 0 and INTMAX, use 2022;
	for every object in names:
	copy names from names.h to array called players else use input;
	for each player:
	create array of scores with value 0;
	while the max score < 100:{
		do:{
	   		`generate random number from seed between 0 and 6 using mod 7;`
	   		`m = enumerated values from 0 to 4(from generated random number);`
	   		`if m  = 1:`
		   		add 10 to score;
	   		`elif m = 2:`
		   		add 10 to score;
	   		`elif m = 3:`
		   		add 15 to score;
	   		`elif m = 4:`
		   		add 5 to score;
			else:
	   			`pig lands on side;`
	   		`if score >= 100:`
		   		print winner and return 0;
   		`}while dpos != 0`
   	`if (p < number of players -1):`
	   `increment p by 1;`
	else:	
   		`p = 0; }`
   	`for every m< number of players :`
   	`if maxscore < score[m]:`
   	`maxscore = scores[m];`
	}


<<<<<<< HEAD














































   if maxscore < score[m]:


=======
>>>>>>> c474b283728ab094336c6261fecce9898967afb6
