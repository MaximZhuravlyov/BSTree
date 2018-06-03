#include "BSTree.hpp"
using BSTree::node;
using BSTree::tree;
template <typename T>
void tree<T>::clean(node<T>* node)
{
	if (node != nullptr) {
		this->clean(node->left);
		this->clean(node->right);
		this->remove(node->data);
	}
	node = nullptr;
	return;
}
template <typename T>
tree<T>::tree(const tree& tree)
{
	this->clean(root);
	stringstream out;
	out << tree;
	T value;
	while (out) 
	{
		out >> value;
		this->insert(value);
	}
}
template <typename T>
void tree<T>::swap(tree<T>& tree)
{
	node<T> node_for_swap = root;
	this->root = tree.root;
	tree.root = node_for_swap;
}
template <typename T>
bool tree<T>::insert(T value)
{
	if (this->exists(value))
		return false;
	if (root == nullptr)
	{
		this->root = new node<T> { value };
		return true;
	}
	else
	{
		node<T>* new_node = root;
		while (new_node != nullptr)
		{
			if (new_node->data > value)
			{
				if (new_node->left == nullptr)
				{
					new_node->left = new node<T>{ value };
					return true;
				}
				new_node = new_node->left;
			}
			else
			{
				if (new_node->right == nullptr)
				{
					new_node->right = new node<T>{ value };
					return true;
				}
				new_node = new_node->right;
			}
		}
    }
	return false;
}
template <typename T>
void tree<T>::print()
{
	if (this->root == nullptr)
	{
		std::cout << "Дерево пусто\n";
		return;
	}
	if (root == nullptr)
		return;
	else
		print_tree(1,root);
	return;
}
template <typename T>
void print_tree(int deep,node<T> *node)
{
	if (node->left != nullptr)
		print_tree(deep + 1, node->left);
	for (int i = 0; i < deep; i++)
		cout << "  ";
	cout << "--" << node->data << endl;
	if (node->right != nullptr)
		print_tree(deep + 1, node->right);
}
template <typename T>
void tree<T>::print(BSTree::traversal_order order)
{
	if (this->root == nullptr)
	{
		cout << "Дерево пусто\n";
		return;
	}
	else
		line_print(root,std::cout,order);
		return;
}
template <typename T>
auto line_print(node<T>* node, std::ostream& stream, BSTree::traversal_order order) -> std::ostream& {
	if (order == BSTree::traversal_order::pre)
		stream << " " << node->data;
	if (node->left != nullptr)
		line_print(node->left, stream, order);
	if (order == BSTree::traversal_order::in)
		stream << " " << node->data;
	if (node->right != nullptr)
		line_print(node->right, stream, order);
	if (order == BSTree::traversal_order::post)
		stream << " " << node->data;
	return stream;
}
template <typename T>
bool tree<T>::exists(T value)
{
	if (root == nullptr)
		return false;
	else
	{
		node<T> *node_ptr = root;
		bool exst = false;
		while (node_ptr != nullptr)
		{
			if (node_ptr->data == value)
				exst = true;
			if (node_ptr->data > value)
				node_ptr = node_ptr->left;
			else
				node_ptr = node_ptr->right;
		}
		return exst;
	}
}
template <typename T>
bool tree<T>::save(const string& path)
{
	if (root == nullptr)
		return false;
	ifstream opening_file(path.c_str());
	if (!opening_file.is_open()) {
		ofstream file_(path.c_str());
		file_ << *this;
		file_.close();
		return true;
	}
	else {
		string answer;
		cout << "Файл уже существует, перезаписать ? (Да|Нет):\n";
		while ( (cin >> answer) && !(answer == "да" || answer == "ДА" || answer == "Да"
			|| answer == "yes" || answer == "Yes" || answer == "YES" || answer == "y" || answer == "Y" || 
			answer == "НЕТ" || answer == "Нет" || answer == "нет" || answer == "no" ||
			answer == "No" || answer == "NO" || answer == "n" || answer == "N") )
		{
			cin.clear();
			cin.ignore(32, '\n');
			cout << "Введите \"yes\" если хотите перезаписать файл, \"no\" - если нет.\n";
		}
		if (answer == "да" || answer == "ДА" || answer == "Да" || answer == "yes" || answer == "Yes" || answer == "YES" || answer == "y" || answer == "Y")
		{
			ofstream file_(path.c_str());
			file_ << *this;
			file_.close();
			return true;
		}
		else if (answer == "НЕТ" || answer == "Нет" || answer == "нет" || answer == "no" || answer == "No" || answer == "NO" || answer == "n" || answer == "N")
			return false;
	}
}
template <typename T>
bool tree<T>::load(const string& path)
{
	ifstream opening_file(path.c_str());
	if (!opening_file.is_open())
		return false;
	cout << "clean\n\n";
	this->clean(root);
	T value;
	opening_file >> value;
	if (!opening_file)
	{
		opening_file.close();
		return false;
	}
	else
		while (opening_file)
		{
			this->insert(value);
			opening_file >> value;
		}
	opening_file.close();
	return true;
}
template <typename T>
bool tree<T>::remove(T value)
{
	if (root == nullptr)
		return false;
	if (!(this->exists(value)))
		return false;
	else if (this->root->right == nullptr && this->root->left == nullptr)
	{
		root->data = 0;
		root = nullptr;
		return true;
	}
	else if (root->data == value)
	{
		node<T> * deleted_node = root;
		if (root->left != nullptr && root->right == nullptr)
			this->root = root->left;
		else if (root->left == nullptr && root->right != nullptr)
			this->root = root->right;
		else
		{
			node<T> * left_root_ptr = root->left;
			root = root->right;
			node<T> * node_ptr = root;
			while (node_ptr->left != left_root_ptr)
			{
				if (node_ptr->left == nullptr)
					node_ptr->left = left_root_ptr;
				else
					node_ptr = node_ptr->left;
			}
			/*while (left_root_ptr != nullptr)
			{
				if (left_root_ptr->left == nullptr)
					left_root_ptr = left_root_ptr->left;
				else
					left_root_ptr = left_root_ptr->right;
			}
			delete left_root_ptr;
			while (node_ptr != nullptr)
			{
				if (node_ptr->left == nullptr)
					node_ptr = node_ptr->left;
				else
					node_ptr = node_ptr->right;
			}
			delete node_ptr;*/
		}
		delete deleted_node;
	}
	else
	{
		node<T> *deleted_node = root;
		node<T> *node_before_deleted_node;
		bool last_turn_left;
		while (deleted_node->data != value)
		{
			node_before_deleted_node = deleted_node;
			if (deleted_node->data > value)
			{
				last_turn_left = true;
				deleted_node = deleted_node->left;
			}
			else
			{
				last_turn_left = false;
				deleted_node = deleted_node->right;
			}
		}
		if (deleted_node->left == nullptr && deleted_node->right == nullptr)
		{
			if (last_turn_left)
				node_before_deleted_node->left = nullptr;
			else
				node_before_deleted_node->right = nullptr;
			return true;
		}
		else if (last_turn_left)
		{
			if (deleted_node->right != nullptr)
			{
				node_before_deleted_node->left = deleted_node->right;
				if (deleted_node->left != nullptr)
				{
					node<T> * node_ptr = deleted_node->left;
					node_before_deleted_node = node_before_deleted_node->left;
					while (node_before_deleted_node->left != node_ptr)
					{
						if (node_before_deleted_node->left == nullptr)
							node_before_deleted_node->left = node_ptr;
						else
							node_before_deleted_node = node_before_deleted_node->left;
					}
					/*while (node_ptr != nullptr)
					{
						if (node_ptr->left == nullptr)
							node_ptr = node_ptr->left;
						else
							node_ptr = node_ptr->right;
					}
					delete node_ptr;*/
				}
			}
			else
				node_before_deleted_node->left = deleted_node->left;
		}
		else  if (!last_turn_left)
		{
			if (deleted_node->left != nullptr)
			{
				node_before_deleted_node->right = deleted_node->left;
				if (deleted_node->right != nullptr)
				{
					node<T> * node_ptr = deleted_node->right;
					node_before_deleted_node = node_before_deleted_node->right;
					while (node_before_deleted_node->right != node_ptr)
					{
						if (node_before_deleted_node->right == nullptr)
							node_before_deleted_node->right = node_ptr;
						else
							node_before_deleted_node = node_before_deleted_node->right;
					}
					/*while (node_ptr != nullptr)
					{
						if (node_ptr->left == nullptr)
							node_ptr = node_ptr->left;
						else
							node_ptr = node_ptr->right;
					}
					delete node_ptr;*/
				}
			}
			else
				node_before_deleted_node->right = deleted_node->right;
		}
		/*while (node_before_deleted_node != nullptr)
		{
			if (node_before_deleted_node->left == nullptr)
				node_before_deleted_node = node_before_deleted_node->left;
			else
				node_before_deleted_node = node_before_deleted_node->right;
		}
		delete node_before_deleted_node;
		delete deleted_node;*/
		return true;
	}
	return false;
}
