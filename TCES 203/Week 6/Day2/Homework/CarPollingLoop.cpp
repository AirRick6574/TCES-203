// CarPollingLoop.cpp
// TCES 203 – Looping practice (incomplete starter version)
// Apply Chapter 5: while loops, input validation, counters, running totals, sentinels

#include <iostream>
using namespace std;

#define DISTANCE_MAX 200
#define DISTANCE_MIN 0
#define MAX_BAT 100
#define MIN_BAT 0

int main()
{
    // 1. Declare counters and variables
    int totalCycles = 0;
    int safeCycles = 0;
    int emergencyStops = 0;

    int distanceToObstacleCm = 0;
    int batteryPercent = 0;
    char driveMode = 'S';

    cout << "=== Car Polling Loop Simulation ===" << endl;

    // 2. Main polling loop (TODO: replace true with correct condition or sentinel check)
    while (distanceToObstacleCm != -1)
    {

        // Distance
        cout << "Enter distance (0-200 cm, -1 to quit): ";
        cin >> distanceToObstacleCm;

        // Validate distance
        while ((distanceToObstacleCm < DISTANCE_MIN ||
                distanceToObstacleCm > DISTANCE_MAX) &&
               distanceToObstacleCm != -1)
        {

            cout << "Not within range (0-200), try again: ";
            cin >> distanceToObstacleCm;
        }

        // Exit if sentinel is entered
        if (distanceToObstacleCm == -1)
        {
            break;
        }

        // Battery
        cout << "Enter battery level (%): ";
        cin >> batteryPercent;

        // Validate battery
        while (batteryPercent < MIN_BAT || batteryPercent > MAX_BAT)
        {
            cout << "Not within range (0-100), try again: ";
            cin >> batteryPercent;
        }

        // Drive Mode
        cout << "Enter drive command (F/B/L/R/S): ";
        cin >> driveMode;
        driveMode = toupper(driveMode);

        // Validate drive command
        while (driveMode != 'F' && driveMode != 'B' &&
               driveMode != 'L' && driveMode != 'R' &&
               driveMode != 'S')
        {

            cout << "Invalid command, try again: ";
            cin >> driveMode;
            driveMode = toupper(driveMode);
        }

        //Safe Cycle Check
        bool isPathClear = (distanceToObstacleCm >= 25);
        bool isBatteryOK = (batteryPercent >= 20);
        bool canMove = (isPathClear && isBatteryOK);

        // Check safety conditions first
        if (!(isPathClear || isBatteryOK || canMove))
        {
            emergencyStops++;
            cout << "EMERGENCY STOP - unsafe cycle." << endl;
            cout << "Left side: STOP" << endl;
            cout << "Right side: STOP" << endl;
        }
        else
        {
            safeCycles++;

            // Driving Decision and Motor Mapping
            switch (driveMode)
            {
            case 'F': // Forward
                cout << "Decision: MOVE FORWARD" << endl;
                cout << "Motor mapping:" << endl;
                cout << "Left side: FORWARD" << endl;
                cout << "Right side: FORWARD" << endl;
                break;

            case 'B': // Backward
                cout << "Decision: MOVE BACKWARD" << endl;
                cout << "Motor mapping:" << endl;
                cout << "Left side: BACKWARD" << endl;
                cout << "Right side: BACKWARD" << endl;
                break;

            case 'L': // Left
                cout << "Decision: TURN LEFT" << endl;
                cout << "Motor mapping:" << endl;
                cout << "Left side: BACKWARD" << endl;
                cout << "Right side: FORWARD" << endl;
                break;

            case 'R': // Right
                cout << "Decision: TURN RIGHT" << endl;
                cout << "Motor mapping:" << endl;
                cout << "Left side: FORWARD" << endl;
                cout << "Right side: BACKWARD" << endl;
                break;

            case 'S': // Stop
                cout << "Decision: STOP" << endl;
                cout << "Motor mapping:" << endl;
                cout << "Left side: STOP" << endl;
                cout << "Right side: STOP" << endl;
                break;
            }
        }

        totalCycles++;
    }

    //Final Report
    cout << "\n=== Final Report ===" << endl;
    cout << "Safe Cycles: " << safeCycles << endl;
    cout << "Emergency Stops: " << emergencyStops << endl;
    cout << "Safe Cycle Percentage: " << batteryPercent << "%" << endl;

    cout << "=== End of Simulation ===" << endl;
    return 0;
}