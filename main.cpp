// import library
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// global variable
string input_file = "database.txt";

// database structure
struct employee_inf {
	string id;
	string name;
	string birthday;
	string role;
	string salary;
	string date_of_employment;
	string email;
	string address;
	string grade;
};

// function header
int import_information(vector<employee_inf> &database);
char selection_menu();
void list_database(vector<employee_inf> &database, int size_database);

// main program
int main() {
	vector<employee_inf> database;
	int size_database;

	size_database = import_information(database);
	char choice = selection_menu();
	while (choice != '0') {
		switch (choice) {
		case '1':
			list_database(database, size_database);
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		default:
			cout << "Invalid input!" << endl;
		}
		choice = selection_menu();
	}

	cout << "Goodbye!" << endl;

	return 0;
}

// function ----------------------------------------

// import database
int import_information(vector<employee_inf> &database) {
	int i = NULL, j, k;
	ifstream input;
	string line, temp;

	input.open(input_file);
	// check existence of input file
	if (input.is_open()) {
		i = 0;
		// get line from input file
		while (getline(input, line)) {
			database.push_back(employee_inf());
			temp = "";
			k = 0;
			//loop over line
			for (j = 0; j < line.length(); j++) {
				// insert parameters
				if (line.at(j) != ',') {
					temp.push_back(line.at(j));
				}
				else {
					switch (k) {
					case 0:
						database[i].id = temp;
						break;
					case 1:
						database[i].name = temp;
						break;
					case 2:
						database[i].birthday = temp;
						break;
					case 3:
						database[i].role = temp;
						break;
					case 4:
						database[i].salary = temp;
						break;
					case 5:
						database[i].date_of_employment = temp;
						break;
					case 6:
						database[i].email = temp;
						break;
					case 7:
						database[i].address = temp;
						break;
					}
					temp = "";
					k++;
				}
			}
			database[i].grade = temp;
			i++;
		}
	}
	else {
		cout << "Input file does not exist." << endl;
	}

	if (i == NULL) {
		cout << "Database is empty." << endl;
	}

	return i;
}

// menu
char selection_menu() {
	char choice;

	// print menu
	cout << "**************************************" << endl;
	cout << "* Welcome to Staff Management System *" << endl;
	cout << "**************************************" << endl;
	cout << "1. List all Employees' Information" << endl;
	cout << "2. Import New Employee's Information" << endl;
	cout << "3. Search for Employee's Information" << endl;
	cout << "4. Edit Employee's Information" << endl;
	cout << "5. Search for Employee's Salary" << endl;
	cout << "6. Search for Employee's Grade" << endl;
	cout << "7. Delete Resigned Employee's Information" << endl;
	cout << "0. Quit" << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}

// menu function ----------

// list all employee
void list_database(vector<employee_inf> &database, int size_database) {
	for (int i = 0; i < size_database; i++) {
		cout << database[i].id << '\t'
			<< database[i].name << '\t'
			<< database[i].birthday << '\t'
			<< database[i].role << '\t'
			<< database[i].salary << '\t'
			<< database[i].date_of_employment << '\t'
			<< database[i].email << '\t'
			<< database[i].address << '\t'
			<< database[i].grade << endl;
	}
}