#pragma once
#include <SFML/Graphics.hpp>

class Shader{
public:

    static sf::Color linearShading(short i){
        return {RGB(i%255, 255.f, 255.f)};
    }

    static sf::Color RGB(float fH, float fS, float fV) {
        float fR=0, fG=0, fB = 0;
        float fC = fV * fS;
        float fHPrime = fmod(fH / 60.0, 6);
        float fX = fC * (1 - fabs(fmod(fHPrime, 2) - 1));
        float fM = fV - fC;

        if(0 <= fHPrime && fHPrime < 1) {
            fR = fC;
            fG = fX;
            fB = 0;
        } else if(1 <= fHPrime && fHPrime < 2) {
            fR = fX;
            fG = fC;
            fB = 0;
        } else if(2 <= fHPrime && fHPrime < 3) {
            fR = 0;
            fG = fC;
            fB = fX;
        } else if(3 <= fHPrime && fHPrime < 4) {
            fR = 0;
            fG = fX;
            fB = fC;
        } else if(4 <= fHPrime && fHPrime < 5) {
            fR = fX;
            fG = 0;
            fB = fC;
        } else if(5 <= fHPrime && fHPrime < 6) {
            fR = fC;
            fG = 0;
            fB = fX;
        } else {
            fR = 0;
            fG = 0;
            fB = 0;
        }

        fR += fM;
        fG += fM;
        fB += fM;

        return {(unsigned char)fR, (unsigned char)fG, (unsigned char)fB};
    }

};