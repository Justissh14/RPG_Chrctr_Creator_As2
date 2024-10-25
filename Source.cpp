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
    int Samurai;
    Lineage(int B, int N, int M, int A, int S) : Bagger(B), Noble(N), Monster(M), Assassin(A), Samurai(S) {}
};

// Player Class. Holds the Class list/info
class Class {
public:
    int Wizard;
    int Barbarian;
    int Monk;
    int Rogue;
    int Wraith;
    Class(int W, int B, int M, int R, int WR) : Wizard(W), Barbarian(B), Monk(M), Rogue(R), Wraith(WR) {}
    Class() = default;
};

// Main Menu [1] Function
void LineageMenu() { // this is the main display menu that the player will see and then be prompted to input a number that correlates to the lineage listed below
    cout << "__________" << endl;
    cout << "[1]Bagger " << endl; // ++2 Wis
    cout << "[2]Noble " << endl; // ++3 CHA
    cout << "[3]Monster " << endl; // ++5 STM
    cout << "[4]Assassin " << endl; // ++3 SPD
    cout << "[5]Samurai " << endl; // ++1 CON
    cout << "[6]-Exit- " << endl;
    cout << "-----------" << endl;
}

// Sub Menu [2] Function
void ClassMenu() {
    cout << "__________" << endl;
    cout << "[1]Wizard " << endl; // ++3 MAG
    cout << "[2]Barbarian " << endl; // ++4 STR
    cout << "[3]Monk " << endl; // ++2 CHA
    cout << "[4]Rogue " << endl; // ++2 MAG
    cout << "[5]Wraith " << endl; // ++6 STM
    cout << "[6]-Exit- " << endl;
    cout << "----------" << endl;
}

// Created Character Attributes
void StatsMenu(int Str_bonus, int Mag_bonus, int Stm_bonus, int Spd_bonus, int Int_bonus, int Wis_bonus, int Con_bonus, int Cha_bonus) {
    int min = 1;
    int max = 15;
    int Str = rand() % (max - min + 1) + min + Str_bonus;
    int Mag = rand() % (max - min + 1) + min + Mag_bonus;
    int Stm = rand() % (max - min + 1) + min + Stm_bonus;
    int Spd = rand() % (max - min + 1) + min + Spd_bonus;
    int Int = rand() % (max - min + 1) + min + Int_bonus;
    int Wis = rand() % (max - min + 1) + min + Wis_bonus;
    int Con = rand() % (max - min + 1) + min + Con_bonus;
    int Cha = rand() % (max - min + 1) + min + Cha_bonus;

    cout << "___________" << endl;
    cout << "Str: " << Str << " Mag: " << Mag << endl;
    cout << "Stm: " << Stm << " Spd: " << Spd << endl;
    cout << "Int: " << Int << " Wis: " << Wis << endl;
    cout << "Con: " << Con << " Cha: " << Cha << endl;
    cout << "-----------" << endl;
}

// Created Character Information
void SubStatsMenu(const string& name, const string& Lineage_choice, const string& Class_choice, int age) {
    cout << "___________" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Lineage: " << Lineage_choice << endl;
    cout << "Class: " << Class_choice << endl;
    cout << "-----------" << endl;
}
int choice3;
// My Main Function
int main() {
    do {
        cout << "RPG_Chrctr_Creator v1.0\n\n";
        cout << "Welcome:\n" << endl;
        cout << "What is your name?: " << endl;
        srand(time(0));
        string name;
        string Class_choice;
        string Lineage_choice;
        int age;
        cin >> name;
        cout << "What is your age?: " << endl;
        cin >> age;
        Character character(name, age); // using the constructor
        cout << "\nHello there! " << character.name << endl;
        cout << "\n| Choose Your Lineage |\n";
        LineageMenu();

        //choices
        int choice = 0, choice2 = 0;
        int Exit_Answr = 0;
        int Str_bonus = 0, Mag_bonus = 0, Stm_bonus = 0, Spd_bonus = 0, Int_bonus = 0, Wis_bonus = 0, Con_bonus = 0, Cha_bonus = 0;

        do {
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "\n Ah yes, a poor Bagger indeed" << "(+2 Wis)\n";
                Wis_bonus += 2;
                Lineage_choice = "Bagger";
                choice = 6;
                continue;
            case 2:
                cout << "\n Noble indeed, great things are to be expected of you" << "(+3 Cha)\n";
                Cha_bonus += 3;
                Lineage_choice = "Noble";
                choice = 6;
                continue;
            case 3:
                cout << "\n You're a Monster!, selfish and ugly yet dangerous!" << "(+5 Stm)\n";
                Stm_bonus += 5;
                Lineage_choice = "Monster";
                choice = 6;
                continue;
            case 4:
                cout << "\n An Assassin is sneaky and agile, use this info wisely" << "(+3 Spd)\n";
                Spd_bonus += 3;
                Lineage_choice = "Assassin";
                choice = 6;
                continue;
            case 5:
                cout << "\n Your Samurai ancestors will help carry you to victory!" << "(+1 Con)\n";
                Con_bonus += 1;
                Lineage_choice = "Samurai";
                choice = 6;
                continue;
            case 6:
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
        } while (choice != 6);

        cout << "\n| Now Choose Your Class |\n";
        ClassMenu();

        do {
            cin >> choice2;
            switch (choice2) {
            case 1:
                cout << "Your Class is: Wizard" << "(+3 Mag)\n ";
                Mag_bonus += 3;
                Class_choice = "Wizard";
                choice2 = 6;
                continue;
            case 2:
                cout << "Your Class is: Barbarian" << "(+4 Str)\n ";
                Str_bonus += 4;
                Class_choice = "Barbarian";
                choice2 = 6;
                continue;
            case 3:
                cout << "Your Class is: Monk" << "(+2 Cha)\n ";
                Cha_bonus += 2;
                Class_choice = "Monk";
                choice2 = 6;
                continue;
            case 4:
                cout << "Your Class is: Rogue" << "(+2 Mag)\n ";
                Mag_bonus += 2;
                Class_choice = "Rogue";
                choice2 = 6;
                continue;
            case 5:
                cout << "Your Class is: Wraith" << "(+6 Stm)\n ";
                Stm_bonus += 6;
                Class_choice = "Wraith";
                choice2 = 6;
                continue;
            case 6:
                cout << "\nAre you sure you want to Quit?\n";
                cout << "([1]y / [2]n)?" << endl;
                cin >> Exit_Answr;
                if (Exit_Answr == 1) {
                    cout << "\n Exiting game, goodbye!\n ";
                    return 0;
                }
                else if (Exit_Answr == 2) {
                    cout << "\n You have chosen to stay\n";
                    std::this_thread::sleep_for(chrono::seconds(2));
                    continue;
                }
                else {
                    cout << "Invalid option, please try again" << endl;
                }
                continue;
            default:
                cout << "Invalid option, please try again" << endl;
            }
        } while (choice2 != 6);

        // Final msg after player creates character
        cout << "\n| This is The Character You Created |\n" << endl;

        // Player's input final results
        SubStatsMenu(character.name, Lineage_choice, Class_choice, character.age);
        cout << "\n| Your Character Attributes |" << endl;
        StatsMenu(Str_bonus, Mag_bonus, Stm_bonus, Spd_bonus, Int_bonus, Wis_bonus, Con_bonus, Cha_bonus);

        //Keep or Create-New prompt
        cout << "\nDo you like your Character or do you want to restart?\n";
        cout << "[1]Keep / [2]Restart\n";
        
        cin >> choice3;
        switch (choice3) {
        case 1:
            return 0;
        case 2:
            break;
        default:
            cout << "Invalid option, please input-[1]-to keep or -[2]- to Restart" << endl;
            break;
        }

    } while (choice3 != 1);

    return 0;
}







