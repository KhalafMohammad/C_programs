#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int i, num, max, temp;
    printf (" Enter a number to set the limit of random numbers \n");
    scanf ("%d", &num);


    printf (" Enter the maximum number from you want to get the random number: \n");
    scanf ("%d", &max);

    printf (" %d random number from 0 to %d number are: \n", num, max);

    for (i = 1; i <= num; i++)
    {
        int temp = (rand()% max);  /* use random() function to get the random number */
        printf("%d", temp); // print the temp
    }
        getch();
}