/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:40:15 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 09:36:48 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"
# include <ctime>

int init(WINDOW *wind)
{
	srand(time(NULL));
	keypad(wind, true);
	nodelay(wind, true);
	curs_set(0);
	cbreak();
	noecho();
	clear();
	refresh();
	attron(COLOR_PAIR(2));
	box(wind, 0, 0);
	attroff(COLOR_PAIR(2));

	return 0;
}

void run(WINDOW *wind)
{
	clock_t t1,t2;
	bool ex;
	int row, col, in_c;				/* to store the number of rows and *
								 * the number of colums of the screen */
	// getmaxyx(stdscr,row,col);	/* get the number of rows and columns */
	getmaxyx(stdscr,row,col);
	Player player((row + 1) / 2, 1, 'o');
	Game game(row, col);
	Enemy enemy;
	game.setPlayer(player);
	game.setEnemy();

	char pl = ' ';

	t2 = clock() / 16666;
	while(1)
	{
		t1 = clock() / 16666;
		if (t1 > t2)
		{
			in_c = wgetch(wind);
			mvaddch(player.getPosY(), player.getPosX(), pl);
			switch(in_c)
			{
				case 27:
					ex = true;
					break;
				case KEY_UP:
					player.setPosY(player.getPosY() - 1);
					break;
				case KEY_DOWN:
					player.setPosY(player.getPosY() + 1);
					break;
				case KEY_LEFT:
					player.setPosX(player.getPosX() - 1);
					break;
				case KEY_RIGHT:
					player.setPosX(player.getPosX() + 1);
					break;
				default:
					break;
			}
			mvaddch(player.getPosY(), player.getPosX(), player.getScin());
			game.redraw();
			game.generateNew();
			box(wind, 0, 0);
			refresh();
			if (ex)
				break;
			t2 = clock() / 16666;
		}
	}
}

void close()
{
	endwin();
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	WINDOW* wind = initscr();//создали указатель на окно

	int status = init(wind);
	if(status == 0)
		run(wind);
	close();
	system("leaks ft_retro");
	return (0);
}
