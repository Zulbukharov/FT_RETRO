/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:49:16 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 06:54:27 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "Object.hpp"

class	Player : public Object
{
	public:
		Player(void);
		~Player(void);
		Player(int y, int x, char o);
		Player(Player const &other);
		Player &operator=(Player const &other);
};

#endif
