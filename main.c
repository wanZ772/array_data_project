// coded by wanz

#include <stdio.h>
#include <string.h>
void CalculateFee(int childs_no, int fees[], int discont_available);
void input();
void test(int test_array[2]);
void output(int total_fee, int discount);
int main()
{
    
    input();

    return 0;
}

void input()    {
    int childs, discont_available;
    char household[10];
    
    
    
    // int fees[4] = {0,370,330,200};
    printf("Welcome to kindergardern\n");
    printf("how many child: ");
    scanf("%d", &childs);
    
    if (childs > 1)  {
        discont_available = 1;
    }
    printf("\nHousehold income (A or B): ");
    scanf("%s", household);
    
    while(strcmp(household, "A") != 0 && strcmp(household, "B") != 0) {
       printf("\nInvalid!\nHousehold income (A or B): ");
     scanf("%s", household); 
    }
    
    if (strcmp(household, "A") == 0) {
 
        int fee[4] = {0,370,330,200};
        CalculateFee(childs,fee, discont_available);
    }   else {
       
        int fee[4] = {0,350,300,150};
        CalculateFee(childs,fee, discont_available);
    }
    
    
}
void test(int fee[2])   {
    printf("testing aray: ");
    printf("%d", fee[1]);
}
void CalculateFee(int childs_no, int fee[4], int discount)   {
    int total_fee = 0;
    int discont_available = discount;
    //{0,370,330,200};  income 5000 keatas
   // {0,350,300,150};  income 5000 kebawah
     // array income yg akan guna
     
    int category;
   
    for (int i = 1; i <= childs_no; i++)    {
        printf("\n\nChild #%d\n========\n", i);
        
        printf("Category (1, 2 or 3): ");
         scanf("%d", &category);
    
    
       while (category != 1 && category != 2 && category != 3)  {
           printf("Invalid!\nCategory (1,2 or 3): ");
           scanf("%d", &category);
       }
       
       
       total_fee = total_fee + fee[category];
       printf("The monthly fee is : RM%d", fee[category]);
    
    }
    output(total_fee, discont_available);
}

void output(int total_fee, int discount)   {
    if (discount != 0) {
        printf("\nTotal fee is RM%d", total_fee);
        printf("\nDiscounted fee is RM %.0f", (total_fee - (total_fee * 0.1)));
    }   else {
        printf("\nTotal fee is RM%d", total_fee);
    }
    printf("\nThank you for using this system.");
}
