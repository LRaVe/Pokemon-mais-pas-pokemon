#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <functional>
#include <memory>
#include <utility>

class Interface;

class GameState
{
public:
    using StateAction = std::function<void(std::unique_ptr<GameState>)>;
    virtual ~GameState() = default;

    void setAction(StateAction stateAction) {
        action = std::move(stateAction);
    }

    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void render(sf::RenderWindow& window, Interface& interface) = 0;
    virtual void update() = 0;
protected:
    StateAction action;
};