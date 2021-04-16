/*
CREATED BY:
CA19103	TUA YONG LIANG	03A
CB19104	SHIA LEE YEE	03A
CA19108	KONG CHOON	    03A
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void Welcome(void);
void Title(void);
void Login(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50]);
void Menu(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50]);
void Add_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50]);
void list_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50]);
void Search_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50]);
void Edit_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50]);
void Delete_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50]);
void print_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50]);
void exit_menu(void);

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(void)
{
    int day[2], month[2], year[4], hour[2], minute[2];
	int choose;
	char Name[50][50], Contact_no[50][50], Date[50][50], Time[50][50], Details[50][50];

    Welcome();
	Title();
	Login(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);

	return 0;
}
/* ***************** Welcome Screen *************** */
void Welcome(void)
{
	printf("\n\t\t\t\t*****************************************");
	printf("\n\t\t\t\t*\t\t\t\t\t*");
	printf("\n\t\t\t\t*\t\tWELCOME TO\t\t*");
	printf("\n\t\t\t\t*    TSK APPOINTMENT BOOKING SYSTEM     *");
	printf("\n\t\t\t\t*\t\t\t\t\t*");
	printf("\n\t\t\t\t*****************************************");
	printf("\n\n\n\n\n Press any key to continue......");
	getch();
	system("cls");
}
/* ***************** Title Screen *************** */
void Title(void)
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t        TSK APPOINMENT BOOKING SYSTEM         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}
/* ***************** Main Menu *************** */
void Menu(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50])
{
	system("cls");
	int choose;
	Title();
	printf("\n\n\n\n\n\t\t\t\t1. Add Appointment\n");
	printf("\n\t\t\t\t2. List Appointment\n");
	printf("\n\t\t\t\t3. Search Appointment\n");
	printf("\n\t\t\t\t4. Edit Appointment\n");
	printf("\n\t\t\t\t5. Delete Appointment\n");
	printf("\n\t\t\t\t6. Print All Appointment\n");
	printf("\n\t\t\t\t7. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 7: ");
	scanf("%d", &choose);

	switch(choose)
    {
      case 1:
        Add_appointment(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
        break;
      case 2:
        list_appointment(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
        break;
      case 3:
        Search_appointment(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
        break;
      case 4:
        Edit_appointment(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
        break;
      case 5:
        Delete_appointment(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
        break;
      case 6:
        print_appointment(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
        break;
      case 7:
        exit_menu();
        break;
      default:
        printf("Invalid input. Please enter the correct option.");
        getch();
	}
}
/* ***************** Exit Screen *************** */
void exit_menu(void)
{
	system("cls");
	Title();
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR USING TSK APPOINTMENT BOOKING SYSTEM !");
	getch();
}
/* ***************** Login Screen *************** */
void Login(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50])
{
  	int e = 0;
  	char Username[15];
  	char Password[15];
  	char original_Username[25] = "username";
    char original_Password[15] = "password";

  	do
    {
        printf("\n\n\n\n\t\t\t\tEnter your Username and Password !");
        printf("\n\n\n\t\t\t\t\tUSERNAME:");
        scanf("%s", &Username);
        printf("\n\n\t\t\t\t\tPASSWORD:");
        scanf("%s", &Password);

        if (strcmp(Username,original_Username) == 0 && strcmp(Password,original_Password) == 0)
        {
            printf("\n\n\n\t\t\t\t\t...Login Successfull...");
            printf("\n\n\n\n\n Press any key to continue......");
            getch();
            Menu(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
            break;
        }
        else
        {
            printf("\n\t\t\tPassword incorrect ! Try Again !");
            e++;
            getch();
        }
    }while(e <= 2);
	if(e > 2)
	{
        printf("You have cross the limit. You cannot login.");
        getch();
        exit_menu();
	}
    system("cls");
}
/* *************ADD APPOINTMENT**************/
void Add_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50])
{
    char ans;
    system("cls");
    Title();
    FILE*ek;
    ek = fopen("Record.txt", "a");
    printf("\n\n\t\t\t****** Add Appointment ******\n");
	/* *********Name************ */
    A:
        printf("\n\t\t\tName (no spacing): ");
        scanf("%s", &Name[0]);
    /* *************** Contact no. *************** */
    B:
        printf("\n\t\t\tContact no: ");
        scanf("%s", &Contact_no[0]);
    /* *************** Date *************** */
    C:
        printf("\n\t\t\t*** Date ***");
        printf("\n\t\t\tEnter Day: ");
        scanf("%d", &day[0]);
        printf("\n\t\t\tEnter Month: ");
        scanf("%d", &month[0]);
        printf("\n\t\t\tEnter Year: ");
        scanf("%d", &year[0]);
    /* *************** Time *************** */
    D:
        printf("\n\t\t\t*** Time in 24 Hour Format ***");
        printf("\n\t\t\tHour: ");
        scanf("%d", &hour[0]);
        printf("\n\t\t\tMinute: ");
        scanf("%d", &minute[0]);
    /* ******************* Details[i] ***************** */
    E:
        printf("\n\t\t\tDetails (no spacing): ");
        scanf("%s", &Details[0]);
        fprintf(ek, "%s %s %.2d/%.2d/%.4d %.2d:%.2d %s\n", Name[0], Contact_no[0], day[0], month[0], year[0], hour[0], minute[0], Details[0]);
        printf("\n\n\t\t\tAppointment Added Successful !");
        fclose(ek);
    /* ******************* Details[i] ***************** */
    F:
        fflush(stdin);
        printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
        scanf("%c",&ans);
        if (toupper(ans) == 'Y')
        {
            Add_appointment(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
        }
        else if(toupper(ans) == 'N')
        {
            printf("\n\t\t Thank you !");
            getch();
            Menu(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
        }
        else
        {
            printf("\n\t\tInvalid Input\n");
            goto F;
        }
}
/* *************VIEW APPOINTMENT**************/
void list_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50])
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek = fopen("Record.txt", "r");
	printf("\n\n\t\t\t****** List Appointment ******\n");
    gotoxy(6,10);
    printf("Name");
    gotoxy(30,10);
    printf("Contact No.");
    gotoxy(55,10);
    printf("Date");
    gotoxy(70,10);
    printf("Time");
    gotoxy(85,10);
    printf("Details\n");
    printf("=================================================================================================================");
    row = 12;
    while(fscanf(ek,"%s %s %s %s %s\n", &Name[0], &Contact_no[0], &Date[0], &Time[0], &Details[0]) != EOF)
    {
        gotoxy(6,row);
        printf("%s", Name[0]);
        gotoxy(30,row);
        printf("%s", Contact_no[0]);
        gotoxy(55,row);
        printf("%s", Date[0]);
        gotoxy(70,row);
        printf("%s", Time[0]);
        gotoxy(85,row);
        printf("%s", Details[0]);
        row++;
    }
    fclose(ek);
    printf("\n\n\n\n\n Press any key to continue......");
    getch();
    Menu(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
}
/* *************SEARCH APPOINTMENT**************/
void Search_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50])
{
	int row;
	char name[20], ans = 0;
	system("cls");
	Title();
	FILE *ek;
	ek = fopen("Record.txt","r");
	printf("\n\n\t\t\t****** Search Appointment ******\n");
	gotoxy(12,8);
	printf("\n Enter Name to be viewed:");
	scanf("%s", name);
	fflush(stdin);
	while(fscanf(ek,"%s %s %s %s %s\n", Name[0], Contact_no[0], Date[0], Time[0], Details[0]) != EOF)
	{
		if(strcmp(Name[0],name) == 0)
		{
			gotoxy(6,10);
            printf("Name");
            gotoxy(30,10);
            printf("Contact No.");
            gotoxy(55,10);
            printf("Date");
            gotoxy(70,10);
            printf("Time");
            gotoxy(85,10);
            printf("Details\n");
			printf("=================================================================================================================");
			row=12;
            gotoxy(6,row);
            printf("%s", Name[0]);
            gotoxy(30,row);
            printf("%s", Contact_no[0]);
            gotoxy(55,row);
            printf("%s", Date[0]);
            gotoxy(70,row);
            printf("%s", Time[0]);
            gotoxy(85,row);
            printf("%s", Details[0]);
            printf("\n");
            break;
		}
    }
    if(strcmp(Name[0],name) != 0)
    {
        gotoxy(5,10);
		printf("Record not found!");
    }
	fclose(ek);

	G:
        printf("\n\n\t\t\tDo you want to view more[Y/N]??");
        scanf("%c", &ans);
        if (toupper(ans) == 'Y')
        {
            Search_appointment(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
        }
        else if(toupper(ans) == 'N')
        {
            printf("\n\t\t Thank you !");
            getch();
            Menu(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
        }
        else
        {
            printf("\n\tInvalid Input !\n");
            goto G;
        }
}
/* *************EDIT APPOINTMENT**************/
void Edit_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50])
{
    FILE *ek, *ft;
    int valid = 0;
    char ch;
    char name[20];

    system("cls");
  	Title();
    ft = fopen("temp.txt","w+");
    ek = fopen("Record.txt","r");
	if(ek == NULL)
	{
		printf("\n\t Cannot open file!! ");
		getch();
		Menu(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
	}
    printf("\n\n\t\t\t****** Edit Appointment ******\n");
	gotoxy(12,13);
	printf("Enter the Name: ");
	scanf("%s",name);
	fflush(stdin);
    gotoxy(12,15);
    if(ft == NULL)
    {
        printf("\n Cannot open file");
        getch();
        Menu(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
    }
    while(fscanf(ek,"%s %s %s %s %s\n", &Name[0], &Contact_no[0], &Date[0], &Time[0], &Details[0]) != EOF)
    {
        if(strcmp(Name[0], name) == 0)
        {
            valid = 1;
            gotoxy(25,17);
			printf("*** Existing Record ***");
			gotoxy(10,19);
			printf("%s %s %s %s %s\n", Name[0], Contact_no[0], Date[0], Time[0], Details[0]);
			gotoxy(12,22);
			printf("Enter New Name: ");
			scanf("%s", &Name[0]);
			gotoxy(12,24);
			printf("Enter New Contact No.: ");
			scanf("%s", &Contact_no[0]);
			gotoxy(12,26);
			printf("Enter New Date(xx/xx/xxxx): ");
			scanf("%s", &Date[0]);
			fflush(stdin);
			gotoxy(12,28);
			printf("Enter New Time in 24 Hour(xx:xx): ");
			scanf("%s", &Time[0]);
			gotoxy(12,30);
			printf("Enter New Details: ");
			scanf("%s", &Details[0]);
			printf("\nPress U charecter for the Updating operation : ");
            ch = getche();
			if(ch == 'u' || ch == 'U')
			{
                fprintf(ft, "%s %s %s %s %s\n", Name[0], Contact_no[0], Date[0], Time[0], Details[0]);
                printf("\n\n\t\t\tAppointment updated successfully !");
            }
        }
        else
        {
            fprintf(ft, "%s %s %s %s %s\n", Name[0], Contact_no[0], Date[0], Time[0], Details[0]);
        }
    }
    if(!valid)
    {
        printf("\n\t\tNO APPOINTMENT FOUND...");
    }
    fclose(ft);
	fclose(ek);
	remove("Record.txt");
   	rename("temp.txt", "Record.txt");
	getch();
	Menu(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
}
/* *************DELETE APPOINTMENT**************/
void Delete_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50])
{
	char name[20];
	int found = 0;
	system("cls");
	Title();
	FILE *ek, *ft;
	ft = fopen("temp.txt", "w+");
	ek = fopen("Record.txt", "r");
	printf("\n\n\t\t\t****** Delete Appointment ******\n");
	gotoxy(12,8);
	printf("\n Enter Name to delete: ");
	fflush(stdin);
	scanf("%s", name);

	while (fscanf(ek, "%s %s %s %s %s\n", Name[0], Contact_no[0], Date[0], Time[0], Details[0]) != EOF)
	{
		if (strcmp(Name, name)!=0)
		{
		    fprintf(ft, "%s %s %s %s %s\n", Name[0], Contact_no[0], Date[0], Time[0], Details[0]);
		}
		else
		{
			printf("%s %s %s %s %s\n", Name[0], Contact_no[0], Date[0], Time[0], Details[0]);
			found = 1;
		}
	}
	if(found == 0)
	{
		printf("\n\n\t\t\t Appointment not found....");
		getch();
		Menu(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("Record.txt");
		rename("temp.txt", "Record.txt");
		printf("\n\n\t\t\t Appointment deleted successfully !");
		getch();
		Menu(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
	}
}
/* *************PRINT APPOINTMENT**************/
void print_appointment(char* Name[][50], char* Contact_no[][50], int* day[0], int* month[0], int* year[0], int* hour[0], int* minute[0], char* Date[][50], char* Time[][50], char* Details[][50])
{
    system("cls");
    Title();
    printf("\n\n\t\t\t****** Print All Appointment ******\n");
    FILE *ek;
    FILE *output;
    ek = fopen("Record.txt", "r");
    output = fopen("Appointment.txt", "w");
    fprintf(output, "\n\n\t\t----------------------------------------------------------------------------------");
    fprintf(output, "\n\t\t\t\t        TSK APPOINMENT BOOKING SYSTEM         ");
    fprintf(output, "\n\t\t----------------------------------------------------------------------------------");
    fprintf(output, "\n\t\t\t\t             APPOINTMENT LIST\n");
    fprintf(output, "---------------------------------------------------------------------------------------------------------------------\n");
    fprintf(output, "\t\tNAME\t\t     CONTACT NO\t\t     DATE\t\t  TIME\t\t       DETAILS\n");
    fprintf(output, "---------------------------------------------------------------------------------------------------------------------\n");
    while(!feof(ek))
    {
        fscanf(ek, "%s %s %s %s %s\n", Name[0], Contact_no[0], Date[0], Time[0], Details[0]);
        fprintf(output, "\t\t\%-20s %-20s %-20s\t %-20s\t %-20s\n", Name[0], Contact_no[0], Date[0], Time[0], Details[0]);
    }
    fclose(output);
    fclose(ek);
    printf("\n\n\t\t\t... Appointment File printed >>>Filename: Appointment ...");
    getch();
    Menu(Name, Contact_no, day, month, year, hour, minute, Date, Time, Details);
}
