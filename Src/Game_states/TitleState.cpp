#include "Game_states/TitleState.hpp"
#include "Game_states/StarterState.hpp"

#include "Interface.hpp"
#include <iostream>
#include "References.hpp"

TitleState::TitleState(Pokemon_Party& party)
    :font(), titleText(font, "Pokemon Game", 50), party(party)
{
    if (!font.openFromFile(PokemonFont)) {
        throw std::runtime_error("Failed to load font");
    }

    titleText.setFillColor(sf::Color::Red);
    titleText.setPosition({400.f, 200.f});
    titleText.setString("Pokemon Game");
    titleText.setCharacterSize(70);

    startButton.emplace("Ressources/FightButton.png", font, "START", 50);
    startButton->setPosition({500.f, 500.f});
    startButton->setScale({1.0f, 1.0f});
}


void TitleState::handleEvent(const sf::Event& event)
{
    sf::Vector2i mousePosition;
    if (const auto* mouseEvent = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseEvent->button == sf::Mouse::Button::Left)
        {
            mousePosition = {mouseEvent->position.x, mouseEvent->position.y};
        }

        // Check if the mouse click is within the bounds of the "Start" button
        if (startButton->contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            // Transition to the StarterState
            action(std::make_unique<StarterState>(party));
        }
    }
}

void TitleState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
    window.draw(titleText);
    startButton->draw(window);
}

void TitleState::update()
{
    // No specific update logic for the title state
}