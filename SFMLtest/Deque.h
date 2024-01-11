#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include "DataStructure.h"
using namespace std;
using namespace sf;


class DequeSimulator : public DataStructureSimulator{
public:
    DequeSimulator();
    ~DequeSimulator();

private:
    sf::RenderWindow window;
    sf::Font font;
    std::deque<int> myDeque;
    sf::Text dequeText;
    float movementDistance;
    sf::RectangleShape movingRectangle;
    sf::Clock pushBackAnimationClock;
    sf::Clock pushFrontAnimationClock;
    sf::Clock popBackAnimationClock;
    sf::Clock popFrontAnimationClock;

    void run();
    void handleEvents();
    void update();
    void render();
    void pushBackElement();
    void pushFrontElement();
    void popBackElement();
    void popFrontElement();
    void drawDeque();
    void updateDequeText();
    void updatePushBackMovement();
    void updatePushFrontMovement();
    void updatePopBackMovement();
    void updatePopFrontMovement();
};
