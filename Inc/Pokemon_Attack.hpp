#pragma once

#include "SetOfPokemon.hpp"
#include "Pokemon.hpp"

class Pokemon_Attack:public SetOfPokemon
{
    private:
        const int maxPokemon = 6;
    public:
        Pokemon_Attack();
        ~Pokemon_Attack();

        void addPokemon(const Pokemon& pokemon);
        void removePokemonByName(const string& name);

        std::vector<Pokemon> getPokemons() const;

};