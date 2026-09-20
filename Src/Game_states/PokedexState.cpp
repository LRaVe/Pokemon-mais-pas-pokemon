#include "Game_states/PokedexState.hpp"

#include "Interface.hpp"

void PokedexState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void PokedexState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}