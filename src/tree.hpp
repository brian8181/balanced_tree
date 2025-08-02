#ifndef __tree_HPP
#define __tree_HPP

#include <vector>
#include <list>
#include "node.hpp"

using std::list;
using std::vector;

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

	void insert( node<T>* _node )
	{
		_nodes.push_back(_node);
		node<T>* cur_node = _root;
		while( cur_node != 0 )
		{
			cur_node = ( _node->get_value() < cur_node->get_value() )
				? cur_node->get_right() : cur_node->get_left();
		}
		cur_node = _node;
	}

	void remove( node<T> _node )
	{
		// remove node from _nodes
		_nodes.erase(_node);
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
			cur_node = (cur_node->get_left() != 0) ? cur_node->get_left() : cur_node->get_right();
		}
	}

private:
node<T>* _root;
vector<node<T>*> _nodes;

};

#endif
