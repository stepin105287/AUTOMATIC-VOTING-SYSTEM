#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

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
char* cast_Vote(int y){
voters1 = fopen("voter.txt","r");
int z=0;
for(z=0;z<=14;z++)
{
    fscanf(voters1,"%d",&voter[z]);
}
fclose(voters1);

int flag=0;
int i=0;
for(i=0;i<=14;i++)
{
    if(y==voter[i])
    {
        flag=1;
        break;
    }
}
if(flag==0)
{
    return "you have already voted (duplicate voter id)\n";
}

else
{
int choice;
printf("\n\n ### Please choose your Candidate by entering their corresponding serial number####\n\n");
printf("\n 1. %s", CANDIDATE1);
printf("\n 2. %s", CANDIDATE2);
printf("\n 3. %s", CANDIDATE3);
printf("\n 4. %s", CANDIDATE4);
printf("\n 5. %s", "None of These");

printf("\n\n Input your choice (1 - 4) : ");
fflush(stdin);
scanf("%d",&choice);
number = fopen("vote.txt","r");
fscanf(number,"%d%d%d%d%d",&votesCount1,&votesCount2,&votesCount3,&votesCount4,&spoiledtvotes);
fclose(number);
int range =-1;

switch(choice){
    case 1: votesCount1++;
             voter[i]=-1;
             range=1;
             break;
    case 2: votesCount2++;
              voter[i]=-1;
             range=1;
             break;
    case 3: votesCount3++;
             voter[i]=-1;
             range=1;
             break;
    case 4: votesCount4++;
              voter[i]=-1;
             range=1;
             break;
    case 5: spoiledtvotes++;
              voter[i]=-1;
             range=1;
             break;
    default: range = 0 ;
}
number=fopen("vote.txt","w");
fprintf(number,"%d %d %d %d %d",votesCount1,votesCount2,votesCount3,votesCount4,spoiledtvotes);
fclose(number);
voters1=fopen("voter.txt","w");
for(int k=0;k<=14;k++)
{
    fprintf(voters1,"%d ",voter[k]);
}
fclose(voters1);
if (range==1)
    return "voting successfull";
else if(range == 0)
    return "you have choosed wrong option, please retry by selecting correct option";
}
}

