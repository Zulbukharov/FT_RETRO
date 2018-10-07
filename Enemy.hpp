/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 05:34:05 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 05:35:11 by azulbukh         ###   ########.fr       */
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
		Enemy(int x, int y, char o);
		Enemy(Enemy const &other);
		Enemy &operator=(Enemy const &other);
};

#endif
