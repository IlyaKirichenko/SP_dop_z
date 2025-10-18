#include <iostream>
using namespace std;

struct EventSystem {
    void (*handlers[100])();
    int count = 0;
};

void registerHandler(EventSystem &system, void(*handler)()) {
    if (system.count < 100) {
        system.handlers[system.count] = handler;
        system.count++;
    }
    else {
        cout << "Too many events";
    }
}

void triggerEvent(const EventSystem& system) {
    cout << "Triggering " << system.count << " events: \n";
    for (int i = 0; i < system.count; i++) {
        system.handlers[i]();
    }
}

void onUserLogin() {
    cout << "User log in\n";
}

void onUserLogout() {
    cout << "User log out\n";
}

void onError() {
    cout << "Error!\n";
}

int main()
{
    EventSystem system;
    registerHandler(system, onUserLogin); 
    registerHandler(system, onUserLogout);
    registerHandler(system, onError);
    triggerEvent(system);
}
