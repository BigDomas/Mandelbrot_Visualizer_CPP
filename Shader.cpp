#include "Shader.h"

sf::Color Shader::linearShading(short numSteps) {
    if (numSteps == -1)
        return sf::Color(sf::Color::Black);
    else if (numSteps == -2){
        return sf::Color(sf::Color::Black);
    }
    return HSVtoRGB(numSteps,1,1);
}

sf::Color Shader::logarithmicShading(short numSteps) {
    if (numSteps == -1)
        return sf::Color(sf::Color::Black);
    else if (numSteps == -2)
        return sf::Color(sf::Color::Black);
    return HSVtoRGB(50*(float)log(numSteps+1),1,1);
}

sf::Color Shader::HSVtoRGB(float H, float S, float V) {
    float C = S * V;
    float HPrime = std::fmod(H *0.0233f, 6.f); // H'
    float X = C * (1 - std::fabs(std::fmod(HPrime, 2.f) - 1));
    float M = V - C;

    float R = 0.f;
    float G = 0.f;
    float B = 0.f;

    switch (static_cast<int>(HPrime)) {
        case 0: R = C; G = X;        break; // [0, 1)
        case 1: R = X; G = C;        break; // [1, 2)
        case 2:        G = C; B = X; break; // [2, 3)
        case 3:        G = X; B = C; break; // [3, 4)
        case 4: R = X;        B = C; break; // [4, 5)
        case 5: R = C;        B = X; break; // [5, 6)
    }

    R += M;
    G += M;
    B += M;

    sf::Color color;
    color.r = static_cast<sf::Uint8>(std::round(R * 255));
    color.g = static_cast<sf::Uint8>(std::round(G * 255));
    color.b = static_cast<sf::Uint8>(std::round(B * 255));

    return color;
}
