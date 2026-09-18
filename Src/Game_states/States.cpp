#include "States.hpp"

#include "Interface.hpp"

void TitleState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void TitleState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}

void StarterState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void StarterState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}

void MainMenuState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void MainMenuState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}

void PokedexState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void PokedexState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}

void PartyState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void PartyState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}

void BattleState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void BattleState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}

void ExitState::handleEvent(const sf::Event& event)
{
    (void)event;
}

void ExitState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);
}