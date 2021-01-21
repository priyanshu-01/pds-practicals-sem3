#include <stdio.h>
#include <conio.h>
#include <string.h>

struct person{
	 char name[20];
	 long telno;
};

void appendData(){
	  FILE *fp;
	  struct person obj;
	  
	  fp=fopen("data.txt","a");
	  printf("**Add Record*\n");
	  printf("Enter Name : ");
	  scanf("%s",obj.name);
	  printf("Enter Telephone No. : ");
	  scanf("%ld",&obj.telno);
	  fprintf(fp,"%20s %7ld",obj.name,obj.telno);
	  fclose(fp);
}

void showAllData(){
	  FILE *fp;
	  struct person obj;
	  
	  fp=fopen("data.txt","r");
	  printf("**Display All Records**\n");
	  printf("\n\n\t\tName\t\t\tTelephone No.");
	  printf("\n\t\t=====\t\t\t===============\n\n");
	  while(!feof(fp))
	  {
	  fscanf(fp,"%20s %7ld",obj.name,&obj.telno);
	  printf("%20s %30ld\n",obj.name,obj.telno);
	  }
	  fclose(fp);
	  getch();
}

void findData(){
	  FILE *fp;
	  struct person obj;
	  char name[20];
	  int totrec=0;
	  
	  fp=fopen("data.txt","r");
	  printf("**Display Specific Records**\n");
	  printf("\nEnter Name : ");
	  scanf("%s",&name);
	  while(!feof(fp))
	  {
	  fscanf(fp,"%20s %7ld",obj.name,&obj.telno);
	     if(strcmpi(obj.name,name)==0){
		printf("\n\nName   :  %s",obj.name);
		printf("\nTelephone No : %ld",obj.telno);
		totrec++;
	     }
	  }
	  if(totrec==0)
	     printf("\n\n\nNo Data Found");
	  else
	     printf("\n\n===Total %d Record found===",totrec);
	  fclose(fp);
	  getch();
}



void main(){
	  int cont=1;
	  char choice;
	  while(cont){
	
	printf("**TELEPHONE DIRECTORY**\n\n");
	printf("1) Append Record\n");
	printf("2) Find Record\n");
	printf("3) Read all record\n");
	printf("4) exit\n");
	printf("Enter your choice : ");
	fflush(stdin);
	choice = getche();
	switch(choice){
		 case '1' : //call append record
			appendData();
			break;
		 case '2' : //call find record
			 findData();
			break;
		 case '3' : //Read all record
			showAllData();
			break;
		 case '4' : //Read all record
			// showAllData();
			cont=0;
			break;
		 default :
            printf("enter correct choice");
	}
	  }
}