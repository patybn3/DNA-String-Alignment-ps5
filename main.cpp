/*
    Copyright 2023 Patricia Antlitz
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/System.hpp>
#include "EDistance.hpp"

int main(int argc, char const *argv[]) {
    std::string s1, s2;

    std::cin >> s1 >> s2;
    sf::Clock clock;
    // Create an EDistance object and compute the optimal distance
    EDistance edistance(s1, s2);
    int distance = edistance.optDistance();

    sf::Time elapsedTime = clock.getElapsedTime();
    // Output the optimal distance

    // Output the alignment
    std::cout << "Edit distance = " << distance << std::endl;
    std::string alignmentStr = edistance.alignment();
    std::cout << alignmentStr;
    std::cout << "Execution time is  : " << elapsedTime.asSeconds() << std::endl;

    return 0;
}
