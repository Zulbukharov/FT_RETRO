/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:40:21 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 09:19:22 by azulbukh         ###   ########.fr       */
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
	for (int i = 0; i < 3; i++)
	{
		this->_head.add();
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

void	Game::generateNew(void)
{
	if (this->_head.length <= 20 && (rand() % 30 == 2))
		this->_head.add();
}

void	Game::redraw(void)
{
	Object* head = _head.head;
	while(head)
	{
		mvaddch(head->getPosY(), head->getPosX(), ' ');
		if (head->getPosX() <= 1)
		{
			head->setPosX(_maxX - 1);
			head->setPosY(rand() % _maxY);
		}
		else
			head->setPosX(head->getPosX() - 1);
		mvaddch(head->getPosY(), head->getPosX(), head->getScin());	
		head = head->next;
	}
}

int	Game::_maxX = 0;
int	Game::_maxY = 0;

