void drawFromPoints(int N, std::vector<sf::Vector2f> &arr, float dt, sf::RenderWindow& win);
sf::Vector2f toWindowCoords(sf::Vector2f pt, int width, int height);
sf::Vector2f toCartesianCoords(sf::Vector2f pt, int width, int height);