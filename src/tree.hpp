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
		// 	if( cur_node->get_left() ! = 0 )
		// 	{
		// 		cur_node = cur_node->get_left();
		// 	}
		// 	else
		// 	{
		// 		if( cur_node->get_right() != 0)
		// 			cur_node = cur_node->get_right();
		// 		else
		// 			cur_node = cur_node->get_parent()->get_right();
		// 	}
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
		node<T>* cur_node = find(val);
		// now remove
		_nodes.erase(cur_node);
	}

	node<T>* find( T val )
	{
		node<T>* cur_node = _root;
		while( cur_node != 0 )
		{
			if( cur_node->get_value() == val )
				return cur_node;

			if( cur_node->get_left() != 0 )
			{
				cur_node = cur_node->get_left();
			}
			else
			{
				if( cur_node->get_right() != 0)
					cur_node = cur_node->get_right();
				else
					cur_node = cur_node->get_parent()->get_right();
			}
		}
		return cur_node; // 0
	}

	void get_all( std::list<node<T>*>& nodes )
	{
		node<T>* cur_node = _root;
		while( cur_node != 0 )
		{
			// push all nodes
			nodes.push_back(cur_node);
			if( cur_node->get_left() != 0 )
			{
				cur_node = cur_node->get_left();
			}
			else
			{
				if( cur_node->get_right() != 0)
					cur_node = cur_node->get_right();
				else
					cur_node = cur_node->get_parent()->get_right();
			}
		}
	}

	static node<T>* make_node( const T& parent )
	{
		node<T>* p_node = new node<T>( &parent );
		return p_node;
	}

	static node<T>* make_node( const T& parent, const T& left, const T& right )
	{
		node<T>* p_node = new node<T>( &parent, &left, &right );
		return p_node;
	}

private:
	node<T>* _root;
	vector<node<T>*> _nodes;

};

#endif
