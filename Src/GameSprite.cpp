#include "GameSprite.hpp"

#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <iostream>

GameSprite::GameSprite(const std::string& imagePath) : texture(), sprite(texture) {
    if (!texture.loadFromFile(imagePath)) {
        throw std::runtime_error("Failed to load texture from " + imagePath);
    }
    sprite.setTexture(texture, true);
    std::cout << "Chargement : " << imagePath
              << " -> " << texture.getSize().x
              << "x" << texture.getSize().y << '\n';
}


void GameSprite::setHighlighted(bool highlighted) {
    isHighlighted = highlighted;
}

void GameSprite::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void GameSprite::setScale(sf::Vector2f scale) {
    sprite.setScale(scale);
}


bool GameSprite::contains(sf::Vector2f point) const {
    return sprite.getGlobalBounds().contains(point);
}

void GameSprite::draw(sf::RenderWindow& window) {
    if (isHighlighted) {
        // Draw a highlight rectangle behind the sprite
        sf::RectangleShape highlightRect(sprite.getGlobalBounds().size);
        highlightRect.setPosition(sprite.getPosition());
        highlightRect.setFillColor(sf::Color(255, 255, 0, 128)); // Semi-transparent yellow
        window.draw(highlightRect);
    }
    
    
    window.draw(sprite);
}

