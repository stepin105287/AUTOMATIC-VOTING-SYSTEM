#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include "functions.h"

#define CANDIDATE_COUNT

#define CANDIDATE1 "Shikhar Dhawan"
#define CANDIDATE2 "Virat Kohli"
#define CANDIDATE3 "M S Dhoni"
#define CANDIDATE4 "Rohit Sharma"


extern int votesCount1, votesCount2, votesCount3, votesCount4, spoiledtvotes;
extern int voter[15];
extern int newVoter[15];
extern int voter1[15];
FILE *voters2;
FILE *number;
FILE *voters1;
extern int check;


int voter_check(char num[5])
{
voters2 = fopen("voter1.txt","r");
int n=0;
for(n=0;n<=14;n++)
{
    fscanf(voters2,"%d",&voter1[n]);
}
fclose(voters2);
int z = atoi(num);
int flag=0;
for(int i=0;i<=14;i++)
{
    if(z==voter1[i])
    {
        flag=1;
        break;
    }
}
if (flag==1)
{
    return 1;
}
else
{
    return 0;

}
}
int admin_password(char a[5])
{
    if (strcmp(a,"1723")==0)
    {
        return 0;
    }
    else
    {
        return 1;

    }
}
