#include "Stack.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int RECTANGLE_WIDTH = 50;
const int RECTANGLE_HEIGHT = 20;
const int STACK_X = 400;
const int STACK_Y = 100;
const float MOVEMENT_SPEED = 200.0f;

StackSimulator::StackSimulator() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Stack Simulator") {
    font.loadFromFile("arial.ttf");

    stackText.setFont(font);
    stackText.setCharacterSize(20);
    stackText.setFillColor(sf::Color::White);
    stackText.setPosition(20, 20);

    run();
}

void StackSimulator::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void StackSimulator::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }

        if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::P) {
                pushElement();
            }
            else if (event.key.code == Keyboard::O) {
                popElement();
            }
        }
    }
}





void StackSimulator::update() {
    updateStackText();
    //updatePushMovement();
    //updatePopMovement();
}

void StackSimulator::render() {
    window.clear();
    drawStack();

    
    
    window.draw(movingRectangle);
    window.draw(stackText);
    updatePushMovement();
    window.display();
}

void StackSimulator::pushElement() {

    int x;
    cout << "Enter Element for PUSH : " << endl;
    cin >> x;

    int newElement = x;
    myStack.push(newElement);

    movingRectangle.setSize(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
    movingRectangle.setFillColor(sf::Color::Red);
    movingRectangle.setPosition(STACK_X, WINDOW_HEIGHT);

    movementDistance = WINDOW_HEIGHT;
    pushAnimationClock.restart();
}

void StackSimulator::popElement() {
    if (!myStack.empty()) {
        int poppedElement = myStack.top();
        myStack.pop();

        //movingRectangle.setSize(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        //movingRectangle.setFillColor(sf::Color::Blue);
        //movingRectangle.setPosition(STACK_X, STACK_Y);
        //movementDistance = STACK_Y;
        //popAnimationClock.restart();
    }
}

//void StackSimulator::drawStack() {
//    int startY = STACK_Y;
//
//    std::stack<int> tempStack = myStack;
//
//    while (!tempStack.empty()) {
//        sf::RectangleShape rectangle(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
//        rectangle.setFillColor(sf::Color::Blue);
//        rectangle.setPosition(STACK_X, startY);
//
//        sf::Text text;
//        text.setFont(font);
//        text.setCharacterSize(15);
//        text.setFillColor(sf::Color::White);
//        text.setPosition(STACK_X + RECTANGLE_WIDTH / 2 - 5, startY + RECTANGLE_HEIGHT / 2 - 10);
//        text.setString(std::to_string(tempStack.top()));
//
//        window.draw(rectangle);
//        window.draw(text);
//
//        tempStack.pop();
//        startY += RECTANGLE_HEIGHT + 5;
//    }
//}



void StackSimulator::drawStack() {
    int startY = STACK_Y;
    bool isFirstRectangle = true;  // Flag to check if it's the top rectangle

    std::stack<int> tempStack = myStack;
    if (!tempStack.empty()) {
        tempStack.pop();

    }
    

    while (!tempStack.empty()) {
        sf::RectangleShape rectangle(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));

         //Use different colors for the top and other rectangles
        //if (isFirstRectangle) {
        //    rectangle.setFillColor(Color::Red);  // Color for the top rectangle
        //    isFirstRectangle = false;
        //}
        //else {
        //    rectangle.setFillColor(Color::Blue);  // Color for other rectangles
        //}

        rectangle.setFillColor(Color::Blue);

        rectangle.setPosition(STACK_X, startY);

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(15);
        text.setFillColor(Color::White);
        text.setPosition(STACK_X + RECTANGLE_WIDTH / 2 - 5, startY + RECTANGLE_HEIGHT / 2 - 10);
        text.setString(std::to_string(tempStack.top()));

        window.draw(rectangle);
        window.draw(text);

        tempStack.pop();
        startY += RECTANGLE_HEIGHT + 5;
    }
}


void StackSimulator::updateStackText() {
    std::string stackContent = "Stack Content: ";
    std::stack<int> tempStack = myStack;

    while (!tempStack.empty()) {
        stackContent += to_string(tempStack.top()) + " ";
        tempStack.pop();
    }

    stackText.setString(stackContent);
}

void StackSimulator::updatePushMovement() {

    if (!myStack.empty()) {
        string s = to_string(myStack.top());

        //cout << s << endl;

        Text a;
        a.setFont(font);
        a.setCharacterSize(15);
        a.setFillColor(Color::White);
        a.setString(s);

        //a.setPosition(500,500);
        
        if (movementDistance > STACK_Y) {
            float deltaTime = pushAnimationClock.restart().asSeconds();
            movementDistance -= MOVEMENT_SPEED * deltaTime;
            movingRectangle.setPosition(STACK_X, movementDistance-25);
            

            
        }
        a.setPosition(movingRectangle.getPosition().x+15,movingRectangle.getPosition().y);
        window.draw(a);


    }
    else {
        cout << "Null" << endl;
    }





}

//void StackSimulator::updatePopMovement() {
//    if (movementDistance < STACK_Y) {
//        float deltaTime = popAnimationClock.restart().asSeconds();
//        movementDistance += MOVEMENT_SPEED * deltaTime;
//        movingRectangle.setPosition(STACK_X, movementDistance);
//    }
//}


