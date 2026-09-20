#pragma once

#include <SFML/Graphics.hpp>

class GameSprite {
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        bool isHighlighted = false;
    public:
        GameSprite()=delete;
        GameSprite(const std::string& imagePath);
        void setScale(sf::Vector2f scale);

        void setHighlighted(bool highlighted);
        void setPosition(sf::Vector2f position);
        void draw(sf::RenderWindow& window);
};