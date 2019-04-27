// import library
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// global variable
const char input_file[20] = "database.txt";

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
	string job;
};

// function header
void import_information(vector<employee_inf>& database);
void export_information(vector<employee_inf>& database);
char selection_menu();
void list_database(vector<employee_inf>& database);
void add_employee(vector<employee_inf>& database);
void search_employee(vector<employee_inf>& database);
void edit_employee(vector<employee_inf>& database);
void recond_employeejob(vector<employee_inf>& database);
void rank_employee(vector<employee_inf>& database);
void delete_employee(vector<employee_inf>& database);
bool check_dup_id(vector<employee_inf>& database, string id);

// main program
int main() {
	vector<employee_inf> database;

	import_information(database);

	char choice = selection_menu();
	while (choice != '0') {
		switch (choice) {
		case '1':
			list_database(database);
			break;
		case '2':
			add_employee(database);
			break;
		case '3':
			search_employee(database);
			break;
		case '4':
			edit_employee(database);
			break;
		case '5':
		  rank_employee(database);
			break;
		case '6':
		  recond_employeejob(database);
			break;
		case '7':
      delete_employee(database);
			break;
		default:
			cout << "Invalid input!" << endl;
		}
		choice = selection_menu();
	}

	cout << "Goodbye!" << endl;

	export_information(database);

	return 0;
}

// function ----------------------------------------

// import database
void import_information(vector<employee_inf>& database) {
	unsigned i = NULL, j, k;
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

		input.close();
	}
	else {
		cout << "Input file does not exist." << endl;
	}

	if (i == 0) {
		cout << "Database is empty." << endl;
	}
}

// export database
void export_information(vector<employee_inf>& database) {
	ofstream output;

	output.open(input_file, ofstream::out | ofstream::trunc);
	if (output.is_open()) {
		for (unsigned i = 0; i < database.size(); i++) {
			output << database[i].id << ','
				<< database[i].name << ','
				<< database[i].birthday << ','
				<< database[i].role << ','
				<< database[i].salary << ','
				<< database[i].date_of_employment << ','
				<< database[i].email << ','
				<< database[i].address << ','
				<< database[i].job << endl;
		}
	}

}

// menu
char selection_menu() {
	char choice;

	// print menu
	system("CLS");
	cout << "**************************************" << endl;
	cout << "* Welcome to Staff Management System *" << endl;
	cout << "**************************************" << endl;
	cout << "1. List all Employees' Information" << endl;
	cout << "2. Add New Employee's Information" << endl;
	cout << "3. Search for Employee's Information" << endl;
	cout << "4. Edit Employee's Information" << endl;
	cout << "5. Rank the Employee's Salary" << endl;
	cout << "6. Recond Employee's Job" << endl;
	cout << "7. Delete Employee's Information" << endl;
	cout << "0. Quit" << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}

// menu function ----------

// list all employee
void list_database(vector<employee_inf>& database) {
	for (unsigned i = 0; i < database.size(); i++) {
		cout << database[i].id << '\t'
			<< database[i].name << '\t'
			<< database[i].birthday << '\t'
			<< database[i].role << '\t'
			<< database[i].salary << '\t'
			<< database[i].date_of_employment << '\t'
			<< database[i].email << '\t'
			<< database[i].address << '\t'
			<< database[i].job << endl;
	}
	system("pause");
}

// add new employee
void add_employee(vector<employee_inf>& database) {
	string temp = "";
	int size = database.size();

	while (true) {
		temp = "";

		database.push_back(employee_inf());
		cout << "Please enter the ID: ";
		cin >> database[size].id;
		cout << "Please enter the Name: ";
		cin >> database[size].name;
		cout << "Please enter the Birthday (dd/mm/yyyy): ";
		cin >> database[size].birthday;
		cout << "Please enter the Role: ";
		cin >> database[size].role;
		cout << "Please enter the Salary: ";
		cin >> database[size].salary;
		cout << "Please enter the Date of Employment: ";
		cin >> database[size].date_of_employment;
		cout << "Please enter the Email: ";
		cin >> database[size].email;
		cout << "Please enter the Address: ";
		cin >> database[size].address;
		cout << "Please enter the Grade: ";
		cin >> database[size].grade;
		cout << endl;

		cout << database[size].id << '\t'
			<< database[size].name << '\t'
			<< database[size].birthday << '\t'
			<< database[size].role << '\t'
			<< database[size].salary << '\t'
			<< database[size].date_of_employment << '\t'
			<< database[size].email << '\t'
			<< database[size].address << '\t'
			<< database[size].grade << endl;

		while (true) {
			cout << "Is the information correct? (y/n): ";
			cin >> temp;
			if (temp == "n") {
				database.pop_back();
				break;
			}
			if (temp == "y") {
				break;
			}
		}

		if (temp == "y") {
			break;
		}
	}

}

// search employee
void search_employee(vector<employee_inf>& database) {
	bool found = false;
	string id, dummy;

	cout << "Please input the ID to be searched: ";
	cin >> id;

	for (unsigned i = 0; i < database.size(); i++) {
		if (database[i].id == id) {
			cout << database[i].id << '\t'
				<< database[i].name << '\t'
				<< database[i].birthday << '\t'
				<< database[i].role << '\t'
				<< database[i].salary << '\t'
				<< database[i].date_of_employment << '\t'
				<< database[i].email << '\t'
				<< database[i].address << '\t'
				<< database[i].grade << endl;
			found = true;
			system("pause");
		}
	}

	if (!found) {
		cout << "ID not found." << endl;
	}
}

// edit employee
void edit_employee(vector<employee_inf>& database) {
	string id, temp;
	int num;
	bool found = false;

	cout << "Please input the ID to be searched: ";
	cin >> id;

	for (unsigned i = 0; i < database.size(); i++) {
		if (database[i].id == id) {
			found = true;

			cout << database[i].id << '\t'
				<< database[i].name << '\t'
				<< database[i].birthday << '\t'
				<< database[i].role << '\t'
				<< database[i].salary << '\t'
				<< database[i].date_of_employment << '\t'
				<< database[i].email << '\t'
				<< database[i].address << '\t'
				<< database[i].grade << endl;

			cout << "What do you want to change?:" << endl;
			cout << "1. ID" << endl;
			cout << "2. Name" << endl;
			cout << "3. Birthday" << endl;
			cout << "4. Role" << endl;
			cout << "5. Salary" << endl;
			cout << "6. Date of Employment" << endl;
			cout << "7. Email" << endl;
			cout << "8. Address" << endl;
			cout << "9. Grade" << endl;
			cin >> num;

			switch (num) {
			case 1:
				cout << "What do you want to change the ID to?: " << endl;
				cin >> temp;
				database[i].id = temp;
			case 2:
				cout << "What do you want to change the Name to?: " << endl;
				cin >> temp;
				database[i].name = temp;
			case 3:
				cout << "What do you want to change the Birthday to?: " << endl;
				cin >> temp;
				database[i].birthday = temp;
			case 4:
				cout << "What do you want to change the Role to?: " << endl;
				cin >> temp;
				database[i].role = temp;
			case 5:
				cout << "What do you want to change the Salary to?: " << endl;
				cin >> temp;
				database[i].salary = temp;
			case 6:
				cout << "What do you want to change the Date of Employment to?: " << endl;
				cin >> temp;
				database[i].date_of_employment = temp;
			case 7:
				cout << "What do you want to change the Email to?: " << endl;
				cin >> temp;
				database[i].email = temp;
			case 8:
				cout << "What do you want to change the Address to?: " << endl;
				cin >> temp;
				database[i].address = temp;
			case 9:
				cout << "What do you want to change the Grade to?: " << endl;
				cin >> temp;
				database[i].grade = temp;
			}
		}
	}

	if (!found) {
		cout << "ID is not found." << endl;
		system("pause");
	}
}
// rank employee
void rank_employee(vector<employee_inf>& database){
	
}
// delete employee
void delete_employee(vector<employee_inf>& database){

}
void recond_employeejob(vector<employee_inf>& database) {
	string id,temp;
	cout << "Please input the ID: ";
	cin >> id;
	bool found = false;
	for (unsigned i=0;i<database.size();i++){
		if (database[i].id==id){
			found=true;
			if (database[i].job==""){
				cout << "What jobs do you arrange for the employee?" ;
			  cin >> database[i].job;
			}
			else{
				cout << "Do the employee finished what he is working on hand? (y/n):";
				cin >> temp;
				if (temp == "n") {
					cout << "What jobs do you arrange for the employee?" ;
				  cin >> database[i].job;
				}
				if (temp == "y") {
					database[i].job.clear();
					cout << "What jobs do you arrange for the employee?";
				  cin >> database[i].job;
				}
			 }
			}
			if (!found) {
				cout << "ID is not found." << endl;
				system("pause");
			}
		}
}
// miscilleaneous function -----
bool check_dup_id(vector<employee_inf>& database, string id) {
	for (unsigned i = 0; i < database.size(); i++) {
		if (database[i].id == id) {
			return true;
		}
	}
	return false;
}

