#include "Pokemon_Attack.hpp"
#include "Pokemon.hpp"
#include <stdexcept>
#include <vector>

Pokemon_Attack::Pokemon_Attack() : SetOfPokemon() {
}

Pokemon_Attack::~Pokemon_Attack() {
}


void Pokemon_Attack::addPokemon(const Pokemon& pokemon) {
    if (pokemons.size() < maxPokemon) {
        pokemons.push_back(pokemon);
    } else {
        throw std::length_error("Cannot add more than 6 Pokemons.");
    }
}

bool Pokemon_Attack::removePokemonByName(const string& name){
    for (auto it = pokemons.begin(); it != pokemons.end(); ++it) {
        if (it->getName() == name) {
            pokemons.erase(it);
            return true;
        }
    }
    return false;
}



std::vector<Pokemon> Pokemon_Attack::getPokemons() const {
    return pokemons;
}

