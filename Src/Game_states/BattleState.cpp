#include "Game_states/BattleState.hpp"
#include "Game_states/ExplorationState.hpp"

#include "Interface.hpp"
#include "References.hpp"

#include <stdexcept>
#include <optional>

BattleState::BattleState(
    Pokemon_Party& party,
    const Pokemon& opponent)
    : party(party),
    playerPokemon(&party.getActivePokemon()),
      opponent(opponent),
      opponentSprite(opponent.getImagePath()),
        textBoxSprite("Ressources/textBoxWithBg.png"),
        font(PokemonFont),
        dialogueText(font, "", 32),
        fullText(),
        visibleCharacters(0),
        characterDelay(0.05f)
{

    
    if (!font.openFromFile(PokemonFont))
    {
        throw std::runtime_error(
            "Impossible de charger la police: " +
            std::string(PokemonFont));
    }
    dialogueText.setFillColor(sf::Color::Black);
    dialogueText.setPosition({100.f, 600.f});

    fleeButton.emplace("Ressources/FleeButton.png", font, "Flee", 32);
    fightButton.emplace("Ressources/FightButton.png", font, "Fight", 32);
    pokemonButton.emplace("Ressources/PokemonButton.png", font, "Pokemon", 32);
    fleeButton->setPosition({200.f, 100.f});
    fightButton->setPosition({700.f, 100.f});
    pokemonButton->setPosition({1200.f, 100.f});
    fleeButton->setScale({0.5f, 0.5f});
    fightButton->setScale({0.5f, 0.5f});
    pokemonButton->setScale({0.5f, 0.5f});

    activePokemonSprite.emplace(playerPokemon->getImagePath());
    activePokemonSprite->setScale({-3.f, 3.f});
    activePokemonSprite->setPosition({650.f, 250.f});

    opponentSprite.setScale({3.f, 3.f});
    opponentSprite.setPosition({950.f, 250.f});


    const auto attackPokemons = party.getAttackSetPokemons();
    constexpr float firstPokemonX = 160.f;
    constexpr float pokemonSpacing = 240.f;
    constexpr float pokemonY = 250.f;

    attackPokemonSprites.reserve(attackPokemons.size());

    for (std::size_t index = 0; index < attackPokemons.size(); ++index)
    {
        attackPokemonSprites.emplace_back(
            attackPokemons[index].getImagePath());
        attackPokemonSprites.back().setScale({2.5f, 2.5f});
        attackPokemonSprites.back().setPosition({
            firstPokemonX + static_cast<float>(index) * pokemonSpacing,
            pokemonY});
    }


    startDialogue("A wild Pokemon appeared!");
}

void BattleState::handleEvent(const sf::Event& event)
{
    if (phase != BattlePhase::MainMenu && phase != BattlePhase::ChoosingPokemon)
    {
        return;
    }
    
    const auto* mouseEvent = event.getIf<sf::Event::MouseButtonPressed>();

    if (mouseEvent == nullptr ||
        mouseEvent->button != sf::Mouse::Button::Left)
    {
        return;
    }

    sf::Vector2i mousePosition(
        static_cast<int>(mouseEvent->position.x),
        static_cast<int>(mouseEvent->position.y)
    );


    if (phase == BattlePhase::MainMenu)
    {
        if (pokemonButton.value().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            startDialogue("Choose a Pokemon!");
            phase = BattlePhase::ChoosingPokemon;
        }

        else if (fleeButton.value().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            startDialogue("You chose to flee!");
            action(std::make_unique<ExplorationState>(party));
        }

        else if (fightButton.value().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            phase = BattlePhase::PlayerTurn;
            startDialogue("You chose to fight!");
            executeTurn();
        }
    }
    else if (phase == BattlePhase::ChoosingPokemon)
    {
        for (std::size_t index = 0;
             index < attackPokemonSprites.size();
             ++index)
        {
            if (attackPokemonSprites[index].contains(
                    static_cast<sf::Vector2f>(mousePosition)))
            {
                choosePokemon(index);
                return;
            }
        }
    }

}

void BattleState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);

    if (phase != BattlePhase::ChoosingPokemon)
    {
        activePokemonSprite->setScale({-3.f, 3.f});
        activePokemonSprite->setPosition({650.f, 250.f});
        activePokemonSprite->draw(window);

        opponentSprite.setPosition({950.f, 250.f});
        opponentSprite.setScale({2.5f, 2.5f});
        opponentSprite.draw(window);
        

        if (phase == BattlePhase::MainMenu)
        {
            fightButton->draw(window);
            fleeButton->draw(window);
            pokemonButton->draw(window);
        }
    }
    else
    {
        for (GameSprite& pokemonSprite : attackPokemonSprites)
        {
            pokemonSprite.draw(window);
        }
    }
    textBoxSprite.setPosition({0.f, 520.f});
    textBoxSprite.setScale({1.f, 1.f});
    textBoxSprite.draw(window);

    window.draw(dialogueText);
}

void BattleState::update()
{
    if (visibleCharacters >= fullText.size())
    {
        if (textClock.getElapsedTime() < sf::seconds(dialoguePause))
        {
            return;
        }

        if (!dialogueQueue.empty())
        {
            fullText = dialogueQueue.front();
            dialogueQueue.pop_front();
            visibleCharacters = 0;
            textClock.restart();
            dialogueText.setString("");
        }
        return;
    }

    if (textClock.getElapsedTime() >= sf::seconds(characterDelay))
    {
        ++visibleCharacters;
        dialogueText.setString(fullText.substr(0, visibleCharacters));
        textClock.restart();
    }

    


}


void BattleState::startDialogue(const std::string& text)
{
    if (!fullText.empty())
    {
        dialogueQueue.push_back(text);
        return;
    }

    fullText = text;
    visibleCharacters = 0;
    textClock.restart();
    dialogueText.setString("");
}

void BattleState::attackTurn(const std::string& playerAttack, const std::string& opponentAttack)
{
    startDialogue("Player used " + playerAttack + "!\nOpponent used " + opponentAttack + "!");

}


void BattleState::executeTurn()
{
    if (phase != BattlePhase::PlayerTurn && phase != BattlePhase::OpponentTurn)
    {
        return;
    }

    if (playerPokemon->getAttack() < opponent.getDefense())
    {
        startDialogue(playerPokemon->getName() + "'s attack was \ntoo weak to damage " + opponent.getName() + "!");
        startDialogue("You can try to choose another\n Pokemon or flee!");
        phase = BattlePhase::MainMenu;
        
    }
    else
    {

    if (playerPokemon == nullptr || playerPokemon->getHitPoint() <= 1)
    {
        phase = BattlePhase::Defeat;
        startDialogue("You lost the battle!");
        return;
    }

    playerPokemon->canAttack(opponent);

    if (opponent.getHitPoint() <= 1)
    {
        phase = BattlePhase::Victory;
        startDialogue("You won the battle!");
        return;
    }

    opponent.canAttack(*playerPokemon);

    }

    phase = BattlePhase::MainMenu;
    startDialogue("What will you do?");
}


void BattleState::choosePokemon(std::size_t index)
{
    const auto attackPokemons = party.getAttackSetPokemons();
    const auto inventoryPokemons = party.getPokemons();

    if (index >= attackPokemons.size())
    {
        throw std::out_of_range("Invalid Pokemon index.");
    }

    for (std::size_t inventoryIndex = 0;
         inventoryIndex < inventoryPokemons.size();
         ++inventoryIndex)
    {
        if (inventoryPokemons[inventoryIndex].getName() ==
            attackPokemons[index].getName())
        {
            party.changeActivePokemon(inventoryIndex);
            playerPokemon = &party.getActivePokemon();
            activePokemonSprite.emplace(playerPokemon->getImagePath());
            activePokemonSprite->setScale({-3.f, 3.f});
            activePokemonSprite->setPosition({650.f, 250.f});
            startDialogue("You chose " + playerPokemon->getName() + "!");
            phase = BattlePhase::MainMenu;
            return;
        }
    }

    throw std::out_of_range("Pokemon is not in the inventory.");
}