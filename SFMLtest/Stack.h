#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include "DataStructure.h"


using namespace std;
using namespace sf;


class StackSimulator : public DataStructureSimulator{
public:
    StackSimulator();

private:
    RenderWindow window;
    Font font;
    stack<int> myStack;
    Text stackText;
    Text inputText;  // Added for graphical input
    float movementDistance;
    RectangleShape movingRectangle;
    Clock pushAnimationClock;
    //Clock popAnimationClock;
    int elementsToAddIndex;

    void run();
    void handleEvents();
    void update();
    void render();
    void pushElement();
    void popElement();
    void drawStack();
    void updateStackText();
    void updatePushMovement();
    //void updatePopMovement();
};

