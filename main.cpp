/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:40:15 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 15:07:06 by azulbukh         ###   ########.fr       */
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
	if(!has_colors())
	{
		endwin();
		std::cout << "ERROR: Terminal does not support color." << std::endl;
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_WHITE, COLOR_WHITE);
	init_pair(4, COLOR_YELLOW, COLOR_WHITE);
	init_pair(5, COLOR_RED, COLOR_WHITE);
	init_pair(6, COLOR_MAGENTA, COLOR_WHITE);

	wbkgd(wind, COLOR_PAIR(3));
	attron(COLOR_PAIR(2));
	box(wind, 0, 0);
	attroff(COLOR_PAIR(2));

	return 0;
}

void run(WINDOW *wind)
{
	clock_t t1,t2;
	bool ex;
	int row, col, in_c;	
	size_t tick = 0;
	getmaxyx(stdscr,row,col);
	Player player((row + 1) / 2, 1, 'o');
	Game game(row, col);
	Enemy enemy;
	game.setPlayer(player);
	game.setEnemy();

	char pl = ' ';

	t2 = clock() / 30000;
	while(player.getHP())
	{
		t1 = clock() / 30000;
		if (t1 > t2)
		{
			in_c = wgetch(wind);
			mvaddch(player.getPosY(), player.getPosX() + 1, pl);
			mvaddch(player.getPosY(), player.getPosX() - 1, pl);
			mvaddch(player.getPosY(), player.getPosX(), pl);
			mvaddch(player.getPosY() + 1, player.getPosX(), pl);
			mvaddch(player.getPosY() - 1, player.getPosX(), pl);
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
				case ' ':
					game.shoot();
					break;
				default:
					break;
			}
			attron(COLOR_PAIR(1));
			mvaddch(player.getPosY(), player.getPosX(), player.getScin());
			mvwaddch(wind, player.getPosY() - 1, player.getPosX(), ACS_UARROW);
		    mvwaddch(wind, player.getPosY() + 1, player.getPosX(), ACS_DARROW);
			mvwaddch(wind, player.getPosY(), player.getPosX() + 1, ACS_RARROW);
			attroff(COLOR_PAIR(1));
			if((tick % 10) / 3) {
    		    wattron(wind, COLOR_PAIR(tick % 2 ? 5 : 4));
  			      mvwaddch(wind, player.getPosY(), player.getPosX() - 1, ACS_RARROW);
    		    wattroff(wind, COLOR_PAIR(tick % 2 ? 5 : 4));
    		}
			tick++;
    		wattron(wind, COLOR_PAIR(5));
			game.redraw();
		    wattroff(wind, COLOR_PAIR(5));
			game.generateNew();
			attron(COLOR_PAIR(2));
			box(wind, 0, 0);
			attroff(COLOR_PAIR(2));
			attron(COLOR_PAIR(1));
			mvwprintw(wind, 2, 2, "[Score][%d]", player.getScore());
			mvwprintw(wind, 4, 2, "[HitPoints][%d]", player.getHP());
			attroff(COLOR_PAIR(1));
			refresh();
			if (ex)
				break;
			t2 = clock() / 30000;
		}
	}
	in_c = 0;
	ex = false;
	clear();
	attron(COLOR_PAIR(1));
	mvwprintw(wind, (Game::getMaxY()) / 2, (Game::getMaxX() - 10) / 2, "%s", "Game Over!");
	mvwprintw(wind, (Game::getMaxY()) / 2  + 5, (Game::getMaxX()) / 2, "%d", player.getScore());
	attroff(COLOR_PAIR(1));
	refresh();
	while (1)
	{
		in_c = wgetch(wind);
		switch(in_c)
		{
			case 27:
				ex = true;		
				break ;
		}
		if (ex)
			break ;
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
