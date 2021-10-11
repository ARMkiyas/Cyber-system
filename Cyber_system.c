/*



*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define FileName "./user_data.dat"
typedef char string[255];

struct loginfo
{
	string user_name;
	string password;
	string name;
	string email;
	string phone;
	string address;
	string dob;
};

//default admin details

struct admin
{
	string user_name;
	string password;
} admin = {"Admin", "Pass"};

struct loginfo login;
void write_data_to_file(struct loginfo *temp);
void create_user();
void Admin();
int user_auth();
void error(char *message);
void load();
void welcome();
void swic();
void login_screen();
void exiting();
void auth();
void user();
void display_all_users();
void user_info();

int main()
{
	struct loginfo login;
	load();
	welcome();
	login_screen();

	return 0;
}

void gotoxy(int x, int y)
{

	COORD coord;

	coord.X = x;

	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void load()
{
	int r, c, q;
	gotoxy(40, 2);
	printf("LOADING CYBER SYSTEM...");
	gotoxy(40, 3);
	for (r = 1; r <= 20; r++)
	{
		for (q = 0; q <= 100000000; q++)
			;
		printf("%c", 177);
	}
	system("cls");
}

void welcome()
{
	gotoxy(40, 2);
	printf("******************************************");
	gotoxy(40, 3);
	printf("********  WELCOME TO CYBER SYSTEM ********");
	gotoxy(40, 4);
	printf("******************************************");
	gotoxy(45, 6);
	printf("Press Any Key To Continue.");
	getch();
	system("cls");
}

void login_screen()
{

	gotoxy(40, 2);
	printf("*******************************");
	gotoxy(40, 3);
	printf("********  Login SCREEN  ********");
	gotoxy(40, 4);
	printf("*******************************");
	gotoxy(43, 6);
	printf("Username : ");
	scanf("%s", &login.user_name);
	gotoxy(43, 8);
	fflush(stdin);
	printf("Password : ");
	char ch;
	int i = 0;
	while (ch != 13)
	{
		ch = getch();
		if (ch != 13 && ch != 8)
		{
			putch('*');
			login.password[i] = ch;
			i++;
		}
	}
	login.password[i + 1] = '\0';
	auth();
}

void auth()
{
	if (login.user_name == NULL || login.password == NULL)
	{
		error("Invalid User_name or Password");
	}
	else if (!strcmp(login.user_name, admin.user_name) && !strcmp(login.password, admin.password))
	{
		Admin();
	}
	else
	{
		user_auth();
	}

	error("Invalid User_name or Password");
}

int user_auth()
{

	FILE *f;

	struct loginfo temp;

	f = fopen(FileName, "rb");

	if (f == NULL)
	{
		error("User details not found");
	}

	while (1)
	{
		fread(&temp, sizeof(temp), 1, f);
		if (feof(f))
		{
			break;
		}
		else if (!strcmp(temp.user_name, login.user_name) && !strcmp(temp.password, login.password))
		{
			login = temp;
			user();
		}
	}

	fclose(f);

	return 0;
}

void Admin()
{
	system("cls");
	gotoxy(40, 3);
	printf("*******  Welcome to Admin Portal  *******");
	gotoxy(43, 5);
	printf("1 : Add a user details");
	gotoxy(43, 6);
	printf("2 : Display all users details");
	gotoxy(43, 7);
	printf("3 : back to login screen(logout)");
	gotoxy(43, 8);
	printf("4 : To Exit the PC");
	gotoxy(43, 10);
	printf("Enter the the no to choose:");
	char choics;
	fflush(stdin);
	choics = getch();
	system("cls");

	switch (choics)
	{
	case '1':
		create_user();
		break;

	case '2':
		display_all_users();
		break;
	case '3':
		login_screen();
		break;
	case '4':
		exiting();
		break;

	default:
		gotoxy(40, 4);
		printf("Invalid Option : Enter any key for option menu");
		getch();
		system("cls");

		break;
	}
}

void user()
{

	system("cls");
	string g = "farnas";
	system("cls");
	gotoxy(40, 2);
	printf("**********************************************************");
	gotoxy(40, 3);
	printf("********  WELCOME MR.%s to CYBER SYSTEM *********", login.name);
	gotoxy(40, 4);
	printf("**********************************************************");
	gotoxy(43, 6);
	printf("1 : Access you information");
	gotoxy(43, 7);
	printf("2 : back to login screen(logout)");
	gotoxy(43, 8);
	printf("3 : To Exit the PC");
	gotoxy(43, 10);
	printf("Enter the the no to choose:");
	char choics;
	fflush(stdin);
	choics = getch();
	system("cls");

	switch (choics)
	{
	case '1':
		user_info();
		break;

	case '2':
		login_screen();
		break;

	case '3':
		exiting();
		break;

	default:
		gotoxy(40, 4);
		printf("Invalid Option : Enter any key for option menu");
		getch();
		system("cls");

		break;
	}
}

void user_info()
{
	system("cls");
	gotoxy(10, 2);
	printf("-----------------------------------------------------------------------------------------------------");
	gotoxy(10, 3);
	printf("######################################## Your information ###########################################");
	gotoxy(10, 4);
	printf("-------------------------------------------------------------------------------------------------------");
	gotoxy(55, 6);
	printf("Name: %s", login.name);
	gotoxy(55, 7);
	printf("Email: %s", login.email);
	gotoxy(55, 8);
	printf("Phone No: %s", login.phone);
	gotoxy(55, 9);
	printf("Address: %s", login.address);
	gotoxy(55, 10);
	printf("Date of birth: %s", login.dob);
	gotoxy(55, 11);
	printf("Username: %s", login.user_name);
	gotoxy(55, 12);
	printf("Default password: %s", login.password);
	gotoxy(10, 14);
	printf("-------------------------------------------------------------------------------------------------------");
	gotoxy(15, 16);
	printf("Enter any key to go back:");
	fflush(stdin);
	getch();
	user();
}

void create_user()
{
	while (1)
	{
		system("cls");
		fflush(stdin);
		struct loginfo temp;
		gotoxy(40, 3);
		printf("************** USER ACCOUNT CREATION **************");
		gotoxy(42, 5);
		printf("Enter Name: ");
		scanf("%s", &temp.name);
		gotoxy(42, 6);
		printf("Enter user\'s E-mail: ");
		scanf("%s", &temp.email);
		gotoxy(42, 7);
		printf("Enter user's phone no: ");
		scanf("%s", &temp.phone);
		gotoxy(42, 8);
		printf("Enter user\'s Address: ");
		scanf("%s", &temp.address);
		gotoxy(42, 9);
		printf("Enter user\'s date of birth(YYYY/MM/DD): ");
		scanf("%s", &temp.dob);
		gotoxy(42, 10);
		printf("Create a username(note:Username must be unique): ");
		scanf("%s", &temp.user_name);
		gotoxy(42, 11);
		printf("Create a default password for user: ");
		scanf("%s", &temp.password);

		while (1)
		{
			int check = 0;
			FILE *f = fopen(FileName, "rb");
			if (!strcmp(temp.user_name, "Admin") || !strcmp(temp.user_name, "admin"))
			{
				goto enter_again;
			}
			if (f != NULL)
			{
				struct loginfo t;
				while (1)
				{
					fread(&t, sizeof(struct loginfo), 1, f);
					if (feof(f))
					{
						break;
					}
					else if (!strcmp(t.user_name, temp.user_name))
					{
					enter_again:
						check = 1;
						system("cls");
						gotoxy(35, 3);
						printf("************** USER ACCOUNT CREATION **************");
						gotoxy(36, 5);
						printf("your have entered username %s is already in use", temp.user_name);
						gotoxy(36, 7);
						printf("please enter a unique username:(note:Username must be unique): ");
						fflush(stdin);
						scanf("%s", &temp.user_name);
						break;
					}
				}
				fclose(f);
				if (check == 0)
					break;
			}
		}

		system("cls");
		gotoxy(40, 3);
		printf("************** Confirmation **************");
		gotoxy(44, 5);
		printf("Name: %s", temp.name);
		gotoxy(44, 6);
		printf("E-mail: %s", temp.email);
		gotoxy(44, 7);
		printf("Phone no: %s", temp.phone);
		gotoxy(44, 8);
		printf("Address: %s", temp.address);
		gotoxy(44, 9);
		printf("Date of birth: %s", temp.dob);
		gotoxy(44, 10);
		printf("Username: %s", temp.user_name);
		gotoxy(44, 11);
		printf("Default password: %s", temp.password);

		gotoxy(41, 13);
		printf("Is it you entered data correct, ");
		gotoxy(41, 14);
		printf("to prosssed(Y OR y),");
		gotoxy(41, 15);
		printf("to go back to main menu(N or n),");
		gotoxy(41, 16);
		printf("to try again enter any other key:");

		fflush(stdin);
		char a = getch();
		if (a == 89 || a == 121)
			write_data_to_file(&temp);
		else if (a == 78 || a == 110)
			Admin();
	}
}

void write_data_to_file(struct loginfo *temp)
{
	FILE *f = fopen(FileName, "ab");
	if (f == NULL)
	{
		error("OOps..!,There is something wrong with the file creation");
	}
	fwrite(temp, sizeof(struct loginfo), 1, f);
	fclose(f);
	system("cls");
	gotoxy(40, 3);
	printf("************** User Account Successfully Created **************");
	gotoxy(49, 5);
	printf("Do you want to create an other user account?");
	gotoxy(41, 6);
	printf("if yes enter Y or y OR, to go back to main menu enter any other key:");
	fflush(stdin);
	char a = getch();
	if (a == 89 || a == 121)
	{
		create_user();
	}
	Admin();
}

void display_all_users()
{
	system("cls");
	int pos_x = 10, pos_y = 4;
	gotoxy(0, 3);
	printf("********************************************All users information******************************************");
	FILE *f;
	struct loginfo temp;

	f = fopen("./user_data.dat", "rb");
	if (f == NULL)
	{
		gotoxy(pos_x, pos_y);
		printf("************** User date not exist **************");
		exit(1);
	}

	while (1)
	{
		int t_pos_y = pos_y;
		fread(&temp, sizeof(temp), 1, f);
		if (feof(f))
		{

			break;
		}
		gotoxy(pos_x, pos_y);
		printf("UserName:%s ", temp.user_name);
		t_pos_y = t_pos_y + 1;
		gotoxy(pos_x, t_pos_y);
		printf("Default password:%s ", temp.password);
		t_pos_y = t_pos_y + 1;
		gotoxy(pos_x, t_pos_y);
		printf("Name:%s ", temp.name);
		t_pos_y = t_pos_y + 1;
		gotoxy(pos_x, t_pos_y);
		printf("Email:%s ", temp.email);
		t_pos_y = t_pos_y + 1;
		gotoxy(pos_x, t_pos_y);
		printf("Phone:%s ", temp.phone);
		t_pos_y = t_pos_y + 1;
		gotoxy(pos_x, t_pos_y);
		printf("Address:%s", temp.address);
		t_pos_y = t_pos_y + 1;
		gotoxy(pos_x, t_pos_y);
		printf("Date of birth:%s", temp.dob);
		t_pos_y = t_pos_y + 1;
		gotoxy(pos_x, t_pos_y);
		pos_x = pos_x + 35;

		if (pos_x == 115)
		{
			pos_x = 10;
			pos_y = pos_y + 9;
		}
	}
	fclose(f);
	pos_x = 10;
	pos_y = pos_y + 8;
	gotoxy(0, pos_y);
	printf("***********************************************************************************************************");
	pos_y = pos_y + 1;
	gotoxy(pos_x, pos_y);
	printf("Back to main menu enter enter key:");
	fflush(stdin);
	getch();
	Admin();
}

void error(char *message)
{
	system("setterm -bold on");
	system("color 4");
	system("cls");
	gotoxy(40, 6);
	printf("############## %s ##############", message);
	gotoxy(45, 8);
	printf("Press any key to try again or to exit enter Y or y");
	fflush(stdin);
	char i;
	i = getch();
	system("color 7");
	system("cls");
	system("setterm -bold off");
	if (i == 89 || i == 121)
	{
		exit(1);
	}
	login_screen();
}

void exiting()
{
	int r, q;
	gotoxy(42, 8);
	printf("EXITING CYBER SYSTEM...");
	gotoxy(42, 9);
	for (r = 1; r <= 20; r++)
	{
		for (q = 0; q <= 100000000; q++)
			;
		printf("*");
	}
	system("cls");
	exit(1);
}