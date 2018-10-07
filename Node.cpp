/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 07:56:42 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/07 11:51:55 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"

LinkedList::LinkedList()
{
	this->length = 0;
	this->head = NULL;
}

LinkedList::~LinkedList()
{
	Object* current = head;
	Object* next;
	while (current != NULL) {
	next = current->next;
	delete (current);
	current = next;
	}
	head = NULL;
}

void LinkedList::add(void)
{
	Object* object = new Enemy;
	object->next = this->head;
	this->head = object;
	this->length++;
}

void LinkedList::add(Player const &other)
{
	Object* object = new Object(other.getPosY(), other.getPosX(), '-');
	object->next = this->head;
	this->head = object;
	this->length++;
}

void LinkedList::add(Object const &other)
{
	Object* object = new Object(other.getPosX(), other.getPosY(), '-');
	object->next = this->head;
	this->head = object;
	this->length++;
}

void LinkedList::print()
{
	Object* head = this->head;
	int i = 1;
	while(head)
	{
		// std::cout << i << ": " << head->data << std::endl;
		head = head->next;
		i++;
	}
}

void LinkedList::pop()
{
	Object * next_node = NULL;
	if (this->head == NULL) {
		return ;
	}
	next_node = (this->head)->next;
	delete (this->head);
	this->length--;
	this->head = next_node;
}

void LinkedList::remove(Object *other)
{
	Object *tmp = NULL;
	if (head == NULL || other == NULL) return;

	if (head == other) {
		head = (head)->next;
		delete (other);
		other = NULL;
	}
	else
	{
		tmp = head;
		while (tmp->next && tmp->next != other)
			tmp = tmp->next;
		if (tmp->next)
		{
			tmp->next = other->next;
			delete (other);
			other = NULL;
		}
	}
}

