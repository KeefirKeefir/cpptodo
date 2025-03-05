#include <string>
#include <iostream>
#include <chrono>
#include <nlohmann/json.hpp>
#include <fstream>

#include "typedefs.h"

using namespace std;
using namespace nlohmann;

const string NotStarted = "not started";
const string InProgress = "in progress";
const string Complete = "complete";


struct Task {
    string title;
    string desc;
    string stage;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Task, title, desc, stage);
};

bool getYN(const string &prompt) {
    string res;
    while (true) {
        cout << prompt << " Y/N: ";
        cin >> ws;
        getline(cin, res);
        if (res == "y" or res == "Y") return true;
        if (res == "n" or res == "N") return false;
        cout << "invalid, Y/N: " << endl;
    }
}

void baseinfo() {
    string input;
    cout << "Enter your name: ";
    getline(cin, input);
    cout << "Hello, " << input << endl;

    i32 number;
    cout << "Number: ";

    while (!(cin >> number)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, Number: ";
    }
    cout << "You entered: " << number << endl;

    if (getYN("Want to continue?")) {
        cout << "Cont.." << endl;
    }
    else {
        cout << "Exiting.." << endl;
    }
}

void jsonstuff() {
    json jsonData;
    jsonData["name"] = "John Doe";
    jsonData["age"] = 30;
    jsonData["isStudent"] = false;

    // Write JSON to a file
    ofstream outFile("data.json");
    if (!outFile) {
        cerr << "Error opening file fo writing\n";
        return;
    }

    outFile << jsonData.dump(4); // Pretty print with 4-space indentation
    outFile.close();

    // Read JSON from a file
    ifstream inFile("data.json");
    if (!inFile) { // Check if the file was successfully opened
        cerr << "Error opening file for reading\n";
        return;
    }

    json readData;
    inFile >> readData;
    inFile.close();

    // Access data
    string name = readData["name"];
    int age = readData["age"];
    bool isStudent = readData["isStudent"];

    cout << "Name: " << name << "\nAge: " << age << "\nStudent: " << boolalpha << isStudent << endl;

}


void addtask(const json &data) {
    json jtask = data;
    ofstream ofile("tasks.json");
    ofile << jtask.dump(4);
    ofile.close();
}

i32 main() {
    Task task = {"Eat food", "go to food and eat it", NotStarted};
    Task task2 = {"Eat food2", "go to food and eat it2", NotStarted};
    addtask(task);
    addtask(task2);
}
