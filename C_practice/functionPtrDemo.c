/*
Demonstration of function pointers/callback implementation
reference link: https://primerpy.medium.com/functional-pointer-and-callback-in-c-86c208df6b2f
*/


#include <stdio.h>
#include <stdlib.h>

typedef void (*EventCallback) (void*);

typedef struct {
    void* data;
    EventCallback callback;
} Event;

void process_event(Event event)
{
    event.callback(event.data);
}

void handle_mouse_click(void* data)
{
    int* coords = (int*)data;
    printf("Mouse clicked at (%d. %d)", coords[0], coords[1]);
}

void handle_keyboard_press(void* data)
{
    int key = *(int*)data;
    printf("Keyboard key pressed! %d\n", key);
}

int main()
{
    
    int mouse_coords[] = {10,20};
    int key = 27;

    Event mouse_event = {mouse_coords, handle_mouse_click};
    Event keyboard_event = {key, handle_keyboard_press};

    process_event(mouse_event);
    process_event(keyboard_event);
    return 0;
}