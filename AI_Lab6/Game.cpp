#include "Game.h"

Game::Game() : m_window{ sf::VideoMode{1800, 1620}, "AI Lab Six" }
{
	m_rect.setSize(sf::Vector2f(m_rectSize, m_rectSize));
	m_rect.setPosition(1.f, 1.f);
	m_rect.setFillColor(sf::Color::Blue);

	for (int x = 1; x < 50; ++x)
	{
		for (int y = 1; y < 50; ++y)
		{
			m_rect.setPosition(sf::Vector2f{m_rectSize * x, m_rectSize * y});
			m_tiles.push_back(m_rect);
		}
	}
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
	}
}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (newEvent.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	render();
}

void Game::render()
{
	m_window.clear();
	for (int i = 0; i < 50; i++)
	{
		for (int y = 0; y < 50; y++)
		{
			m_window.draw(m_tiles.at(y));
		}
	}
	m_window.display();
}
