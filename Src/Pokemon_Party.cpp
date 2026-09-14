#include "Pokemon_Party.hpp"
#include "Pokemon.hpp"
#include <stdexcept>

Pokemon_Party::Pokemon_Party() : SetOfPokemon() {
}

Pokemon_Party::~Pokemon_Party() {
}

void Pokemon_Party::addPokemon(const Pokemon& pokemon) {
    pokemons.push_back(pokemon);
}

void Pokemon_Party::removePokemonByName(const string& name){
    for (auto it = pokemons.begin(); it != pokemons.end(); ++it) {
        if (it->getName() == name) {
            pokemons.erase(it);
            return;
        }
    }
    throw std::runtime_error(name + " is not in the party.");
}

std::vector<Pokemon> Pokemon_Party::getPokemons() const {
    return pokemons;
}
