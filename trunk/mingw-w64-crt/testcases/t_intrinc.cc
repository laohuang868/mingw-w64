#include <windows.h>
#include <stdio.h>

int main() {
    LONG poop = 0;
    for (int i = 0; i < 5; ++i) {
        printf("[%02i]\n", InterlockedIncrement(&poop));
    }
    for (int j = 0; j < 5; ++j) {
        printf("[%02i]\n", InterlockedDecrement(&poop));
    }
}

