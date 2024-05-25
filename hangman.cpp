#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <algorithm>

void displayWord(sf::RenderWindow &window, const std::string &word, const std::vector<bool> &guessed, sf::Font &font) {
    std::string displayString;
    for (size_t i = 0; i < word.size(); ++i) {
        if (guessed[i]) {
            displayString += word[i];
        } else {
            displayString += "_";
        }
        displayString += " ";
    }

    sf::Text text(displayString, font, 30);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 50);
    window.draw(text);
}

void drawHangman(sf::RenderWindow &window, int attemptsLeft) {
    sf::RectangleShape base(sf::Vector2f(200, 10));
    base.setPosition(50, 500);
    base.setFillColor(sf::Color::White);
    window.draw(base);

    sf::RectangleShape pole(sf::Vector2f(10, 400));
    pole.setPosition(100, 100);
    pole.setFillColor(sf::Color::White);
    window.draw(pole);

    sf::RectangleShape top(sf::Vector2f(100, 10));
    top.setPosition(100, 100);
    top.setFillColor(sf::Color::White);
    window.draw(top);

    sf::RectangleShape rope(sf::Vector2f(10, 50));
    rope.setPosition(200, 110);
    rope.setFillColor(sf::Color::White);
    window.draw(rope);

    if (attemptsLeft <= 5) {
        sf::CircleShape head(25);
        head.setPosition(175, 160);
        head.setFillColor(sf::Color::White);
        window.draw(head);
    }
    if (attemptsLeft <= 4) {
        sf::RectangleShape body(sf::Vector2f(10, 150));
        body.setPosition(200, 210);
        body.setFillColor(sf::Color::White);
        window.draw(body);
    }
    if (attemptsLeft <= 3) {
        sf::RectangleShape leftArm(sf::Vector2f(80, 10));
        leftArm.setPosition(120, 220);
        leftArm.setFillColor(sf::Color::White);
        window.draw(leftArm);
    }
    if (attemptsLeft <= 2) {
        sf::RectangleShape rightArm(sf::Vector2f(80, 10));
        rightArm.setPosition(200, 220);
        rightArm.setFillColor(sf::Color::White);
        window.draw(rightArm);
    }
    if (attemptsLeft <= 1) {
        sf::RectangleShape leftLeg(sf::Vector2f(10, 80));
        leftLeg.setPosition(190, 360);
        leftLeg.setFillColor(sf::Color::White);
        window.draw(leftLeg);
    }
    if (attemptsLeft == 0) {
        sf::RectangleShape rightLeg(sf::Vector2f(10, 80));
        rightLeg.setPosition(210, 360);
        rightLeg.setFillColor(sf::Color::White);
        window.draw(rightLeg);
    }
}

int main() {
    std::string word = "hangman";
    std::vector<bool> guessed(word.size(), false);
    std::vector<char> wrongGuesses;
    int attemptsLeft = 6;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Hangman Game");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;  // Ensure you have an arial.ttf in your project directory
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                char guess = static_cast<char>(event.text.unicode);
                if (std::isalpha(guess)) {
                    guess = std::tolower(guess);
                    if (std::find(word.begin(), word.end(), guess) != word.end()) {
                        for (size_t i = 0; i < word.size(); ++i) {
                            if (word[i] == guess) {
                                guessed[i] = true;
                            }
                        }
                    } else {
                        if (std::find(wrongGuesses.begin(), wrongGuesses.end(), guess) == wrongGuesses.end()) {
                            wrongGuesses.push_back(guess);
                            --attemptsLeft;
                        }
                    }
                }
            }
        }

        window.clear();
        displayWord(window, word, guessed, font);
        drawHangman(window, attemptsLeft);
        window.display();

        if (std::all_of(guessed.begin(), guessed.end(), [](bool v) { return v; }) || attemptsLeft == 0) {
            sf::sleep(sf::seconds(3));
            window.close();
        }
    }

    return 0;
}