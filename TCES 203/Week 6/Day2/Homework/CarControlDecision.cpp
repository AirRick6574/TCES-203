
#include <iostream>
using namespace std;

int main() {
    // 1. Declare variables
    int distanceToObstacleCm = 0;
    int batteryPercent = 0;
    char driveMode = 'S';   // F, B, L, R, S

    // 2. Read input from user
    cout << "Enter distance to obstacle (cm 0-200): ";
    cin >> distanceToObstacleCm;

    cout << "Enter battery level (% 0-100): ";
    cin >> batteryPercent;

    cout << "Enter drive command (F=forward, B=backward, L=left, R=right, S=stop): ";
    cin >> driveMode;

    // 3. Validate input
    // TODO: use relational + logical operators (|| and &&) to validate
    
    // If distance is NOT between 0 and 200 → print error and return
    if ((distanceToObstacleCm < 0) || (distanceToObstacleCm > 200)) {
        cout << "Error: distance out of range." << endl;
        return 0;
    }

    // If battery is NOT between 0 and 100 → print error and return
    if ((batteryPercent < 0) || (batteryPercent > 100)) {
        cout << "Error: battery level out of range." << endl;
        return 0;
    }

    // If command is NOT one of F,B,L,R,S → print error and return
    if (driveMode != 'F' && driveMode != 'B' &&
               driveMode != 'L' && driveMode != 'R' &&
               driveMode != 'S') {
        cout << "Error: invalid drive command." << endl;
        return 0;
    }

    // 4. Safety flags
    // TODO: create flags using expressions
    bool isPathClear = distanceToObstacleCm >= 25;
    bool isBatteryOK = batteryPercent >= 20;
    bool canMove = (isPathClear && isBatteryOK);

    cout << "Path clear: " << isPathClear << endl;
    cout << "Battery OK: " << isBatteryOK << endl;

    // 5. Decision logic (if/else)
    // TODO: implement the chain exactly as in the activity:
    // if cannot move → emergency stop and force S
    // else if F or B → print move
    // else if L or R → print strafe
    // else → unknown
    if (!canMove) {
        cout << "EMERGENCY STOP: unsafe to move!" << endl;
        driveMode = 'S';   // force stop
    } else if (driveMode == 'F' || driveMode == 'B') {
        // print moving forward/backward
        cout << "Moving ";
        if (driveMode == 'F') {
            cout << "forward" << endl;
        } else {
            cout << "backward" << endl;
        }
    } else if (driveMode == 'L' || driveMode == 'R') {
        cout << "Strafing ";
        if ( driveMode == 'L') {
            cout << "left" << endl;
        } else {
            cout << "right" << endl;
        }
    } else {
        cout << "Unknown command." << endl;
    }

    // 6. Motor mapping (switch)
    // TODO: complete switch with cases F, B, L, R, S
    cout << endl << "Motor mapping:" << endl;
    switch (driveMode) {
        case 'F':
            // TODO: print “All wheels: FORWARD”
            cout << "All Wheels: Forward" << endl;
            break;
        case 'B':
            // TODO: print “All wheels: BACKWARD”
            cout << "All Wheels: Backward" << endl;
            break;
        case 'L':
            // TODO: print left side BACKWARD, right side FORWARD
            cout << "Left Side: Backward" << endl;
            cout << "Right Side: Forward" << endl;
            break;
        case 'R':
            // TODO: print left side FORWARD, right side BACKWARD
            cout << "Right Side: Backward" << endl;
            cout << "Left Side: Forward" << endl;
            break;
        case 'S':
            // TODO: print “All wheels: STOP”
            cout << "All Wheels: Stop" << endl;
            break;
        default:
            cout << "No mapping for this command." << endl;
            break;
    }

    cout << "Program finished." << endl;
    return 0;
}