#pragma once

#include "GameState.hpp"
#include "Pokemon_Party.hpp"
#include "GameSprite.hpp"
#include "Button.hpp"

#include <vector>
#include <optional>

class PartyState final : public GameState
{
private:
    sf::Font font;
    Pokemon_Party& party;
    std::vector<GameSprite> pokemonSprites;
    std::optional<Button> ReturnButton;
public:
    PartyState(Pokemon_Party& party);
    void handleEvent(const sf::Event& event) override;
    void render(sf::RenderWindow& window, Interface& interface) override;
    void update() override;
};