#include <stdio.h>
#include <conio.h>

void dummy(float a)
{
    float *p = &a;
}

struct bill
{
    char item[40];
    float qty, price;
} b[100];

int main()
{
  
    int i = 0, c = 1;
    char ch;
    float amt, total = 0;

    do
    {
        fflush(stdin);
        printf("Enter Product Name  : ");
        gets(b[i].item);
        printf("Enter Qty and Price : ");
        scanf("%f%f", &b[i].qty, &b[i].price);
        fflush(stdin);
        printf("Add More Items [y/n] : ");
        scanf("%c", &ch);
        if (ch == 'y')
        {
            i++;
            c++;
        };
    } while (ch == 'y');

    printf("============================================================");
    printf("\n THAKUR----------------MARKET");
    puts("\n============================================================");
    printf("%-10s%15s%17s%17s\n", "Item", "Qty", "Price", "Amount");
    puts("------------------------------------------------------------");
    for (i = 0; i < c; i++)
    {
        amt = b[i].qty * b[i].price;
        total = total + amt;
        printf("%-9s %16.2f\t%10.2f\t%11.2f\n", b[i].item, b[i].qty,
               b[i].price, amt);
    }
    puts("------------------------------------------------------------");

  
    printf("Total Amount :\t\t\t\t %.3f\n", total);
    
    puts("VISIT AGAIN\n");

    return 0;
}
