#ifndef __tree_HPP
#define __tree_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <span>
#include "node.hpp"

using std::cout;
using std::endl;
using std::list;
using std::vector;
//using std::span;

template<typename T>
class tree
{

public:
	tree( )
	{
	}

	tree( T root )
	{
		T* pn = new T;
		&pn = root;
		_root = new node( pn );
	}

	tree( node<T>* root )  : _root ( root ), _current( root )
	{
	}

	tree( const tree& n )
	{
		_root = n._root;
	}

	virtual ~tree( )
	{
		int len = _nodes.size();
		for(int i = 0; i < len; ++i)
		{
			delete _nodes[1];
		}
	}

	tree( vector<T>& v )
	{
		// sort
		int len = v.size();
		double h = len;
		while(h > 0)
		{
			//vector<T> vleft = std::span(v);
			//.subspan(0, h);
			cout << "h = " << h << std::endl;
		}
	}

	void balance( vector<T>& v, node<T>* n )
	{
		int len = v.size();
		int offset = floor( len/2 );
		while( offset > 0 )
		{
			offset = floor(len/2);
			n->set_left(v[offset]);
			n->set_right(v[len-offset]);
			// get sub vector
			vector<int> subleft = { v.begin(), v.begin() + offset };
			vector<int> subright = { v.begin() + offset, v.end() - offset };
			// balance left then right
			balance( subleft,  n->get_left() );
			balance(  subright,  n->get_right() );
		}
	}

	bool operator<( const tree& that )
	{
		return false;
	}

	node<T>* get_root( )
	{
		return _root;
	}

	node<T>* move_next()
	{
		node<T>* cur_node = _current;
		while( cur_node != 0 )
		{
			if( cur_node->get_left() != 0 )
			{
				cur_node = cur_node->get_left();
			}
			else
			{
				if( cur_node->get_right() != 0 )
					cur_node = cur_node->get_right();
				else if( cur_node->get_parent()->get_right() =! 0 )
					cur_node = cur_node->get_parent()->get_right();
				else
					cur_node = 0;
			}
		}
		_current = cur_node;
		return _current;
	}

	void insert( T& v )
	{
		node<T>* pn = new node<T>;
		pn->set_value( v );
		insert( pn );
	}

	void insert( node<T>* _node )
	{
		_nodes.push_back(_node);
		node<T>* cur_node = _root;
		while( cur_node != 0 )
		{
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
		cur_node = _node;
	}

	void remove( node<T> _node )
	{
		// remove node from _nodes
		_nodes.erase(_node);
	}

	void remove( T val )
	{
		// find
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
	node<T>* _current;
	vector<node<T>*> _nodes;

};

#endif
