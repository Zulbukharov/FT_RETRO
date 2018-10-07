/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:40:15 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 05:28:52 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"

int init(WINDOW *wind)
{
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
	bool ex;
	int row, col, in_c;				/* to store the number of rows and *
								 * the number of colums of the screen */
	// getmaxyx(stdscr,row,col);	/* get the number of rows and columns */
	getmaxyx(stdscr,row,col);
	Player player(col / 2, row / 2, 'o');

	char pl = ' ';

	while(1)
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
	// usleep(10000);
	refresh();
	if (ex)
		break;
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
	return (0);
}
