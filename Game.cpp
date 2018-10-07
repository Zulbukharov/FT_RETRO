/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:40:21 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 06:04:49 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(void)
{
	// std::cout << "Game created" << std::endl;
}

Game::Game(int maxX, int maxY)
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

void	Game::setEnemy(Enemy &l)
{
	this->_enemyes = &l;
}


int		Game::getMaxY(void)
{
	return (_maxX);
}

int		Game::getMaxX(void)
{
	return (_maxY);
}

Player &Game::getPlayer(void)
{
	return (*this->_player);
}

Enemy  &Game::getEnemy(void)
{
	return (*this->_enemyes);
}

void	Game::redraw(void)
{
	mvaddch(this->_enemyes->getPosY(), this->_enemyes->getPosX(), ' ');
	if (this->_enemyes->getPosX() > -1)
		this->_enemyes->setPosX(this->_enemyes->getPosX() - 1);
	mvaddch(this->_enemyes->getPosY(), this->_enemyes->getPosX(), this->_enemyes->getScin());
}

int	Game::_maxX = 0;
int	Game::_maxY = 0;

