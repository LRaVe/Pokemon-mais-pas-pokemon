#include "Game_states/ExitState.hpp"

#include "Interface.hpp"

void ExitState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void ExitState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}