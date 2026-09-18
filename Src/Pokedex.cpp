#include "Pokedex.hpp" 

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

Pokedex* Pokedex::instance = nullptr;

Pokedex::Pokedex(const std::string& fileName):SetOfPokemon() {

    std::cout << "*** Constructeur du Pokedex ***" << std::endl;


    std::ifstream file(fileName);
    if(!file.is_open()){
        std::cerr<<"File "<<fileName<<" not found "<<std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
    //    std::cout << line << std::endl;
        std::stringstream inputstringstream(line);
        std::string cell;
        std::vector<std::string> lineData;

        while(std::getline(inputstringstream,cell,',')){
            lineData.push_back(cell);
        }
        int id = std::stoi(lineData.at(0));
        double attackValue = std::stod(lineData.at(6));
        double hitPoint = std::stod(lineData.at(5));
        double defenseValue = std::stod(lineData.at(7));
        int generation = std::stoi(lineData.at(11));

        pokemons.push_back(Pokemon(id,lineData.at(1),hitPoint,attackValue,
                                            defenseValue,generation));
    }
}

Pokemon Pokedex::getByIndex(int index) {
    for (const auto& pokemon : pokemons) {
        if (pokemon.getId() == index) {
            return Pokemon(pokemon);
        }
    }
    throw std::runtime_error("Pokemon with id " + std::to_string(index) + " not found.");
}

Pokemon Pokedex::getByName(const std::string& name) {
    for (const auto& pokemon : pokemons) {
        if (pokemon.getName() == name) {
            return Pokemon(pokemon);
        }
    }
    throw std::runtime_error("Pokemon with name " + name + " not found.");
}

std::string Pokedex::getPokemonImage(int index) const {
    return "../../Ressources/pokemon/" + std::to_string(index) + ".png";
}