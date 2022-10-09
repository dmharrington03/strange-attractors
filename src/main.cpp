#include <SFML/Graphics.hpp>
#include <vector>
#include "headers.hpp"
#include "funcs.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#define PI 3.14159



std::vector<sf::Vector2f> pts;

const float dt = 0.001;
const float rho = 28;
const float sigma = 10;
const float beta = 2.66666667;

const int width = 1200;
const int height = 1200;

const int size = 100000;


int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    sf::RectangleShape shape(sf::Vector2f(2, 100));
    shape.setFillColor(sf::Color::White);
    shape.setPosition(500, 500);
    shape.setRotation(45.f);

    // for (int i = 0; i < 7; i++) {
    //     pts.push_back(sf::Vector2f(500 + 100 * cos(i * (2 * PI) / 6), 500 - 100 * sin(i * (2 * PI) / 6)));
    // }
    // pts.push_back(sf::Vector2f(600, 600));
    // pts.push_back(sf::Vector2f(600, 300));
    // pts.push_back(sf::Vector2f(300, 300));
    // pts.push_back(sf::Vector2f(300, 600));
    // pts.push_back(sf::Vector2f(600, 600));

    //TODO projection, rotation

    sf::Vector3f dr(0, 0, 0);
    sf::Vector3f r(.01, .01, .01);
    pts.push_back(toWindowCoords(sf::Vector2f(r.z * 5, r.y * 5), width, height));

    // std::cout << "Vector: \n";
    // Populate vector
    for (int i = 0; i < size; i++) {
        dr.x = sigma * (r.y - r.x) * dt;
        dr.y = (r.x * (rho - r.z) - r.y) * dt;
        dr.z = (r.x * r.y - beta * r.z) * dt;
        r = r + dr;
        // std::cout << "(" + std::to_string(r.x) + ", " + std::to_string(r.y) + ")\n";
        pts.push_back(toWindowCoords(sf::Vector2f(r.z * 15 - 400, r.y * 15), width, height));
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        window.clear();
        // window.draw(shape);
        drawFromPoints(size, pts, window);
        window.display();
    }

    return 0;
}
