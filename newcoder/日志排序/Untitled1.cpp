#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct infor{
	int y,m,d,h,min,sec,msec,a,b;
	char name[100],t[300];
}info;

info inf[10001];

bool cmp(info a, info b)
{
	if(a.a!=b.a) return a.a<b.a;
	else if(a.b!=b.b) return a.b<b.b;
	else if(a.y!=b.y) return a.y<b.y;
	else if(a.m!=b.m) return a.m<b.m;
	else if(a.d!=b.d) return a.d<b.d;
	else if(a.h!=b.h) return a.h<b.h;
	else if(a.min!=b.min) return a.min<b.min;
	else if(a.sec!=b.sec) return a.sec<b.sec;
	else if(a.msec!=b.msec) return a.msec<b.msec;
	else return strcmp(a.name,b.name)<0;
};
int main()
{
	int num=0;
	char temp[300];
	while(gets(temp))
	{
		/*
		int i=0,j=0;
		while(temp[i] == ' ') i++;
		j=i;
		while(temp[j] != ' ') j++;
		for(int k=i;k<j;k++)
			inf[num].name[k-i] = temp[k];
		inf[num].name[j] = '\0';
		//puts(inf[num].name);
		
		i=j;
		while(temp[i] == ' ') i++;
		
		int l;
		j=strlen(temp)-1;
		while(temp[j] == ' ') j--;
		l = j;
		while(temp[j] != ' ') j--;
		for(int k=j+1;k<=l;k++)
			inf[num].date2[k-j-1] = temp[k];
		inf[num].date2[l+1] = '\0';
		//puts(inf[num].date2);
		
		while(temp[j] == ' ') j--;
		for(int k=i;k<=j;k++)
			inf[num].date1[k-i] = temp[k];
		inf[num].date1[j+1] = '\0';
		//puts(inf[num].date1);
		*/
		if(strlen(temp) == 0) break;
		strcpy(inf[num].t,temp);
		sscanf(temp,"%s %d-%d-%d %d:%d:%d,%d %d.%d(s)",inf[num].name,&inf[num].y,&inf[num].m,&inf[num].d,&inf[num].h,&inf[num].min,&inf[num].sec,&inf[num].msec,&inf[num].a,&inf[num].b);
		num++;
	}
	sort(inf,inf+num,cmp);
	for(int i=0;i<num;i++)
		puts(inf[i].t); 
	return 0;
} 
