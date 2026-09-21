#pragma once

#include <SFML/Graphics.hpp>

class GameSprite {
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        bool isHighlighted = false;
    public:
        virtual ~GameSprite() = default;
        GameSprite()=delete;
        GameSprite(const std::string& imagePath);
        virtual void setScale(sf::Vector2f scale);

        virtual bool contains(sf::Vector2f point) const;
        sf::FloatRect getGlobalBounds() const;
        void setHighlighted(bool highlighted);
        virtual void setPosition(sf::Vector2f position);
        virtual void draw(sf::RenderWindow& window);
};