#include <iostream>

#include "Pokemon.hpp"
#include "Pokedex.hpp"
#include "Pokemon_Party.hpp"
#include "Pokemon_Attack.hpp"

#include "References.hpp"

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({1000, 800}), "SFML works!");
    sf::Font font;
    if (!font.openFromFile(TasteBreadHD))
    {
        std::cerr << "Could not load font.\n";
    }
    sf::Text text(font, "Salut!", 24);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }
    std::cout << "Hello, World!" << std::endl;
    
    Pokemon pikachu(25, "Pikachu", 35, 50, 40, 1);
    //pikachu.displayInfo();
    Pokemon charmander(4, "Charmander", 30, 55, 35, 1);
    //charmander.displayInfo();
    Pokemon bulbasaur(1, "Bulbasaur", 45, 49, 49, 1);

    
    pikachu.canAttack(charmander);
    charmander.displayInfo(); 



    Pokedex* pokedex = Pokedex::getInstance(pokedexCSV);
    Pokemon_Party party = Pokemon_Party();


    pokedex->getByIndex(25).displayInfo();
    pokedex->getByName("Charmander").displayInfo();
    pokedex->getByName("Bulbasaur").displayInfo();


    party.addPokemon(pikachu);
    party.addPokemon(charmander);

    //Test de deplacement d'un Pokémon de la liste principale vers l'attaque 

    party.addPokemon(pokedex->getByName("Charizard"));
    std::cout << "Pokemons in party: " << std::endl;
    for (const auto& pokemon : party.getPokemons()) {
        pokemon.displayInfo();
    }

    party.addPokemonToAttackSet(party.getByName("Charizard"));
    std::cout << "Pokemons in attack set: " << std::endl;
    for (const auto& pokemon : party.getAttackSetPokemons()) {
        pokemon.displayInfo();
    }

    std::cout << "Pokemons in party after the change: " << std::endl;
    for (const auto& pokemon : party.getPokemons()) {
        pokemon.displayInfo();
    }

    party.removePokemonFromAttackSetByName("Charizard");
    std::cout << "Pokemons in attack set after the change: " << std::endl;
    for (const auto& pokemon : party.getAttackSetPokemons()) {
        pokemon.displayInfo();
    }

    std::cout << "Pokemons in party after the change: " << std::endl;
    for (const auto& pokemon : party.getPokemons()) {
        pokemon.displayInfo();
    }




    return 0;

   
    
}