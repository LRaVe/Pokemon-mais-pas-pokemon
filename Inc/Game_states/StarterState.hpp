#pragma once

#include "GameState.hpp"
#include "GameSprite.hpp"
#include <array>
#include <memory>
#include <SFML/Graphics.hpp>

class StarterState final : public GameState
{
private: 
    sf::Font font;
    sf::Text ChooseText;
    std::array<std::unique_ptr<GameSprite>, 3> starterPokemonSprites;
    bool isPokemonSelected = false;
public:
    StarterState();
    void handleEvent(const sf::Event& event) override;
    void render(sf::RenderWindow& window, Interface& interface) override;
};