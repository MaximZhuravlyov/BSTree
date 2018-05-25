#include "BSTree.hpp"
using BSTree::node;
using BSTree::tree;
void tree::clean(node*& node)
{
	if (node->left != nullptr)
		clean(node->left);
	if (node->right != nullptr)
		clean(node->right);
	delete node;
	node = nullptr;
}
bool tree::exist_next_node(node* node)
{
	if (node->exist == true)
		return false;
	else
		return true;
}
int tree::node_num(node* node)
{
	return node->data;
}
void tree::inset(node** node1, int val)
{
	if ((*node1) == nullptr)
	{
		(*node1) = new node;
		(*node1)->data = val;
		(*node1)->left = (*node1)->right = nullptr;
		return;
	}
	if ((*node1)->data > val)
		inset(&(*node1)->left, val);
	else
		inset(&(*node1)->right, val);
}
void tree::print(node* node, int deep = 0)
{
	if (node == nullptr)
		return;
	else;
	{
		if (node->left != nullptr)
			print(node->left, deep + 1);
		for (int i = 0; i < deep; i++)
			cout << "  ";

		cout << "--" << node->data << endl;
		if (node->right != nullptr)
			print(node->right, deep + 1);
	}
}
void tree::print_cir(node* node, int chose)
{
	if (node == nullptr)
		return;
	else;
	{
		if (chose == 1)
			cout << " " << node->data;
		if (node->left != nullptr)
			print_cir(node->left, chose);
		if (chose == 2)
			cout << " " << node->data;
		if (node->right != nullptr)
			print_cir(node->right, chose);
		if (chose == 3)
			cout << " " << node->data;
	}
}
bool tree::exist_if_elem(node* node, int chkng_elm)
{
	if (find_elem(node, chkng_elm, 0) != 0)
		return true;
	else
		return false;
}
int tree::find_elem(node* node, int chkng_elm, int exst_elm)
{
	if (node->data == chkng_elm)
		exst_elm++;
	if (node == nullptr)
		return exst_elm;
	else
	{
		if (node->left != nullptr)
			exst_elm = find_elem(node->left, chkng_elm, exst_elm);
		if (node->right != nullptr)
			exst_elm = find_elem(node->right, chkng_elm, exst_elm);
	}
	return exst_elm;
}
int tree::delete_elem(node* node1, int del_elm, node* lastnode = nullptr, bool last_node_right = true, node* new_root = nullptr, int elem_quantity = 1)
{
	if (node1->data == del_elm  && elem_quantity == 1)
	{
		clean(this->root);
	}
	if (node1->data == del_elm)
	{
		if (node1->left == nullptr && node1->right == nullptr)
		{
			if (last_node_right)
				lastnode->right = nullptr;
			else
				lastnode->left = nullptr;
			delete node1;
			return 0;
		}
		if (node1->left != nullptr && node1->right == nullptr)
		{
			if (last_node_right)
				lastnode->right = node1->left;
			else
				lastnode->left = node1->left;
			delete node1;
			return 0;
		}
		if (node1->left == nullptr && node1->right != nullptr)
		{
			if (last_node_right)
				lastnode->right = node1->right;
			else
				lastnode->left = node1->right;
			delete node1;
			return 0;
		}
		if (node1->left != nullptr && node1->right != nullptr)
		{
			if (last_node_right)
			{
				if (node_num(node1->left) > lastnode->data)
					lastnode->right = node1->left;
				else
					lastnode->right = node1->right;
			}
			else
			{
				if (node_num(node1->left) > lastnode->data)
					lastnode->left = node1->left;
				else
					lastnode->left = node1->right;
			}
			new_root = node1->right;
			delete node1;
			return 1;
		}

	}
	else if (node1 == nullptr)
		return 0;
	else
	{
		if (node1->left != nullptr && new_root == nullptr)
			delete_elem(node1->left, del_elm, node1, false, new_root);
		if (node1->right != nullptr)
			delete_elem(node1->right, del_elm, node1, true, new_root);
	}
	return 0;
}