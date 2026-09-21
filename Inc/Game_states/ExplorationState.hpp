#pragma once

#include "GameState.hpp"
#include "Pokedex.hpp"
#include "Pokemon.hpp"
#include "GameSprite.hpp"
#include "Button.hpp"
#include "Pokemon_Party.hpp"

#include <SFML/Graphics.hpp>
#include <optional>

class ExplorationState final : public GameState
{
private:
    sf::Texture bgTexture;
    sf::Sprite bgSprite;
    sf::Font font;
    sf::Text ExploreText;
    

    sf::Clock searchClock;
    sf::Clock nextSearchClock;
    bool isSearching = false;
    bool hasFoundPokemon = false;
    bool isCaptured = false;
    bool isWaitingForNextSearch = false;

    std::optional<Pokemon> foundPokemon;
    std::optional<GameSprite> foundPokemonSprite;

    std::optional<Button> captureButtonSprite;
    std::optional<Button> fleeButtonSprite;
    std::optional<Button> fightButtonSprite;

    Pokemon_Party& party;
public:

    ExplorationState(Pokemon_Party& party);

    void handleEvent(const sf::Event& event) override;
    void render(sf::RenderWindow& window, Interface& interface) override;
    void update() override;
    Pokemon picKRandomPokemon() const;
    void search();
};