/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:40:21 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 07:01:19 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(void)
{
	// std::cout << "Game created" << std::endl;
}

Game::Game(int maxY, int maxX)
{
	this->setMaxX(maxX);
	this->setMaxY(maxY);
	// std::cout << "Game created" << std::endl;
}

Game::~Game(void)
{
	// std::cout << "Game Dead" << std::endl;
}

Game::Game(Game const &other)
{
	*this = other;
}

Game &Game::operator=(Game const &other)
{
	if (this != &other)
	{

	}
	return (*this);
}

void	Game::setMaxX(int x)
{
	this->_maxX = x;
}

void	Game::setMaxY(int y)
{
	this->_maxY = y;
}

void	Game::setPlayer(Player &l)
{
	this->_player = &l;
}

void	Game::setEnemy(void)
{
	for (int i = 0; i < 10; i++)
	{
		this->_enemyes[i] = new Enemy;
	}
}

int		Game::getMaxY(void)
{
	return (_maxY);
}

int		Game::getMaxX(void)
{
	return (_maxX);
}

Player &Game::getPlayer(void)
{
	return (*this->_player);
}

// Enemy  &Game::getEnemy(void)
// {
// 	return (*this->_enemyes);
// }

void	Game::redraw(void)
{
	for (int i = 0; i < 10; i++)
	{
		mvaddch(this->_enemyes[i]->getPosY(), this->_enemyes[i]->getPosX(), ' ');
		// if (this->_enemyes[i]->getPosX() > 1)
			this->_enemyes[i]->setPosX(this->_enemyes[i]->getPosX() - 1);
		mvaddch(this->_enemyes[i]->getPosY(), this->_enemyes[i]->getPosX(), this->_enemyes[i]->getScin());
	}
}

int	Game::_maxX = 0;
int	Game::_maxY = 0;

