/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:40:04 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 06:55:45 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"
#include "Game.hpp"

Object::Object(void)
{
	// std::cout << "Object created" << std::endl;
}

Object::Object(int y, int x, char o)
{
	// std::cout << "Object created" << std::endl;
	this->setPosX(x);
	this->setPosY(y);
	this->setSkin(o);
}

Object::~Object(void)
{
	// std::cout << "Object Dead" << std::endl;
}

Object::Object(Object const &other)
{
	*this = other;
}

Object &Object::operator=(Object const &other)
{
	if (this != &other)
	{

	}
	return (*this);
}

void	Object::setPosX(int x)
{
	this->_posX = x;
}

void	Object::setPosY(int y)
{
	this->_posY = y;
	// if (this->_posY <= 1)
	// 	this->_posY = 1;
	// else if (this->_posY >= Game::getMaxY() - 1)
	// 	this->_posY = Game::getMaxY() - 2;
}

void	Object::setHP(int hp)
{
	this->_hp = hp;
}

void	Object::setScore(int score)
{
	this->_score = score;
}

void	Object::setSkin(char o)
{
	this->o = o;
}

int		Object::getPosX(void) const
{
	return (this->_posX);
}

int		Object::getPosY(void) const
{
	return (this->_posY);
}

int		Object::getHP(void) const
{
	return (this->_hp);
}

int		Object::getScore(void) const
{
	return (this->_score);
}

char	Object::getScin(void) const
{
	return (this->o);
}

