cmake_minimum_required(VERSION 3.20)

project(Pokemon
    VERSION 1.0
    LANGUAGES CXX
)



set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    Src/main.cpp
    Src/Pokemon.cpp
    Src/Pokedex.cpp
    Src/SetOfPokemon.cpp
    Src/Pokemon_Party.cpp
    Src/Pokemon_Attack.cpp
    Src/Interface.cpp
    Src/Game.cpp
    Src/Game_states/TitleState.cpp
    Src/Game_states/StarterState.cpp
    Src/Game_states/PartyState.cpp
    Src/Game_states/BattleState.cpp
    Src/Game_states/ExplorationState.cpp
    Src/GameSprite.cpp
    Src/Button.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

if(WIN32)
    set(VCPKG_INSTALLED_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")
    if(EXISTS "${VCPKG_INSTALLED_DIR}")
        list(PREPEND CMAKE_PREFIX_PATH "${VCPKG_INSTALLED_DIR}")
    endif()
endif()

find_package(SFML COMPONENTS Graphics Window System CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/Ressources"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/Ressources"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${VCPKG_INSTALLED_DIR}/bin"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${VCPKG_INSTALLED_DIR}/debug/bin"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
    )
else()
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/Ressources"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/Ressources"
    )
endif()

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    BUNDLE DESTINATION .
)

install(DIRECTORY "${CMAKE_SOURCE_DIR}/Ressources"
    DESTINATION bin
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/Inc
)
