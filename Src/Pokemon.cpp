#include "Pokemon.hpp"

#include <iostream>

int Pokemon::nbPokemon=0;

Pokemon::Pokemon(const int &id, const string &name, const double &hitPoint, const double &attack, const double &defense, const int &generation) : id(id), name(name), hitPoint(hitPoint), attack(attack), defense(defense), generation(generation) {
    nbPokemon++;
    imagePath = "../../Ressources/pokemon/" + std::to_string(id) + ".png";
}

Pokemon::Pokemon(const Pokemon& anotherPokemon)
        : id(anotherPokemon.id),
            name(anotherPokemon.name),
            hitPoint(anotherPokemon.hitPoint),
            attack(anotherPokemon.attack),
            defense(anotherPokemon.defense),
            generation(anotherPokemon.generation),
            imagePath(anotherPokemon.imagePath) {
        ++nbPokemon;
}

Pokemon::~Pokemon() {
    //std::cout << "Destructeur : " << name << std::endl;
}

int Pokemon::getId() const {return id;}

string Pokemon::getName() const {return name;}

double Pokemon::getAttack() const {return attack;}

double Pokemon::getDefense() const {return defense;}

double Pokemon::getHitPoint() const {return hitPoint;}

int Pokemon::getGeneration() const {return generation;}

int Pokemon::getNbPokemon() const {return nbPokemon;}


void Pokemon::displayInfo() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Hit Points: " << hitPoint << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Generation: " << generation << std::endl;
}

bool Pokemon::canAttack(Pokemon& target) const {
    if (attack > target.defense)
    {
        damage(target);
        return true;
    }
    else
    {
        return false;
    }
}

void Pokemon::damage(Pokemon& target) const{
    target.hitPoint -= (attack - target.defense);
    if (target.getHitPoint() < 1)
    {
        target.hitPoint = 1;
        std::cout << target.name << "is unable to fight !" << std::endl;
    }
    else
    {
        std::cout << target.name << " takes damage !" << std::endl;
    }
    
}


