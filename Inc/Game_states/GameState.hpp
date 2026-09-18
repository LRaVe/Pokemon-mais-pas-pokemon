#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class Interface;

class GameState
{
public:
    virtual ~GameState() = default;

    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void render(sf::RenderWindow& window, Interface& interface) = 0;
};