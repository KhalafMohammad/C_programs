#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){

    char numans; // numans char type 

    printf("\nWould you like to play? Enter Y or N: \n");
    scanf(" %c", &numans);
    printf("\n answer is %c\n", numans); // prints the answer 

    while (numans == 'Y'){ // checks if answer is Y

        srand(time(0)); // #include time cause we need a new number every time we roll the dice otherwise its gonna roll the same number.

        int randnum = (rand()% 6) + 1; // 6 is the max number of the dice so 1,2,3,4,5,6. The + 1 is because we dont want 0 as result.
        
        printf("%d\n", randnum); // prints the random number 
        if (randnum == 6){       // checks if the random num is then breaks the loop.
            printf("\nYYYAAAYYY!!!!\n\n");
            break;
        }
        printf("would you like to play again: "); // asks if you wanna play again if answer is Y keeps looping otherwise breaks it.
        scanf(" %c", &numans);
        printf("\n answer is %c\n", numans); // prints the answer
    }
printf("GoodBye!\n");
return 0;    
}