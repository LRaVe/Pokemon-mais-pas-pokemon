#pragma once

#include "SetOfPokemon.hpp"
#include "Pokemon.hpp"
#include "Pokemon_Attack.hpp"

#include <vector>



class Pokemon_Party:public SetOfPokemon 
{
    private:
    // A chaque instance de Pokemon_Party, il y a un objet Pokemon_Attack qui représente l'ensemble des Pokémon en attaque.
        Pokemon_Attack attackSet;
        std::size_t activePokemon = 0;
    public:
        Pokemon_Party();
        ~Pokemon_Party();

        void addPokemon(const Pokemon& pokemon);
        void removePokemonByName(const string& name);
        void addPokemonToAttackSet(const Pokemon& pokemon);
        void removePokemonFromAttackSetByName(const string& name);

        std::vector<Pokemon> getPokemons() const;

        std::vector<Pokemon> getAttackSetPokemons() const;

        Pokemon& getActivePokemon();
        const Pokemon& getActivePokemon() const;
        void changeActivePokemon(std::size_t index);

};