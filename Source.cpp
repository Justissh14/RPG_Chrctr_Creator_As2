#include <iostream> // the standard library
#include <string> // strings
#include <vector> // vectors for storage
#include <cstdlib> // for rand()
#include <ctime> // for time()
#include <chrono> // also for time but different because it's for wait call functions
#include <thread> // this is for the chrono wait function

using namespace std; // so I can be lazy I defined these early on to save time typing xD
using namespace std::chrono;
using std::cout;
using std::cin;
using std::endl;
// Character class
class Character {
public:
    string name;
    int age;
    Character(string n, int a) : name(n), age(a) {} // still needa fix the constructor
    Character() = default;
};
// Lineage, class. Holds Lineage info 
class Lineage {
public:
    int Bagger;
    int Noble;
    int Monster;
    int Assassin;

    Lineage(int B, int N, int M, int A) : Bagger(B), Noble(N), Monster(M), Assassin(A) {}
};
// Player Class, class. Hold the Class list/ info
class Class {
public:
    int Wizard;
    int Barbarian;
    int Monk;
    int Rogue;
    Class(int W, int B, int M, int R) : Wizard(W), Barbarian(B), Monk(M), Rogue(R) {}

    Class() = default;
};

// Main Menu [1] Function
void LineageMenu() { // this is the main display menu that the player will see and then be prompted to input a number that correlates to the lineage listed below
    cout << "__________" << endl;
    cout << "[1]Bagger " << endl;
    cout << "[2]Noble " << endl;
    cout << "[3]Monster " << endl;
    cout << "[4]Assassin " << endl;
    cout << "[5]-Quit-" << endl;
    cout << "-----------" << endl;
};
// Sub Menu [2] Function
void ClassMenu() {
    cout << "__________" << endl;
    cout << "[1]Wizard " << endl;
    cout << "[2]Barbarian " << endl;
    cout << "[3]Monk " << endl;
    cout << "[4]Rogue " << endl;
    cout << "[5]<Back " << endl;
    cout << "----------" << endl;
}

int Exit_Answr;

int main() {
    cout << "RPG_Chrctr_Creator v1.0\n\n";
    cout << "Welcome:" << endl;
    cout << "What is your name?: " << endl;

    string name;
    int age;

    cin >> name;
    cout << "What is your age?: " << endl;
    cin >> age;

    Character character(name, age); // properly using the constructor

    cout << "\nHello there! " << character.name << " What is your Ancestry?: " << endl;
    LineageMenu();

    /* std::srand(std::time(0));
       cout << (std::rand() % 8) + 1 << endl; */ // random number between 1-8

    // Exit loop choices
    int choice,choice2 = 0;
    


    do {
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\n Ah yes, a poor Bagger indeed\n";
            ClassMenu();
            break;
        case 2:
            cout << "\n Noble indeed, great things are to be expected of you\n";
            break;
        case 3:
            cout << "\n You're a Monster!, selfish and ugly yet dangerous!\n";
            break;
        case 4:
            cout << "\n An Assassin is sneaky and agile, use this info wisely\n";
            break;
        case 5:
            cout << "\nAre you sure you want to Quit?\n";
            cout << "([1]y / [2]n)?" << endl;
            cin >> Exit_Answr;
            if (Exit_Answr == 1) {
                cout << "\n Exiting game, goodbye!\n ";
                return 0;
            }
            else if (Exit_Answr == 2) {
                cout << "\n You have chosen to stay\n ";
                std::this_thread::sleep_for(chrono::seconds(2));
                continue;
            }
            else {
                cout << "Invalid option, please try again" << endl;
            }
            break;
        default:
            cout << "Invalid option, please try again" << endl;
        }
    } while (choice != 5);
    ClassMenu();
   int Exit_Answr = 0;
    
    do {
        cin >> choice2;

        switch (choice2) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            cout << "\nAre you sure you want to Quit?\n";
            cout << "([1]y / [2]n)?" << endl;
            cin >> Exit_Answr;
            if (Exit_Answr == 1) {
                cout << "\n Exiting game, goodbye!\n ";
                return 0;
            }
            else if (Exit_Answr == 2) {
                cout << "\n You have chosen to stay\n ";
                std::this_thread::sleep_for(chrono::seconds(2));
                continue;
            }
            else {
                cout << "Invalid option, please try again" << endl;
            }
            break;
        default:
            cout << "Invalid option, please try again" << endl;

        }
        

    } while (choice2 != 5);

    return 0;
}



