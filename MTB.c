#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
char name[100], name1[100], year[100], time[100];
int cost, cost1, num;
void login();
void insert_details();
void viewAll();
void find();
void book_ticket();
void old_record();
int removes();
int main()
{
	int a;
	system("cls");
	while (1)
	{
		printf("\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\n\n");
		printf("\t\t\t\t\tMOVIE TICKET BOOKING ");
		printf("\n");
		printf("\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\n\n\t\t\tEnter (1) To Insert Movie (Admin only)");
		printf("\n\t\t\tEnter (2) To View All Movie");
		printf("\n\t\t\tEnter (3) To Find Movie ");
		printf("\n\t\t\tEnter (4) To Book Tickets");
		printf("\n\t\t\tEnter (5) To View All Transactions");
		printf("\n\t\t\tEnter (6) To Remove movie (Admin only)");
		printf("\n\t\t\tEnter (0) To Exit ");
		printf("\n\n\t\t\tEnter Your Choice ::");
		scanf("%d", &a);
		system("cls");
		switch (a)
		{
		case 1:
			insert_details();
			break;
		case 2:
			viewAll();
			break;
		case 3:
			find();
			break;
		case 4:
			book_ticket();
			break;
		case 5:
			old_record();
			break;
		case 6:
			removes();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Wrong choice !");
			break;
		}
	}
	return 0;
}
void login()
{
	char uname[50], u[] = "user", pword[50], p[] = "pass";
	printf("\n\t\t++++++++++++++++++++++++++++++  LOGIN FIRST  ++++++++++++++++++++++++++++++  ");
log:
	printf(" \n\n                  ENTER USERNAME:-");
	fflush(stdin);
	scanf("%s", &uname);
	printf(" \n\n                  ENTER PASSWORD:-");
	fflush(stdin);
	scanf("%s", &pword);
	if (strcmp(uname, u) == 0 && strcmp(pword, p) == 0)
	{
		printf("\n\n\n\t\t\tLOGIN IS SUCCESSFUL !!!!");
		printf("\n\n\n\t\t\t\tPress any key to continue...\n");
		getch();
		system("cls");
	}
	else
	{
		system("cls");
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		printf("\n        WRONG !! PASSWORD OR USERNAME !!");
		goto log;
	}
}
void insert_details()
{
	login();
	FILE *p;
	printf("Enter movie code :- ");
	scanf("%d", &num);
	printf("Enter  name :- ");
	fflush(stdin);
	scanf("%s", &name);
	printf("Enter Release year:- ");
	fflush(stdin);
	scanf("%s", &year);
	printf("Enter Ticket Price:- ");
	scanf("%d", &cost);
	printf("Enter timing :- ");
	fflush(stdin);
	scanf("%s", &time);
	system("cls");
	p = fopen("movie.txt", "a");
	if (p == NULL)
	{
		printf("not Found");
	}
	else
	{
		fprintf(p, "%d %s %s %d %s\n", num, name, year, cost, time);
		printf("Recorded Successfully");
	}
	printf("\n");
	fclose(p);
}
void viewAll()
{
	char ch;
	FILE *p;
	p = fopen("movie.txt", "r");
	if (p == NULL)
	{
		printf("not found !");
	}
	else
	{
		system("cls");
		printf("\t\t\tno.	\tMovie\t\tYear\tPrice\tTiming\n");
		while (fscanf(p, "%d %s %s %d %s", &num, &name, &year, &cost, &time) != EOF)
		{
			printf("\t\t\t%d	 %15s\t%s\t%5d  	%7s\n", num, name, year, cost, time);
		}
		printf("\n");
	}
	fclose(p);
}
void find()
{
	FILE *p;
	int bm;
	printf("Enter movie no. :");
	scanf("%d", &bm);
	p = fopen("movie.txt", "r");
	if (p == NULL)
	{
		printf("not found !");
	}
	else
	{
		while (fscanf(p, "%d %s %s %d %s", &num, &name, &year, &cost, &time) != EOF)
		{
			if (bm == num)
			{
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%d", num);
				printf("\n\t\tMovie Name ::%s", name);
				printf("\n\t\tReleased Year ::%s", year);
				printf("\n\t\tPrice of Ticket ::%d", cost);
				printf("\n\t\tTiming :: %s", time);
				strcpy(name1, name);
				cost1 = cost;
			}
		}
	}
	fclose(p);
}
void book_ticket()
{
	FILE *p;
	FILE *ufp;
	long long int mobile;
	int total_seat, total_amount;
	char n[20];
	int movie_code;
	// viewAll();
	char ch;
	p = fopen("movie.txt", "r");
	if (p == NULL)
	{
		printf("not found !");
	}
	else
	{
		system("cls");
		printf("\t\t\tno.	\tMovie\t\tYear\tPrice\tTiming\n");
		while (fscanf(p, "%d %s %s %d %s", &num, &name, &year, &cost, &time) != EOF)
		{
			printf("\t\t\t%d	 %15s\t%s\t%5d  	%7s\n", num, name, year, cost, time);
		}
		printf("\n");
	}
	fclose(p);
	int bm;
	printf("Enter movie no. :");
	scanf("%d", &bm);
	p = fopen("movie.txt", "r");
	if (p == NULL)
	{
		printf("not found !");
	}
	else
	{
		while (fscanf(p, "%d %s %s %d %s", &num, &name, &year, &cost, &time) != EOF)
		{
			if (bm == num)
			{
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%d", num);
				printf("\n\t\tMovie Name ::%s", name);
				printf("\n\t\tReleased Year ::%s", year);
				printf("\n\t\tPrice of Ticket ::%d", cost);
				printf("\n\t\tTiming :: %s", time);
				strcpy(name1, name);
				cost1 = cost;
			}
		}
		//	find();
		printf("\n* Fill Deatails  *");
		printf("\n your name :");
		fflush(stdin);
		scanf("%s", &n);
		printf("\n mobile number :");
		scanf("%lld", &mobile);
		printf("\n Total number of tickets :");
		scanf("%d", &total_seat);
		total_amount = cost1 * total_seat;
		system("cls");
		printf("\t-----------------THEATER BOOKING TICKET----------------\n");
		printf("\t============================================================\n");
		printf("\t Booking ID : %d \t\t\tShow Name : %s \n", name1, name1);
		printf("\t Customer  : %s\n", n);
		printf("\t Mobile no.: %lld\n", mobile);
		printf("\t\t                                          Date      : 14-04-2022\n");
		printf("\t                                              Show Time     : %s\n", time);
		printf("\t                                              Total seat    : %d\n", total_seat);
		printf("\t                                              Cost per seat : %d\n", cost1);
		printf("\t                                              Total price . : %d\n", total_amount);
		printf("\t                                              Payment mode  : Cash\n\n");
		ufp = fopen("oldtransection.txt", "a");
		if (ufp == NULL)
		{
			printf("not Found");
		}
		else
		{
			fprintf(ufp, "%s %lld %d %d %s %d \n", n, mobile, total_seat, total_amount, name1, cost1);
			printf("\n Record insert Sucessfull to the old record file");
			printf("\n");
		}
		fclose(ufp);
		fclose(p);
	}
}
void old_record()
{
	long long int mobile;
	int total_seat, total_amount;
	char n[20];
	int movie_code;
	FILE *ufp;
	ufp = fopen("oldTransection.txt", "r");
	if (ufp == NULL)
	{
		printf("file does not found !");
	}
	else
	{
		system("cls");
		printf("\t\tName\tmobile.no seats\ttotal amount\tmovie\t\t\tcost per seat\n");
		while (fscanf(ufp, "%s %lld %d %d %s %d \n", &n, &mobile, &total_seat, &total_amount, &name1, &cost1) != EOF)
		{
			printf("%20s %11lld %5d %10d \t%20s %10d \n", n, mobile, total_seat, total_amount, name1, cost1);
		}
	}
	fclose(ufp);
}
int removes()
{
	login();
	FILE *p, *t;
	int bm;
	printf("Enter movie code :");
	scanf("%d", &bm);
	p = fopen("movie.txt", "r");
	t = fopen("temp.txt", "a");
	if (p == NULL)
	{
		printf("not found !");
	}
	else
	{
		while (fscanf(p, "%d %s %s %d %s", &num, &name, &year, &cost, &time) != EOF)
		{
			if (bm == num)
			{
				printf("Removed");
			}
			else
			{
				fprintf(t, "%d %s %s %d %s\n", num, name, year, cost, time);
			}
		}
	}
	fclose(p);
	fclose(t);
	removes("movie.txt");
	rename("temp.txt", "movie.txt");
}