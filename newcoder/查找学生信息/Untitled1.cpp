#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student{
    char name[20];
    char sex[5];
    char id[5];
    int age;
}st;

st temp[1001];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<1001;i++)
        temp[i].age = -1;
    for(int i=0;i<n;i++)
    {
        int index,ta;
        char tn[20],ts[5],tid[5];
        scanf("%s %s %s %d",tid,tn,ts,&ta);
        index = atoi(tid);
        strcpy(temp[index].id,tid);
        strcpy(temp[index].name,tn);
        strcpy(temp[index].sex,ts);
        temp[index].age = ta;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    	int j;
    	scanf("%d",&j);
        if( temp[j].age == -1 ) puts("No Answer!");
        else
        {
            printf("%s %s %s %d\n",temp[j].id,temp[j].name,temp[j].sex,temp[j].age);
        }
    }
    return 0;
}
