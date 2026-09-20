#include "Game_states/StarterState.hpp"

#include "Interface.hpp"
#include <array>
#include <SFML/Graphics.hpp>
#include <stdexcept>

StarterState::StarterState()
    : font(),
    ChooseText(font, "Choose your starter Pokemon!", 48),
     starterPokemonSprites{
          std::make_unique<GameSprite>("../../Ressources/pokemon/1.png"),
          std::make_unique<GameSprite>("../../Ressources/pokemon/4.png"),
          std::make_unique<GameSprite>("../../Ressources/pokemon/7.png")}
{
    starterPokemonSprites[0]->setPosition({328.f, 306.f});
    starterPokemonSprites[1]->setPosition({656.f, 306.f});
    starterPokemonSprites[2]->setPosition({984.f, 306.f});
    for (auto& sprite : starterPokemonSprites)
    {
        sprite->setScale({3.f, 3.f});
    }
    if (!font.openFromFile("../../Ressources/Taste Bread HD.otf")) {
        // Handle error
    }
    ChooseText.setFont(font);
    ChooseText.setString("Choose your starter Pokémon!");
    ChooseText.setCharacterSize(48);
    ChooseText.setFillColor(sf::Color::Black);
    ChooseText.setPosition({656.f, 250.f});
}

void StarterState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void StarterState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);

    window.draw(ChooseText);

    for (const std::unique_ptr<GameSprite>& sprite : starterPokemonSprites)
    {
        sprite->draw(window);
    }
}