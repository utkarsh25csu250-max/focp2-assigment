#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>   // FIX 1: needed for time()
using namespace std;

int main() {
    srand(time(0));   // FIX 2: seed the random generator

    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    // FIX 3: handle empty input
    if (name.empty()) {
        cout << "You didn't even enter a name. That's roast #1 already!" << endl;
        return 0;
    }

    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have gold.",
        "{name}'s debugging style is staring at the screen until the bug leaves.",
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name}'s Wi-Fi is faster than their thinking speed.",
        "{name} once tried to Ctrl+Z real life. It didn't work.",
        "{name}'s code has more bugs than a jungle at midnight.",
        "Even Stack Overflow closed the tab when {name} asked a question."
    };

    int index = rand() % roasts.size();
    string roast = roasts[index];

    // FIX 4: replace ALL occurrences of {name}
    size_t pos;
    while ((pos = roast.find("{name}")) != string::npos)
        roast.replace(pos, 6, name);

    cout << "\n🔥 Roast: " << roast << endl;
    return 0;
}