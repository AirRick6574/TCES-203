#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

int main() {
    // Chapter 3 Activity: Expressions and Interactivity

    // 1) Read pilot and drone info
    cout << "Pilot name: ";
    string pilot;
    getline(cin, pilot);

    cout << "Battery capacity (mAh): ";
    int capacity_mAh;
    cin >> capacity_mAh;

    cout << "Average current draw during flight (mA): ";
    int draw_mA;
    cin >> draw_mA;

    // Clear leftover newline before next getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Location/mission label (one short line): ";
    string mission;
    getline(cin, mission);

    // 2) Compute estimated flight time in minutes using floating-point math
    // time_minutes = (capacity_mAh / draw_mA) * 60, but force floating division with static_cast
    double time_minutes = static_cast<double>(capacity_mAh) / static_cast<double>(draw_mA) * 60.0;

    cout << "Estimated distance flown (meters): ";
    int dist_m;
    cin >> dist_m;
    double time_seconds = time_minutes * 60.0;
    double speed_mps = (time_seconds > 0.0) ? static_cast<double>(dist_m) / time_seconds : 0.0;
    double speed_kph = speed_mps * 3.6;


    // 4) Show formatted output with fixed and setprecision
    cout << fixed;
    cout << "Pilot: " << pilot << "\n";
    cout << "Mission: " << mission << "\n";
    cout << setprecision(1)
        << "Estimated flight time (min): " << time_minutes << "\n";
    cout << setprecision(2)
        << "Avg speed: " << speed_mps << " m/s  (" << speed_kph << " km/h)\n";


    // 5) Combined assignment: simulate 5% higher draw
    int draw_loaded = draw_mA;
    draw_loaded += static_cast<int>(draw_loaded * 0.05); // +5%
    double time_minutes_loaded =
        static_cast<double>(capacity_mAh) / static_cast<double>(draw_loaded) * 60.0;
    cout << setprecision(1)
        << "Flight time with +5% draw (min): " << time_minutes_loaded << "\n";


    // 6) Named constant: 15% reserve
    const double RESERVE_FRAC = 0.15;
    double usable_mAh = capacity_mAh * (1.0 - RESERVE_FRAC);
    double time_minutes_reserve =
        usable_mAh / static_cast<double>(draw_mA) * 60.0;
    cout << setprecision(1)
        << "Reserve-aware time (15% held back) (min): " << time_minutes_reserve << "\n";


    // 7) Overflow awareness mini-demo (safe illustration)
    short int nearMax = 32767;
    cout << "short nearMax (before) = " << nearMax << "\n";
    nearMax = nearMax + 1; // may wrap
    cout << "short nearMax (after +1) = " << nearMax << "  <-- overflow demo\n";


    return 0;
}