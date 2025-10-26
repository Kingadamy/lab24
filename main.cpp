#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;


int select_goat(list<Goat> trip){
    cout << "Which goat would you like to delete? (pick a number) \n";
    int count = 1;
    for(auto goat : trip) { // this loop goes through each goat in the list
        cout << " [" << count++ << "] " << // number the goats
            goat.get_name() <<
            " (" << goat.get_age() << ", " 
             << goat.get_color() << ")\n";
    }

    int choice; // get user choice
    cin >> choice;
    return choice;

}

void delete_goat(list<Goat> &trip) {
    if(trip.empty()) { // check if the list is empty
        cout << "No goats to delete.\n";
        return;
    }

    int selection = select_goat(trip); // get the user's selection

    // see if choice exists
    if(selection < 1 || selection > trip.size()) {
        cout << "Invalid selection. \n";
        return;
    }

    // iterate to the selected goat
    auto it = trip.begin();
    advance(it, selection - 1); // go to position we want to delete

    cout << "Deleted: " << it->get_name() << endl; // show which goat is deleted
    trip.erase(it); // remove the goat from the list
}
                        


void add_goat(list<Goat> &trip, string names[], string colors[]) { // create a new goat with random name, color, age
    int name_used = rand() % SZ_NAMES; // select random name from the names array
    int color_used = rand() % SZ_COLORS; // select random color from the colors array
    int age = rand() % (MAX_AGE + 1); // select random age from 0 to MAX_AGE

    Goat new_goat; // here we create the new goat
    new_goat.set_name(names[name_used]); // set the name
    new_goat.set_color(colors[color_used]); // set the color
    new_goat.set_age(age); // set age

    trip.push_back(new_goat); // add the new goat to the list

    cout << "Added goat: " << new_goat.get_name() << ", Age: " << new_goat.get_age()
         << ", Color: " << new_goat.get_color() << endl;
}

void display_trip(list<Goat> trip) { // display all goats in the trip
    if(trip.empty()) { // check if the list is empty
        cout << "No goats in the trip.\n";
        return;
    }

    int count = 1; // set count to one 
    cout << "Goats in the trip:\n";
    for(auto goat : trip) { // this loop goes through each goat in the list
        cout << " [" << count++ << "]" << // number the goats
             goat.get_name() <<
            " (" << goat.get_age() << ", "  << 
             goat.get_color() << ")\n";
}
}


int main_menu() {
 cout << "*** GOAT MANAGER 3001 ***\n"
      << "[1] Add a goat\n"
      << "[2] Delete a goat\n"
      << "[3] List goats\n"
      << "[4] Quit\n"
      << "Choice --> ";

      int choice;
        cin >> choice;
        return choice;
}
      




int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> trip; // create the list 

    while(true) {
        int choice = main_menu(); // show the menu and get user choice

       if (choice == 1) {
           add_goat(trip, names, colors);
       }
       else if (choice == 2) {
           delete_goat(trip);
       }
       else if (choice == 3) {
           display_trip(trip);
       }
       else if (choice == 4) {
           cout << "Exiting Goat Manager 3001.\n";
           break;
       }
       else {
           cout << "Invalid choice.\n";
       }
    }

    return 0;
}

