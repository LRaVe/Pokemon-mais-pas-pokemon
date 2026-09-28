# TP Introduction en C++

Auteur : Lucas Raveloarinoro


## Introduction

Ce projet est une première introduction au langage C++. Il s'agit d'un jeu s'inspirant de Pokemon. Il a été réalisé en 18h et contient les premiers objets clés du jeu, pour une version simplifiée.

## Classes

- `Pokemon` : représente un Pokémon avec son id, son nom, ses points de vie, son attaque, sa défense et sa génération. Pour l'instant, on ne peut qu'attaquer.
- `SetOfPokemon` : classe abstraite qui stocke une collection de Pokémons et permet de les rechercher par id ou par nom.
- `Pokedex` : hérite de `SetOfPokemon`. Elle utilise le design pattern Singleton.
- `Pokemon_Party` : hérite de `SetOfPokemon` et représente l'ensemble des pokemons du joueur. Elle possède également un `Pokemon_Attack` pour les Pokémons actuellement en attaque.
- `Pokemon_Attack` : hérite de `SetOfPokemon` et représente l’ensemble des Pokémons placés en attaque, avec une limite de six Pokémons.

## Diagramme de classes

```mermaid
classDiagram
  class Pokemon {
    -int id
    -string name
    -double hitPoint
    -double attack
    -double defense
    -int generation
    +canAttack(Pokemon target) bool
    +damage(Pokemon target) void
  }

  class SetOfPokemon {
    #vector~Pokemon~ pokemons
    +getByIndex(int index) Pokemon
    +getByName(string name) Pokemon
    +displayAllPokemons() void
  }

  class Pokedex {
    -Pokedex* instance
    +getInstance(string fileName) Pokedex*
    +getByPosition(size_t position) Pokemon
    +getTotalPokemon() int
  }

  class Pokemon_Party {
    -Pokemon_Attack attackSet
    -size_t activePokemon
    +addPokemon(Pokemon pokemon) void
    +changeActivePokemon(size_t index) void
    +getActivePokemon() Pokemon
  }

  class Pokemon_Attack {
    -const int maxPokemon = 6
    +addPokemon(Pokemon pokemon) void
    +removePokemonByName(string name) bool
  }

  SetOfPokemon <|-- Pokedex
  SetOfPokemon <|-- Pokemon_Party
  SetOfPokemon <|-- Pokemon_Attack
  SetOfPokemon "1" o-- "0..*" Pokemon : contient
  Pokemon_Party *-- "1" Pokemon_Attack : possède
  Pokedex "1" --> "1" Pokedex : singleton
```

## Interface Graphique

Cette étape n'est qu'en développement pour l'instant, lors de l'execution, fermez la fenêtre pour voir le programme dans le CLI.

## Comment build le projet

Si vous cherchez à le build depuis le CLI, il faut être à la racine du projet, et avoir CMake et vcpkg installés. Il faut ensuite taper : 
```powershell
cmake -S . -B build `
  -DCMAKE_TOOLCHAIN_FILE="C:\path_to_vcpkg\vcpkg\scripts\buildsystems\vcpkg.cmake"```

Puis 
```cmake --build build --config Debug```

Et lancer le programme : 
```Pokemon.exe```