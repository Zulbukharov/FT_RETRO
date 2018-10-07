/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:40:21 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 15:03:35 by azulbukh         ###   ########.fr       */
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
		*this = other;
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
		if ((head->getPosX() == _player->getPosX() + 1 &&
		head->getPosY() == _player->getPosY()) ||
		(head->getPosY() == _player->getPosY() + 1 &&
		head->getPosX() == _player->getPosX()) ||
		(head->getPosY() == _player->getPosY() - 1 &&
		head->getPosX() == _player->getPosX()))
		{
			_player->setHP(_player->getHP() - 1);
			head->setPosX(_maxX - 1);
			head->setPosY(rand() % _maxY);
		}
		if (head->getPosX() <= 1)
		{
			head->setPosX(_maxX - 1);
			head->setPosY(rand() % _maxY);
		}
		else
			head->setPosX(head->getPosX() - 1);
		Object* shoots = _shoots.head;
		while(shoots)
		{
			if ((head->getPosX() ^ shoots->getPosX()) >= 0 && (head->getPosX() ^ shoots->getPosX()) <= 3
			&& head->getPosY() == shoots->getPosY())
			{
				head->setPosX(_maxX - 1);
				head->setPosY(rand() % _maxY);
				_player->setScore(_player->getScore() + 10);
				mvaddch(shoots->getPosY(), shoots->getPosX(), ' ');
				_shoots.remove(shoots);
			}
			shoots = shoots->next;
		}
		mvaddch(head->getPosY(), head->getPosX(), head->getScin());
		head = head->next;
	}

	Object* shoots = _shoots.head;
	while(shoots)
	{
		mvaddch(shoots->getPosY(), shoots->getPosX(), ' ');
		if (shoots->getPosX() >= _maxX - 4)
			_shoots.remove(shoots);
		else
		{
			shoots->setPosX(shoots->getPosX() + 1);
			mvaddch(shoots->getPosY(), shoots->getPosX(), shoots->getScin());	
		}
		shoots = shoots->next;
	}

}

void	Game::shoot(void)
{
	this->_shoots.add(getPlayer());
}

int	Game::_maxX = 0;
int	Game::_maxY = 0;

