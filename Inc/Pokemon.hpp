#pragma once

#include <string>

using std::string;

class Pokemon {
    private:
        int id;
        string name;
        double hitPoint;
        double attack;
        double defense;
        int generation;
        static int nbPokemon;
    public:
        Pokemon()=delete;
        Pokemon(const int &id, const string &name, const double &hitPoint, const double &attack, const double &defense, const int &generation);
        Pokemon(const Pokemon& anotherPokemon);
        
        ~Pokemon();

        int getId() const;
        string getName() const;
        double getHitPoint() const;
        double getAttack() const;
        double getDefense() const;
        int getGeneration() const;
        int getNbPokemon() const;

        void displayInfo() const;

        bool canAttack(Pokemon& target) const;

        void damage(Pokemon& target) const;

};
