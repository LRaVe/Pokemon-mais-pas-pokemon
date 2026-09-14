#pragma once

#include "SetOfPokemon.hpp"
#include "Pokemon.hpp"

#include <Vector>



class Pokemon_Party:public SetOfPokemon 
{
    private:
    public:
        Pokemon_Party();
        ~Pokemon_Party();

        void addPokemon(const Pokemon& pokemon);
        void removePokemonByName(const string& name);

        std::vector<Pokemon> getPokemons() const;

};