/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:40:09 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 06:53:35 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP
# define OBJECT_HPP
# include <iostream>

class	Object
{
	public:
		Object(void);
		~Object(void);
		Object(int y, int x, char o);
		Object(Object const &other);
		Object &operator=(Object const &other);

		int		getPosX(void) const;
		int		getPosY(void) const;
		int		getHP(void) const;
		int		getScore(void) const;
		void	setSkin(char o);

		void	setPosX(int x);
		void	setPosY(int y);
		void	setHP(int hp);
		void	setScore(int score);
		char	getScin(void) const;
	private:
		int		_posX,
				_posY,
				_hp,
				_score;
		char 	o;
};

#endif

