#include<stdio.h>
#include<conio.h>
#include<string.h>

struct list{
char date[20];
char name[20];
char bname[20];
char mobile[15];
char bwriter[20] ;
int year;
}issue[10];
int n,i;

struct {
char author[20];
char title[30];
int edition;
}book[30];

void issue_book()
{
int k;
FILE *fp;
fp=fopen("library.txt","a");
printf("How many books you want to Issue : ");
scanf("%d",&k);
for(i=0;i<k;i++)
{
	printf("Book %d",i+1);
    printf("\nEnter the Date: ");
    scanf("%s",&issue[i].date);
    printf("Enter Name: ");
    scanf("%s",&issue[i].name);
    printf("Enter Mobile Number: ");
    scanf("%s",&issue[i].mobile);
    printf("Enter Book Name: ");
    scanf("%s",&issue[i].bname);
    printf("Enter the Author Name: ");
    scanf("%s",&issue[i].bwriter);
    printf("Enter Edition(Year): ");
    scanf("%d",&issue[i].year);
    fprintf(fp,"%s %s %s %s %s %d\n",issue[i].date,issue[i].name,issue[i].mobile,issue[i].bname,issue[i].bwriter,issue[i].year);
}
printf("Record Saved..\n");
fclose(fp);
getch();
}

void return_book()
{
	FILE *ptr,*p;
	char ch;
	int i=0,j=0,s,x,n;
	char yn[20],bn[20];
	printf("Enter Your Name: ");
	scanf("%s",&yn);
	printf("Enter the Book Name: ");
	scanf("%s",&bn);
	ptr=fopen("library.txt","r");
	while(!feof(ptr))
	{
	fscanf(ptr,"%s %s %s %s %s %d\n",issue[i].date,issue[i].name,issue[i].mobile,issue[i].bname,issue[i].bwriter,&issue[i].year);
	s=strcmp(yn,issue[i].name);
	x=strcmp(bn,issue[i].bname);
	    if(s==0 && x==0)
	    {
		printf("Entry Found...");
		break;
		}
	 i++;
    }
	fclose(ptr);
    if(s!=0)
	{
		printf("Entry Not Found!!!!");
	}
	if(s==0 && x==0)
	{
	ptr=fopen("library.txt","r");
	p=fopen("library1.txt","w");
	ch=getc(ptr);
	while(ch!=EOF)
   {	
   ch=getc(ptr);
   if(ch=='\n')
   {
   	j++;
   }
   	if(j!=i)
   	{
   		putc(ch,p);
	}
}
fclose(ptr);
fclose(p);
remove("library.txt");
rename("library1.txt","library.txt");
printf("Book Returned Successfully..");
}
}


void display()
{
FILE *fp;
char c;
fp=fopen("library.txt","r");
while(!feof(fp))
{
    c=getc(fp);
	printf("%c",c);
}
fclose(fp);
getch();
}

void add_book()
{
FILE *ptr;
int p,s;
printf("How many books you want to add :");
scanf("%d",&s);
for(p=0;p<s;p++)
	{
	printf("Book %d :",p+1);
	printf("\nEnter the Title :");
	scanf("%s",&book[p].title);
	printf("Enter the Author Name:");
	scanf("%s",&book[p].author);
	printf("Enter the Edition:");
	scanf("%d",&book[p].edition);
	ptr=fopen("booklist.txt","a");
	fprintf(ptr,"%s %s %d\n",book[p].title,book[p].author,book[p].edition);
	fclose(ptr);
    }
printf("Record Saved and Updated...");
getch();
}

void see_all()
{
FILE *ptr;
char c;
ptr=fopen("booklist.txt","r");
while(!feof(ptr))
	{
	    c=getc(ptr);
		printf("%c",c);
	}
fclose(ptr);
getch();
}

void search_book()
{
	FILE *ptr;
	int i=0,s,n;
	char bn[20];
	printf("Enter the Book Name: ");
	scanf("%s",&bn);
	ptr=fopen("booklist.txt","r");
	while(!feof(ptr))
	{
	fscanf(ptr,"%s %s %d",book[i].title,book[i].author,&book[i].edition);
	s=strcmp(bn,book[i].title);
	    if(s==0)
	    {
		  printf("Book is Available..");
		  printf("\nThe Author of the Book is: %s",book[i].author);
		  printf("\nEdition of the Book is: %d",book[i].edition); 
		  printf("\nDo you want to Issue the book?: ");
		  printf("\nYes: Enter 1   No: Enter 2 --- ");
	      scanf("%d",&n);
	      if(n==1)
	      {
	      	issue_book();
		  }
		  break;
	    }
	 i++;
    }
	fclose(ptr);
        if(s!=0)
		{
		printf("Book is Not Available!!!!");
		}	
	getch();
	
}

void header()
{
	printf("\n");
	printf("\n");
    printf("               **WELCOME TO LOVELY**           \n");
    printf("       ###LIBRARY MANAGEMENT SYSTEM###      \n");
}
void main()
{
	char ch;
	int x;
	header();
	printf("Enter Password : ");
	scanf("%d",&x);
	if(x==8521)
	{
	do
	{
	printf("\n");
	printf("\n");	
	printf("Enter <1> to Search Book\n");
	printf("Enter <2> to Issue Book\n");
	printf("Enter <3> to Return Book\n");
	printf("Enter <4> to See All Issued Books\n");
	printf("Enter <5> to Add Book\n");
	printf("Enter <6> to See All Available Books\n");	
	printf("\nEnter Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
				search_book();
				break;
		case 2:
			    issue_book();
			    break;
		case 3:
		        return_book();
				break;	    
		case 4:
				display();
			    break;
		case 5:
				add_book();
				break;
		case 6:
		        see_all();
				break; 					
		default:
				printf("invalid selection");		
		}
	}
	while(ch!=-1);
}
else 
{
	printf("Wrong Password!!");
}
	getch();	
}	
