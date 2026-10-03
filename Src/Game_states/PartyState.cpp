#include "Game_states/PartyState.hpp"
#include "Game_states/ExplorationState.hpp"

#include "Interface.hpp" 
#include "References.hpp"


PartyState::PartyState(Pokemon_Party& party)
    : font(PokemonFont), party(party)
{
    const auto pokemons = party.getPokemons();
    constexpr float firstPokemonX = 50.f;
    constexpr float firstPokemonY = 50.f;
    constexpr float pokemonSpacingX = 380.f;
    constexpr float pokemonSpacingY = 260.f;
    constexpr std::size_t columns = 3;

    ReturnButton.emplace(
        "Ressources/PokemonButton.png", font , "Return", 50);

    ReturnButton->setPosition({1300.f, 700.f});
    ReturnButton->setScale({0.5f, 0.5f});

    pokemonSprites.reserve(pokemons.size());
    for (std::size_t index = 0; index < pokemons.size(); ++index)
    {
        pokemonSprites.emplace_back(pokemons[index].getImagePath());
        pokemonSprites.back().setScale({2.5f, 2.5f});
        pokemonSprites.back().setPosition({
            firstPokemonX + static_cast<float>(index % columns) * pokemonSpacingX,
            firstPokemonY + static_cast<float>(index / columns) * pokemonSpacingY});
    }
}


void PartyState::handleEvent(const sf::Event& event)
{
    sf::Vector2i mousePosition;
    if (const auto* mouseEvent = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseEvent->button == sf::Mouse::Button::Left)
        {
            mousePosition = {mouseEvent->position.x, mouseEvent->position.y};
        }

        if (ReturnButton->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            action(std::make_unique<ExplorationState>(party));
        }
    }
}

void PartyState::render(sf::RenderWindow& window, Interface& interface)
{
    interface.render(window);

    for (GameSprite& pokemonSprite : pokemonSprites)
    {
        pokemonSprite.draw(window);
    }


    ReturnButton->draw(window);
}

void PartyState::update()
{

}