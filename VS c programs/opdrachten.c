#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// void displayArray(int array[], int size);

// int main(){

//     int someIntArray[] = {8, 5, 9, 2, 14};
//     int someIntArraysSize = sizeof(someIntArray) / sizeof(int);

//     displayArray(someIntArray, someIntArraysSize);

//     return 0;
// }

// void displayArray(int array[], int size){

//     int i;
//     for ( i = 0; i < size; i++)
//     {
//         printf("the value at place %d is: %d", i, array[i]);
//         printf("\n");
//     }
    

// }
//==========================================================================================================

// // #define test

// void dectobinary(int dec1, int dec2, int dec3);

// int main(){

//     int decimal1;
//     int decimal2;

//     printf("enter a number to turn it binarrry: \n");
//     scanf("%d: ", &decimal1);

//     printf("enter a second number to turn it binarrry: \n");
//     scanf("%d: ", &decimal2);

//     int decimal3 = decimal1 ^ decimal2;

//     printf("dit is de xor of de decimal3 %d\n", decimal3);


//     dectobinary(decimal1, decimal2, decimal3);
//     return 0;
// }

// void dectobinary(int dec1, int dec2, int dec3){
//     printf("first num in binary is:  ");
//     int count1 = 0;
//     for(int i = 31; i >= 0; i--){

//         int bi1 = dec1 >> i;
//         count1++;
//         if(bi1& 1){
//             printf("1");

//         }else{
//             printf("0"); 
//         }
//         if(count1 == 4 & i > 0){
//             printf(" ");
//             count1 = 0;
//         }
        
//     }
//     printf("\n");

//     int count2 = 0;
//     printf("tweede num in binary is: ");
//     for(int i = 31; i >= 0; i--){
        
//         int bi2 = dec2 >> i;
//         count2++;
//         if (bi2& 1){
//             printf("1");

//         }else{
//             printf("0");
//         }
        
//         if(count2 == 4 & i > 0){
//             printf(" ");
//             count2 = 0;
//         }
//         }
        
//     printf("\n");
//     int nullen = 0;
//     int enen = 0;
//     printf("XOR van biede binaries:  ");
//     int count3 = 0;
//         for(int i = 31; i >= 0; i--){

//         int bi3 = dec3 >> i;
//         count3++;
//         if(bi3 & 1){
//             printf("1");
//         }
//         else{
//             printf("0");   
//         }
//         if(count3 == 4 & i > 0){

//             printf(" ");
//             count3 = 0;
//         }
//     }

//     for (int i = 0; i < 32; i++)
//     {
//         if(dec3 & 1)
//         {
//             enen++;
//         }
//         else
//             nullen++;
//         dec3 >>= 1;
//     }
    

//     printf("\n");
//     printf("antal nullen zijn %d: \n", nullen);
//     printf("antal enen zijn %d: \n", enen);


// #ifdef test
//     int a = dec1 & dec2;
//     int b = ~dec1 & ~dec2;
//     int z = ~a & ~b;
//     printf("xor value is %d : " ,z);
// #endif

// }

//========================================================================================================================

// #define areequal(a, b) ((a) == (b))

// enum bool{False, ture};

// int main(){

//     int a = 1;
//     int b = 9;

// enum bool equal = areequal(a, b);

// if(equal)
// {
//     printf("%d and %d are indeed equal.", a,b);
// }else
//     printf("%d and %d are not equal.", a,b);

//     return 0;
// }

//=======================================================================-====================================_==================================



// #define test



#define opdrnemer 3

struct opdrachtnemer {

    char voornaam[50];
    char achternaam[50];
    int age;
    float uurtrief;
    int gewerkturen;
    
};

void raporteerbeloningen(struct opdrachtnemer opdrNemers[], int n);

int main()
{
    struct opdrachtnemer opdrNemers[opdrnemer] = {
        {"koos", "korswagen", 32,135.75f, 89},
        {"Bolus","Bonkpok", 44, 162.25f, 24},
        {"Mohammad","Khalaf", 26, 89.45f, 46}};

    // int s = sizeof(opdrNemers)/ sizeof(opdrachtnemer);

#ifdef test
    printf("print opdrnemer naam %s\n:", opdrNemers[0].voornaam);
    printf("print opdrnemer naam %s\n:", opdrNemers[1].voornaam);
    
#endif 

    raporteerbeloningen(opdrNemers, opdrnemer);

    return 0;
}

void printinfo(struct opdrachtnemer opdrNemer){
    float totaaluren;
    totaaluren = (float)opdrNemer.uurtrief * (float)opdrNemer.gewerkturen;
    printf("de opdrnemer: %s %s, %d jaaroud, heeft recht op %.2f\n", opdrNemer.voornaam, opdrNemer.achternaam, opdrNemer.age, totaaluren);

}


void raporteerbeloningen(struct opdrachtnemer opdrNemers[], int n){
    for (int i = 0; i < n; i++)
    {
        printinfo(opdrNemers[i]);
    }
}



