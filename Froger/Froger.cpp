// Froger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.h"
#include "Platform.h"

#include "Image.h""


int main(int argc, char* args[])
{

    Platform* platform = Platform::getPtr();
    platform->init(640, 480);
    while(true)
    {
        platform->input();
        platform->update();
        platform->draw();
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu