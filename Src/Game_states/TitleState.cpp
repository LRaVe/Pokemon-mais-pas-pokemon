#include "Game_states/TitleState.hpp"

#include "Interface.hpp"

void TitleState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void TitleState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}