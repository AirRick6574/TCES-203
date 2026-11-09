// CarPollingLoop.cpp
// TCES 203 – Looping practice (incomplete starter version)
// Apply Chapter 5: while loops, input validation, counters, running totals, sentinels

#include <iostream>
using namespace std;

#define DISTANCE_MAX 200
#define DISTANCE_MIN 0
#define MAX_BAT 100

int main() {
    // 1. Declare counters and variables
    int totalCycles = 0;
    int safeCycles = 0;
    int emergencyStops = 0;

    int distanceToObstacleCm = 0;
    int batteryPercent = 0;
    char driveMode = 'S';

    cout << "=== Car Polling Loop Simulation ===" << endl;

    // 2. Main polling loop (TODO: replace true with correct condition or sentinel check)
    while (distanceToObstacleCm != -1) {
        
        //Distance
        cout << "Enter distance (0–200 cm, –1 to quit): ";
        cin >> distanceToObstacleCm;
        if (distanceToObstacleCm == -1) {
            continue;
        }
        
        while (distanceToObstacleCm < DISTANCE_MIN || distanceToObstacleCm > DISTANCE_MAX){
            cout << "Not within range (0-200), try again: ";
            cin >> distanceToObstacleCm;
        }

        //Battery
        cout << "Enter battery level (%): ";
        cin >> batteryPercent;
        while (batteryPercent < DISTANCE_MIN || batteryPercent >= MAX_BAT){
            cout << "Not within range (0-100), try again: ";
            cin >> batteryPercent;
        }


        //Drive Mode
        int check = 0;

        cout << "Enter drive command (F/B/L/R/S): "; 
        cin >> (driveMode);
        driveMode = toupper(driveMode);
        while (check == 0)
        {
            switch (driveMode){
                case 'F':
                    check = 1;
                    break;
                case 'B':
                    check = 1;  
                    break;
                case 'L':
                    check = 1;  
                    break;
                case 'R':
                    check = 1;
                    break;
                case 'S':
                    check = 1;
                    break;
                default:
                    cout << "Incorrect Response, try again: ";
                    cin >> (driveMode);
                    driveMode = toupper(driveMode);
                    break;

            }
        }
        
        // TODO: ask for distance and validate using while loop (Section 5.2)
        // Sentinel: if user enters -1, break the loop

        // TODO: ask for battery level and validate (must be 0–100)

        // TODO: ask for drive command (F/B/L/R/S) and validate with while loop

        // Once data is valid, increment totalCycles

        // 3. Compute safety flags (TODO)
        //bool isPathClear = /* TODO */;
        //bool isBatteryOK = /* TODO */;
        //bool canMove = /* TODO */;

        // 4. Decision logic (TODO: use if/else)
        // If not canMove → emergency stop
        // Else print action based on driveMode

        // 5. Update counters (safeCycles, emergencyStops)

        // 6. Motor mapping (TODO: use switch on driveMode)
        // Print simulated wheel directions for L298N
    }

    // 7. After loop ends, print final report (TODO)
    // Show totalCycles, safeCycles, emergencyStops, and percentage of safe cycles

    cout << "=== End of Simulation ===" << endl;
    return 0;
}