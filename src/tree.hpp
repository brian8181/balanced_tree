#ifndef __tree_HPP
#define __tree_HPP

#include <list>
#include "node.hpp"

template<typename T>
class tree
{

public:
	tree( )
	{
	}

	tree( node<T>* root )  : _root (root )
	{
	}

	tree( const tree& n )
	{
		_root = n._root;
	}

	virtual ~tree( )
	{
	}

	bool operator<( const tree& that )
	{
		return false;
	}

	node<T>* get_root( )
	{
		return _root;
	}

	void insert( node<T>* n )
	{
		node<T>* cur_node = _root;
		while( cur_node != 0 )
		{
			cur_node = ( n->get_value() < cur_node->get_value() )
				? cur_node->get_right() : cur_node->get_left();
		}
		cur_node = n;
	}

	void remove( node<T> node )
	{

	}

	void remove( T val )
	{
		node<T>* cur_node = _root;
		while( cur_node != 0 )
		{
			if( cur_node->get_value() == val )
			{

			}
		}
	}

	node<T>* find( T val )
	{
		node<T>* cur_node = _root;
		while( cur_node != 0 )
		{
			if( cur_node->get_value() == val )
				return cur_node;

			cur_node = ( val < cur_node->get_value() )
				? cur_node = cur_node->get_right() : cur_node = cur_node->get_left();
		}
		return cur_node; // 0
	}

	void get_all(std::list<node<T>*>& nodes)
	{
		node<T>* cur_node = _root;
		while( cur_node != 0 )
		{
			if(cur_node->get_left() != 0)
				cur_node == cur_node->get_left();
			else if (cur_node->get_right() != 0)
				cur_node == cur_node->get_right();
			else
				return;
			nodes.push_front(cur_node);
		}
	}

private:
node<T>* _root;

};

#endif
