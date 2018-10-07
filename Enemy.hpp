/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 05:34:05 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 06:52:46 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
# include "Object.hpp"

class	Enemy : public Object
{
	public:
		Enemy(void);
		~Enemy(void);
		Enemy(int y, int x, char o);
		Enemy(Enemy const &other);
		Enemy &operator=(Enemy const &other);
};

#endif
