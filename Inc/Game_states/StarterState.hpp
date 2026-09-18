#pragma once

#include "GameState.hpp"

class StarterState final : public GameState
{
public:
    void handleEvent(const sf::Event& event) override;
    void render(sf::RenderWindow& window, Interface& interface) override;
};