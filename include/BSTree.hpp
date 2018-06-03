#pragma once

#ifndef BSTree_hpp
#define BSTree_hpp

#include <iostream>
#include <locale>
#include <fstream>
#include <initializer_list>
#include <sstream>
using namespace std;
namespace BSTree
{
	enum class traversal_order { pre = 0, in = 1, post = 2 };
	template <typename T>
	struct node
	{
		T data;
		node* left;
		node* right;
		node(T val = 0): left{ nullptr }, right{ nullptr }
		{
			data = val;
		};
	};
	template <typename T>
	class tree {	
		void clean(node<T>* node1);
		node<T>* root;
	public:
		
		tree() : root{ nullptr } {};
		tree(std::initializer_list<T> list): tree{}
		{	for (auto &item: list)
				this->insert(item);		}
		tree(const tree& tree);
		void swap(tree& tree);
		bool insert(T value);
		void print();
		void print(traversal_order order);
		bool exists(T value);
		bool save(const string& path);
		bool load(const string& path);
		bool remove(T value);
		template <typename T1>
		auto friend operator<<(std::ostream &stream, const tree<T1> &tree_in_stream)->std::ostream&
		{
			line_print(tree_in_stream.root, stream, traversal_order::pre);
			return stream;
		};
		template <typename T1>
		auto operator=(const tree<T1>& Tree)->tree<T1>& 
		{
			this->clean(root);
			this->swap(Tree);
			return *this;
		}

		~tree() { clean(root); }
	};
}
#endif 
