// import libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int employee_num = 10000;
// database structure
struct emplyee_inf {
  string id;
  string name;
  string birthday;
  string role;
  string salary;
  string date_of_employment;
  string email;
  string address;
  string grade;
} database[empolyee_num];

char selection_menu()
{
	char choice;

	// print selection meun
	cout << "**************************************" << endl;
	cout << "* Welcome to Staff Management System *" << endl;
  cout << "**************************************" << endl;
	cout << "1. Import New Employee's Information" << endl;
	cout << "2. Search for Employee's Information" << endl;
	cout << "3. Edit Employee's Information" << endl;
	cout << "4. Search for Employee's Salary" << endl;
	cout << "5. Search for Employee's grade" << endl;
	cout << "6. Delete Resigned Employee's Information" << endl;
	cout << "0. Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}
// main program
int main()
{
	char choice = selection_menu();
	while (choice != '0')
	{
		switch (choice)
		{
			case '1':
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

			default:
				cout << "Invalid input!" << endl;
		}
		choice = selection_menu();
	}

	cout << "Goodbye!" << endl << endl;


	return 0;
}

// import information program
int import_information() {
  int i, j, k, pos;
  ifstream input;
  string input_data = "database.txt", line, temp;

  input.open(input_data);
  // check input file exists
  if (input.is_open()) {
    i = 0;
    // get line from input file
    while (getline(input, line)) {
      temp = "";
      k = 0;
      // loop over line
      for (j = 0; j < line.length(); j++) {
        // insert parameters
        if (line.at(j) != ',' && j != line.length()-1) {
          temp.push_back(line.at(j));
        }
        else {
          switch (k) {
            case 0: { database[i].id = temp;
                      break;
                    } 
            case 1: { database[i].name = temp;
                      break;
                    } 
            case 2: { database[i].birthday = temp;
                      break;
                    } 
            case 3: { database[i].role = temp;
                      break;
                    } 
            case 4: { database[i].salary = temp;
                      break;
                    } 
            case 5: { database[i].date_of_employment = temp;
                      break;
                    } 
            case 6: { database[i].email = temp;
                      break;
                    } 
            case 7: { database[i].address = temp;
                      break;
                    } 
            case 8: { database[i].grade = temp;
                      break;
                    } 
          }
          temp = "";
          k++;
        }
      }
      i++;
    }
  }
  else {
    cout << database << " does not exist." << endl;
  }

  return 0;
}
