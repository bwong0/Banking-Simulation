/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */
 

#pragma once

template <class T>
class Node
{
public:
	
	T data;     // The data in the node
	Node<T>* next;   // Pointer to next node
	
	// Constructors 
	Node();
	Node(T theData);
	Node(T theData, Node<T>* theNextNode);

}; 

#include "Node.cpp"