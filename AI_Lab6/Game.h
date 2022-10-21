#ifndef GAME_H

#include "SFML/Graphics.hpp"

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	float m_rectSize = 10.f;

	sf::RectangleShape m_rect;
	std::vector<sf::RectangleShape> m_tiles;
	sf::RenderWindow m_window;

};

#endif // !GAME_H
