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
    Character(string n, int a) : name(n), age(a) {} // fixed the constructor
    Character() = default;
};

// Lineage class. Holds Lineage info 
class Lineage {
public:
    int Bagger;
    int Noble;
    int Monster;
    int Assassin;

    Lineage(int B, int N, int M, int A) : Bagger(B), Noble(N), Monster(M), Assassin(A) {}
};

// Player Class. Holds the Class list/info
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
    cout << "[5]-Exit- " << endl;
    cout << "-----------" << endl;
}

// Sub Menu [2] Function
void ClassMenu() {
    cout << "__________" << endl;
    cout << "[1]Wizard " << endl;
    cout << "[2]Barbarian " << endl;
    cout << "[3]Monk " << endl;
    cout << "[4]Rogue " << endl;
    cout << "[5]-Exit- " << endl;
    cout << "----------" << endl;
}

void StatsMenu(const string& name, int age, int choice, int choice2) {
    cout << "___________" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Lineage: " << choice << endl;
    cout << "Class: " << choice2 << endl;
    cout << "-----------" << endl;
}

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

    int choice = 0, choice2 = 0;
    int Exit_Answr = 0;

    do {
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\n Ah yes, a poor Bagger indeed\n";
            cout << "Hello World!" << endl;
            choice = 5;
            continue;
        case 2:
            cout << "\n Noble indeed, great things are to be expected of you\n";
            continue;
        case 3:
            cout << "\n You're a Monster!, selfish and ugly yet dangerous!\n";
            continue;
        case 4:
            cout << "\n An Assassin is sneaky and agile, use this info wisely\n";
            continue;
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

    do {
        cin >> choice2;
        switch (choice2) {
        case 1:
            cout << "Wizard\n ";
            choice2 = 5;
            continue;
        case 2:
            cout << "Barbarian\n ";
            continue;
        case 3:
            cout << "Monk\n ";
            continue;
        case 4:
            cout << "Rogue\n ";
            continue;
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

    StatsMenu(character.name, character.age, choice, choice2);

    return 0;
}




