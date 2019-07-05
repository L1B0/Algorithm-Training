#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
void mult(char *a, char b[5])
{
	char *c;
	c = (char *)malloc(2600);
	memset(c,0,strlen(c));
	memcpy(c,a,strlen(a));
	memset(a,0,strlen(a));
	
	int lenc=strlen(c),lenb=strlen(b);
	for(int i=0;i<(lenc+lenb-1);i++)
	{
		int sum=0;
		for(int j=0;j<=((lenc-1)>i?i:(lenc-1));j++)
		{
			if(i-j>=lenb) continue;
			sum += (c[j]-'0')*(b[i-j]-'0');
		}
		//这里要注意char范围为-127-127 
		int t = a[i];
		t += sum;
		if(t>9) a[i+1]=t/10;
		a[i] = t%10+'0';
	}
	if(a[lenc+lenb-1] != '\0') a[lenc+lenb-1]+='0',a[lenc+lenb] = '\0';
	return ;
}

char* calc(int n)
{
	char *s;
	s = (char *)malloc(2600);
	memset(s,0,strlen(s));
	s[0]='1';
	for(int i=2;i<=n;i++)
	{
		char a[5];
		sprintf(a,"%d",i);
		for(int j=0;j<strlen(a)/2;j++)
		{
			char t=a[j];
			a[j]=a[strlen(a)-j-1];
			a[strlen(a)-j-1] = t;
		}
		mult(s,a);
	}
	//puts(s);
	return s;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if( n <= 2 )
		{
			printf("%d\n",n);
			continue;
		}
		char *s;
		s = calc(n); 
		for(int i=strlen(s)-1;i>=0;i--)
		{
			printf("%c",s[i]);
		}
		printf("\n");
	}
} 
