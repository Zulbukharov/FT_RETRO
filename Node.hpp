/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 07:56:36 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 15:03:20 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP
# include <cstdlib>
# include "Object.hpp"
# include "Enemy.hpp"
# include "Player.hpp"

class LinkedList
{
	public:
		int length;
		Object *head;

		LinkedList(void);
		~LinkedList(void);
		LinkedList(LinkedList const &other);
		LinkedList &operator=(LinkedList const &other);
		void add(Player const &other);
		void add(Object const &other);
		void remove(Object *other);
		void add(void);
		void print(void);
		void pop(void);
		Object &get(void);
};

#endif
