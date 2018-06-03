#include "bstree.hpp"
#include "BSTree.cpp"
using BSTree::node;
using BSTree::tree;
using std::cin;
using std::cout;
int main(){
    tree<int> tree1; //������ ������
    tree<int> tree2 = {5,1,3,6,8,4}; //������������� � ������� ������ �������������
    cout << tree1 << tree2 << endl; //����� ������ � ������� ��������� << 
    tree2.print(); //����� ������
    tree1 = tree2; //�������� ������������
    tree1.print(BSTree::traversal_order::pre); //������ ����� ����� ������
    cout << "\n";
    tree<int> tree3;
    tree3.insert(10); //������� ���������� ����
    tree3.insert(1);
    tree3.insert(6);
    tree3.print(BSTree::traversal_order::post); //�������� ����� ����� ������
    cout << "\n";
    cout << boolalpha << tree2.exists(10) << "\n"; //����� �����
    cout << tree3.exists(1) << "\n";
    
    tree2.remove(4); //�������� ��������
    cout << tree2 << "\n";
    
    tree3.save("text.txt"); //������ ������ � ����
    tree1.load("text.txt"); //�������� ������ �� �����
    cout << tree1 << endl;
    exit(0);
}