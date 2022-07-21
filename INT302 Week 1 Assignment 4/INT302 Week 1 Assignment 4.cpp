#include <iostream>
#include <SDL.h>
#include <Turtle.h>
#undef main //The system errors with SDL.h without this line

using namespace std;

int main()
{
    const int windowWidth = 650;
    const int windowHeight = 480;
    int birthYear;
    int currentYear;
    int childAge;
    string userInput;

    cout << "Happy Birthday." << endl; // Bulk of the normal assignment begins here.
    cout << "Enter child's year of birth:" << endl;
    cin >> birthYear;
    cout << "Enter the current year:" << endl;
    cin >> currentYear;
    childAge = currentYear - birthYear;
    cout << childAge << endl;
    cout << "Here is your cake!" << endl; // Buld of the normal assignemnt ends here.

    Turtle t;

    t.windowMake(windowWidth, windowHeight); // Build the window
    t.clear();
    
    //Drawing the cake!
    t.move(10, windowHeight * .9, 0.0);
    for (int i = 0; i < 2; i++) {
        t.forward((windowWidth - 20));
        t.left(90);
        t.forward(windowHeight * .15);
        t.left(90);
    }
    t.move(((windowWidth - 20) * .1) + 10, (windowHeight * .9) - (windowHeight * .15), 0.0);
    for (int i = 0; i < 2; i++) {
        t.forward(((windowWidth - 20) * .8));
        t.left(90);
        t.forward(windowHeight * .15);
        t.left(90);
    }
    t.move(((windowWidth - 20) * .2) + 10, (windowHeight * .9) - ((windowHeight * .15) * 2), 0.0);
    for (int i = 0; i < 2; i++) {
        t.forward(((windowWidth - 20) * .6));
        t.left(90);
        t.forward(windowHeight * .15);
        t.left(90);
    }

    t.flush();  // Clear the data

    SDL_Delay(4000); // Give time to look at the window

    t.~Turtle(); // Kill the window

    return 0;
}