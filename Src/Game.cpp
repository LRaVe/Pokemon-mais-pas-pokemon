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
            currentState(std::make_unique<TitleState>()),
            interface()
{
    party.addPokemon(pokedex->getByName("Pikachu"));
    window.create(sf::VideoMode({1000, 800}), "SFML works!");

    

    
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
        
        window.clear();
        currentState->render(window, interface);
        window.display();
    }
}