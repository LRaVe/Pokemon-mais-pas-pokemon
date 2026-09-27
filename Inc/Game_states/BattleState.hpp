#pragma once

#include "GameState.hpp"
#include "Pokemon.hpp"
#include "Pokemon_Party.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>

#include <optional>
#include <deque>
#include <vector>

enum class BattlePhase
{
    MainMenu,
    ChoosingPokemon,
    PlayerTurn,
    OpponentTurn,
    Victory,
    Defeat,
    Flee
};

class BattleState final : public GameState
{
private:
    Pokemon_Party& party;
    Pokemon* playerPokemon=nullptr;
    Pokemon opponent;
    GameSprite opponentSprite;
    GameSprite textBoxSprite;
    std::optional<GameSprite> activePokemonSprite;
    sf::Font font;
    sf::Text dialogueText;
    sf::Clock textClock;
    std::string fullText;
    std::deque<std::string> dialogueQueue;
    std::size_t visibleCharacters = 0;
    float characterDelay = 0.05f; 
    float dialoguePause = 1.5f;
    std::optional<Button> fleeButton;
    std::optional<Button> fightButton;
    std::optional<Button> pokemonButton;
    std::vector<GameSprite> attackPokemonSprites;
    BattlePhase phase = BattlePhase::MainMenu;

public:
    BattleState(Pokemon_Party& party, const Pokemon& opponent);

    void handleEvent(const sf::Event& event) override;
    void render(sf::RenderWindow& window, Interface& interface) override;
    void update() override;

    void startDialogue(const std::string& text);
    void attackTurn(const std::string& playerAttack, const std::string& opponentAttack);
    void executeTurn();
    void choosePokemon(std::size_t index);
};