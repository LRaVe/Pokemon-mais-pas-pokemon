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
    throw std::out_of_range(name + " is not in the party.");
}

void Pokemon_Party::addPokemonToAttackSet(const Pokemon& pokemon) {
    // L'équipe active est un sous-ensemble de l'inventaire.
    this->attackSet.addPokemon(pokemon);
}

void Pokemon_Party::removePokemonFromAttackSetByName(const string& name) {
    // Le Pokémon reste dans l'inventaire lorsqu'il quitte l'équipe active.
    this->attackSet.removePokemonByName(name);
}

std::vector<Pokemon> Pokemon_Party::getPokemons() const {
    return pokemons;
}

std::vector<Pokemon> Pokemon_Party::getAttackSetPokemons() const {
    return attackSet.getPokemons();
}

Pokemon& Pokemon_Party::getActivePokemon()
{
    if (pokemons.empty())
    {
        throw std::runtime_error("The party is empty.");
    }

    return pokemons[activePokemon];
}

const Pokemon& Pokemon_Party::getActivePokemon() const
{
    if (pokemons.empty())
    {
        throw std::runtime_error("The party is empty.");
    }

    return pokemons[activePokemon];
}


void Pokemon_Party::changeActivePokemon(std::size_t index) {
    if (index >= pokemons.size()) {
        throw std::out_of_range("Index out of range");
    }
    activePokemon = index;
}
