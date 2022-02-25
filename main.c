#include<stdio.h>
#include<string.h>
void showmenu(char[][20],float[]);
float getmoney();
void purchase(float,float[],char[][20]);
int main()
{	char drink[5][20]={"mineral water","coca-cola","seven-Up","nescafe","soydrink"};
	float total,price[5]={1,2.5,2.2,3,1.9};
	showmenu(drink,price);
	total=getmoney();
	purchase(total,price,drink);
	system("pause");
	return 0;
}
void showmenu(char a[][20],float b[])
{	int i;
	for(i=0;i<5;i++)
	{	printf("\t%s \tRM %.2f",a[i],b[i]);
		printf("\n");
	}
}
float getmoney()
{	int x;
	float total=0;
	do
	{	printf("enter money(cents) : (-1 to stop) : ");
		scanf("%d",&x);
		switch(x)
		{	case -1: break;
			case 50:
			case 20:
			case 10: total+=(float)x/100;
					 printf("total amount inserted until now = RM%.2f\n",total);	
					 break;	
			default: printf("invalid! enter again\n");
		}
	}while(x!=-1);
	return total;
}
void purchase(float total,float price[],char drink[][20])
{	int i;
	char choice[20];
	printf("\navailable drinks :\n");
	for(i=0;i<5;i++)
	{	if(total>=price[i])
		{	printf("%s \tRM %.2f",drink[i],price[i]);
			printf("\n");
		}
	}
	printf("\nwhich one do you like to buy? :\n");
	printf("your choice : ");
	fflush(stdin);
	gets(choice);
	for(i=0;i<5;i++)
	{	if(strcmp(drink[i],choice)==0)
		printf("price = RM %.2f\nbalance = RM%.2f\n",price[i],total-price[i]);
		
	}printf("thank you \2\n");
}
