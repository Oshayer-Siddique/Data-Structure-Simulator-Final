#include "Deque.h"



using namespace std;

using namespace sf;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const int RECTANGLE_WIDTH = 50;
const int RECTANGLE_HEIGHT = 50;
const int DEQUE_X = 200;
const int DEQUE_Y = 500;
const float MOVEMENT_SPEED = 5.0f;

DequeSimulator::DequeSimulator() : window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Deque Simulator") {
    font.loadFromFile("arial.ttf"); // Make sure to provide a valid font file path

    dequeText.setFont(font);
    dequeText.setCharacterSize(30);
    dequeText.setFillColor(Color::Blue);
    dequeText.setPosition(20, 20);

    run();
}

DequeSimulator::~DequeSimulator() {
    // Destructor, if needed
}

void DequeSimulator::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void DequeSimulator::handleEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }

        if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::B) {
                pushBackElement();
            }
            else if (event.key.code == Keyboard::F) {
                pushFrontElement();
            }
            else if (event.key.code == Keyboard::N) {
                popBackElement();
            }
            else if (event.key.code == Keyboard::M) {
                popFrontElement();
            }
        }
    }
}

void DequeSimulator::update() {
    updateDequeText();
    // updatePushBackMovement();
    // updatePushFrontMovement();
    // updatePopBackMovement();
    // updatePopFrontMovement();
}

void DequeSimulator::render() {
    window.clear();

    // Draw the deque
    drawDeque();

    // Draw the deque text
    window.draw(dequeText);

    // Draw the moving rectangle
    // window.draw(movingRectangle);

    window.display();
}

void DequeSimulator::pushBackElement() {
    int newElement = rand() % 100; // Generate a random element
    myDeque.push_back(newElement);

    // Set up the moving rectangle
    // movingRectangle.setSize(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
    // movingRectangle.setFillColor(Color::Red);
    // movingRectangle.setPosition(WINDOW_WIDTH, DEQUE_Y);

    // movementDistance = DEQUE_Y;
    // pushBackAnimationClock.restart();
}

void DequeSimulator::pushFrontElement() {
    int newElement = rand() % 100; // Generate a random element
    myDeque.push_front(newElement);

    // Set up the moving rectangle for push_front animation
    // movingRectangle.setSize(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
    // movingRectangle.setFillColor(Color::Red);
    // movingRectangle.setPosition(DEQUE_X, DEQUE_Y);
    // movementDistance = WINDOW_WIDTH;
    // pushFrontAnimationClock.restart();
}

void DequeSimulator::popBackElement() {
    if (!myDeque.empty()) {
        myDeque.pop_back();

        // Set up the moving rectangle for pop_back animation
        // movingRectangle.setSize(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        // movingRectangle.setFillColor(Color::Red);
        // movingRectangle.setPosition(WINDOW_WIDTH, DEQUE_Y);
        // movementDistance = DEQUE_Y;
        // popBackAnimationClock.restart();
    }
}

void DequeSimulator::popFrontElement() {
    if (!myDeque.empty()) {
        myDeque.pop_front();

        // Set up the moving rectangle for pop_front animation
        // movingRectangle.setSize(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        // movingRectangle.setFillColor(Color::Red);
        // movingRectangle.setPosition(DEQUE_X, DEQUE_Y);
        // movementDistance = WINDOW_WIDTH;
        // popFrontAnimationClock.restart();
    }
}

void DequeSimulator::drawDeque() {
    int startX = DEQUE_X;

    // Create a temporary deque for iteration without modifying the original deque
    std::deque<int> tempDeque = myDeque;

    while (!tempDeque.empty()) {
        RectangleShape rectangle(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        rectangle.setFillColor(Color::Green);
        rectangle.setPosition(startX, DEQUE_Y);
        window.draw(rectangle);

        // Draw text on the rectangles
        Text text;
        text.setFont(font);
        text.setCharacterSize(15);
        text.setFillColor(Color::Black);
        text.setPosition(startX + RECTANGLE_WIDTH / 2 - 5, DEQUE_Y + RECTANGLE_HEIGHT / 2 - 10);
        text.setString(std::to_string(tempDeque.front()));
        window.draw(text);

        tempDeque.pop_front(); // Move to the next element
        startX += RECTANGLE_WIDTH + 5; // Add some space between rectangles
    }
}

void DequeSimulator::updateDequeText() {
    std::string dequeContent = "Deque Content: ";
    std::deque<int> tempDeque = myDeque;

    while (!tempDeque.empty()) {
        dequeContent += std::to_string(tempDeque.front()) + " ";
        tempDeque.pop_front();
    }

    dequeText.setString(dequeContent);
}

// void DequeSimulator::updatePushBackMovement() {
//     if (movementDistance > DEQUE_X) {
//         float deltaTime = pushBackAnimationClock.restart().asSeconds();
//         movementDistance -= MOVEMENT_SPEED * deltaTime;
//         movingRectangle.setPosition(movementDistance, DEQUE_Y);
//     }
// }

// void DequeSimulator::updatePushFrontMovement() {
//     if (movementDistance < DEQUE_X) {
//         float deltaTime = pushFrontAnimationClock.restart().asSeconds();
//         movementDistance += MOVEMENT_SPEED * deltaTime;
//         movingRectangle.setPosition(movementDistance, DEQUE_Y);
//     }
// }

// void DequeSimulator::updatePopBackMovement() {
//     if (movementDistance > DEQUE_X) {
//         float deltaTime = popBackAnimationClock.restart().asSeconds();
//         movementDistance -= MOV
