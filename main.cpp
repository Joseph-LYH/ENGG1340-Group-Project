// import libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
} database[50];

// main program
int main() {
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