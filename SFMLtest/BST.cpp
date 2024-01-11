#include "BST.h"
#include <iostream>

BinaryTree::BinaryTree() : root(nullptr) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Font file not found! Please make sure you have arial.ttf in the same directory as the executable.\n";
    }
}

void BinaryTree::insert(int value) {
    root = insertRecursive(root, value);
}

void BinaryTree::draw(sf::RenderWindow& window, float x, float y, float xOffset, float yOffset) {
    drawRecursive(window, root, x, y, xOffset, yOffset);
}

void BinaryTree::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            int x;
            cout << "Enter the value in BST : " << endl;
            cin >> x;
            int value = x;
            std::cout << "Inserting value: " << value << std::endl;
            insert(value);
        }
    }
}

Node* BinaryTree::insertRecursive(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertRecursive(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertRecursive(root->right, value);
    }

    return root;
}

void BinaryTree::drawRecursive(sf::RenderWindow& window, Node* root, float x, float y, float xOffset, float yOffset) {
    if (root != nullptr) {
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::White);
        circle.setOutlineColor(sf::Color::Black);
        circle.setOutlineThickness(2);
        circle.setPosition(x, y);
        window.draw(circle);

        int n = root->data;
        std::string s = std::to_string(n);

        sf::Text text;
        text.setFont(font);
        text.setString(s);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Red);
        text.setPosition(x + 5, y + 5);
        window.draw(text);

        if (root->left != nullptr) {
            drawRecursive(window, root->left, x - xOffset, y + yOffset, xOffset / 2, yOffset);
            drawLine(window, x, y, x - xOffset, y + yOffset);
        }

        if (root->right != nullptr) {
            drawRecursive(window, root->right, x + xOffset, y + yOffset, xOffset / 2, yOffset);
            drawLine(window, x, y, x + xOffset, y + yOffset);
        }
    }
}

void BinaryTree::drawLine(sf::RenderWindow& window, float x1, float y1, float x2, float y2) {
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x1 + 20, y1 + 20)),
        sf::Vertex(sf::Vector2f(x2 + 20, y2 + 20))
    };

    window.draw(line, 2, sf::Lines);
}

void BinaryTree::render(BinaryTree& bst, float x, float y, float xOffset, float yOffset) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "BST Insertion Simulation");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            bst.handleInput(event);
        }

        // Perform any additional update logic here if needed

        window.clear(sf::Color::Green);
        bst.draw(window, x, y, xOffset, yOffset);
        window.display();
    }
}

