#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char input[1001]={0};

int div()
{
	if(strlen(input) == 1 && input[strlen(input)-1] == '1') return -1;
	
	//div2
	int flag=0; //进位 
	int ret = (input[strlen(input)-1]-'0')%2;
	for(int i=0;i<strlen(input);i++)
	{
		if(flag)
		{
			int num=(input[i]-'0')+10;
			input[i]=num/2+'0';
			flag = num%2; 
		}
		else
		{
			int num=(input[i]-'0');
			input[i]=num/2+'0';
			flag = num%2; 
		} 
	}
	//清除左边的0 
	int i;
	char temp2[1001]={0};
	for(i=0;i<strlen(input);i++)
	{
		if(input[i] == '0') continue;
		else break;
	}
	for(int j=i;j<strlen(input);j++)
	{
		temp2[j-i]=input[j];
	}
	memcpy(input,temp2,1001); 
	//puts(input);
	return ret;
}
int main()
{
	while(scanf("%s",input)!=EOF)
    {
    	if(input[0] == '0' && strlen(input) == 1 )
		{
			puts("0\0");
			continue;
		}
    	int num=0;
   		char bin[5000]={0};
    	while(1)
    	{
    	    int i = div();
    	    if(i == -1)
			{
				bin[num++]='1';
				break;
			}
     	   bin[num++]=i+'0';
   		}
  		//puts(bin);

    	for(int i=strlen(bin)-1;i>=0;i--)
    	{
    		printf("%c",bin[i]);
		}
		printf("\n");
	}
	return 0;
}
