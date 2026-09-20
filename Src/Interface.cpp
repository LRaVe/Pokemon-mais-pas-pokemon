#include "Interface.hpp"
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <iostream>

#include "References.hpp"
#include "Game.hpp"

Interface::Interface() {
    sf::Font font;
    if (!font.openFromFile(TasteBreadHD))
    {
        std::cerr << "Could not load font.\n";
    }
}
    


void Interface::render(sf::RenderWindow&) {
    

    
}
