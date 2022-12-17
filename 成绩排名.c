#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int include(char* x,char* y);
int com(char* a,char* b)
{
	if(strlen(a)==strlen(b))
		return strcmp(a,b);
	else
		return strlen(a)-strlen(b);
}
int main(void)
{
	int n,x[10]={0},z=0,j=0,rank;
	scanf("%d",&n);//读入组数 
	char name[n][11],ID[n][19],score[n][4],m[19];
	scanf("%s",&m);//读入待查找字符（串） 
	for(int i=0;i<n;i++)//读入数据 
	scanf("%s %s %s",name[i],ID[i],score[i]);
	if((m[0]<='z'&&m[0]>='a')||(m[0]<='Z'&&m[0]>='A'))//模糊查找名字 
	{
		for(int i=0;i<n;i++)
		{
			if(include(name[i],m))
			x[j++]=i;
		}
	}
	else if(strlen(m)>3)//模糊查找学号 
	{
		for(int i=0;i<n;i++)
		{
			if(include(ID[i],m))
			x[j++]=i;
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if((strcmp(score[i],m)==0)||(include(ID[i],m)))//精确查找分数,模糊查找学号 
			x[j++]=i;	
		}
	}
	for(int i=0;i<n;i++)
	    {
	    	rank=1;
	    	if(i==x[z])//按序号打印数据 
	    	{
	    		z++;
	    		printf("%s %s %s ",name[i],ID[i],score[i]);
	    		if(strcmp(score[i],"n/a")==0)
	    		printf("n/a\n");
	    		else//成绩排名 
	    		{
	    			for(int f=0;f<n;f++)
	    		{
	    			if(strcmp(score[f],"n/a")==0)
	    			;
	    			else if(com(score[f],score[i])>0)
	    			rank++;
				}
				printf("%d\n",rank);
				}
			}
		}
	return 0;
}
int include(char* x,char* y)
{
	int v;
	v=strlen(y);
	if(strcmp(x,y)==0)//判断是否相等 
	return 1;
	else//判断是否包含 
	{
		for(int i=0;*(x+i+v-1)!='\0';i++)
		{
			int j=0,k;
			if(*(x+i)==*(y+j))
			{
				k=i;
				while(*(y+j)!='\0')
				{
					if(*(x+k)!=*(y+j))
					break;
					k++;
					j++;
				}
				if(*(y+j)=='\0')
				return 1;
			}
		}
		return 0;
	}
}
