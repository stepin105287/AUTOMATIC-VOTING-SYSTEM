#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include "functions.h"
#include "test_functions.h"

#define CANDIDATE_COUNT

#define CANDIDATE1 "Shikhar Dhawan"
#define CANDIDATE2 "Virat Kohli"
#define CANDIDATE3 "M S Dhoni"
#define CANDIDATE4 "Rohit Sharma"

int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0, spoiledtvotes=0;
int voter[15]={1234,1324,1243,1342,1423,1432,2134,2314,2341,2413,2431,2143,3124,3214,3241};
int newVoter[15]={1234,1324,1243,1342,1423,1432,2134,2314,2341,2413,2431,2143,3124,3214,3241};
int voter1[15];
FILE *voters2;
FILE *number;
FILE *voters1;
int check=0;


void vote_Count(){
number=fopen("vote.txt","r");
fscanf(number,"%d%d%d%d%d",&votesCount1,&votesCount2,&votesCount3,&votesCount4,&spoiledtvotes);
fclose(number);
printf("\n\n ##### Voting Statics ####");
printf("\n %s - %d ", CANDIDATE1, votesCount1);
printf("\n %s - %d ", CANDIDATE2, votesCount2);
printf("\n %s - %d ", CANDIDATE3, votesCount3);
printf("\n %s - %d ", CANDIDATE4, votesCount4);
printf("\n %s - %d ", "none of the above", spoiledtvotes);
}

void leadingCandidate(){
number=fopen("vote.txt","r");
fscanf(number,"%d%d%d%d%d",&votesCount1,&votesCount2,&votesCount3,&votesCount4,&spoiledtvotes);
fclose(number);
    printf("\n\n  #### Leading Candiate ####\n\n");
    if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1 >votesCount4)
    printf("[%s]",CANDIDATE1);
    else if (votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2 >votesCount1)
    printf("[%s]",CANDIDATE2);
    else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3 >votesCount1)
    printf("[%s]",CANDIDATE3);
    else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4 >votesCount3)
    printf("[%s]",CANDIDATE4);
    else
    printf("----- Warning !!! No-win situation----");



}


void initial()
{
do{
int count1=0;
printf("enter 1 to start the election freshly, enter 2 to continue with previous election.\n");
fflush(stdin);
scanf("%d",&count1);
switch(count1)
{

case 1:
number=fopen("vote.txt","w");
fprintf(number,"%d %d %d %d %d",0,0,0,0,0);
fclose(number);
voters2=fopen("voter.txt","w");
for(int k=0;k<=14;k++)
{
    fprintf(voters2,"%d ",newVoter[k]);
}
fclose(voters2);
case 2:
    check=1;
    break;
default: printf("invalid option, please retry by selecting correct option\n");

}
}while(check!=1);
}







int main()
{
int choice,compare;
int lst;
voters2 = fopen("voter1.txt","r");
int z=0;
for(z=0;z<=14;z++)
{
    fscanf(voters2,"%d",&voter1[z]);
}
fclose(voters2);
test_main();
initial();

do{
printf("\n\n ###### Welcome to cricket captains election 2020 #####\n");
printf("press 1 to cast the vote, press 2 for admin options and press 3 to exit\n");
fflush(stdin);
scanf("%d",&lst);

switch(lst)
{
case 1:
printf("\n\n Cast the Vote\n");
char num[5];
printf("enter voter id no:\n");
fflush(stdin);
scanf("%s",num);
int y=atoi(num);
int flag=0;
flag=voter_check(num);
if (flag==1)
{
   char * ptr = cast_Vote(y);
   printf("%s",ptr);
}
else
{
    printf("you entered invalid voter id please retry with valid voter id\n");
}
lst=0;
break;


   case 2:

lst=0;
printf("enter the admin password\n");
fflush(stdin);
char x[5];
scanf("%s",x);
compare=admin_password(x);
if(compare!=0)

{
    printf("you entered invalid password please retry with valid password\n");
}
else
{
printf("\n 1..press 1 to view the number of votes obtained by each candidate");
printf("\n 2..press 2 to view the name of the leading candidate");
printf("\n 3..press 3 to exit");

printf("\n\n Please enter your choice : ");
scanf("%d", &choice);

switch(choice)
{
case 1: choice=0;
vote_Count();
break;
case 2: choice=0;
leadingCandidate();
break;
case 3: break;
default:choice=0;
printf("\n Error: Invalid Choice, please retry\n");
}
}
break;
case 3: break;
default:
        lst=0;
        printf("\n invalid option, please retry by entering valid option");
}
}while(choice!=3&&lst!=3);

//hold the screen
getchar();

return 0;
}
