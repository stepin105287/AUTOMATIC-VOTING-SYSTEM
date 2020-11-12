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

int voter_array[15]={1234,1324,1243,1342,1423,1432,2134,2314,2341,2413,2431,2143,3124,3214,3241};


int voter_check(char num[5])
{
int z = atoi(num);
int flag=0;
for(int i=0;i<=14;i++)
{
    if(z==voter_array[i])
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
