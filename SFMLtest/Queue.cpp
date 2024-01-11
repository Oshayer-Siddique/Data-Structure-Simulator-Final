#include "Queue.h"
#include <iostream>

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const int RECTANGLE_WIDTH = 50;
const int RECTANGLE_HEIGHT = 50;
const int QUEUE_X = 200;
const int QUEUE_Y = 500;
const float MOVEMENT_SPEED = 200.0f;
int counter = 0;

QueueSimulator::QueueSimulator() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Queue Simulator") {
    font.loadFromFile("arial.ttf");

    queueText.setFont(font);
    queueText.setCharacterSize(30);
    queueText.setFillColor(sf::Color::Blue);
    queueText.setPosition(20, 20);

    run();
}

void QueueSimulator::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void QueueSimulator::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::P) {
                enqueueElement();
            }
            else if (event.key.code == sf::Keyboard::O) {
                dequeueElement();
            }
        }
    }
}

void QueueSimulator::update() {
    updateQueueText();
    //updateEnqueueMovement();
    // updateDequeueMovement();
}

void QueueSimulator::render() {
    window.clear();

 
    drawQueue();

    //window.draw(movingRectangle);
    window.draw(queueText);
    //updateEnqueueMovement();

  
    

    window.display();
}

void QueueSimulator::enqueueElement() {

    int x; 
    cout << "Enter number for Push : " << endl;
    cin >> x;
    int newElement = x;
    myQueue.push(newElement);
    counter++;

     //Set up the moving rectangle
     movingRectangle.setSize(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
     movingRectangle.setFillColor(sf::Color::Green);
     movingRectangle.setPosition(0, 0);

     //movementDistance = QUEUE_Y;
     //pushAnimationClock.restart();
}

void QueueSimulator::dequeueElement() {
    if (!myQueue.empty()) {
        int dequeuedElement = myQueue.front();
        myQueue.pop();

        // Set up the moving rectangle for dequeue animation
        // movingRectangle.setSize(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        // movingRectangle.setFillColor(sf::Color::Green);
        // movingRectangle.setPosition(QUEUE_X, QUEUE_Y);
        // movementDistance = WINDOW_WIDTH;
        // popAnimationClock.restart();
    }
}

void QueueSimulator::drawQueue() {
    int startX = QUEUE_X;

    std::queue<int> tempQueue = myQueue;


    //if (!tempQueue.empty()) {
    //    tempQueue.pop();
    //}

    while (!tempQueue.empty()) {
        sf::RectangleShape rectangle(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(startX, QUEUE_Y);
        window.draw(rectangle);

        // Draw text on the rectangles
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::Black);
        text.setPosition(startX + RECTANGLE_WIDTH / 2 - 5, QUEUE_Y + RECTANGLE_HEIGHT / 2 - 10);
        text.setString(std::to_string(tempQueue.front()));
        window.draw(text);

        tempQueue.pop();
        startX += RECTANGLE_WIDTH+5;
    }
}

void QueueSimulator::updateQueueText() {
    std::string queueContent = "Queue Content: ";
    std::queue<int> tempQueue = myQueue;

    while (!tempQueue.empty()) {
        queueContent += std::to_string(tempQueue.front()) + " ";
        tempQueue.pop();
    }

    queueText.setString(queueContent);
}

 //void QueueSimulator::updateEnqueueMovement() {
 //    if (!myQueue.empty()) {

 //        string s = to_string(myQueue.back());

 //        cout << s << endl;


 //        Text a;
 //        a.setFont(font);
 //        a.setCharacterSize(15);
 //        a.setFillColor(Color::Red);
 //        a.setString(s);

 //        cout << movementDistance << endl;
 //        if (movementDistance > QUEUE_X) {
 //            float deltaTime = pushAnimationClock.restart().asSeconds();
 //            movementDistance -= MOVEMENT_SPEED * deltaTime;
 //            //cout << deltaTime << endl;
 //            movingRectangle.setPosition(movementDistance-60, QUEUE_Y);
 //        }

 //        a.setPosition(movingRectangle.getPosition().x + 15, movingRectangle.getPosition().y);
 //        //a.setPosition(300,300);
 //        window.draw(a);

 //    }


 //}


void QueueSimulator::updateEnqueueMovement() {

    int startX = QUEUE_X;
    if (!myQueue.empty()) {
        string s = to_string(myQueue.back());

        cout << s << endl;

        Text a;
        a.setFont(font);
        a.setCharacterSize(15);
        a.setFillColor(Color::Red);
        a.setString(s);

        startX += (RECTANGLE_WIDTH+5) * counter;


        //cout << startX << endl;

        

        
        
        if (movementDistance >= 0) {
            float deltaTime = pushAnimationClock.restart().asSeconds();
            movementDistance -= MOVEMENT_SPEED * deltaTime;
            movingRectangle.setPosition(startX - 55, QUEUE_Y);
        }

        



        a.setPosition(movingRectangle.getPosition().x + 15, movingRectangle.getPosition().y);
        //a.setPosition(startX - 50, QUEUE_Y);
        cout << a.getPosition().x << endl;
        window.draw(a);
    }
}



// void QueueSimulator::updateDequeueMovement() {
//     if (movementDistance < QUEUE_X) {
//         float deltaTime = popAnimationClock.restart().asSeconds();
//         movementDistance += MOVEMENT_SPEED * deltaTime;
//         movingRectangle.setPosition(movementDistance, QUEUE_Y);
//     }
// }

