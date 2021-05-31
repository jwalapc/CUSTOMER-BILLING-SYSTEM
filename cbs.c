#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct itm
{
	int prno;
	char prname[10];
	int qty;
	int price;
}it;
struct customer
{
	int prno;
	char prname[10];
	int qty;
	int price;
	int amount;
}cst[100];
struct tempor
{
	int prno;
	char prname[10];
	int qty;
	int price;
	int amount;
}cstr[100];
int t=0,n=0,k=0,ba=0,ti=0; 
///function section*********************
void create()
{
	int i=0;
	FILE *fp,*fpq;
	fp=fopen("shop.txt","w");
	if(fp==NULL)
	{
		printf("ERROR\n");
		exit(0);
	}
	printf("enter the number of records\n");
	scanf("%d",&n);
	fpq=fopen("asd.txt","w");
	fprintf(fpq,"%d",n);
	fclose(fpq);
	while(i<n)
	{
		printf("enter the product code\n");
		scanf("%d",&it.prno);
		printf("enter the name\n");
		scanf("%s",it.prname);
		printf("enter the quantity\n");
		scanf("%d",&it.qty);
		printf("enter the price\n");
		scanf("%d",&it.price);
		i++;
		fprintf(fp,"%d\t%s\t%d\t%d\t",it.prno,it.prname,it.qty,it.price);
	}
	//fprintf(fp,"%d",0);
	fclose(fp);
	printf("\n records are being created so please come back again\n");
//	exit(0);
}
/////function 2***********
void bill()
{
int na,a,cont=0,k,r=0,w=0,ch,l=0,bi=0,ln=0;
//char k;
l3 : printf("enter the product number\n");
scanf("%d",&na);
FILE *fp,*fptr;
fp=fopen("shop.txt","r");
fptr=fopen("temp.txt","w");
while(!(feof(fp)))
{
	l++;
fscanf(fp,"%d",&it.prno);
fscanf(fp,"%s",it.prname);
fscanf(fp,"%d",&it.qty);
fscanf(fp,"%d",&it.price);
if(it.prno==na)
{
	ln++;
	if(ln==2)
	break;
	printf("enter the quantity\n");
	scanf("%d",&a);
	if(a<=it.qty)
	{
		cst[ti].prno=it.prno;
		strcpy(cst[ti].prname,it.prname);
		cst[ti].qty=a;
		cst[ti].price=it.price;
		it.qty=it.qty-a;
		ti++;
		//goto l1;	
	}
	else
	printf("out of stock\n");
	bi++;
	//goto l1;	
}
else
{
	cont++;
    fprintf(fptr,"%d\t",it.prno);
    fprintf(fptr,"%s\t",it.prname);
    fprintf(fptr,"%d\t",it.qty);
    fprintf(fptr,"%d\t",it.price);
	continue;
}
fprintf(fptr,"%d\t",it.prno);
fprintf(fptr,"%s\t",it.prname);
fprintf(fptr,"%d\t",it.qty);
fprintf(fptr,"%d\t",it.price);
}
if(l==cont)
printf("error\nchoose proprly\n");
fclose(fptr);
fclose(fp);
remove("shop.txt");
rename("temp.txt","shop.txt");
ln=0;
printf("do you want to shop more\npress 1 for yes\n");
scanf("%d",&k);
if(k==1)
goto l3;

}
void display()
{
	int nk=0;
    FILE *fp;
	fp=fopen("shop.txt","r");	
	if(feof(fp))
	{
		printf("error in opening file\n");
		exit(0);
	}
	printf("================================================================================\n");
	printf("\t|product number\t|product name\t|quantity\t|price\t|\n");
	printf("=================================================================================\n");
	while(nk!=n)
	{
		nk++;
		fscanf(fp,"%d",&it.prno);
		if(it.prno==0)
		{
		printf("product number cannot be zero\n");
		break;
		}
		fscanf(fp,"%s",it.prname);
		fscanf(fp,"%d",&it.qty);
		fscanf(fp,"%d",&it.price);
		printf("\n\t  %14d|\t%8s|\t%8d|\t%d|\n",it.prno,it.prname,it.qty,it.price);		
	}
	fclose(fp);
}
////functin section*******************	
void edit()
{
    FILE *fp,*fptr,*fpk;
	int h,found=0,ka=0,z,p;
	fp=fopen("shop.txt","r");
	fptr=fopen("temp1.txt","w");
	fpk=fopen("temp2.txt","w");
	printf("enter the product number to delete\n");
	scanf("%d",&h);
	p=n;
	while(!(ka==p))
	{
		ka++;
		fscanf(fp,"%d",&it.prno);
		if(it.prno==h)
		{
			found=1;
			fscanf(fp,"%s",it.prname);
			fscanf(fp,"%d",&it.qty);
			fscanf(fp,"%d",&it.price);
			n--;
			printf("product has been sucessfully deleted\n");
		}
		else
		{ 
			fscanf(fp,"%s",it.prname);
			fscanf(fp,"%d",&it.qty);
			fscanf(fp,"%d",&it.price);
			fprintf(fptr,"%d\t%s\t%d\t%d\t",it.prno,it.prname,it.qty,it.price);
		}
	}
	    fprintf(fpk,"%d",n);
	    fclose(fpk);
		fclose(fptr);
		fclose(fp);
		if(found==0)
		printf("\n product not found\n");
		remove("asd.txt");
		rename("temp2.txt","asd.txt");
		remove("shop.txt");
		rename("temp1.txt","shop.txt");
	}

void invoice()
{
	int i,j,o;
	float amt,gt=0;
	if(ti==0)
	
	{printf("no products in your cart\n");
	exit(0);}
	printf("\n\n********************INVOICE**********************\n");
	printf("================================================================================\n");
	printf("product number\t| product name\t| price\t| quantity\t| amount\t|\n");
	printf("================================================================================\n");
	for(o=0;o<ti;o++)
	{
		cst[o].amount=0;
		cst[o].amount=(cst[o].qty)*(cst[o].price);
		gt=gt+cst[o].amount;		
	}
	for(j=0;j<ti;j++)
	{
		printf("%6d\t       |%9s   \t  | %3d\t|%3d\t        |   %3d\n",cst[j].prno,cst[j].prname,cst[j].price,cst[j].qty,cst[j].amount);
	}
	printf("\n amount payable is %f",gt);
	printf("thank you for shopping\ncome again\n");
	exit(0);
}
void mdelete()
{
	int i,j,f,g=0,aj=0,ag=0;
	char ab[100];
	FILE *fw,*fq;
	printf("enter the product number to be deleted\n");
	scanf("%d",&f);
	for(i=0;i<ti;i++)
	{
	  if(cst[i].prno==f)
	  {aj=cst[i].qty;
	  printf("\nproduct deleted successfully\n");} 
	  continue;
	  cstr[g].prno=cst[i].prno;
	  strcpy(cstr[g].prname,cst[i].prname);
	  cstr[g].qty=cst[i].qty; 
	  cstr[g].price=cst[i].price;
	  g++;
	}
	for(j=0;j<g;j++)
	{
	 cst[j].prno=cstr[j].prno;
 	 strcpy(cst[j].prname,cstr[j].prname);
	  cst[j].qty=cstr[j].qty; 
	  cst[j].price=cstr[j].price;
	}
	ti=g;
	printf("\n%d",aj);
	fq=fopen("shop.txt","r");
	fw=fopen("temp4.txt","w");
	for(j=0;j<n;j++)
	{
		    fscanf(fq,"%d",&it.prno);
		    fscanf(fq,"%s",it.prname);
			fscanf(fq,"%d",&it.qty);
			fscanf(fq,"%d",&it.price);
			if(it.prno==f)
			{ag=aj+it.qty;
			fprintf(fw,"%d\t%s\t%d\t%d\t",it.prno,it.prname,ag,it.price);}
            else
			fprintf(fw,"%d\t%s\t%d\t%d\t",it.prno,it.prname,it.qty,it.price);	
			
	}
	fclose(fq);
    fclose(fw);
    remove("shop.txt");
    rename("temp4.txt","shop.txt");
}
void mdisplay()
{
	int i,j,o;
	printf("================================================================================\n");
	printf("product number\t|product name\t|quantity\t|price\t\n");
	printf("================================================================================\n");
	for(o=0;o<ti;o++)
	{
		printf("%14d\t|%12s\t|%6d\t|%6d\n",cst[o].prno,cst[o].prname,cst[o].qty,cst[o].price);
	}
}

main()
{
	char ch,password[10],q[10]="yatish";
	int s=0,y=0,w=1,i;
	FILE *fpe;
	fpe=fopen("asd.txt","r");
	fscanf(fpe,"%d",&n);
	fclose(fpe);
	printf("\t********WELCOME TO DENIMXPRESS**************\n\n");
	printf("\t        YOU ARE LUCKY TO BE SHOPPING HERE\n");
	printf("\tplease note that all the products' price are discounted and are genuine\n\tso no bargain\n");
	printf("\treference number%d\n",n);
	q: printf("\n\n\t01. ADMINISTRATOR\n\t02. CUSTOMER\n\t03.BREAK\n");
	scanf("%d",&s);
	switch(s)
	{
	          case 1: printf("\tenter password\n\t");
              for(i=0;i<6;i++)
              {
              ch = getch();
              password[i] = ch;
              ch = '*' ;
               printf("%c",ch);
              }
              password[i]='\0';
              if(strcmp(password,q))
              { 
              printf("wrong password try again");
              goto q;
             }
               else
               goto l3;
               l3: printf("\n\tacess granted\n");
		       printf("\t01.CREATE\n\t02.DELETE/MODIFY\n\t03.DISPLAY\n\t04.MAIN MENUE\n");
		        scanf("%d",&y);
		        switch(y)
		        {
        			case 1:create();
        			      goto q;
  			      case 2:edit();
  			             goto q;
                  case 3:display();
                         goto q;
                  case 4: goto q;
                  default : printf("error\n");
				  goto q;       
        		}
		         break;
       case 2: printf("\t01.BILL\n\t02.INVOICE\n\t03.DISPLAY\n\t04.MY CART\n\t05.MAIN MENUE\n\t06. DELETE ITEMS IN CART\n");
              scanf("%d",&y);
              switch(y)
		        {
        			case 1:bill();
        			      goto q;
  			      case 2:invoice();
  			             goto q;
                  case 3:display();
                         goto q;
                  case 4: mdisplay();
                  goto q;
                  case 5: goto q;
                  case 6: mdelete();
                  goto q;
                  default : printf("error\n"); 
				  goto q;      
        		}
		         break;
      case 3: printf("breaking...\n");
      break;
       default : printf("error\n");
       break;       
	}	
}
