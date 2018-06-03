#include "bstree.hpp"
#include "BSTree.cpp"
using BSTree::node;
using BSTree::tree;
using std::cin;
using std::cout;
int main(){
    tree<int> tree1; //пустое дерево
    tree<int> tree2 = {5,1,3,6,8,4}; //инициализация с помощью списка инициализации
    cout << tree1 << tree2 << endl; //вывод дерева с помощью оператора << 
    tree2.print(); //вывод дерева
    tree1 = tree2; //оператор присваивания
    tree1.print(BSTree::traversal_order::pre); //прямой вывод узлов дерева
    cout << "\n";
    tree<int> tree3;
    tree3.insert(10); //функция добавления узла
    tree3.insert(1);
    tree3.insert(6);
    tree3.print(BSTree::traversal_order::post); //обратный вывод узлов дерева
    cout << "\n";
    cout << boolalpha << tree2.exists(10) << "\n"; //поиск узлов
    cout << tree3.exists(1) << "\n";
    
    tree2.remove(4); //удаление элемента
    cout << tree2 << "\n";
    
    tree3.save("text.txt"); //запись дерева в файл
    tree1.load("text.txt"); //загрузка дерева из файла
    cout << tree1 << endl;
    exit(0);
}