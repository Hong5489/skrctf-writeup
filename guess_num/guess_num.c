#include <stdio.h>
#include <stdlib.h> 

#define FLAGSIZE_MAX 128

char flag[FLAGSIZE_MAX];

void setup(){ 
    FILE *f = fopen("flag.txt","r");
    fgets(flag,FLAGSIZE_MAX,f);
    gid_t gid = getegid();
    setresgid(gid, gid, gid);
} 

int main () { 
    setup();
    // Generate random number using current time
    srand(time(0)); 
    int num = (rand() % 999999) + 1;
    char name[20];
    int guess;
    printf("Guess the number correctly to win the Flag!\nBut you only have one chance!\n"); 
    printf("Enter your name: ");
    scanf("%s",&name);
    printf("Guess a number between One to One Million: ");
    scanf("%i",&guess); 
    // If you guess the correct number, you will get the flag!
    if(guess == num){ 
        printf("Congrats %s!\nHere is your flag: %s\n",name,flag);
    } 
    else{ 
        printf("Wrong! The correct number is: %i\n",num); 
    } 
    return(0);
}