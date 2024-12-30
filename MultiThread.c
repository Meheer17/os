#include <stdio.h>
#include <windows.h>

// gcc -o MultiThread MultiThread.c -lpthread

DWORD WINAPI print_message(LPVOID lpParam) {
    printf("Hello from thread!\n");
    return 0;
}

int main() {
    HANDLE thread;
    
    // Create a thread
    thread = CreateThread(NULL, 0, print_message, NULL, 0, NULL);

    // Wait for the thread to finish
    WaitForSingleObject(thread, INFINITE);
    
    printf("Hello from main!\n");

    // Close the thread handle
    CloseHandle(thread);

    return 0;
}
