#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
 
char s[7];
void myputs(bool flag[7],char output[7])
{	
	if( strlen(output) == strlen(s) )
	{
		puts(output);
		return ;
	}
	 
	for(int i=0;i<strlen(s);i++)
	{
		if(flag[i] == 0)
		{
			output[strlen(output)] = s[i];
			output[strlen(output)+1] = '\0';
			flag[i] = 1; 
			myputs(flag,output); 
			flag[i] = 0;
			output[strlen(output)-1] = '\0';
		}
	}
	
	return ;
}

int main()
{
	while(gets(s))
	{
		sort(s,s+strlen(s));
		//puts(s);
		char output[7]={0};
		bool flag[7] = {0};
		myputs(flag,output);
		printf("\n");
	}
	
	return 0;
}
