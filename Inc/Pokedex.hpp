#include "SetOfPokemon.hpp"

#include <iostream>

#include <fstream>
#include <sstream>


class Pokedex : public SetOfPokemon {
    private:
        static Pokedex* instance;
        Pokedex(const std::string& fileName);

        Pokedex(const Pokedex& anotherPokedex) = delete;
        Pokedex& operator=(const Pokedex& anotherPokedex) = delete;

    public:
        static Pokedex* getInstance(const std::string& fileName) {
            if (instance == nullptr) {
                instance = new Pokedex(fileName);
            }
            return instance;
        }

        ~Pokedex() {
            std::cout << "*** Destructeur du Pokedex ***" << std::endl;
        }
        Pokemon getByIndex(int index) override;
        Pokemon getByName(const std::string& name) override;
    };