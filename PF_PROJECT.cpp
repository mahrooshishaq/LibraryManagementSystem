#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<dirent.h>
#include<stdafx.h>
#include<conio.h>
#include<time.h>
#include<cstring>
#include<iomanip>
using namespace std;

int a = 0, v = 0; // file number in BOOKS
//int v = 0; 
int j = 0; //lending waly struct ka counter
int index = 0; //SEARCHING BYNAME OR ISBN INDEX MAIN VALUE RETURN HOTI
int l_index = 0;
int temp_no = 0; //tempstruct ka index no;
int dell = 0;
//string returning_d;
int da, mo, ye;
int fine;
int yes, bro, check = 0;
string retu;
struct Books
{
	string book_name, author, publish_date, quantity, ISBN;
};
struct Lending
{
	string issued_book, issuing_date, return_date, borrower, fine;
};
struct Temp
{
	string book_ka_naam, uska_author, publishing_date, quant, isbn;
};
struct Del {

	string issued_b, issuing_d, return_d, jisne_li, Fine;
};
struct FINE
{
	int fine;
};
Books books[1000];
Lending lent[1000];
Temp tempBooks[1000];
Del del[1000];
FINE totalfine[10];

#define LEFT 97
#define RIGHT 100
using namespace std;
void gotoxy(int x, int y) {

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void graphics() {
	system("cls");
	system("Color 0B");

	gotoxy(25, 0);	cout << "                  V______________V      " << endl;
	Sleep(40);
	gotoxy(25, 2);	cout << "                V  88888     888      888    8     8   V     " << endl;
	Sleep(40);
	gotoxy(25, 3);	cout << "               V   8    8  8     8  8     8  8   8      V    " << endl;
	Sleep(40);
	gotoxy(25, 4);	cout << "              V    88888   8     8  8     8  888         V   " << endl;
	Sleep(40);
	gotoxy(25, 5);	cout << "             V     8    8  8     8  8     8  8   8        V  " << endl;
	Sleep(40);
	gotoxy(25, 6);	cout << "            V      88888     888      888    8     8       V " << endl;
	Sleep(40);
	gotoxy(25, 7);	cout << "           ||________________||" << endl;
	Sleep(40);
	gotoxy(25, 8);	cout << "           ||----------------------------------------------||" << endl;
	Sleep(40);
	gotoxy(25, 9);	cout << "           ||                                              ||" << endl;
	Sleep(40);
	gotoxy(25, 10);	cout << "           ||                                              ||" << endl;
	Sleep(40);
	gotoxy(25, 11);	cout << "           ||                                              ||" << endl;
	Sleep(40);
	gotoxy(25, 12);	cout << "           ||                 WELCOME to                   ||" << endl;
	Sleep(40);
	gotoxy(25, 13);	cout << "           ||             IMLiM   KUTAB   KHANA            ||" << endl;
	Sleep(40);
	gotoxy(25, 14);	cout << "           ||                                              ||" << endl;
	Sleep(40);
	gotoxy(25, 15);	cout << "           ||                  1:LOG-IN                    ||" << endl;
	Sleep(40);
	gotoxy(25, 16);	cout << "           ||                  2:REGISTRATION              ||" << endl;
	Sleep(40);
	gotoxy(25, 17);	cout << "           ||                                              ||" << endl;
	Sleep(40);
	gotoxy(25, 18);	cout << "           ||                                              ||" << endl;
	Sleep(40);
	gotoxy(25, 19);	cout << "           ||                                              ||" << endl;
	Sleep(40);
	gotoxy(25, 20);	cout << "           ||                                              ||" << endl;
	Sleep(40);
	gotoxy(25, 21);	cout << "           __________________" << endl;
	Sleep(40);
	gotoxy(25, 22);	cout << "           --------------------------------------------------" << endl;
	Sleep(40);


}
void GRAPHICS() {
	system("cls");
	system("Color 0B");

	gotoxy(10, 10);		cout << "                       " << endl;
	gotoxy(10, 11);    	cout << " ||                  ||" << endl;
	gotoxy(10, 12);	    cout << " ||                  ||" << endl;
	gotoxy(10, 13);	    cout << " ||                  ||" << endl;
	gotoxy(10, 14);	    cout << " ||      ___     ||" << endl;
	gotoxy(10, 15);	    cout << " ||     ||     ||    ||" << endl;
	gotoxy(10, 16);	    cout << " ||     ||     ||    ||" << endl;
	gotoxy(10, 17);	    cout << " ||     ||     ||    ||" << endl;
	gotoxy(10, 18);	    cout << " ||__||     ||_||" << endl;
	Sleep(300);

	cout << endl;
	gotoxy(40, 10);	cout << " ___ " << endl;
	gotoxy(40, 11);	cout << " ||        " << endl;
	gotoxy(40, 12); cout << " ||        " << endl;
	gotoxy(40, 13); cout << " ||        " << endl;
	gotoxy(40, 14); cout << " ||____" << endl;
	gotoxy(40, 15); cout << " ||        " << endl;
	gotoxy(40, 16); cout << " ||        " << endl;
	gotoxy(40, 17); cout << " ||        " << endl;
	gotoxy(40, 18); cout << " ||        " << endl;
	gotoxy(40, 18); cout << " ----------" << endl;

	Sleep(300);
	cout << endl;
	gotoxy(50, 10);	cout << " ||         " << endl;
	gotoxy(50, 11);	cout << " ||         " << endl;
	gotoxy(50, 12); cout << " ||         " << endl;
	gotoxy(50, 13); cout << " ||         " << endl;
	gotoxy(50, 14); cout << " ||         " << endl;
	gotoxy(50, 15); cout << " ||         " << endl;
	gotoxy(50, 16); cout << " ||         " << endl;
	gotoxy(50, 17); cout << " ||         " << endl;
	gotoxy(50, 18); cout << " ||___" << endl;
	Sleep(300);
	cout << endl;

	cout << endl;
	gotoxy(60, 10); cout << " ----------------   " << endl;
	gotoxy(60, 11);	cout << "  ||              " << endl;
	gotoxy(60, 12); cout << "  ||              " << endl;
	gotoxy(60, 13); cout << "  ||              " << endl;
	gotoxy(60, 14); cout << "  ||              " << endl;
	gotoxy(60, 15); cout << "  ||              " << endl;
	gotoxy(60, 16); cout << "  ||              " << endl;
	gotoxy(60, 17); cout << "  ||              " << endl;
	gotoxy(60, 18); cout << "  ||              " << endl;
	gotoxy(60, 18); cout << "  --------------- " << endl;

	Sleep(300);

	gotoxy(70, 10);	  cout << " ||---------||" << endl;
	gotoxy(70, 11);	  cout << " ||         ||" << endl;
	gotoxy(70, 12);   cout << " ||         ||" << endl;
	gotoxy(70, 13);   cout << " ||         ||" << endl;
	gotoxy(70, 14);   cout << " ||         ||" << endl;
	gotoxy(70, 15);   cout << " ||         ||" << endl;
	gotoxy(70, 16);   cout << " ||         ||" << endl;
	gotoxy(70, 17);   cout << " ||         ||" << endl;
	gotoxy(70, 18);   cout << " ||---------||" << endl;

	Sleep(300);
	cout << endl;

	gotoxy(85, 11);	   cout << "||------       --------" << endl;
	gotoxy(85, 12);    cout << "||      ||     ||    ||" << endl;
	gotoxy(85, 13);    cout << "||      ||     ||    ||" << endl;
	gotoxy(85, 14);    cout << "||      ||     ||    ||" << endl;
	gotoxy(85, 15);    cout << "||       -------     ||" << endl;
	gotoxy(85, 16);    cout << "||                   ||" << endl;
	gotoxy(85, 17);    cout << "||                   ||" << endl;
	gotoxy(85, 18);    cout << "||                   ||" << endl;
	Sleep(300);
	cout << endl;

	cout << endl;
	gotoxy(105, 10); cout << " ___ " << endl;
	gotoxy(105, 11); cout << " ||        " << endl;
	gotoxy(105, 12); cout << " ||        " << endl;
	gotoxy(105, 13); cout << " ||        " << endl;
	gotoxy(105, 14); cout << " ||____" << endl;
	gotoxy(105, 15); cout << " ||        " << endl;
	gotoxy(105, 16); cout << " ||        " << endl;
	gotoxy(105, 17); cout << " ||        " << endl;
	gotoxy(105, 18); cout << " ||        " << endl;
	gotoxy(105, 18); cout << " ----------" << endl;

	Sleep(300);
	cout << endl;

	gotoxy(10, 10);		cout << "                  " << endl;
	gotoxy(10, 11);    	cout << "                  " << endl;
	gotoxy(10, 12);	    cout << "                  " << endl;
	gotoxy(10, 13);	    cout << "                  " << endl;
	gotoxy(10, 14);	    cout << "                  " << endl;
	gotoxy(10, 15);	    cout << "                  " << endl;
	gotoxy(10, 16);	    cout << "                  " << endl;
	gotoxy(10, 17);	    cout << "                  " << endl;
	gotoxy(10, 18);	    cout << "                  " << endl;
	Sleep(300);
	cout << endl;
	gotoxy(30, 10);		cout << "                   " << endl;
	gotoxy(30, 11);    	cout << "                   " << endl;
	gotoxy(30, 12);	    cout << "                   " << endl;
	gotoxy(30, 13);	    cout << "                   " << endl;
	gotoxy(30, 14);	    cout << "                   " << endl;
	gotoxy(30, 15);	    cout << "                   " << endl;
	gotoxy(30, 16);	    cout << "                   " << endl;
	gotoxy(30, 17);	    cout << "                   " << endl;
	gotoxy(30, 18);	    cout << "                   " << endl;
	Sleep(300);
	gotoxy(32, 10);		cout << "                   " << endl;
	gotoxy(32, 11);    	cout << "                   " << endl;
	gotoxy(32, 12);	    cout << "                   " << endl;
	gotoxy(32, 13);	    cout << "                   " << endl;
	gotoxy(32, 14);	    cout << "                   " << endl;
	gotoxy(32, 15);	    cout << "                   " << endl;
	gotoxy(32, 16);	    cout << "                   " << endl;
	gotoxy(32, 17);	    cout << "                   " << endl;
	gotoxy(32, 18);	    cout << "                   " << endl;
	Sleep(300);
	cout << endl;
	gotoxy(50, 10);		cout << "-------------     " << endl;
	gotoxy(50, 11);    	cout << "-----------       " << endl;
	gotoxy(50, 12);	    cout << "    ||            " << endl;
	gotoxy(50, 13);	    cout << "    ||            " << endl;
	gotoxy(50, 14);	    cout << "    ||            " << endl;
	gotoxy(50, 15);	    cout << "    ||            " << endl;
	gotoxy(50, 16);	    cout << "    ||            " << endl;
	gotoxy(50, 17);	    cout << "    ||            " << endl;
	gotoxy(50, 18);	    cout << "    ||            " << endl;
	Sleep(300);

	gotoxy(65, 10);	  cout << " ||---------||   " << endl;
	gotoxy(65, 11);	  cout << " ||         ||   " << endl;
	gotoxy(65, 12);   cout << " ||         ||   " << endl;
	gotoxy(65, 13);   cout << " ||         ||   " << endl;
	gotoxy(65, 14);   cout << " ||         ||   " << endl;
	gotoxy(65, 15);   cout << " ||         ||   " << endl;
	gotoxy(65, 16);   cout << " ||         ||   " << endl;
	gotoxy(65, 17);   cout << " ||         ||   " << endl;
	gotoxy(65, 18);   cout << " ||---------||   " << endl;

	Sleep(300);
	cout << endl;
	gotoxy(80, 10);		cout << "                  " << endl;
	gotoxy(80, 11);    	cout << "                  " << endl;
	gotoxy(80, 12);	    cout << "                  " << endl;
	gotoxy(80, 13);	    cout << "                  " << endl;
	gotoxy(80, 14);	    cout << "                  " << endl;
	gotoxy(80, 15);	    cout << "                  " << endl;
	gotoxy(80, 16);	    cout << "                  " << endl;
	gotoxy(80, 17);	    cout << "                  " << endl;
	gotoxy(80, 18);	    cout << "                  " << endl;
	Sleep(300);
	cout << endl;
	gotoxy(80, 10);		cout << "                  " << endl;
	gotoxy(80, 11);    	cout << "                  " << endl;
	gotoxy(80, 12);	    cout << "                  " << endl;
	gotoxy(80, 13);	    cout << "                  " << endl;
	gotoxy(80, 14);	    cout << "                  " << endl;
	gotoxy(80, 15);	    cout << "                  " << endl;
	gotoxy(80, 16);	    cout << "                  " << endl;
	gotoxy(80, 17);	    cout << "                  " << endl;
	gotoxy(80, 18);	    cout << "                  " << endl;
	Sleep(300);
	cout << endl;
	gotoxy(90, 10);		cout << "                  " << endl;
	gotoxy(90, 11);    	cout << "                  " << endl;
	gotoxy(90, 12);	    cout << "                  " << endl;
	gotoxy(90, 13);	    cout << "                  " << endl;
	gotoxy(90, 14);	    cout << "                  " << endl;
	gotoxy(90, 15);	    cout << "                  " << endl;
	gotoxy(90, 16);	    cout << "                  " << endl;
	gotoxy(90, 17);	    cout << "                  " << endl;
	gotoxy(90, 18);	    cout << "                  " << endl;
	Sleep(300);
	cout << endl;
	gotoxy(100, 10);   cout << "                  " << endl;
	gotoxy(100, 11);   cout << "                  " << endl;
	gotoxy(100, 12);   cout << "                  " << endl;
	gotoxy(100, 13);   cout << "                  " << endl;
	gotoxy(100, 14);   cout << "                  " << endl;
	gotoxy(100, 15);   cout << "                  " << endl;
	gotoxy(100, 16);   cout << "                  " << endl;
	gotoxy(100, 17);   cout << "                  " << endl;
	gotoxy(100, 18);   cout << "                  " << endl;
	Sleep(300);
	cout << endl;
	gotoxy(10, 10);	  cout << "---------      " << endl;
	gotoxy(10, 11);	  cout << "  ----         " << endl;
	gotoxy(10, 12);   cout << "   ||          " << endl;
	gotoxy(10, 13);   cout << "   ||          " << endl;
	gotoxy(10, 14);   cout << "   ||          " << endl;
	gotoxy(10, 15);   cout << "   ||          " << endl;
	gotoxy(10, 16);   cout << "   ||          " << endl;
	gotoxy(10, 17);   cout << "  ----         " << endl;
	gotoxy(10, 18);   cout << "---------      " << endl;

	Sleep(300);
	cout << endl;
	gotoxy(20, 10);	   cout << "||------       --------" << endl;
	gotoxy(20, 11);	   cout << "||------       --------" << endl;
	gotoxy(20, 12);    cout << "||      ||     ||    ||" << endl;
	gotoxy(20, 13);    cout << "||      ||     ||    ||" << endl;
	gotoxy(20, 14);    cout << "||      ||     ||    ||" << endl;
	gotoxy(20, 15);    cout << "||       -------     ||" << endl;
	gotoxy(20, 16);    cout << "||                   ||" << endl;
	gotoxy(20, 17);    cout << "||                   ||" << endl;
	gotoxy(20, 18);    cout << "||                   ||" << endl;
	Sleep(300);
	cout << endl;
	gotoxy(45, 10);	cout << " ||         " << endl;
	gotoxy(45, 11);	cout << " ||         " << endl;
	gotoxy(45, 12); cout << " ||         " << endl;
	gotoxy(45, 13); cout << " ||         " << endl;
	gotoxy(45, 14); cout << " ||         " << endl;
	gotoxy(45, 15); cout << " ||         " << endl;
	gotoxy(45, 16); cout << " ||         " << endl;
	gotoxy(45, 17); cout << " ||         " << endl;
	gotoxy(45, 18); cout << " ||___" << endl;
	gotoxy(45, 19); cout << " _____" << endl;
	Sleep(300);
	cout << endl;
	gotoxy(60, 10);   cout << "---------      " << endl;
	gotoxy(60, 11);   cout << "  ----         " << endl;
	gotoxy(60, 12);   cout << "   ||          " << endl;
	gotoxy(60, 13);   cout << "   ||          " << endl;
	gotoxy(60, 14);   cout << "   ||          " << endl;
	gotoxy(60, 15);   cout << "   ||          " << endl;
	gotoxy(60, 16);   cout << "   ||          " << endl;
	gotoxy(60, 17);   cout << "  ----         " << endl;
	gotoxy(60, 18);   cout << "---------      " << endl;

	Sleep(300);
	cout << endl;
	gotoxy(70, 10);	   cout << "||------       --------" << endl;
	gotoxy(70, 11);	   cout << "||------       --------" << endl;
	gotoxy(70, 12);    cout << "||      ||     ||    ||" << endl;
	gotoxy(70, 13);    cout << "||      ||     ||    ||" << endl;
	gotoxy(70, 14);    cout << "||      ||     ||    ||" << endl;
	gotoxy(70, 15);    cout << "||       -------     ||" << endl;
	gotoxy(70, 16);    cout << "||                   ||" << endl;
	gotoxy(70, 17);    cout << "||                   ||" << endl;
	gotoxy(70, 18);    cout << "||                   ||" << endl;
	Sleep(300);
	cout << endl;

}
void load() {
	system("Color 0E");
	char a = 219; // ascii code for block is 219
	gotoxy(50, 20);
	cout << "LOADING..." << endl;
	gotoxy(50, 21);
	for (int i = 0; i < 20; i++) {
		cout << a;
		Sleep(40);
	}
}
bool Register(void)
{
	string username, password;
	char read[30];
	int d = 1;
	do
	{
		switch (d)
		{
		case 1:
		{

			fstream file1;
			file1.open("REGISTER.txt ", ios::in);
			cout << "ENTER YOUR USERNAME.\n";
			cin >> username;
			cout << "ENTER YOUR PASSWORD\n";
			cin >> password;
			if (file1.is_open())
			{
				while (!file1.eof())
				{
					file1 >> read;
					if (read == username || read == password)
					{
						cout << "THIS USER ALREADY EXISTS. PLEASE ENTER A NEW USERNAME AND PASSWORD\n";
						d = 1;
						break;
					}
					else
					{
						d = 2;
					}
				}
				file1.close();
			}
			break;
		}
		case 2:
		{
			fstream file;
			file.open("REGISTER.txt", ios::app);
			if (file.is_open())
			{
				file << username;
				file << endl;
				file << password;
				file << endl;
				file.close();
				return 1;
			}
			d = 3;
			break;
		}
		}
	} while (d == 1 || d == 2);
}
void searchbyname(Books books[], int size, int& index, string ii)
{
	for (int i = 0; i < size; i++)
	{
		if (books[i].book_name == ii)
		{

			index = i;
			yes = i;
			break;
		}
		else
		{
			yes = 2000;
		}
	}
}
void name_search_lending(Lending lent[], int size, int& l_index, string ii)
{
	for (int i = 0; i < size; i++)
	{

		if (books[i].book_name == ii)
		{

			l_index = i;
			bro = i;
			break;
		}
		else
		{

			bro = 2000;
		}
	}
}
void searchbyisbn(Books books[], int size, int& index, int ISBN)
{

	int s = 0, e = size - 1, mid, c = 0;
	while (s <= e)
	{
		mid = (s + e) / 2;
		if (stol(books[mid].ISBN) == ISBN)
		{
			index = mid;
			yes = mid;
			check = 1;
			break;
		}
		else if (stol(books[mid].ISBN) >= ISBN)
		{
			e = mid - 1;
			c++;
		}
		else
		{
			s = mid + 1;
			c++;
		}
	}
}
void storage(Books books[1000])
{
	string filename;
	ofstream file;


	for (int i = 0, j = 1; i < 3 && j <= 3; i++, j++)
	{


		cout << "BOOK" << j << endl;
		cout << "---------------------------" << endl;
		cout << "ENTER THE BOOK SR.NO (EG. 1 AS 01): " << endl;
		cin >> filename;
		file.open("BOOKS\\" + filename + ".txt");
		if (file.is_open())
		{


			cout << "Enter the name of the book: " << endl;
			cin.ignore();
			getline(cin, books[i].book_name);
			file << books[i].book_name << ",";



			cout << "Enter the author's name: " << endl;

			getline(cin, books[i].author);
			file << books[i].author << ",";


			cout << "Enter The Book's ISBN No:" << endl;
			cin >> books[i].ISBN;
			file << books[i].ISBN << ",";


			cout << "Enter The Year It Was Published in:" << endl;
			cin >> books[i].publish_date;
			file << books[i].publish_date << ",";

			cout << "The quantity:" << endl;
			cin >> books[i].quantity;
			file << books[i].quantity;


			file.close();
			system("CLS");
		}
	}


}
void read_database()
{
	int pop = 0;
	{
		DIR* directory;
		struct dirent* xyz;
		directory = opendir("BOOKS");
		string fname;


		if (directory) {
			while ((xyz = readdir(directory)) != NULL)
			{
				fname = "BOOKS\\";
				if (!strcmp(xyz->d_name, ".") || !strcmp(xyz->d_name, "..")) {
					continue;
				}
				else
				{
					fname = fname + xyz->d_name;

					ifstream file;
					string abc;
					file.open(fname);
					int temp1 = 0;
					while (getline(file, abc)) {

						temp1++;
					}
					file.close();
					ifstream file2;
					file2.open(fname);
					for (int u = 0; u < temp1; u++)
					{
						getline(file2, books[pop].book_name, ',');
						getline(file2, books[pop].author, ',');
						getline(file2, books[pop].ISBN, ',');
						getline(file2, books[pop].publish_date, ',');
						getline(file2, books[pop].quantity, '\n');
						pop++;
					}

					file2.close();
				}
			}
		}
		closedir(directory);
	}
	a = pop;
}
void read_lending()
{
	{
		DIR* directory;
		struct dirent* xyz;
		directory = opendir("LENDING");
		string fname;


		if (directory) {
			while ((xyz = readdir(directory)) != NULL)
			{
				fname = "LENDING\\";
				if (!strcmp(xyz->d_name, ".") || !strcmp(xyz->d_name, "..")) {
					continue;
				}
				else
				{
					fname = fname + xyz->d_name;

					ifstream file;
					string abc;
					file.open(fname);
					int temp1 = 0;
					while (getline(file, abc)) {

						temp1++;
					}
					file.close();
					ifstream file2;
					file2.open(fname);
					for (int v = 0; v < temp1; v++)
					{
						getline(file2, lent[j].issued_book, ',');
						getline(file2, lent[j].issuing_date, ',');
						getline(file2, lent[j].return_date, ',');
						getline(file2, lent[j].borrower, ',');
						getline(file2, lent[j].fine, '\n');
						j++;
					}

					file2.close();
				}
			}
		}
		closedir(directory);
	}
}
void sorting(Books books[1000])
{
	int i, j;
	string temp_nm, temp_au, temp_pub, temp_q, temp_isbn;
	for (i = 1; i < a; i++)
	{
		temp_nm = books[i].book_name;
		temp_au = books[i].author;
		temp_isbn = books[i].ISBN;
		temp_pub = books[i].publish_date;
		temp_q = books[i].quantity;

		j = i - 1;
		while (j >= 0 && stol(books[j].ISBN) > stol(temp_isbn))
		{
			books[j + 1].book_name = books[j].book_name;
			books[j + 1].author = books[j].author;
			books[j + 1].ISBN = books[j].ISBN;
			books[j + 1].publish_date = books[j].publish_date;
			books[j + 1].quantity = books[j].quantity;
			j--;

		}
		books[j + 1].book_name = temp_nm;
		books[j + 1].author = temp_au;
		books[j + 1].ISBN = temp_isbn;
		books[j + 1].publish_date = temp_pub;
		books[j + 1].quantity = temp_q;

	}

}
void issue_book()
{
	int search_option, i = 0, po = 0;
DUBARA_SEARCH:
	cout << "ENTER 1 TO SEARCH THE BOOK BY ITS NAME." << '\t';
	cout << "ENTER 2 TO SEARCH THE BOOK BY ISBN.NO." << endl;
	cin >> search_option;
	if (search_option == 1)
	{
		string ii;
		cout << "Enter THE NAME OF BOOK YOU ARE SEARCHING FOR : " << endl;
		cin.ignore();
		getline(cin, ii);
		searchbyname(books, a, index, ii);
		i = yes;
	}
	else if (search_option == 2)
	{
		string ii;
		cout << "Enter THE ISBN OF BOOK YOU ARE SEARCHING FOR : " << endl;
		cin >> ii;
		searchbyisbn(books, a, index, stoi(ii));
		i = yes;
	}
	if (i == 2000)
	{
		system("CLS");
		cout << "THE BOOK WAS NOT FOUND. SEARCH ANOTHER BOOK." << endl;
		goto DUBARA_SEARCH;
	}
	else
	{
		DIR* directoryy;
		struct dirent* xyz;
		directoryy = opendir("BOOKS");
		string fName;

		if (directoryy) {
			while ((xyz = readdir(directoryy)) != NULL)
			{
				fName = "BOOKS\\";
				if (!strcmp(xyz->d_name, ".") || !strcmp(xyz->d_name, "..")) {
					continue;
				}
				else
				{
					fName = fName + xyz->d_name;

					ifstream file1;
					string abc;
					file1.open(fName);
					int temp1 = 0;
					while (getline(file1, abc)) {

						temp1++;
					}
					file1.close();
					fstream file3;
					file3.open(fName);

					for (int j = 0; j < temp1; j++)
					{
						getline(file3, tempBooks[temp_no].book_ka_naam, ',');
						getline(file3, tempBooks[temp_no].uska_author, ',');
						getline(file3, tempBooks[temp_no].isbn, ',');
						getline(file3, tempBooks[temp_no].publishing_date, ',');
						getline(file3, tempBooks[temp_no].quant, '\n');

						if (tempBooks[temp_no].book_ka_naam == books[i].book_name)
						{
							int q = stoi(tempBooks[temp_no].quant);
							if (q == 0)
							{
								cout << "THIS BOOK CANNOT BE ISSUED DUE TO LESS AVAILABILITY\n";
								break;
							}
							else
							{
								q--;
								string an = to_string(q);
								books[i].quantity = an;
								ofstream file4;
								file4.open(fName);
								file4 << books[i].book_name << ",";
								file4 << books[i].author << ",";
								file4 << books[i].ISBN << ",";
								file4 << books[i].publish_date << ",";
								file4 << books[i].quantity;
								file4.close();

								string filename;
								ofstream file;
								system("CLS");
								cout << "TO ISSUE THE BOOK." << endl;
								cout << "...................." << endl << endl;;
								cout << "Enter the Book Sr.no: " << endl;

								cin >> filename;
								file.open("LENDING\\" + filename + ".txt");
								if (file.is_open())
								{
									lent[j].issued_book = books[index].book_name;
									file << lent[j].issued_book << ",";

									cout << "Enter the name of the borrower: " << endl;
									cin.ignore();
									getline(cin, lent[j].borrower);
									file << lent[j].borrower << ",";

									cout << "Enter the issued date: " << endl;
									cin >> lent[j].issuing_date;
									file << lent[j].issuing_date << ",";


									cout << "Enter the return date in format e.g 12-12-2022 as 12-12-22 :" << endl;
									cin >> lent[j].return_date;
									file << lent[j].return_date << ",";

									cout << "Enter the fine for late return: " << endl;
									cin >> lent[j].fine;
									file << lent[j].fine;
									j++;
									file.close();
									cout << "THE BOOK HAS BEEN ISSUED" << endl;
									po = 1;
									break;
								}
							}
						}
					}
					temp_no++;
					file3.close();
				}
				if (po == 1)
				{
					break;
				}
				else
				{
					continue;
				}
			}
		}

		index = 0;
		temp_no = 0;
		closedir(directoryy);
	}
}
void Return()
{

	string name;
	cout << "Enter the name  of the book: " << endl;
	cin.ignore();
	getline(cin, name);

	cout << "Enter the date it is being returned on: " << endl;
	cout << "day: ";
	cin >> da;
	cout << "month: ";
	cin >> mo;
	cout << "year: ";
	cin >> ye;

	name_search_lending(lent, j, l_index, name);
	int r = bro;
	DIR* delete_dir;
	struct dirent* ibbi;

	delete_dir = opendir("LENDING");
	string fName;
	char fileka_naam[100] = { 'L','E','N','D','I','N','G','\\','\\' };


	if (delete_dir)
	{
		while ((ibbi = readdir(delete_dir)) != NULL)
		{
			fName = "LENDING\\";
			if (!strcmp(ibbi->d_name, ".") || !strcmp(ibbi->d_name, "..")) {
				continue;

			}
			else
			{
				fName = fName + ibbi->d_name;

				ifstream file1;
				string end_tak;
				file1.open(fName);
				int temp11 = 0;
				while (getline(file1, end_tak)) {

					temp11++;
				}

				file1.close();
				fstream file3;
				file3.open(fName);

				dell = 0;
				for (int j = 0; j < temp11; j++)
				{
					getline(file3, del[dell].issued_b, ',');
					getline(file3, del[dell].issuing_d, ',');
					getline(file3, del[dell].return_d, ',');
					getline(file3, del[dell].jisne_li, ',');
					getline(file3, del[dell].Fine, '\n');


					if (del[dell].issued_b == lent[l_index].issued_book)
					{
						/*return lent[dell].return_date; */
						strcat_s(fileka_naam, ibbi->d_name);
						retu = del[dell].return_d;
						break;
					}
					dell++;
				}


				file3.close();

				remove(fileka_naam);
				cout << "THE BOOK HAS BEEN SUCCESSFULLY RETURNED" << endl;

			}
		}
	}
	closedir(delete_dir);

	int i;
	searchbyname(books, a, index, name);
	i = yes;
	DIR* directoryy;
	struct dirent* xyzz;
	directoryy = opendir("BOOKS");


	if (directoryy)
	{

		while ((xyzz = readdir(directoryy)) != NULL)
		{
			string fName = "BOOKS\\";
			if (!strcmp(xyzz->d_name, ".") || !strcmp(xyzz->d_name, "..")) {
				continue;
			}
			else
			{
				fName = fName + xyzz->d_name;

				ifstream file1;
				string abc;
				file1.open(fName);
				int temp1 = 0;
				while (getline(file1, abc))
				{

					temp1++;
				}
				file1.close();
				fstream file3;
				file3.open(fName);

				for (int j = 0; j < temp1; j++)
				{
					getline(file3, tempBooks[temp_no].book_ka_naam, ',');
					getline(file3, tempBooks[temp_no].uska_author, ',');
					getline(file3, tempBooks[temp_no].isbn, ',');
					getline(file3, tempBooks[temp_no].publishing_date, ',');
					getline(file3, tempBooks[temp_no].quant, '\n');

					if (tempBooks[temp_no].book_ka_naam == books[i].book_name)
					{
						int q = stoi(tempBooks[temp_no].quant);
						q++;
						string an = to_string(q);
						books[i].quantity = an;
						ofstream file4;
						file4.open(fName);
						file4 << books[i].book_name << ",";
						file4 << books[i].author << ",";
						file4 << books[i].ISBN << ",";
						file4 << books[i].publish_date << ",";
						file4 << books[i].quantity;
						file4.close();

					}
				}
				temp_no++;
				file3.close();
			}
		}
	}temp_no = 0;
	closedir(directoryy);
}
void Fine(int date1, int month1, int year1)
{
	int day, month, year;

	cout << "TYPE THIS " << retu << " ORIGINAL RETURN DATE AGAIN " << endl;
	cout << "day: " << endl;
	cin >> day;
	cout << "month: " << endl;
	cin >> month;
	cout << "year: " << endl;
	cin >> year;


	if ((date1 - day) > 0 || (month1 - month) > 0 || (year1 - year) > 0)
	{
		cout << "FINE WILL BE COLLECTED" << endl;
		totalfine[0].fine += 100;
		fstream filefine;
		filefine.open("fine.txt", ios::out);
		if (filefine.is_open())
		{
			filefine << totalfine[0].fine;
			filefine.close();
		}
	}
	else
	{
		cout << endl << "NO FINE" << endl;
	}


}
int reading_fine()
{
	fstream filefine;
	filefine.open("fine.txt");
	if (filefine.is_open())
	{
	}filefine.close();
	ifstream fileffine;
	fileffine.open("fine.txt");
	if (fileffine.is_open())
	{
		fileffine >> totalfine[0].fine;
	}fileffine.close();
	return totalfine[0].fine;
}
void adding_book(Books books[], int& size)
{
	int add_number;
	string filename;
	ofstream file;

	cout << "Enter the number of books that you wish to add: " << endl;
	cin >> add_number;

	for (int i = a; i < a + add_number; i++)
	{
		cout << "Enter the Book Sr.no: " << endl;
		cin >> filename;
		file.open("BOOKS\\" + filename + ".txt");
		if (file.is_open())
		{


			cout << "Enter The Name Of The Book :" << endl;
			cin.ignore();
			getline(cin, books[i].book_name);
			file << books[i].book_name << ",";



			cout << "Enter The Author's name :" << endl;

			getline(cin, books[i].author);
			file << books[i].author << ",";


			cout << "Enter The Book ISBN No:" << endl;
			cin >> books[i].ISBN;
			file << books[i].ISBN << ",";


			cout << "Enter The Year It Was Published in:" << endl;
			cin >> books[i].publish_date;
			file << books[i].publish_date << ",";

			cout << "The quantity:" << endl;
			cin >> books[i].quantity;
			file << books[i].quantity;


			file.close();
			system("CLS");
		}
	}
	a = a + add_number;
}
void delete_bookfile()
{
	string name;
	cout << "ENTER THE NAME OF THE BOOK : " << endl;
	cin.ignore();
	getline(cin, name);

	searchbyname(books, a, index, name);
	int i = yes;
	if (i == 2000)
	{
		cout << "BOOK NOT FOUND\n";
	}
	dell = 0;
	DIR* delete_dir;
	struct dirent* ibbi;

	delete_dir = opendir("BOOKS");
	string fName;
	char filekanaam[100] = { 'B','O','O','K','S','\\','\\','\0' };


	if (delete_dir) {
		while ((ibbi = readdir(delete_dir)) != NULL)
		{
			fName = "BOOKS\\";
			if (!strcmp(ibbi->d_name, ".") || !strcmp(ibbi->d_name, "..")) {
				continue;

			}
			else
			{
				fName = fName + ibbi->d_name;

				ifstream file1;
				string end_tak;
				file1.open(fName);
				int temp11 = 0;
				while (getline(file1, end_tak)) {

					temp11++;
				}
				file1.close();
				fstream file3;
				file3.open(fName);
				for (int k = 0; k < temp11; k++, dell++)
				{
					getline(file3, tempBooks[dell].book_ka_naam, ',');
					getline(file3, tempBooks[dell].uska_author, ',');
					getline(file3, tempBooks[dell].publishing_date, ',');
					getline(file3, tempBooks[dell].quant, ',');
					getline(file3, tempBooks[dell].isbn, '\n');
					if (tempBooks[dell].book_ka_naam == books[i].book_name)
					{
						cout << "THIS BOOK HAS BEEN DELETED\n";
						strcat_s(filekanaam, ibbi->d_name);
					}
				}
				file3.close();
				remove(filekanaam);
			}
		}
	}
	index = 0;
	closedir(delete_dir);
	a--;
}
void displayBooks(Books books[1000])
{
	cout << "Sr. No" << setw(20) << "Book Name" << setw(20) << "Author" << setw(20) << "ISBN" << setw(20) << "Publish Date" << setw(20) << "Quantity " << endl;

	for (int i = 0; i < a; i++)
	{
		cout << " " << i + 1 << "." << setw(26) << books[i].book_name << setw(15) << books[i].author << setw(20) << books[i].ISBN << setw(20) << books[i].publish_date << setw(20) << books[i].quantity << endl;
	}
}
int main()
{
	int choice, w;
	string return_struct;
	read_database();
	read_lending();
	sorting(books);
	int x, y; // syntax ka part hy
	GRAPHICS();
	load();
	graphics();
	int tu, b, f = 0;
	ofstream file1;
	file1.open("REGISTER.txt ", ios::app);
	if (file1.is_open())
	{
	}
	file1.close();
	cin >> b;
	system("CLS");
	do
	{
		switch (b)
		{
		case 1:
		{
			f = Register();
			if (f == 1)
			{
				cout << "ENTER 2 IF YOU WANT TO LOG-IN NOW : \n";
				cin >> b;
				break;
			}
		}
		case 2:
		{
			string username, password;
			char read[30], pass[30];
			int c = 0, n = 1, m = 1;
			cout << "ENTER YOUR USERNAME : \n";
			cin >> username;
			cout << "ENTER YOUR PASSWORD : \n";
			cin >> password;
			ifstream file;
			file.open("REGISTER.txt");
			if (file.is_open())
			{
				while (!file.eof())
				{
					file >> read;
					if (read == username)
					{
						cout << "ENTERED USER NAME IS CORRECT\n";
						c++;
						ifstream file;
						file.open("REGISTER.txt");
						if (file.is_open())
						{
							while (!file.eof())
							{
								file >> pass;
								if ((n + 1) == m)
								{
									if (pass == password)
									{
										cout << "ENTERED PASSWORD IS CORRECT\n";
										c++;
									}
								}
								m++;
							}
							file.close();
						}
					}
					else
					{
						n++;
					}
				}
				if (c == 2)
				{
					cout << "YOU HAVE SUCCESSFULLY LOGGED IN\n";
					b = 3;

				}
				else
				{
					cout << "YOU HAVE ENTERED WRONG LOG-IN INFORMATION. \nIF YOU WANT TO REGISTER PRESS 1 : \nIF YOU WANT TO RETRY FOR LOGGING IN PRESS 2 : \n";
					cin >> b;
					if (b == 1)
					{
						cout << "FOR REGISTERATION PLEASE \n";
					}
				}
				file.close();
			}
			break;
		}
		}
	} while (b == 2 || b == 1);
	if (b == 3)
	{

	MENU:
		cout << "****";
		cout << "\n\n\t\t\t\tMENU";
		cout << "\n1. ISSUE A BOOK";
		cout << "\n2. RETURN A BOOK";
		cout << "\n3. SEARCH A PARTICULAR BOOK";
		cout << "\n4. UPDATE";
		cout << "\n5. DISPLAY ALL BOOKS IN THE LIBRARY";
		cout << "\n6. EXIT";
		cout << "\n7. FINE COLLECTION" << endl << endl;
		cout << "****" << endl;
		cout << "PLEASE ENTER ONE OF THE ABOVE MENTIONED CHOICES" << endl;
		cin >> choice;
		do
		{
			switch (choice)
			{
			case 1:
			{
				issue_book();
				cout << "ENTER 0 TO ISSUE ANOTHER BOOK" << endl;
				cout << "ENTER 1 TO RETURN TO MAIN MENU" << endl;
				cout << "ENTER 2 TO EXIT" << endl;
				cin >> w;
				if (w == 0)
				{
					choice = 1;
					system("CLS");
					issue_book();
				}
				else if (w == 1)
				{
					system("CLS");
					goto MENU;
				}
				else
				{
					choice = 6;
				}

				break;
			}
			case 2:
			{
				Return();
				Fine(da, mo, ye);
				cout << "ENTER 0 TO RETURN ANOTHER BOOK" << endl;
				cout << "ENTER 1 TO RETURN TO MAIN MENU" << endl;
				cout << "ENTER 2 TO EXIT" << endl;
				cin >> w;
				if (w == 0)
				{
					choice = 2;
					system("CLS");
				}
				else if (w == 1)
				{
					system("CLS");
					goto MENU;
				}
				else
				{
					choice = 6;
				}

				break;
			}
			case 3:
			{
				int search_option, i;
				cout << "ENTER 1 TO SEARCH THE BOOK BY ITS NAME." << endl;
				cout << "ENTER 2 TO SEARCH THE BOOK BY ISBN.NO." << endl;
				cin >> search_option;
				if (search_option == 1)
				{
					string ii;
					cout << "Enter the name of the book you are searching for: " << endl;
					cin.ignore();
					getline(cin, ii);
					searchbyname(books, a, index, ii);
					i = yes;
					if (i != 2000)
					{
						cout << "THIS BOOK IS AVAILABLE IN LIBRARY\n";
						cout << "BOOK NAME : " << books[i].book_name << endl;
						cout << "AUTHOR NAME : " << books[i].author << endl;
						cout << "PUBLISH DATE : " << books[i].publish_date << endl;
						cout << "ISBN : " << books[i].ISBN << endl;
					}
					else
					{
						system("CLS");
						cout << "THE BOOK WAS NOT FOUND." << endl;
					}
				}
				else if (search_option == 2)
				{
					string ii;
					cout << "Enter the ISBN of the book you are searching for: " << endl;
					cin >> ii;
					searchbyisbn(books, a, index, stoi(ii));
					i = yes;
					if (check != 0)
					{
						cout << "THIS BOOK IS AVAILABLE IN LIBRARY\n";
						cout << "BOOK NAME : " << books[i].book_name << endl;
						cout << "AUTHOR NAME : " << books[i].author << endl;
						cout << "PUBLISH DATE : " << books[i].publish_date << endl;
						cout << "ISBN : " << books[i].ISBN << endl;
						check = 0;
					}
					else if (check == 0)
					{
						system("CLS");
						cout << "THE BOOK WAS NOT FOUND." << endl;
					}
				}
				cout << "ENTER 0 TO SEARCH ANOTHER BOOK" << endl;
				cout << "ENTER 1 TO RETURN TO MAIN MENU" << endl;
				cout << "ENTER 2 TO EXIT" << endl;
				cin >> w;
				if (w == 0)
				{
					choice = 3;
					system("CLS");
				}
				else if (w == 1)
				{
					system("CLS");
					goto MENU;
				}
				else
				{
					choice = 6;
				}
				break;
			}
			case 4:
			{
				int update_option;
				cout << "ENTER 1 TO ADD BOOKS" << endl;
				cout << "ENTER 2 TO DELETE A BOOK" << endl;
				cin >> update_option;
				if (update_option == 1)
				{
					adding_book(books, a);
					cout << "YOUR DESIRED NUMBER OF BOOKS HAVE BEEN ADDED" << endl;
				}
				else if (update_option == 2)
				{
					delete_bookfile();
				}
				cout << "ENTER 0 TO ADD/DELETE ANOTHER BOOK" << endl;
				cout << "ENTER 1 TO RETURN TO MAIN MENU" << endl;
				cout << "ENTER 2 TO EXIT" << endl;
				cin >> w;
				if (w == 0)
				{
					choice = 4;
					system("CLS");
					break;
				}
				else if (w == 1)
				{
					system("CLS");
					goto MENU;
				}
				else
				{
					choice = 6;
				}
				break;
			}
			/*case 5:
			{
				displayBooks(books);
				cout << "ENTER 0 TO REFRESH DISPLAY" << endl;
				cout << "ENTER 1 TO RETURN TO MAIN MENU" << endl;
				cout << "ENTER 2 TO EXIT" << endl;
				cin >> w;
				if (w == 0)
				{
					choice = 5;
					system("CLS");
					break;
				}
				else if (w == 1)
				{
					system("CLS");
					goto MENU;
				}
				else
				{
					choice = 6;
				}
				break;
			}*/
			case 6:
			{
				exit(0);
			}
			case 7:
			{
				cout << "TOTAL FINE COLLECTED FROM ALL LATE RETURNS" << endl;
				cout << reading_fine();
				cout << "\nENTER 0 TO SHOW FINE AGAIN" << endl;
				cout << "ENTER 1 TO RETURN TO MAIN MENU" << endl;
				cout << "ENTER 2 TO EXIT" << endl;
				cin >> w;
				if (w == 0)
				{
					choice = 5;
					system("CLS");
					break;
				}
				else if (w == 1)
				{
					system("CLS");
					goto MENU;
				}
				else
				{
					choice = 6;
				}
				break;
			}
			default:
				system("CLS");
				storage(books);
				goto MENU;
			}
		} while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7);
	}
}