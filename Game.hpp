/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:42:47 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 05:13:37 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP
# include <iostream>
# include <string>
# include <ctime>
# include <ncurses.h>
# include <unistd.h>

class	Game
{
	public:
		Game(void);
		~Game(void);
		Game(Game const &other);
		Game &operator=(Game const &other);
		void	setMaxX(int x);
		void	setMaxY(int y);

		int		getMaxY(void);
		int		getMaxX(void);
	private:
		int		_maxX,
				_maxY;
};

#endif
