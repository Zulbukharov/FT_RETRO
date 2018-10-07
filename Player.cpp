/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:49:10 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 06:54:35 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void) : Object()
{
	// std::cout << "Player created" << std::endl;
}

Player::~Player(void)
{
	// std::cout << "Player Dead" << std::endl;
}

Player::Player(int y, int x, char o) : Object(y, x, o)
{
	// std::cout << "Player created" << std::endl;
}

Player::Player(Player const &other)
{
	*this = other;
}

Player &Player::operator=(Player const &other)
{
	if (this != &other)
	{

	}
	return (*this);
}
