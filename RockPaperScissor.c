/* 
                                       Date - 23/07/2021
                            Project Name - Rock, Paper & Scissor Game
                                    Author - Atharv Vani
                                Co-Author - Priyanshi Agrawal
                                        C - Language
*/
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Global Variable
int score_p1 = 0, score_p2 = 0;
char name[30];

int produce_Random_Val() //For having a random value for the computer's turn
{
    srand(time(NULL));
    return rand() % 2;
}
void show_Turn(int num) //To show turn number and name
{
    if (num == 1)
    {
        printf("\n%s's Turn\n", name);
    }
    else if (num == 2)
    {
        printf("\nCOMPUTER's Turn\n");
    }
}
void condition_Check(char p1, char p2) //Checking win or loose
{
    if ((p1 == 'r' && p2 == 'r') || (p1 == 'p' && p2 == 'p') || (p1 == 's' && p2 == 's'))
    {
        printf("\nThis Round was a TIE..!!\n");
    }
    else if ((p1 == 'p' && p2 == 'r') || (p1 == 'r' && p2 == 's') || (p1 == 's' && p2 == 'p'))
    {
        score_p1++;
        printf("\n%s Won This Round..!!\n", name);
    }
    else if ((p1 == 'r' && p2 == 'p') || (p1 == 's' && p2 == 'r') || (p1 == 'p' && p2 == 's'))
    {
        score_p2++;
        printf("\nCOMPUTER Won This Round..!!\n");
    }
}
const char *player_Selection(int p_code) //To show Selection Preference
{
    if (p_code == 0)
    {
        return "Rock";
    }
    else if (p_code == 1)
    {
        return "Paper";
    }
    else
    {
        return "Scissor";
    }
}
void final_Result() //To Show Final Result
{
    if (score_p1 > score_p2)
    {
        printf("\t\t%s is the WINNER..%c", name,1);
        printf("\n-------------------------------------------------------\n");

    }
    else if (score_p2 > score_p1)
    {
        printf("\t\tCOMPUTER is the WINNER..\n");
        printf("\t\tBetter Luck Next Time %c\n",3);
        printf("-------------------------------------------------------\n");

    }
    else
    {
        printf("\t\tGame TIED..%c\n",2);
        printf("-------------------------------------------------------\n");
    }
}
void main() //Main Funtion
{
    printf("Enter Player's Name : \n");
    gets(name);
    strupr(name);

    system("cls");

    int p1_code, p2_code, i;
    char code[3] = {'r', 'p', 's'};
    for (i = 0; i < 3; i++)
    {
        show_Turn(1);

    select_again:

        printf("Select a number of your choice accordingly : \n0->Rock    1->Paper    2->Scissor\n");
        scanf("%d", &p1_code);
        printf("You Selected %s\n", player_Selection(p1_code));

        if (p1_code > 2 || p1_code < 0)
        {
            printf("Select Appropriate Number..!!\n");
            goto select_again;
        }
        show_Turn(2);
        p2_code = produce_Random_Val();
        printf("Computer Selected %s\n", player_Selection(p2_code));

        condition_Check(code[p1_code], code[p2_code]);
        
        printf("\nPress any Key to move Ahead");
        getch();
        system("cls");
    }
    printf("\n-------------------------SCORE-------------------------\n");
    printf("\t\tScore of %s : %d\n", name, score_p1);
    printf("\t\tScore of COMPUTER : %d\n", score_p2);
    printf("-------------------------------------------------------\n");
    final_Result();
}
