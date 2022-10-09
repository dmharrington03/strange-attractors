#include "headers.hpp"
#include <vector>
#include <math.h>

#define PI 3.14159

void drawFromPoints(int N, std::vector<sf::Vector2f> &arr, sf::RenderWindow& win) {
/* Params: 
    N: length of vector
    arr: pointer to vector of points
    win: reference to sfml window
*/
    for (int i = 0; i < N-1; i++) {
        sf::Vector2f r = arr.at(i+1) - arr.at(i);
        float dist = hypotf(r.x, r.y);
        float angle = atan2(r.y, r.x);
        sf::RectangleShape line(sf::Vector2f(1, dist));
        line.setFillColor(sf::Color::White);
        line.setPosition(arr.at(i));
        line.setRotation(-90 + angle * 180 / PI);
        win.draw(line);
    }
}

sf::Vector2f toCartesianCoords(sf::Vector2f pt, int width, int height) {
    return sf::Vector2f(pt.x - width / 2, -pt.y + height / 2);
}

sf::Vector2f toWindowCoords(sf::Vector2f pt, int width, int height) {
    return sf::Vector2f(pt.x + width / 2, -pt.y + height / 2);
}