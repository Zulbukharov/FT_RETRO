/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 05:33:59 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 14:59:41 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Game.hpp"

Enemy::Enemy(void) : Object((rand() % (Game::getMaxY() - 1)), Game::getMaxX() - 2, '@')
{
	// std::cout << "Enemy created" << std::endl;
}

Enemy::~Enemy(void)
{
	// std::cout << "Enemy Dead" << std::endl;
}

Enemy::Enemy(Enemy const &other)
{
	*this = other;
}

Enemy &Enemy::operator=(Enemy const &other)
{
	if (this != &other)
	{
		this->setPosX(other.getPosX());
		this->setPosY(other.getPosY());
		this->setSkin(other.getScin());
	}
	return (*this);
}
