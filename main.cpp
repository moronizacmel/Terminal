#include <iostream>
using namespace std;

int main() {


    int option;


    while (true) {
        cout << ""<< endl;
        cout << "Select an option"<< endl;
        cout << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Write" << endl;
        cout << "4. Delete" << endl;
        cout << "-----------------------------" << endl;
        cin >> option;
        cout << ""<< endl;
        
        switch (option) {
            case 1:
                cout << "Creating..." << endl;
                break;

            case 2:
                cout << "Reading..." << endl;
                break;

            case 3:
                cout << "Writing..." << endl;
                break;

            case 4:
                cout << "Deleting..." << endl;
                break;

            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }
    }


    
    
    return 0;
}
