#include "Game_states/MainMenuState.hpp"

#include "Interface.hpp"

void MainMenuState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void MainMenuState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}