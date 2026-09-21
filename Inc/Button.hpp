#pragma once
#include "GameSprite.hpp"
#include <SFML/Graphics.hpp>

class Button final : public GameSprite
{
private:
    sf::Text buttonText;
    sf::Vector2f textOffset;

public:
    Button(
        const std::string& imagePath,
        sf::Font& font,
        const std::string& text,
        unsigned int characterSize);

    void setPosition(sf::Vector2f position) override;
    void setScale(sf::Vector2f scale) override;
    void draw(sf::RenderWindow& window) override;

private:
    void centerText();
};