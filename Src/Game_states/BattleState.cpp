#include "Game_states/BattleState.hpp"

#include "Interface.hpp"

void BattleState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void BattleState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}