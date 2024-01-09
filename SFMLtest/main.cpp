//#include <SFML/Graphics.hpp>
//
//class MovingBall {
//public:
//    MovingBall(float radius)
//        : circle(radius), speed(100.0f), destination(400.0f, 300.0f), isMoving(false) {
//        circle.setFillColor(sf::Color::Green);
//        circle.setPosition(100.0f, 100.0f); // Initial position
//    }
//
//    void move(float deltaTime) {
//        if (isMoving) {
//            sf::Vector2f direction = destination - circle.getPosition();
//            float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
//
//            if (distance > 1.0f) { // Avoid division by zero
//                direction /= distance;
//                circle.move(direction * speed * deltaTime);
//            }
//        }
//    }
//
//    void setDestination(sf::Vector2f newDestination) {
//        destination = newDestination;
//        isMoving = true;
//    }
//
//    void draw(sf::RenderWindow& window) {
//        window.draw(circle);
//    }
//
//    bool isMovingNow() const {
//        return isMoving;
//    }
//
//private:
//    sf::CircleShape circle;
//    float speed;
//    sf::Vector2f destination;
//    bool isMoving;
//};
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Automated Movement");
//    window.setFramerateLimit(60);
//
//    MovingBall movingBall(30.0f);
//
//    sf::Clock clock;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//
//            if (event.type == sf::Event::KeyPressed) {
//                if (event.key.code == sf::Keyboard::Space) {
//                    movingBall.setDestination(sf::Vector2f(400.0f, 300.0f));
//                }
//            }
//        }
//
//        float deltaTime = clock.restart().asSeconds();
//
//        movingBall.move(deltaTime);
//
//        window.clear();
//        movingBall.draw(window);
//        window.display();
//    }
//
//    return 0;
//}


//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//class MovingBall {
//public:
//    MovingBall(float radius)
//        : circle(radius), speed(100.0f), destination(400.0f, 300.0f), isMoving(false) {
//        circle.setFillColor(sf::Color::Green);
//        circle.setPosition(100.0f, 100.0f); // Initial position
//
//        font.loadFromFile("arial.ttf"); // Make sure to provide a valid font file path
//        text.setFont(font);
//        text.setCharacterSize(20);
//        text.setString("12");
//        text.setFillColor(sf::Color::Red);
//
//        updateTextPosition(); // Set initial text position
//
//        sf::FloatRect textBounds = text.getLocalBounds();
//        text.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
//    }
//
//    void move(float deltaTime) {
//        if (isMoving) {
//            sf::Vector2f direction = destination - circle.getPosition();
//            float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
//
//            if (distance > 1.0f) { // Avoid division by zero
//                direction /= distance;
//                circle.move(direction * speed * deltaTime);
//                updateTextPosition();
//            }
//        }
//    }
//
//    void setDestination(sf::Vector2f newDestination) {
//        destination = newDestination;
//        isMoving = true;
//    }
//
//    void draw(sf::RenderWindow& window) {
//        window.draw(circle);
//        window.draw(text);
//    }
//
//    bool isMovingNow() const {
//        return isMoving;
//    }
//
//private:
//    sf::CircleShape circle;
//    float speed;
//    sf::Vector2f destination;
//    bool isMoving;
//    sf::Text text;
//    sf::Font font;
//
//    void updateTextPosition() {
//        text.setPosition(circle.getPosition().x+25,circle.getPosition().y+25);
//    }
//};
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Automated Movement");
//    window.setFramerateLimit(60);
//
//    MovingBall movingBall(30.0f);
//
//    sf::Clock clock;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//
//            if (event.type == sf::Event::KeyPressed) {
//                if (event.key.code == sf::Keyboard::Space) {
//                    movingBall.setDestination(sf::Vector2f(400.0f, 300.0f));
//                }
//            }
//        }
//
//        float deltaTime = clock.restart().asSeconds();
//
//        movingBall.move(deltaTime);
//
//        window.clear();
//        movingBall.draw(window);
//        window.display();
//    }
//
//    return 0;
//}


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class MovingBall {
public:
    MovingBall(float radius, const sf::Vector2f& initialPosition, const std::string& number)
        : circle(radius), speed(300.0f), destination(initialPosition), isMoving(false) {
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(initialPosition);

        font.loadFromFile("arial.ttf"); // Make sure to provide a valid font file path
        text.setFont(font);
        text.setCharacterSize(20);
        text.setString(number);
        text.setFillColor(sf::Color::Red);

        updateTextPosition(); // Set initial text position

        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
    }

    void move(float deltaTime) {
        if (isMoving) {
            sf::Vector2f direction = destination - circle.getPosition();
            float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

            if (distance > 1.0f) { // Avoid division by zero
                direction /= distance;
                circle.move(direction * speed * deltaTime);
                updateTextPosition();
            }
            else {
                // The ball has reached the destination
                isMoving = false;
            }
        }
    }

    void setDestination(const sf::Vector2f& newDestination) {
        destination = newDestination;
        isMoving = true;
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(circle);
        window.draw(text);
    }

    bool isMovingNow() const {
        return isMoving;
    }

private:
    sf::CircleShape circle;
    float speed;
    sf::Vector2f destination;
    bool isMoving;
    sf::Text text;
    sf::Font font;

    void updateTextPosition() {
        text.setPosition(circle.getPosition().x + 25, circle.getPosition().y + 25);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Moving Balls Sequentially");
    window.setFramerateLimit(60);

    MovingBall ball3(30.0f, sf::Vector2f(100.0f, 100.0f), "12");
    MovingBall ball2(30.0f, sf::Vector2f(170.0f, 100.0f), "34");
    MovingBall ball1(30.0f, sf::Vector2f(240.0f, 100.0f), "56");

    // Define the rectangle

    sf::RectangleShape rectangle(sf::Vector2f(100.0f, 390.0f)); // Width: 100, Height: 50
    rectangle.setFillColor(sf::Color::Transparent); // Set fill color to transparent
    rectangle.setOutlineColor(sf::Color::Blue); // Set border color
    rectangle.setOutlineThickness(2.0f); // Set border thickness

    rectangle.setPosition(1300.0f, 600.0f);


    std::vector<MovingBall*> balls = { &ball1, &ball2, &ball3 };
    std::size_t currentBallIndex = 0;

    sf::Clock clock;
    float moveInterval = 3.0f; // Time interval in seconds
    float counter = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    // Set the destination for the current ball

                    



                    

                    if (currentBallIndex < balls.size()) {
                        //balls[currentBallIndex]->setDestination(sf::Vector2f(1320.0f, 100.0f));
                        balls[currentBallIndex]->setDestination(sf::Vector2f(1320.0f, 920.0f - counter * 70.0f));
                        
                        currentBallIndex++;
                    }
                    counter++;
                    
                }
            }
        }

        float deltaTime = clock.restart().asSeconds();


        

        for (auto& ball : balls) {
            ball->move(deltaTime);
        }

        window.clear();
        for (const auto& ball : balls) {
            ball->draw(window);
        }

        // Draw the rectangle


        window.draw(rectangle);
        

        window.display();
    }

    return 0;
}
