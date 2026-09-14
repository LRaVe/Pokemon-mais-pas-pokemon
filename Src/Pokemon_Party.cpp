#include "Pokemon_Party.hpp"
#include "Pokemon_Attack.hpp"
#include "Pokemon.hpp"
#include <stdexcept>

Pokemon_Party::Pokemon_Party() : SetOfPokemon(), attackSet() {
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

void Pokemon_Party::addPokemonToAttackSet(const Pokemon& pokemon) {
    // Ajoute le Pokémon à l'attaque
    this->attackSet.addPokemon(pokemon);
    // Supprime le Pokémon de la liste principale
    for (auto it = pokemons.begin(); it != pokemons.end(); ++it) {
        if (it->getName() == pokemon.getName()) {
            pokemons.erase(it);
            return;
        }
    }
    throw std::runtime_error(pokemon.getName() + " is not in the party.");
}

void Pokemon_Party::removePokemonFromAttackSetByName(const string& name) {
    // Ajoute le Pokémon de l'attaque à la liste principale
    pokemons.push_back(this->attackSet.getByName(name));
    // Supprime le Pokémon de l'attaque
    this->attackSet.removePokemonByName(name);
    
}

std::vector<Pokemon> Pokemon_Party::getPokemons() const {
    return pokemons;
}

std::vector<Pokemon> Pokemon_Party::getAttackSetPokemons() const {
    return attackSet.getPokemons();
}
