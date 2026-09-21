#include "Game_states/StarterState.hpp"
#include "Game_states/ExplorationState.hpp"

#include "Interface.hpp"
#include "References.hpp"
#include "Game.hpp"
#include <array>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <iostream>


StarterState::StarterState(Pokemon_Party& party)
    : font(GoldyBurst),
    ChooseText(font, "Choose your starter Pokemon!", 48),
     starterPokemonSprites{
          std::make_unique<GameSprite>("Ressources/pokemon/1.png"),
          std::make_unique<GameSprite>("Ressources/pokemon/4.png"),
          std::make_unique<GameSprite>("Ressources/pokemon/7.png")},
     party(party)
{
    starterPokemonSprites[0]->setPosition({328.f, 306.f});
    starterPokemonSprites[1]->setPosition({656.f, 306.f});
    starterPokemonSprites[2]->setPosition({984.f, 306.f});
    for (auto& sprite : starterPokemonSprites)
    {
        sprite->setScale({3.f, 3.f});
    }
    if (!font.openFromFile(GoldyBurst)) {
        // Handle error
        throw std::runtime_error("Failed to open font file");
    }
    ChooseText.setFillColor(sf::Color::Black);
    ChooseText.setFont(font);
    ChooseText.setCharacterSize(48);
    ChooseText.setString("Choose your starter Pokemon!");
    ChooseText.setPosition({328.f, 250.f});
}

void StarterState::handleEvent(const sf::Event& event)
{
    if (const auto* mouseButton = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButton->button == sf::Mouse::Button::Left)
        {
            const sf::Vector2f mousePos(
                static_cast<float>(mouseButton->position.x),
                static_cast<float>(mouseButton->position.y));

            for (const std::unique_ptr<GameSprite>& sprite : starterPokemonSprites)
            {
                if (sprite->contains(mousePos))
                {
                    isPokemonSelected = true;
                    std::cout << "Pokemon selected!" << std::endl;
                    
                    break;
                }
            }
        }

    
    }
    if (const auto* mouseMove = event.getIf<sf::Event::MouseMoved>())
    {
        sf::Vector2f mousePos(
            static_cast<float>(mouseMove->position.x),
            static_cast<float>(mouseMove->position.y)
        );

        for (auto& sprite : starterPokemonSprites)
        {
            sprite->setHighlighted(sprite->contains(mousePos));
        }
    }

    if (isPokemonSelected && action)
    {
        action(std::make_unique<ExplorationState>(party));
    }
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

void StarterState::update()
{
}