#include <iostream>
#include "Date.h"
#include "calcDays.h"
using namespace std;

int main() {
    int userInput = 0;

    // Step 1: Print program purpose
    cout << "COVID Self Assessment Test" << endl;
    cout << "Welcome to the COVID Self Test please enter your result. Enter either 1, 2, 3, or 4: ";
    cin >> userInput;

    // Step 2: Branch depending on test result
    switch (userInput) {
        // Case 1: positive test
        // - quarantine for 7 days
        case 1:
            cout << "COVID Test status: positive" << endl;
            cout << "Date tested positive: 02/01/2023" << endl;
            cout << "Looks like you need to isolate yourself for 7 days" << endl;
            cout << "Return to classes: 02/08/2023" << endl;
            cout << "Goodbye!" << endl;
            break;

        // Case 2: negative test, no exposure
        // - quarantine for 0 days
        case 2:
            cout << "COVID Test status: negative" << endl;
            cout << "Exposed to positive case: No" << endl;
            cout << "Looks like you need to isolate yourself for 0 days" << endl;
            cout << "Goodbye!" << endl;
            break;

        // Case 3: negative test but exposed
        // - check vaccine date
        // - if fully vaccinated → 3 days
        // - else falls under case 4
        case 3: {
            cout << "Test result: negative but exposed" << endl;
            cout << "You were exposed to someone who tested positive." << endl;

            // Ask for vaccine shot date
            int dayShot, monthShot, yearShot;
            cout << "Enter the date of your second vaccine shot (day month year): ";
            cin >> dayShot >> monthShot >> yearShot;
            Date secondShot(dayShot, monthShot, yearShot);

            // Ask for exposure date
            int dayExposed, monthExposed, yearExposed;
            cout << "Enter the date you were exposed (day month year): ";
            cin >> dayExposed >> monthExposed >> yearExposed;
            Date exposedDate(dayExposed, monthExposed, yearExposed);

            // Check time since vaccination
            int daysSinceVaccination = calcDays(secondShot, exposedDate);

            if (daysSinceVaccination >= 14) {
                // Fully vaccinated
                int isolationDays = 3;
                Date returnDate = exposedDate;
                returnDate.addDays(isolationDays);

                cout << "You were fully vaccinated at the time of exposure." << endl;
                cout << "Stay home for " << isolationDays << " days." << endl;
                cout << "Return to school on: ";
                returnDate.showDate();
                cout << endl;
            } else {
                // Not fully vaccinated
                cout << "You were NOT fully vaccinated at the time of exposure." << endl;
                cout << "You fall under Case 4 and should isolate 12 days." << endl;
            }
            break;
        }

        // Case 4: negative + exposed + not fully vaccinated
        // - quarantine 12 days
        case 4: {
            cout << "Test result: negative but not fully vaccinated" << endl;
            cout << "You were exposed to someone who tested positive." << endl;

            int isolationDays = 12;
            cout << "Since you were NOT fully vaccinated at the time of exposure," << endl;
            cout << "you should stay home for " << isolationDays << " days." << endl;

            // Ask for exposure date
            int dayExposed, monthExposed, yearExposed;
            cout << "Enter the date you were exposed (day month year): ";
            cin >> dayExposed >> monthExposed >> yearExposed;
            Date exposedDate(dayExposed, monthExposed, yearExposed);

            // Calculate return date
            Date returnDate = exposedDate;
            returnDate.addDays(isolationDays);
            cout << "You can return to school on: ";
            returnDate.showDate();
            cout << endl;
            break;
        }

        // Invalid option
        default:
            cout << "Error. Enter a valid choice." << endl;
            break;
    }

    return 0;
}