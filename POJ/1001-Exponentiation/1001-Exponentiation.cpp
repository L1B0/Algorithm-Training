#include <stdio.h>
#include <string.h>
int times=0;

char *myCalc(char source[1000], char s[1000], int times)
{
	if( times == 0 ) return s;
	
	int last=0,a=strlen(source),b=strlen(s);
	char res[1000]={0};	
	for(int i=0;i<(a+b-1);i++) // times
	{
		int temp=last,first,end;
		if( i < a )
		{
			first = 0;
			end = i+1;
		}
		else if( i < b )
		{
			first = 0;
			end = a; 
		}
		else
		{
			first = i-b+1;
			end = a;
		}
		for(int j=first;j<end;j++)
		{
				temp += (source[j]-'0')*(s[i-j]-'0');
		}
		res[i] = temp%10 + '0';
		last = temp/10;
	}
	if( last != 0 ) res[a+b-1] = last+'0';
	//puts(res);
	return myCalc(source,res,times-1);
}

int main()
{
	char input[10]; 
	while( scanf("%s %d",input,&times) != EOF )
	{
		int num=0,points = 0,flag = 0;
		char sum[1000] = {0};
		for(int i=strlen(input)-1;i>=0;i--)
		{
			if(input[i] == '0' && flag == 0)continue;
			else if(flag == 0) flag = 1;
			if(input[i] == '.')
			{
				flag = 2;
				continue;
			}
			sum[num++] = input[i];
			if(flag == 1) points ++;
		}
		if( flag != 2 ) points = 0;
		
		
		for(int i=strlen(sum)-1;i>=0;i--)
		{
			if(sum[i] == '0')
				sum[i] = 0;
			else break; 
		}
		//printf("%d %s\n",points,sum);
		char *results = myCalc(sum,sum,times-1);
		if( strlen(results) < points*times )
		{
			printf(".");
			for(int i=0;i<(points*times-strlen(results));i++)
				printf("0");
		}
		for(int i=strlen(results)-1;i>=0;i--)
		{
			if( (i+1) == points*times )
				printf(".");
			printf("%c",results[i]);
		}
		printf("\n");
	}
	return 0;
}
