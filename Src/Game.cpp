#include "Game.hpp"
#include <iostream>
#include <stdexcept>

#include "Pokemon.hpp"
#include "Pokedex.hpp"
#include "Pokemon_Party.hpp"
#include "References.hpp"
#include "States.hpp"

#include "Interface.hpp"


Game::Game()
    : pokedex(Pokedex::getInstance(pokedexCSV)),
      party(),
      window(),
      interface(),
      currentState(std::make_unique<StarterState>())
{
    window.create(sf::VideoMode({1600, 900}),
    "Pokemon",
    sf::Style::Default,
    sf::State::Windowed);

    

    
}

Game::~Game() {
    std::cout << "*** Destructeur du Game ***" << std::endl;
}

const GameState& Game::getCurrentState() const {
    return *currentState;
}

void Game::changeState(std::unique_ptr<GameState> state) {
    currentState = std::move(state);
}

void Game::run(){
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            currentState->handleEvent(*event);
        }
        
        window.clear(sf::Color::White);
        currentState->render(window, interface);
        window.display();
    }
}