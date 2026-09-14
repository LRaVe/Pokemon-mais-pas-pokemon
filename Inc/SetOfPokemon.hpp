#pragma once

#include "Pokemon.hpp"
#include <vector>

using std::string;

class SetOfPokemon
{
protected:
    std::vector<Pokemon> pokemons;
public:
    SetOfPokemon();
    ~SetOfPokemon();

    virtual Pokemon getByIndex(int index);

    virtual Pokemon getByName(const string& name);

    void displayAllPokemons() const;

};