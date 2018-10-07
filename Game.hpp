/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:42:47 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 09:35:54 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP
# include <iostream>
# include <string>
# include <ctime>
# include <ncurses.h>
# include <unistd.h>
# include "Player.hpp"
# include "Enemy.hpp"
# include "Node.hpp"

class	Game
{
	public:
		Game(void);
		Game(int maxY, int maxX);
		~Game(void);
		Game(Game const &other);
		Game &operator=(Game const &other);
		void	setMaxX(int x);
		void	setMaxY(int y);
		void	setPlayer(Player &l);
		void	setEnemy(void);

		static int	getMaxY(void);
		static int	getMaxX(void);
		Player &getPlayer(void);

		void	generateNew(void);
		void	redraw(void);
	private:
		static int	_maxX,
				_maxY;
		Player	*_player;
		// Enemy	*_enemyes[10];
		LinkedList _head;
};

#endif
