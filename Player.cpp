/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:49:10 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 05:24:36 by azulbukh         ###   ########.fr       */
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

Player::Player(int x, int y, char o) : Object(x, y, o)
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
