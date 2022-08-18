# README
## Description
Simulates the game Pass the Pigs, in which the code simulates a game(in which the number of players(between 2 and 10) and the seed which is used to randomly generate numbers is requested as inputs) that loops through a given list of players sequentially until one player reaches 100 points. 
## How to Build
Using the vim text editor in linux, create a C program in which the user is prompted to enter the number of players playing(if it is not within 2 and 10 inclusive, the default is set to 2) and the seed(if it is not withing 0 and UINTMAX, default to 2022). Then, using a library of names, a number of names respective to the number of players are copied to an array. Then, an array of scores correlated to the players is generated and initialized to zero. Then, as long as no players have more than 100 points, players are given a chance to roll the pig in a sequential order according to their position in the array of names. Then, the randomly generated number (as per the seed) is set to mod 7, in order to get a set of numbers from 0 to 6. This randomly generated number is then enumerated to its respective position of the pig, and thus is rewarded the correct amount of points, or ends the players turn. The code then checks again if the player has recieved 100 points, resulting in both a "winner" message and the "return 0." If neither has occured, the code increments the player postion by one, and if it is the last player, resets it to zero. 
## How to Run
use the "./" command to run pig.c and enter the number of players and seed generation as per the prompt# README
## Description
Simulates the game Pass the Pigs, in which the code simulates a game(in which the number of players(between 2 and 10) and the seed which is used to randomly generate numbers is requested as inputs) that loops through a given list of players sequentially until one player reaches 100 points. 
## How to Build
Using the vim text editor in linux, create a C program in which the user is prompted to enter the number of players playing(if it is not within 2 and 10 inclusive, the default is set to 2) and the seed(if it is not withing 0 and UINTMAX, default to 2022). Then, using a library of names, a number of names respective to the number of players are copied to an array. Then, an array of scores correlated to the players is generated and initialized to zero. Then, as long as no players have more than 100 points, players are given a chance to roll the pig in a sequential order according to their position in the array of names. Then, the randomly generated number (as per the seed) is set to mod 7, in order to get a set of numbers from 0 to 6. This randomly generated number is then enumerated to its respective position of the pig, and thus is rewarded the correct amount of points, or ends the players turn. The code then checks again if the player has recieved 100 points, resulting in both a "winner" message and the "return 0." If neither has occured, the code increments the player postion by one, and if it is the last player, resets it to zero. 
## How to Run
use the "./" command to run pig.c and enter the number of players and seed generation as per the prompt.







