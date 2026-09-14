#include "SetOfPokemon.hpp"

#include <stdexcept>

SetOfPokemon::SetOfPokemon(/* args */)
{
}

SetOfPokemon::~SetOfPokemon()
{
}

Pokemon SetOfPokemon::getByIndex(int index) {
    for (const auto& pokemon : pokemons) {
        if (pokemon.getId() == index) {
            return pokemon;
        }
    }
    throw std::runtime_error("Pokemon with id " + std::to_string(index) + " not found.");
}

Pokemon SetOfPokemon::getByName(const string& name) {
    for (const auto& pokemon : pokemons) {
        if (pokemon.getName() == name) {
            return pokemon;
        }
    }
    throw std::runtime_error("Pokemon with name " + name + " not found.");
}

void SetOfPokemon::displayAllPokemons() const {
    for (const auto& pokemon : pokemons) {
        pokemon.displayInfo();
    }
}
