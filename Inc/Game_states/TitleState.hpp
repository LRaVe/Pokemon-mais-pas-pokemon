#pragma once

#include "GameState.hpp"
#include "Button.hpp"
#include "Pokemon_Party.hpp"

#include <SFML/Graphics.hpp>

class TitleState final : public GameState
{
private: 
    sf::Texture bgTexture;
    sf::Sprite bgSprite;
    sf::Font font;
    sf::Text titleText;
    std::optional<Button> startButton;
    Pokemon_Party& party;
    
public:

    TitleState(Pokemon_Party& party);
    void handleEvent(const sf::Event& event) override;
    void render(sf::RenderWindow& window, Interface& interface) override;
    void update() override;
};