#include "Game_states/PartyState.hpp"

#include "Interface.hpp"

void PartyState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void PartyState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}