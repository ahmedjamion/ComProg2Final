/***********************************************
Jamion, Ahmed Rashad I.
BS InfotTech 1A
Final Exam Defense

Survey Corps Trainee Record Management System
Data usedis based on the anime "Attack on Titan"
***********************************************/

#include <iostream>
#include <limits>  //ignoreline() function
#include <iomanip> //setw() function
#include <string>
#include <fstream> //for input and output stream
#include <sstream> //for reading from saved file txt/csv

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BRIGHT_BLACK "\033[90m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

#define BACKGROUND_BLACK "\033[40m"
#define BACKGROUND_RED "\033[41m"
#define BACKGROUND_GREEN "\033[42m"
#define BACKGROUND_YELLOW "\033[43m"
#define BACKGROUND_BLUE "\033[44m"
#define BACKGROUND_MAGENTA "\033[45m"
#define BACKGROUND_CYAN "\033[46m"
#define BACKGROUND_WHITE "\033[47m"
#define BACKGROUND_BRIGHT_BLACK "\033[100m"
#define BACKGROUND_BRIGHT_RED "\033[101m"
#define BACKGROUND_BRIGHT_GREEN "\033[102m"
#define BACKGROUND_BRIGHT_YELLOW "\033[103m"
#define BACKGROUND_BRIGHT_BLUE "\033[104m"
#define BACKGROUND_BRIGHT_MAGENTA "\033[105m"
#define BACKGROUND_BRIGHT_CYAN "\033[106m"
#define BACKGROUND_BRIGHT_WHITE "\033[107m"

using namespace std;

const int MAXSIZE = 10; // constant variable for maximum record size

// Data Structure
struct Trainee
{
	int traineeID;
	string firstName;
	string lastName;
	string gender;
	int age;
	string birthPlace;
	string status;
	Trainee()
	{
		traineeID = 0;
		firstName = "";
		lastName = "";
		gender = "";
		age = 0;
		birthPlace = "";
		status = "";
	}
};

// Prototype list
void welcomeMenu(Trainee *a);
void mainMenu(Trainee *a);
void readMenu(Trainee *a);
void saveMenu(Trainee *a);
void addRecord(Trainee *a);
void deleteMenu(Trainee *a);
void deleteRecord(Trainee *a);
void removeFallen(Trainee *a);
void saveMemories(Trainee *a, string b);
void shiftRecords(Trainee *a, int index);
void viewRecords(Trainee *a);
void showTable(Trainee *a);
void searchRecord(Trainee *a);
int traineeIndex(Trainee *a);
void updateRecord(Trainee *a);
void showRecord(Trainee *a, int index);
void countRecords(Trainee *a);
void sortRecord(Trainee *a);
void clearRecord(Trainee *a);
bool empty(Trainee *a);
void readFile(Trainee *a, string b);
void saveFile(Trainee *a, string b);
bool duplicate(Trainee *a, int newID);
void ignoreline();
int lineCount(string b);
void exitScreen();

int main()
{
	Trainee trainee[MAXSIZE] = {}; // Creation of an array of object of the struct Trainee
	welcomeMenu(trainee);		   // Calls welcome menu
	mainMenu(trainee);			   // Calls main menu
	saveFile(trainee, "Temporary.csv");
	exitScreen();
	return 0;
}

void welcomeMenu(Trainee *a)
{ // Welcome Menu
	char option{};
	bool invalidInput = true; // bool variable to handle invalid user input
	while (invalidInput)
	{
		system("cls");
		cout << BACKGROUND_BLUE << BRIGHT_WHITE;
		cout << "+-----------------------------------+" << endl;
		cout << "|       S U R V E Y  C O R P S      |" << endl;
		cout << "|       TRAINEE RECORD MANAGER      |" << endl;
		cout << "+-----------------------------------+" << endl;
		cout << RESET;
		cout << endl;
		cout << BACKGROUND_BLUE << BRIGHT_WHITE;
		cout << "+---+-------------------------------+" << endl;
		cout << "| 1 | Load Trainee Record Main File |" << endl;
		cout << "+---+-------------------------------+" << endl;
		cout << "| 2 | Pick from Available Files     |" << endl;
		cout << "+---+-------------------------------+" << endl;
		cout << "| 3 | Go to MAIN MENU               |" << endl;
		cout << "+---+-------------------------------+" << endl;
		cout << RESET;
		cout << "Pick an option: ";
		cin >> option;
		ignoreline();
		// Switch for first menu
		switch (option)
		{
		case '1':
			readFile(a, "Trainee Record.csv");
			invalidInput = false;
			break;
		case '2':
			readMenu(a);
			invalidInput = false;
			break;
		case '3':
			invalidInput = false;
		default:
			break;
		}
	}
}

void mainMenu(Trainee *a)
{ // main menu
	char option;
	do
	{
		system("cls");
		cout << BACKGROUND_BLUE << BRIGHT_WHITE;
		cout << "+----------------------------------------+" << endl;
		cout << "|         M  A  I  N   M  E  N  U        |" << endl;
		cout << "+----------------------------------------+" << endl;
		cout << RESET;
		cout << endl;
		cout << BACKGROUND_BLUE << BRIGHT_WHITE;
		cout << "+---+--------------+--+--------------+---+" << endl;
		cout << "| 1 | ADD NEW      |  |        Count | 6 |" << endl;
		cout << "+---+--------------+--+--------------+---+" << endl;
		cout << "| 2 | DELETE       |  |         Sort | 7 |" << endl;
		cout << "+---+--------------+--+--------------+---+" << endl;
		cout << "| 3 | DISPLAY      |  |    Clear All | 8 |" << endl;
		cout << "+---+--------------+--+--------------+---+" << endl;
		cout << "| 4 | SEARCH       |  |    Load File | 9 |" << endl;
		cout << "+---+--------------+--+--------------+---+" << endl;
		cout << "| 5 | UPDATE       |  |    Save File | S |" << endl;
		cout << "+---+--------------------------------+---+" << endl;
		cout << "| X |       E    X    I    T         | X |" << endl;
		cout << "+---+--------------------------------+---+" << endl;
		cout << RESET;
		cout << "Pick an Operation: ";
		cin >> option;
		ignoreline();

		switch (option)
		{
		case '1': // Add new record
			addRecord(a);
			break;
		case '2': // Delete a record
			deleteMenu(a);
			break;
		case '3': // View current records
			viewRecords(a);
			break;
		case '4': // Search record
			searchRecord(a);
			break;
		case '5': // Update a record
			updateRecord(a);
			break;
		case '6': // count the records
			countRecords(a);
			break;
		case '7': // Sort current record
			sortRecord(a);
			break;
		case '8': // Clear/empty record
			clearRecord(a);
			break;
		case '9': // Load/read a file
			readMenu(a);
			break;
		case 's':
		case 'S': // save current record
			saveMenu(a);
			break;
		case 'x':
		case 'X': // save then exit
			break;
		default:
			break;
		}
	} while (option != 'x');
}

void readMenu(Trainee *a)
{ // menu for loading/reading existing save files
	char option;
	bool invalidInput = true;
	while (invalidInput)
	{
		system("cls");
		cout << BACKGROUND_BLUE << BRIGHT_WHITE;
		cout << "+------------------------+" << endl;
		cout << "|   LOAD EXISTING FILE   |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| 1 | Trainee Record.csv |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| 2 | Activity 4.csv     |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| 3 | Temporary.csv      |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| 4 | Fallen Heroes.csv  |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| 5 | Open a File        |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| x | Main Menu          |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << RESET;
		cout << "Pick an option: ";
		cin >> option;
		ignoreline();
		switch (option)
		{
		case '1':
			readFile(a, "Trainee Record.csv");
			invalidInput = false;
			break;
		case '2':
			readFile(a, "Activity 4.csv");
			invalidInput = false;
			break;
		case '3':
			readFile(a, "Temporary.csv");
			invalidInput = false;
			break;
		case '4':
			readFile(a, "Fallen Heroes.csv");
			invalidInput = false;
			break;
		case '5':
			readFile(a, "");
			invalidInput = false;
			break;
		case 'x':
		case 'X':
			invalidInput = false;
			break;
		default:
			break;
		}
	}
}

void addRecord(Trainee *a)
{ // adding a new record

	for (int i = 0; i < MAXSIZE; i++)
	{ // loop looking for empty space on the table
		if (a[i].traineeID == 0)
		{ // if empty space is found
			string input;
			bool success = false; // handle stoi fail
			while (!success)
			{ // handling stoi error
				system("cls");
				cout << BACKGROUND_BLUE << BRIGHT_WHITE;
				cout << "+-------------------------------+" << endl;
				cout << "|   A D D  N E W  R E C O R D   |" << endl;
				cout << "+-------------------------------+" << endl;
				cout << RESET;
				cout << "Trainee ID: ";
				getline(cin, input);

				try
				{
					int newID = stoi(input);
					if (duplicate(a, newID))
					{ // handling duplicate ID
						cout << "Duplicate ID detected";
						cin.get();
					}
					else
					{
						a[i].traineeID = stoi(input);
						success = true;
					}
				}
				catch (invalid_argument &e)
				{
					cout << "Invalid input";
					cin.get();
				}
				catch (out_of_range &e)
				{
					cout << "Invalid input";
					cin.get();
				}
			}
			cout << "First Name: ";
			getline(cin, input);
			a[i].firstName = input;

			cout << "Last Name: ";
			getline(cin, input);
			a[i].lastName = input;

			cout << "Gender: ";
			getline(cin, input);
			a[i].gender = input;

			success = false; // setting to false for reuse
			while (!success)
			{
				cout << "Age: ";
				getline(cin, input);
				try
				{
					a[i].age = stoi(input);
					success = true; // success
				}
				catch (invalid_argument &e)
				{
					cout << "Invalid input";
					cin.get();
				}
				catch (out_of_range &e)
				{
					cout << "Out of range";
					cin.get();
				}
			}

			cout << "Birthplace: ";
			getline(cin, input);
			a[i].birthPlace = input;

			cout << "Status: ";
			getline(cin, input);
			a[i].status = input;

			system("cls");
			showRecord(a, i); // shows new record added
			cout << "N E W  R E C O R D  A D D E D" << endl;
			cout << "Press enter to go to main menu";
			cin.get();
			return;
		}
	}
	showTable(a);
	cout << "R E C O R D  F U L L" << endl;
	cout << "Press enter to go to main menu";

	cin.get();
}

void deleteRecord(Trainee *a)
{ // delete function
	system("cls");
	showTable(a);
	cout << "Pick a record to DELETE" << endl;
	int index = traineeIndex(a);
	if (index == -1)
	{
		system("cls");
		cout << "Record not found, pick a valid record";
		cin.get();
		deleteRecord(a);
	}
	else
	{
		system("cls");
		showRecord(a, index);
		shiftRecords(a, index); // function that actually performs delete(not actually delete but emptying a space)
		cout << "R E C O R D  D E L E T E D" << endl;
		cout << "Press Enter to go to main menu";
		cin.get();
	}
}

void viewRecords(Trainee *a)
{
	showTable(a);
	cout << "C U R R E N T  R E C O R D S" << endl;
	cout << "Press enter to go to main menu";
	cin.get();
}

void showTable(Trainee *a)
{ // view current record (outputs all current record)
	system("cls");
	cout << "                     S U R V E Y  C O R P S  T R A I N E E  R E C O R D S                    " << endl;
	cout << BACKGROUND_WHITE << BLACK;
	cout << "+====+============+============+============+========+======+======================+========+" << endl;
	cout << "|" << left << setw(4) << "NO.";
	cout << "|" << left << setw(12) << "TRAINEE ID";
	cout << "|" << left << setw(12) << "FIRST NAME";
	cout << "|" << left << setw(12) << "LAST NAME";
	cout << "|" << left << setw(8) << "GENDER";
	cout << "|" << left << setw(6) << "AGE";
	cout << "|" << left << setw(22) << "BIRTHPLACE";
	cout << "|" << left << setw(8) << "STATUS"
		 << "|" << endl;
	cout << "+====+============+============+============+========+======+======================+========+" << endl;
	if (empty(a))
	{
		cout << "|                                  R E C O R D  E M P T Y                                   |" << endl;
		cout << "+===========================================================================================+" << endl;
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].traineeID != 0)
		{
			if (a[i].status == "Dead")
				cout << BACKGROUND_BRIGHT_RED;
			if (a[i].status == "Alive")
				cout << BACKGROUND_BRIGHT_GREEN;
			cout << "|" << left << setw(4) << i + 1;
			cout << "|" << left << setw(12) << a[i].traineeID;
			cout << "|" << left << setw(12) << a[i].firstName;
			cout << "|" << left << setw(12) << a[i].lastName;
			cout << "|" << left << setw(8) << a[i].gender;
			cout << "|" << left << setw(6) << a[i].age;
			cout << "|" << left << setw(22) << a[i].birthPlace;
			cout << "|" << left << setw(8) << a[i].status << "|";
			cout << endl;
			cout << RESET;
			cout << BACKGROUND_WHITE << BLACK;
			cout << "+----+------------+------------+------------+--------+------+----------------------+--------+" << endl;
		}
	}
	cout << RESET;
}

void searchRecord(Trainee *a)
{
	system("cls");
	cout << BACKGROUND_BLUE << BRIGHT_WHITE;
	cout << "+----------------------------+" << endl;
	cout << "|  S E A R C H  R E C O R D  |" << endl;
	cout << "+----------------------------+" << endl;
	cout << RESET;
	int index = traineeIndex(a);
	if (index == -1)
	{
		system("cls");
		cout << BRIGHT_RED;
		cout << "R E C O R D  N O T  F O U N D" << endl;
		cout << RESET;
		cout << "-----------------------------" << endl;
		cout << "Press enter to go to main menu";
		cin.get();
		return;
	}
	else
	{
		system("cls");
		cout << BRIGHT_GREEN;
		cout << "R E C O R D  F O U N D" << endl;
		cout << RESET;
		showRecord(a, index);
		cout << "Press enter to go to main menu";

		cin.get();
	}
}

int traineeIndex(Trainee *a)
{ // searching record returns index (also used by delete functio)
	int input;
	cout << "Trainee ID: ";
	cin >> input;
	ignoreline();
	if (cin.fail())
	{
		ignoreline();
		return -1;
	}
	else
	{
		for (int i = 0; i < MAXSIZE; i++)
		{
			if (a[i].traineeID == input)
			{
				return i;
			}
		}
	}
	return -1;
}

void sortRecord(Trainee *a)
{ // sorts code in ascending order(using insertion sort)
	for (int i = 1; i < MAXSIZE; i++)
	{
		if (a[i].traineeID == 0)
		{
			continue;
		}
		Trainee key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j].traineeID > key.traineeID)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
	showTable(a);
	cout << "R E C O R D  S O R T E D" << endl;
	cout << "Press enter to go to main menu";

	cin.get();
}

void clearRecord(Trainee *a)
{ // emptying all records using constructor (not actually deleting)
	for (int i = 0; i < MAXSIZE; i++)
	{
		while (a[i].traineeID != 0)
		{
			a[i] = Trainee();
		}
	}
	showTable(a);
	cout << "R E C O R D  C L E A R E D" << endl;
	cout << "Press enter to go to main menu";

	cin.get();
}

void saveMenu(Trainee *a)
{ // menu for saving records
	bool invalidInput = true;
	char option;
	while (invalidInput)
	{
		system("cls");
		cout << BACKGROUND_BLUE << BRIGHT_WHITE;
		cout << "+------------------------+" << endl;
		cout << "| SAVE TO EXISTING FILE  |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| 1 | Trainee Record.csv |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| 2 | Activity 4.csv     |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| 3 | Temporary.csv      |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| 4 | Create/Open a File |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << "| x | Main Menu          |" << endl;
		cout << "+---+--------------------+" << endl;
		cout << RESET;
		cout << "Pick an option: ";
		cin >> option;
		ignoreline();
		switch (option)
		{
		case '1':
			saveFile(a, "Trainee Record.csv");
			invalidInput = false;
			break;
		case '2':
			saveFile(a, "Activity 4.csv");
			invalidInput = false;
			break;
		case '3':
			saveFile(a, "Temporary.csv");
			invalidInput = false;
			break;
		case '4':
			saveFile(a, "");
			invalidInput = false;
			break;
		case 'x':
		case 'X':
			invalidInput = false;
			break;
		default:
			break;
		}
	}
}

void readFile(Trainee *a, string fileName = "")
{ // read/load from a file
	system("cls");
	ifstream traineeRecord;
	if (fileName.empty())
	{ // checking if second parameter is empty
		string input;
		cout << BACKGROUND_BLUE << BRIGHT_WHITE;
		cout << "+-------------------------+" << endl;
		cout << "|   L O A D  A  F I L E   |" << endl;
		cout << "+-------------------------+" << endl;
		cout << RESET;
		cout << "File Name: ";
		getline(cin, input);
		fileName = input;
	}
	// execution jumps here if second parameter is not empty
	traineeRecord.open(fileName);
	if (traineeRecord.is_open())
	{
		// using stringstream to extract data from .csv file
		string firstline;
		getline(traineeRecord, firstline);
		string line;
		string temp;
		int i = 0;
		while (getline(traineeRecord, line))
		{
			stringstream ss(line);
			string component;

			getline(ss, component, ',');
			temp = component;

			getline(ss, component, ',');
			a[i].traineeID = stoi(component);

			getline(ss, component, ',');
			a[i].firstName = component;

			getline(ss, component, ',');
			a[i].lastName = component;

			getline(ss, component, ',');
			a[i].gender = component;

			getline(ss, component, ',');
			a[i].age = stoi(component);

			getline(ss, component, ',');
			a[i].birthPlace = component;

			getline(ss, component, ',');
			a[i].status = component;
			i++;
		}
	}
	else
	{ // if unable to open file
		cout << "Error opening file" << endl;
		cout << "Press enter to go to main menu.";
		cin.get();
		return;
	}
	traineeRecord.close(); // closing open file
	// system("cls");
	cout << BACKGROUND_BLUE << BRIGHT_WHITE;
	cout << "+----------------------------------------+" << endl;
	cout << "|  S U C C E S S F U L L Y  L O A D E D  |" << endl;
	cout << "+----------------------------------------+" << endl;
	cout << RESET;
	cout << "[" << fileName << "]" << endl;
	cout << "Press enter to go to main menu.";
	cin.get();
}

void saveFile(Trainee *a, string fileName = "")
{ // saves current record
	// system("cls");
	ofstream traineeRecord;
	if (fileName.empty())
	{ // checking if second parameter is empty
		string input;
		cout << BACKGROUND_BLUE << BRIGHT_WHITE;
		cout << "+----------------------------------------+" << endl;
		cout << "| C R E A T E  O R  O P E N  A  F I L E  |" << endl;
		cout << "+----------------------------------------+" << endl;
		cout << RESET;
		cout << "File name: ";
		getline(cin, input);
		fileName = input;
	}
	// execution jumps here if second parameter is not empty
	traineeRecord.open(fileName);
	if (traineeRecord.is_open())
	{ // checks if file is open
		// writing to file
		traineeRecord << "No., Trainee ID,First Name, Last Name, Gender, Age, Birthplace, Status" << endl;
		for (int i = 0; i < MAXSIZE; i++)
		{
			if (a[i].traineeID != 0)
			{
				traineeRecord << i + 1 << ",";
				traineeRecord << a[i].traineeID << ",";
				traineeRecord << a[i].firstName << ",";
				traineeRecord << a[i].lastName << ",";
				traineeRecord << a[i].gender << ",";
				traineeRecord << a[i].age << ",";
				traineeRecord << a[i].birthPlace << ",";
				traineeRecord << a[i].status << endl;
			}
		}
	}
	else
	{
		cout << "Error opening file" << endl;
		cout << "Press enter to continue";
		cin.get();
		return;
	}
	traineeRecord.close(); // closing file
	system("cls");
	cout << BACKGROUND_BLUE << BRIGHT_WHITE;
	cout << "+--------------------------------------+" << endl;
	cout << "|  S U C C E S S F U L L Y  S A V E D  |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << RESET;
	cout << "[" << fileName << "]" << endl;
	cout << "Press enter to continue";
	cin.get();
}

void showRecord(Trainee *a, int index)
{ // shows a single record in the table
	cout << BACKGROUND_WHITE << BLACK;
	cout << "+====+============+============+============+========+======+======================+========+" << endl;
	cout << "|" << left << setw(4) << "NO.";
	cout << "|" << left << setw(12) << "TRAINEE ID";
	cout << "|" << left << setw(12) << "FIRST NAME";
	cout << "|" << left << setw(12) << "LAST NAME";
	cout << "|" << left << setw(8) << "GENDER";
	cout << "|" << left << setw(6) << "AGE";
	cout << "|" << left << setw(22) << "BIRTHPLACE";
	cout << "|" << left << setw(8) << "STATUS"
		 << "|" << endl;
	cout << "+====+============+============+============+========+======+======================+========+" << endl;
	if (empty(a))
	{ // if record is empty
		cout << "\t\t\t\t\tRecord Empty" << endl;
	}
	if (a[index].status == "Alive")
		cout << BACKGROUND_BRIGHT_GREEN;
	if (a[index].status == "Dead")
		cout << BACKGROUND_BRIGHT_RED;
	cout << "|" << left << setw(4) << index + 1;
	cout << "|" << left << setw(12) << a[index].traineeID;
	cout << "|" << left << setw(12) << a[index].firstName;
	cout << "|" << left << setw(12) << a[index].lastName;
	cout << "|" << left << setw(8) << a[index].gender;
	cout << "|" << left << setw(6) << a[index].age;
	cout << "|" << left << setw(22) << a[index].birthPlace;
	cout << "|" << left << setw(8) << a[index].status << "|";
	cout << endl;
	cout << RESET;
	cout << BACKGROUND_WHITE << BLACK;
	cout << "+----+------------+------------+------------+--------+------+----------------------+--------+" << endl;
	cout << RESET;
}

void shiftRecords(Trainee *a, int index)
{ // used by delete function to shift/move records
	// index parameter is the record to be deleted
	// code to shift next data to previous data(record to be deleted), basically deleting the previous
	int counter = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{ // calculating how many data exists on the record
		if (a[i].traineeID != 0)
			counter++;
	}
	for (int j = index; j < counter - 1; j++)
	{ // loop for shifting record one place forward using counter as limiter
		a[j] = a[j + 1];
		index++;
	}
	a[index] = Trainee(); // initializing the data to empty, making it available for adding new record
}

bool empty(Trainee *a)
{ // checks if record is empty
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].traineeID != 0)
			return false;
	}
	return true;
}

bool duplicate(Trainee *a, int newID)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].traineeID != 0)
		{
			if (a[i].traineeID == newID)
			{
				return true;
			}
		}
	}
	return false;
}

void ignoreline()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void updateRecord(Trainee *a)
{ // update existing records
	showTable(a);
	cout << "Pick a record to  U P D A T E" << endl;
	int index = traineeIndex(a);
	if (index == -1)
	{
		system("cls");
		cout << BRIGHT_RED;
		cout << "R E C O R D  N O T  F O U N D" << endl;
		cout << RESET;
		cout << "-----------------------------" << endl;
		cout << "Press enter to go to main menu";
		cin.get();
		return;
	}
	else
	{
		char option{};
		while (option != 'x')
		{
			system("cls");
			showRecord(a, index);
			cout << "       F I E L D S" << endl;
			cout << "------------------------" << endl;
			cout << "1. Trainee ID" << endl;
			cout << "2. First Name" << endl;
			cout << "3. Last Name" << endl;
			cout << "4. Gender" << endl;
			cout << "5. Age" << endl;
			cout << "6. Birthplace" << endl;
			cout << "7. Status" << endl;
			cout << "------------------------" << endl;
			cout << "x. Main Menu" << endl;
			cout << "------------------------" << endl;
			cout << "Pick a field to update: ";

			cin >> option;
			ignoreline();
			bool success = false;
			string input;
			switch (option)
			{
			case '1':
				while (!success)
				{
					system("cls");
					showRecord(a, index);
					cout << "Update Trainee ID: ";
					getline(cin, input);
					if (!input.empty())
					{
						try
						{
							a[index].traineeID = stoi(input);
							success = true;
							cout << "Age updated" << endl;
							cout << "Press enter to continue";
							cin.get();
						}
						catch (invalid_argument &e)
						{
							cout << "Invalid input";
							cin.get();
						}
						catch (out_of_range &e)
						{
							cout << "Invalid input";
							cin.get();
						}
					}
					else
					{
						cout << "Update canceled" << endl;
						cout << "Press enter to continue";
						cin.get();
					}
				}
				break;
			case '2':
				system("cls");
				showRecord(a, index);
				cout << "Update First Name: ";
				getline(cin, input);
				if (!input.empty())
				{ // skips update when enter is pressed without input
					system("cls");
					a[index].firstName = input;
					showRecord(a, index);
					cout << "First Name updated" << endl;
					cout << "Press enter to continue";
					cin.get();
				}
				else
				{
					cout << "Update canceled" << endl;
					cout << "Press enter to continue";
					cin.get();
				}
				break;
			case '3':
				system("cls");
				showRecord(a, index);
				cout << "Update Last Name: ";
				getline(cin, input);
				if (!input.empty())
				{
					system("cls");
					a[index].lastName = input;
					showRecord(a, index);
					cout << "Last Name updated" << endl;
					cout << "Press enter to continue";
					cin.get();
				}
				else
				{
					cout << "Update canceled" << endl;
					cout << "Press enter to continue";
					cin.get();
				}
				break;
			case '4':
				system("cls");
				showRecord(a, index);
				cout << "Update Gender: ";
				getline(cin, input);
				if (!input.empty())
				{
					system("cls");
					a[index].gender = input;
					showRecord(a, index);
					cout << "Gender updated" << endl;
					cout << "Press enter to continue";
					cin.get();
				}
				else
				{
					cout << "Update canceled" << endl;
					cout << "Press enter to continue";
					cin.get();
				}
				break;

			case '5':
				success = false;
				while (!success)
				{
					system("cls");
					showRecord(a, index);
					cout << "Update Age: ";
					getline(cin, input);
					if (!input.empty())
					{
						try
						{
							a[index].age = stoi(input);
							success = true;
							cout << "Age updated" << endl;
							cout << "Press enter to continue";
							cin.get();
						}
						catch (invalid_argument &e)
						{
							cout << "Invalid input";
							cin.get();
						}
						catch (out_of_range &e)
						{
							cout << "Invalid input";
							cin.get();
						}
					}
					else
					{
						cout << "Update canceled" << endl;
						cout << "Press enter to continue";
						cin.get();
					}
				}
				break;
			case '6':
				system("cls");
				showRecord(a, index);
				cout << "Update Birthplace: ";
				getline(cin, input);
				if (!input.empty())
				{
					system("cls");
					a[index].birthPlace = input;
					showRecord(a, index);
					cout << "Birthplace updated" << endl;
					cout << "Press enter to continue";
					cin.get();
				}
				else
				{
					cout << "Update canceled" << endl;
					cout << "Press enter to continue";
					cin.get();
				}
				break;
			case '7':
				system("cls");
				showRecord(a, index);
				cout << "Update Status: ";
				getline(cin, input);
				if (!input.empty())
				{
					system("cls");
					a[index].status = input;
					showRecord(a, index);
					cout << "Status updated" << endl;
					cout << "Press enter to continue";
					cin.get();
				}
				else
				{
					cout << "Update canceled" << endl;
					cout << "Press enter to continue";
					cin.get();
				}
				break;
			case 'x':
				break;
			default:
				break;
			}
		}
	}
}

void removeFallen(Trainee *a)
{
	saveMemories(a, "Fallen Heroes.csv");
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].status == "Dead")
		{
			shiftRecords(a, i);
			i--;
		}
	}
}

void deleteMenu(Trainee *a)
{
	char option{};
	bool invalidInput = true;
	while (invalidInput)
	{
		system("cls");
		cout << BACKGROUND_BLUE << BRIGHT_WHITE;
		cout << "+============================+" << endl;
		cout << "| D E L E T E  O P T I O N S |" << endl;
		cout << "+===+========================+" << endl;
		cout << "| 1 | Delete a Record        |" << endl;
		cout << "+---+------------------------+" << endl;
		cout << "| 2 | Free Fallen Heroes     |" << endl;
		cout << "+---+------------------------+" << endl;
		cout << "| x | Main Menu              |" << endl;
		cout << "+---+------------------------+" << endl;
		cout << RESET;
		cout << "Pick an option: ";
		cin >> option;
		ignoreline();
		switch (option)
		{
		case '1':
			deleteRecord(a);
			invalidInput = false;
			break;
		case '2':
			removeFallen(a);
			invalidInput = false;
			break;
		case 'x':
		case 'X':
			invalidInput = false;
			break;
		default:
			break;
		}
	}
}

void saveMemories(Trainee *a, string fileName)
{ // saves current record
	int count = lineCount(fileName);

	ofstream traineeRecord;
	traineeRecord.open(fileName, ios::app);
	if (traineeRecord.is_open())
	{
		for (int i = 0; i < MAXSIZE; i++)
		{
			if (a[i].status == "Dead")
			{
				if (count == 0)
				{
					traineeRecord << "No., Trainee ID,First Name, Last Name, Gender, Age, Birthplace, Status" << endl;
					count++;
				}
				traineeRecord << count << ",";
				traineeRecord << a[i].traineeID << ",";
				traineeRecord << a[i].firstName << ",";
				traineeRecord << a[i].lastName << ",";
				traineeRecord << a[i].gender << ",";
				traineeRecord << a[i].age << ",";
				traineeRecord << a[i].birthPlace << ",";
				traineeRecord << a[i].status << endl;
				count++;
			}
		}
	}
	else
	{
		cout << "Error opening file" << endl;
		cout << "Press enter to continue";
		cin.get();
		return;
	}
	traineeRecord.close(); // closing file
	system("cls");
	cout << BRIGHT_BLUE;
	cout << "FALLEN HEROES SUCCESFULLY FREED" << endl;
	cout << RESET;
	cout << "-------------------------------" << endl;
	cout << "Records: [" << fileName << "]" << endl;
	cout << "Press enter to continue";
	// ignoreline();
	cin.get();
}

int lineCount(string b)
{
	int counter = 0;
	ifstream memoryRecord;
	memoryRecord.open(b);
	if (memoryRecord.is_open())
	{
		string line;
		while (getline(memoryRecord, line))
		{
			counter++;
		}
	}
	else
	{
		cout << "Unable to open file";
	}
	return counter;
}

void countRecords(Trainee *a)
{
	system("cls");
	int total = 0;
	int alive = 0;
	int dead = 0;
	int female = 0;
	int male = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].traineeID != 0)
		{
			total++;
		}
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].status == "Alive")
		{
			alive++;
		}
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].status == "Dead")
		{
			dead++;
		}
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].gender == "Female")
		{
			female++;
		}
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].gender == "Male")
		{
			male++;
		}
	}
	cout << BRIGHT_BLUE << "CURRENT RECORD COUNT" << RESET << endl;
	cout << "------------------------------" << endl;
	cout << "Total Records: " << total << endl;
	cout << "Female: " << female << endl;
	cout << "Male: " << male << endl;
	cout << BRIGHT_GREEN << "Alive: " << alive << RESET << endl;
	cout << BRIGHT_RED << "Dead: " << dead << RESET << endl;
	cout << "------------------------------" << endl;
	cout << "Press enter to go to main menu";
	cin.get();
}

void exitScreen()
{
	system("cls");
	cout << BRIGHT_YELLOW << BACKGROUND_BLUE;
	cout << "                                       " << endl;
	cout << "  O N E  D A Y,                        " << endl;
	cout << "                                       " << endl;
	cout << "  W E ' L L  B R E A K  I T  D O W N.  " << endl;
	cout << "                                       " << endl;
	cout << "  T H I S  W A L L,                    " << endl;
	cout << "                                       " << endl;
	cout << "  H I D I N G  T H E  T R U T H,       " << endl;
	cout << "                                       " << endl;
	cout << "  W I L L  F A L L.                    " << endl;
	cout << "                                       " << endl;
	cout << RESET;
	cin.get();
}
