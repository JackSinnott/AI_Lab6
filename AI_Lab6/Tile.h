#ifndef TILE_H
#define TILE_H

#include "SFML/Graphics.hpp"

class Tile
{
public:
	Tile(int x, int y);
	~Tile();

private:
	int m_x, m_y;
	int m_cost;
	sf::RectangleShape m_rect;
};

#endif // !TILE_H
