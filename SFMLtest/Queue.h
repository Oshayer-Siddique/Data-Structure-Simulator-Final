#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include<deque>
#include "DataStructure.h"

using namespace std;
using namespace sf;



class QueueSimulator  : public DataStructureSimulator{
public:
	QueueSimulator();

private:
    RenderWindow window;
    Font font;
    queue<int> myQueue;
    Text queueText;
    float movementDistance = 0.0f;
    RectangleShape movingRectangle;
    Clock pushAnimationClock;
    Clock popAnimationClock;

    void run();
    void handleEvents();
    void update();
    void render();
    void enqueueElement();
    void dequeueElement();
    void drawQueue();
    void updateQueueText();
    void updateEnqueueMovement();
	
};

 