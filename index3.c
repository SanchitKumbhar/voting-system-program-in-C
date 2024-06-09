#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
// #include <time.h>

/*
Here we had created a structure consisting of array of PartiesNames which is nohing but the
candidates names.
*/
typedef struct info
{
    char PartiesNames[50];
    // char Studentposition[20];
} voting;

// function which shows the votes
int showvotes(voting votesys[], int total_votes[], int numberofparties[], int sum);
// function which calculates the votes
int votingcalculations(voting votesys[], int numberofparties[], int sum);

int main()
{

    char filename[20];
    int numberofheadboys[4], k = 1;
    // here created a new variable using the 'voting' structure
    voting votesys[100]; 

    printf("\t\t\t\t  Vidya Niketan Voting System Program");

    // Here the program starts we used getch() to hold the screen 
    int sum = 0;
    printf("\n\nPress Enter to continue: ");
    getch();
    // We cleared the screen so that a new screen will appear
    system("cls");

    // here a loop starts to take the input for number of candidates and name of candidates

    for (int i = 1; i <= 4; i++)
    {
        if (i == 1)
        {
            printf("\n\nEnter the candidates names for Head Boy: \n\n");
        }
        else if (i == 2)
        {
            printf("\n\nEnter the candidates names for Head Girl: \n\n");
        }
        else if (i == 3)
        {
            printf("\n\nEnter the candidates names for Vice Head Boy: \n\n");
        }
        else if (i == 4)
        {
            printf("\n\nEnter the candidates names for Vice Head Girl: \n\n");
        }

        fflush(stdin);
        printf("\n\nEnter the number of Candidates: ");
        scanf("%d", &numberofheadboys[i]);

        // This loop adds the candidate names
        for (int j = 1; j <= numberofheadboys[i]; j++)
        {
            fflush(stdin);
            printf("\n\nEnter the name of Candidate:  ");
            gets(votesys[k].PartiesNames);
            k++;
            // puts(votesys[i].boy[i]);
        }

        system("cls");
    }
    // This loop adds the number of candidates of each position
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= numberofheadboys[i]; j++)
        {
            sum += numberofheadboys[i];

            break;
        }
    }

    printf("\n\n%d\n\n", sum);

    printf("Enter Votings: ");

    votingcalculations(votesys, numberofheadboys, sum);

    getch();

    return 0;
}

int votingcalculations(voting votesys[], int numberofparties[], int sum)
{

    int vote;
    char data[100];
    // fp = fopen(filename, "r+");
    int k = 0, m = 1, n = 1, a = 0;

    fflush(stdin);

    int count[101];

    for (int i = 0; i <= 100; i++)
    {
        count[i] = 0;
    }



    do
    {
        system("cls");
        printf("Choose the serial number to vote.(NOTE: TO STOP VOTING PRESS 0)");
        printf("\nParty Names:- \n");
        for (int i = 1; i <= 4; i++)
        {
            if (i == 1)
            {
                printf("\n\ncandidates names for Head Boy: \n\n");
            }
            else if (i == 2)
            {
                printf("\n\ncandidates names for Head Girl: \n\n");
            }
            else if (i == 3)
            {
                printf("\n\ncandidates names for Vice Head Boy: \n\n");
            }
            else if (i == 4)
            {
                printf("\n\ncandidates names for Vice Head Girl: \n\n");
            }
            for (int j = 1; j <= numberofparties[i]; j++)
            {
                printf("%d.%s\n", m, votesys[m].PartiesNames);
                m++;
            }
            puts("= ");
            scanf("%d", &vote);
            for (int j = 1; j <= sum; j++)
            {

                if (vote == j)
                {

                    count[j]++;
                    break;
                }
            }
            system("cls");
        }
        m = 1;
        // n = 1;
        // a = 1;
        system("cls");

    } while (vote != 0);

    showvotes(votesys, count, numberofparties, sum);
}

int showvotes(voting votesys[], int total_votes[], int numberofparties[], int sum)
{

    // Calculation of total votings;
    char filename[20];
    fflush(stdin);
    printf("\nCreate a new file= ");
    gets(filename);
    int sumation = 0, m = 1;
    FILE *fp;
    fp = fopen(filename, "w");

    fprintf(fp, "Party Names:\n");
    for (int i = 1; i <= sum; i++)
    {
        fprintf(fp, "\n%d. %s", i, votesys[i].PartiesNames);
    }

    fprintf(fp, "\n\nIndividual votes:\n ");
    for (int i = 1; i <= sum; i++)
    {
        fprintf(fp, "\n%d. %s= %d", i, votesys[i].PartiesNames, total_votes[i]);
    }

    for (int i = 0; i <= sum; i++)
    {
        sumation += total_votes[i];
    }

    fprintf(fp, "\n\nTotal Votings: %d", sumation);

    printf("\n\n\nTotal Votings = %d", sumation);
}
