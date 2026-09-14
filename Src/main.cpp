#include <iostream>

#include "Pokemon.hpp"
#include "Pokedex.hpp"
#include "Pokemon_Party.hpp"

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({1000, 800}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    std::cout << "Hello, World!" << std::endl;
    
    Pokemon pikachu(25, "Pikachu", 35, 50, 40, 1);
    //pikachu.displayInfo();
    Pokemon charmander(4, "Charmander", 30, 55, 35, 1);
    //charmander.displayInfo();
    Pokemon bulbasaur(1, "Bulbasaur", 45, 49, 49, 1);



    Pokedex* pokedex = Pokedex::getInstance("..\\..\\Ressources\\pokedex.csv");

    pokedex->getByIndex(25).displayInfo();
    pokedex->getByName("Charmander").displayInfo();
    pokedex->getByName("Bulbasaur").displayInfo();
    Pokemon_Party party=Pokemon_Party();

    party.addPokemon(pikachu);
    party.addPokemon(charmander);


    pikachu.canAttack(charmander);
    charmander.displayInfo(); 


    return 0;

   
    
}