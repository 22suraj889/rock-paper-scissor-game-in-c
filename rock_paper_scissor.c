#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateRandom();
int check_for_win(char player, char cpu);
int main()
{
    int playerScore = 0, computerScore=0;
    char temp, flag;
    char name[20];
    printf("Enter name of the player.\n");
      gets(name);
    char game[] = {'r','p','s'};
    int t = 3;
    while(t--)
    {

        printf("Welcome to stone paper scissor game\n");
        printf("Enter 1 for Rock\nEnter 2 for Paper\nEnter 3 for Scissor\n");

        printf("%s turns: Enter your choice\n",name);
        int n;
        scanf("%d",&n);
        getchar();
         temp = game[n-1];
        printf("%s choosed %c\n",name,temp);

        printf("Computer turns...\n");
        int m = generateRandom()+1;
         flag = game[m-1];
        printf("Computer choosed %c\n",flag);

        if(check_for_win(temp,flag)== -1){
            playerScore += 1;
            computerScore += 1;
            printf("This was tie!!!\n");
        }
        else if(check_for_win(temp,flag)==1){
            computerScore += 1;
            printf("Computer got it!!!\n");
        }
        else {
            playerScore += 1;
            printf("%s got it!!!\n",name);
        }
        
          printf("%s points: %d\nComputer points: %d\n\n",name,playerScore,computerScore);
    } 

    if(computerScore>playerScore){
        printf("Computer won the game!!!\n");
    }
    else if(computerScore==playerScore){
        printf("Tie between Player and computer...\n",name);
    }
    else{
        printf("%s won the game!!!\n",name);
    }
}
int generateRandom()
{
    srand(time(NULL));
    return (rand()%3);
}
int check_for_win(char player, char cpu)
{
    int check;
    if(player==cpu)
    check = -1;
    else if((player=='r'&&cpu=='p') || (player=='p'&&cpu=='s') || (player=='s'&&cpu=='r'))
    check = 1;
    else if((player=='p'&&cpu=='r') || (player=='s'&&cpu=='p') || (player=='r'&&cpu=='s'))
    check = 0;

    return check;
}