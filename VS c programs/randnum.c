#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quiz(){
    char YorN;

    printf("Do you wanna play Y or N??\n>>> ");
    scanf("c", YorN);
    if (YorN == 'Y'){
        main();
    }
}

int main(void){

    srand(time(0));

    int randnum = (rand()% 6) + 1;
        
    printf("%d\n", randnum);
    if (randnum == 6){
        printf("YYYAAAYYY!!!!\n\n");
        quiz();
    }
    
return 0;
}