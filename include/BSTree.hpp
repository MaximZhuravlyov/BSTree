#pragma once

#ifndef BSTree_hpp
#define BSTree_hpp

#include <iostream>
#include <locale>
#include <fstream>
using namespace std;

namespace BSTree
{
	struct node
	{
		int data;
		node* left;
		node* right;
		bool exist;
		node() : data{ 0 }, left{ nullptr }, right{ nullptr } {};
	};
}
namespace BSTree
{
	struct tree {
	public: node* root;
		tree() : root{ nullptr } {};
		void clean(node*& node);
		bool exist_next_node(node* node); //проверка существовани€ элемента по указателю на него
		int node_num(node* node);
		void inset(node** node1, int val);
		void print(node* node, int deep);
		void print_cir(node* node, int chose);
		bool exist_if_elem(node* node, int chkng_elm); //проверка существовани€ элемента
		int find_elem(node* node, int chkng_elm, int exst_elm);
		int delete_elem(node* node1, int del_elm, node* lastnode, bool last_node_right, node* new_root, int elem_quantity);
		~tree() {
			clean(root);
		}
	};
}
#endif 
