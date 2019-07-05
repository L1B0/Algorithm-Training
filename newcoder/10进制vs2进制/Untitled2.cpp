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
    scanf("%s",input);
    
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
    int flag=0;
    char output[5001]={0};
    memset(output,'0',5000);
    output[5000]=bin[0];
    for(int i=1;i<strlen(bin);i++)
    {
    	flag = bin[i]-'0';
        for(int j=strlen(output)-1;j>=0;j--)
        {
        	int num = output[j]-'0';
        	num = num*2+flag;
        	output[j] = num%10+'0';
        	flag = num/10;
		}
    }
    int i=0;
    while(output[i]=='0') i++;
    for(;i<strlen(output);i++)
    {
    	printf("%c",output[i]);
	}
	printf("\n");
	return 0;
}
