#ifndef __tree_HPP
#define __tree_HPP

#include "node.hpp"

template<typename T>
class tree
{

public:
	tree()
	{
	}

	tree( node<T>* root )  : _root(root)
	{
	}

	tree( const tree& n )
	{
		_root = n._root;
	}

	bool operator<( const tree& that )
	{
		return false;
	}

	virtual ~tree()
	{

	}

	node<T>* get_root()
	{
		return _root;
	}

	void insert( node<T> n )
	{
		node<T>* cur_node = _root;
		while(cur_node != 0)
		{
			cur_node = (n._value < cur_node._value)
				? cur_node._right : cur_node._left;
		}
		cur_node = n;
	}

	void remove(node<T> node)
	{

	}

	void remove( T val )
	{
		node<T>* cur_node = _root;
		while(cur_node != 0)
		{
			if(cur_node->_value == val)
			{
				if(cur_node->_parent.left == cur_node)
				{
					cur_node->_parent.left = cur_node->_left;
					cur_node->_left->_right = cur_node->_right;
				}
				else
				{
					cur_node->_parent.right = cur_node->_left;
					cur_node->_left->_right = cur_node->_right;
				}
			}
		}
	}

	node<T>* find(T val)
	{
		node<T>* cur_node = _root;
		while(cur_node != 0)
		{
			if(cur_node->_value == val)
				return cur_node;

			cur_node = (val < cur_node._value)
				? cur_node = cur_node._right : cur_node = cur_node._left;
		}
		return cur_node; // 0
	}

private:
node<T>* _root;

};

#endif
