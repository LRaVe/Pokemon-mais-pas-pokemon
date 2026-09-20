#include "Pokedex.hpp"
#include "Pokemon_Party.hpp"
#include "References.hpp"
#include "Interface.hpp"
#include <memory>

class GameState;


class Game
{
private:
    Pokedex* pokedex;
    Pokemon_Party party;   
    sf::RenderWindow window;
    Interface interface;
    std::unique_ptr<GameState> currentState;



public:
    Game();
    ~Game();
    void changeState(std::unique_ptr<GameState> state);
    const GameState& getCurrentState() const;
    void run();
};
