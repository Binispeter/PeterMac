#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 3

typedef struct
{
    char participant_name[32];
    int num_of_Submissions;
    int Ids[3];
} participantT;

int numberOfSubmissions(int line, int array[N][3]);
void addToTable(participantT table[40], char participants[N][32], int submissionsIds[N][3]);
int searchParticipant(participantT table[40], char name[32], int *submissions);
void getInput(participantT newtable[40], int num, FILE *infile, participantT oldtable[40]);

int main()
{
    char participants[N][32]= {"Papas Giorgos", "Nikolaou Petros", "Tzelou Anna"};
    int submissionIds[N][3]=
    {
        {2, 0, 0},
        {11, 22, 0},
        {7, 0, 0}
    };

    participantT tableParticipants[40];

    int i, submissions, sub_sum=0, submissions_search, position_search;
    float mean_sub;

    for(i=0; i<N; i++)
    {
        submissions = numberOfSubmissions(i, submissionIds);
        printf("Participant Name:%-20s Number of Submissions:%d\n", participants[i], submissions);
        sub_sum+=submissions;
    }

    mean_sub = (float)sub_sum / N;

    printf("Total number of Submissions:%d, Mean number of submissions: %.2f\n", sub_sum, mean_sub);
    for(i=0; i<30; i++)
        printf("#");
    printf("\n");

    addToTable(tableParticipants, participants, submissionIds);

    position_search = searchParticipant(tableParticipants, "Papas Giorgos", &submissions_search);

    if(position_search == -1)
        printf("Participant not found\n");

    else
    {
        printf("Name: %s\n", tableParticipants[position_search].participant_name);
        printf("Position: %d\n", position_search);
        printf("Number of submissions: %d\n", submissions_search);\
    }
    for(i=0; i<30; i++)
        printf("#");
    printf("\n");




    return 0;
}

int numberOfSubmissions(int line, int array[N][3])
{
    int i, count=0;

    for (i=0; i<3; i++)
    {
        if(array[line][i] != 0)
            count++;
    }

    return count;
}

void addToTable(participantT table[40], char participants[N][32], int submissionsIds[N][3])
{
    int i, j;

    for(i=0; i<N; i++)
    {
        strcpy(table[i].participant_name, participants[i]);
        table[i].num_of_Submissions = numberOfSubmissions(i, submissionsIds);
        for(j=0; j<3; j++)
            table[i].Ids[j] = submissionsIds[j];

    }

}

int searchParticipant(participantT table[40], char name[32], int *submissions)
{
    int i, position;

    for(i=0; i<N; i++)
    {
        if((strcmp(name, table[i].participant_name)) == 0)
        {
            position = i;
            *submissions = table[i].num_of_Submissions;
            break;
        }
        else
        {
            position = -1;
            *submissions = 0;
        }
    }
    return position;
}

void getInput(participantT newtable[40], int num, FILE *infile, participantT oldtable[40])
{

}
