// mecanum_sim.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ===== Function Prototypes =====
void displayMenu();
int getUserChoice();
//int checkCarLog(bool &retFlag); 
bool checkCarLog(ofstream &logFile); 
void moveForward(ofstream &);
void moveBackward(ofstream &);
void turnLeft(ofstream &);
void turnRight(ofstream &);
void activateCamera(ofstream &);
void logAction(ofstream &, const string &);
void readConfigFile(string &speed, string &cameraMode); // pass-by-reference for outputs

int main() {
    string speed = "50";       // default if config missing
    string cameraMode = "OFF"; // default if config missing
    ofstream logFile;

    // TODO 1: Read configuration data from file using readConfigFile(speed, cameraMode)
    // Hint: open "config.txt", parse lines like "key=value" and set the variables.
    readConfigFile(speed, cameraMode);

    // TODO 2: Open "car_log.txt" for writing and verify it opened successfully
    // If open fails, print an error and exit gracefully.
    if (!checkCarLog(logFile)) return 0;

    cout << "Loaded config: speed=" << speed
         << ", camera_mode=" << cameraMode << "\n";

    int choice;
    do {
        displayMenu();
        choice = getUserChoice();

        // TODO 3: Use a switch statement to handle user choice
        switch (choice)
        {
        case 1:
            moveForward(logFile);
            break;

        case 2:
            moveBackward(logFile);
            break;

        case 3:
            turnLeft(logFile);
            break;

        case 4:
            turnRight(logFile);
            break;

        case 5:
            activateCamera(logFile);
            break;

        case 6:
            cout << "Exiting..." << "\n";
            break;
        
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != 6); // Exit when user selects 6
    logFile.close();
}


// ===== Function Definitions =====
void displayMenu() {
    cout << "\n--- MECANUM CAR MENU ---\n";
    cout << "1. Move Forward\n";
    cout << "2. Move Backward\n";
    cout << "3. Turn Left\n";
    cout << "4. Turn Right\n";
    cout << "5. Activate Camera\n";
    cout << "6. Exit\n";
}

int getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    if (!(cin >> choice)) {
        // simple recovery
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }
    return choice;
}

void moveForward(ofstream &logFile) {
    cout << "Moving forward...\n";
    logAction(logFile, "Move Forward");
}

void moveBackward(ofstream &logFile) {
    // TODO 5: Print a message and log "Move Backward"
    // Example: cout << "Moving backward...\n"; logAction(logFile, "Move Backward");
    cout << "Moving backward...\n"; logAction(logFile, "Move Backward");
}

void turnLeft(ofstream &logFile) {
    // TODO 6: Print a message and log "Turn Left"
    cout << "Turn Left\n"; logAction(logFile, "Turn Left");
}   

void turnRight(ofstream &logFile) {
    // TODO 7: Print a message and log "Turn Right"
    cout << "Turn Right\n"; logAction(logFile, "Turn Right");
}

void activateCamera(ofstream &logFile) {
    // TODO 8: Print a message and log "Activate Camera"
    cout << "Activate Camera\n"; logAction(logFile, "Activate Camera");
}

void logAction(ofstream &logFile, const string &action) {
    // TODO 9: Write the action string to the log file, one action per line
    // Example: logFile << action << std::endl;
    logFile << action << std::endl;
}

void readConfigFile(string &speed, string &cameraMode) {
    ifstream config("config.txt");
    if (!config) {
        cout << "No configuration file found; using defaults.\n";
        return;
    }
    string line;
    while (getline(config, line)) {
        // Very simple parsing: expect lines like "key=value"
        size_t eq = line.find('='); //note size_t is a unsigned integer type, will scale to 32-bit or 64-bit
        if (eq == string::npos) continue;
        string key = line.substr(0, eq);
        string value = line.substr(eq + 1);
        if (key == "speed") speed = value;
        else if (key == "camera_mode") cameraMode = value;
    }
    // Files (i.e., file stream objects) should be passed by reference per the slides.
    // This function uses pass-by-reference to return multiple values.  :contentReference[oaicite:10]{index=10}
}

bool checkCarLog(ofstream &logFile) {
    logFile.open("car_log.txt");

    if (!logFile)
    {
        cout << "Unable to open car logging file; closing program\n";
        return false;
    }

    cout << "CarLog File verified\n";
    return true;
}