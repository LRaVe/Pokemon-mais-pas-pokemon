#include "Game_states/ExplorationState.hpp"

#include <algorithm>
#include <iostream>
#include <random>

#include "Interface.hpp"
#include "References.hpp"
#include "Pokedex.hpp"

ExplorationState::ExplorationState(Pokemon_Party& party)
    : bgTexture(), 
    bgSprite(bgTexture), font(), 
    ExploreText(font, "Searching...",50), 
    hasFoundPokemon(false), 
    searchClock(), 
    isSearching(false),
    party(party)
{
    if (!bgTexture.loadFromFile(ExploreBackground)) {
        // Handle error
        throw std::runtime_error("Failed to load background texture");
    }

    bgSprite.setTexture(bgTexture,true);
    const sf::Vector2u textureSize = bgTexture.getSize();
    bgSprite.setPosition({0.f, 0.f});
    bgSprite.setScale({
    1600.f / static_cast<float>(textureSize.x),
    900.f / static_cast<float>(textureSize.y)
    });


    if (!font.openFromFile(GoldyBurst)) {
        // Handle error
        throw std::runtime_error("Failed to open font file");
    }

    captureButtonSprite.emplace(
        "Ressources/CaptureButton.png", font, "Capture", 50);
    fleeButtonSprite.emplace(
        "Ressources/FleeButton.png", font, "Flee", 50);
    fightButtonSprite.emplace(
        "Ressources/FightButton.png", font, "Fight", 50);

    captureButtonSprite->setPosition({1300.f, 300.f});
    captureButtonSprite->setScale({0.5f, 0.5f});
    fightButtonSprite->setPosition({1300.f, 500.f});
    fightButtonSprite->setScale({0.5f, 0.5f});
    fleeButtonSprite->setPosition({1300.f, 700.f});
    fleeButtonSprite->setScale({0.5f, 0.5f});


    ExploreText.setFillColor(sf::Color::Black);
    ExploreText.setFont(font);
    ExploreText.setCharacterSize(50);
    ExploreText.setString("Searching...");
    ExploreText.setPosition({300.f, 200.f});

    search();
}

void ExplorationState::handleEvent(const sf::Event& event)
{
    if (const auto* mouseButton = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButton->button == sf::Mouse::Button::Left)
        {
            const sf::Vector2f mousePos(
                static_cast<float>(mouseButton->position.x),
                static_cast<float>(mouseButton->position.y));
            
            std::cout << "Mouse clicked at: (" << mousePos.x << ", " << mousePos.y << ")" << std::endl;
            
            if (hasFoundPokemon &&
                !isCaptured &&
                captureButtonSprite->contains(mousePos))
            {
                int randomChance = std::rand() % 100; // Random number between 0 and 99
                if (randomChance < 50) { // 50% chance to capture
                    std::cout << "Pokemon captured!" << std::endl;
                    party.addPokemon(*foundPokemon);
                    isCaptured = true;
                    ExploreText.setString("Pokemon captured!");
                    ExploreText.setFillColor(sf::Color::Blue);

                    const auto partyPokemons = party.getPokemons();
                    const bool wasAdded = std::any_of(
                        partyPokemons.begin(),
                        partyPokemons.end(),
                        [this](const Pokemon& pokemon)
                        {
                            return pokemon.getName() == foundPokemon->getName();
                        });

                    if (wasAdded)
                    {
                        std::cout << foundPokemon->getName()
                                  << " added to the party." << std::endl;
                    }
                }
                else {
                    std::cout << "Capture failed!" << std::endl;
                    ExploreText.setString("Capture failed!");
                    ExploreText.setFillColor(sf::Color::Red);
                }

                hasFoundPokemon = false;
                isWaitingForNextSearch = true;
                nextSearchClock.restart();
                return;
            }

            if (hasFoundPokemon &&
                fleeButtonSprite->contains(mousePos))
            {
                std::cout << "You fled from the Pokemon!" << std::endl;
                foundPokemonSprite.reset();
                foundPokemon.reset();
                hasFoundPokemon = false;
                isWaitingForNextSearch = true;
                nextSearchClock.restart();
                return;
            }



            if (hasFoundPokemon &&
                fightButtonSprite->contains(mousePos))
            {
                std::cout << "You chose to fight the Pokemon!" << std::endl;
                
            }
        
        }

    
    }
}

void ExplorationState::render(sf::RenderWindow& window, Interface& interface)
{
    window.draw(bgSprite);
    interface.render(window);
    window.draw(ExploreText);

    if (foundPokemonSprite)
    {
        foundPokemonSprite->draw(window);
    }

    if (hasFoundPokemon)
    {
        captureButtonSprite->draw(window);
        fleeButtonSprite->draw(window);
        fightButtonSprite->draw(window);
    }
}

Pokemon ExplorationState::picKRandomPokemon() const
{
    Pokedex* pokedex = Pokedex::getInstance(pokedexCSV);
    const int totalPokemon = pokedex->getTotalPokemon();

    if (totalPokemon <= 0)
    {
        throw std::runtime_error("The Pokedex is empty");
    }

    static std::random_device device;
    static std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(0, totalPokemon - 1);
    const int randomIndex = distribution(generator);

    return pokedex->getByPosition(
        static_cast<std::size_t>(randomIndex));
}

void ExplorationState::search()
{
    if (isSearching || hasFoundPokemon)
    {
        return;
    }

    std::cout << "Searching for Pokemon..." << std::endl;
    isSearching = true;
    isCaptured = false;
    searchClock.restart();
    ExploreText.setString("Searching...");
    ExploreText.setFillColor(sf::Color::Black);
}

void ExplorationState::update()
{
    if (isWaitingForNextSearch)
    {
        if (nextSearchClock.getElapsedTime() >= sf::seconds(2.f))
        {
            foundPokemonSprite.reset();
            foundPokemon.reset();
            isCaptured = false;
            isWaitingForNextSearch = false;
            search();
        }

        return;
    }

    if (!isSearching ||
        searchClock.getElapsedTime() < sf::seconds(2.f))
    {
        return;
    }

    isSearching = false;
    hasFoundPokemon = true;

    try
    {
        foundPokemon = picKRandomPokemon();
        std::cout << "Image path: " << foundPokemon->getImagePath() << std::endl;
        foundPokemonSprite.emplace(foundPokemon->getImagePath());
        foundPokemonSprite->setScale({5.f, 5.f});
        foundPokemonSprite->setPosition({500.f, 400.f});
        ExploreText.setString(
            "You found a wild Pokemon : " + foundPokemon->getName());
        std::cout << "You found a wild Pokemon: "
                  << foundPokemon->getName() << std::endl;
        ExploreText.setFillColor(sf::Color::Green);
    }
    catch (const std::exception& error)
    {
        std::cerr << "Erreur lors du chargement du sprite : "
                  << error.what() << '\n';
        hasFoundPokemon = false;
        return;
    }
}
