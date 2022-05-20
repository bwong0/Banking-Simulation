/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */

#include <cstdio>  // Needed for NULL
#include "Node.h"

template <class T>
Node<T>::Node()
{

	next = NULL;
}

template <class T>
Node<T>::Node(T theData)
{
	data = theData;
	next = NULL;
}

template <class T>
Node<T>::Node(T theData, Node<T>* theNextNode)
{
	data = theData;
	next = theNextNode;
}
