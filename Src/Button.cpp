#include "Button.hpp"

Button::Button(
    const std::string& imagePath,
    sf::Font& font,
    const std::string& text,
    unsigned int characterSize)
    : GameSprite(imagePath),
      buttonText(font, text, characterSize),
      textOffset({0.f, 0.f})
{
    buttonText.setFillColor(sf::Color::Black);
}

void Button::setPosition(sf::Vector2f position)
{
    GameSprite::setPosition(position);
    centerText();
}

void Button::setScale(sf::Vector2f scale)
{
    GameSprite::setScale(scale);
    centerText();
}

void Button::centerText()
{
    const sf::FloatRect buttonBounds = getGlobalBounds();
    const sf::FloatRect textBounds = buttonText.getLocalBounds();

    buttonText.setOrigin({
        textBounds.position.x + textBounds.size.x / 2.f,
        textBounds.position.y + textBounds.size.y / 2.f
    });
    buttonText.setPosition({
        buttonBounds.position.x + buttonBounds.size.x / 2.f,
        buttonBounds.position.y + buttonBounds.size.y / 2.f
    });
}

void Button::draw(sf::RenderWindow& window)
{
    GameSprite::draw(window);
    window.draw(buttonText);
}