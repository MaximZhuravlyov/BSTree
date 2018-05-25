#include "BSTree.hpp"
#include "BSTree.cpp"
using BSTree::node;
using BSTree::tree;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	tree *first = new tree;
	if (argc == 1)
	{
		first->root->exist=false;
	}
	if (argc > 1)
	{
		string line_of_argv;
		bool miss;
		int length_of_elem_mass = 0;
		for (int i = 1; i < argc; i++)
		{
			length_of_elem_mass++;
			miss = false;
			if (i != 1)
				for (int k = i; k > 1; k--)
					if (atoi(argv[i]) == atoi(argv[k - 1]))
					{
						miss = true;
						length_of_elem_mass--;
					}
			if (!miss)
			{
				line_of_argv += argv[i];
				line_of_argv += ' ';
			}
		}
		int num_of_digits = 0;
		for (int i = 0; i < line_of_argv.length(); i++)
		{
			if (line_of_argv[i] == '0' || line_of_argv[i] == '1' || line_of_argv[i] == '2' || line_of_argv[i] == '3' || line_of_argv[i] == '4' ||
				line_of_argv[i] == '5' || line_of_argv[i] == '6' || line_of_argv[i] == '7' || line_of_argv[i] == '8' || line_of_argv[i] == '9')
			{
				num_of_digits++;
				continue;
			}
			else
				line_of_argv[i] = ' ';
		}
		if(num_of_digits == 0)
			first->root->exist = false;
		int *mass_of_elem = new int[length_of_elem_mass]{0};
		int space = 0;
		int entering_elem;
		for (int i = 0; space < (line_of_argv.length());i++)
		{
			while (line_of_argv[space] == ' ')
				space++;
			mass_of_elem[i] = atoi(line_of_argv.c_str());
			entering_elem = atoi(line_of_argv.c_str());
			while (entering_elem != 0)
			{
				line_of_argv[space] = ' ';
				space++;
				entering_elem /= 10;
			}
			while (line_of_argv[space] == ' ')
				space++;
		}
		for (int i = 0; i < length_of_elem_mass; i++)
		{
			first->inset(&first->root, mass_of_elem[i]);
		}
		std::cout << "\n";
	}
	bool repeat = true;
	do {
		std::cout << "1. Вывести дерево на экран\n";
		std::cout << "2. Вывести список узлов дерева\n";
		std::cout << "3. Добавить узел в дерево\n";
		std::cout << "4. Удалить узел из дерева\n";
		std::cout << "5. Сохранить дерево в файл\n";
		std::cout << "6. Загрузить дерево из файла\n";
		std::cout << "7. Проверить наличие узла\n";
		std::cout << "8. Завершить работу программы\n";
		int act;
		while ((!(std::cin >> act)) || (act > 8) )
		{
			std::cin.clear();
			std::cin.ignore(32, '\n');
			std::cout << "Выберите вариант ответа из предоставленного списка\n";
		}

		switch (act)
		{
		case 1:
		{
			if (!(first->exist_next_node(first->root)))
			{
				std::cout << "Дерево пусто\n";
				break;
			}
			first->print(first->root);
			break;
		}
		case 2:
		{
			if (!(first->exist_next_node(first->root)))
			{
				std::cout << "Дерево пусто\n";
				break;
			}
			std::cout << "    a. Прямо обход\n";
			std::cout << "    b. Поперечный обход\n";
			std::cout << "    c. Обратный обход\n";
			string answer;
			
			while ((!(std::cin >> answer))/* || (answer != "a") || (answer != "b") || (answer != "c")*/)
			{
				std::cin.clear();
				std::cin.ignore(32, '\n');
				std::cout << " Выберите вариант ответа из предоставленного списка\n";
			}
			if (answer == "a")
			{
				first->print_cir(first->root,1);
				std::cout << "\n";
			}
			if (answer == "b")
			{
				first->print_cir(first->root, 2);
				std::cout << "\n";
			}
			if (answer == "c")
			{
				first->print_cir(first->root, 3);
				std::cout << "\n";
			}
				break;
		}
		case 3:
		{
			std::cout << "Введите значение для нового узла\n";
			int new_elem;
			while (!(std::cin >> new_elem))
			{
				std::cin.clear();
				std::cin.ignore(32, '\n');
				std::cout << "Введите целочисленное значение\n";
			}
			if(first->exist_if_elem(first->root, new_elem))
					std::cout << "Узел уже существует в дереве\n";
			else
					first->inset(&first->root, new_elem);
			break;
		}
		case 4:
		{
			if (!(first->exist_next_node(first->root)))
			{
				std::cout << "Дерево пусто\n";
				break;
			}
			int del_elem;
			while (!(std::cin >> del_elem))
			{
				std::cin.clear();
				std::cin.ignore(32, '\n');
				std::cout << "Введите целочисленное значение\n";
			}
			if (first->delete_elem(first->root, del_elem))
				std::cout << "Успешно\n";
			break;
		}
		case 5:
		{

			if (!(first->exist_next_node(first->root)))
			{
				std::cout << "Дерево пусто\n";
				break;
			}
			cout << "Введите путь к файлу: ";
			string fail_name;
			while (!(std::cin >> fail_name))
			{
				std::cin.clear();
				std::cin.ignore(32, '\n');
				std::cout << "Некорректное название, попробуйте снова\n";
			}
			struct stat buffer;
			if (stat(fail_name.c_str(), &buffer) == 0)
			{
				cout << "Перезаписать файл ? (y/N): ";
				string answer;
				cin >> answer;
				while (!(std::cin >> fail_name))
				{
					std::cin.clear();
					std::cin.ignore(32, '\n');
					std::cout << "Некорректное название, попробуйте снова\n";
				}
				if (answer == "yes" || answer == "Yes" || answer == "YES" || answer == "y" || answer == "Y")
				{
					ofstream fout(fail_name, ios_base::trunc);
					first->print(first->root);
					fout.close();
					cin.get();
					cin.ignore(32, '\n');
					break;
				}
				else
				{
					cin.get();
					cin.ignore(32, '\n');
					break;
				}
			}
			else
			{
				ofstream fout(fail_name);
				first->print(first->root);
				fout.close();
				cin.get();
				cin.ignore(32, '\n');
				break;
			}
			break;
		}
		case 6:
		{
			cout << "Введите путь к файлу:  ";
			string fail_name;
			cin >> fail_name;
			bool suc = false;;
			std::ifstream outputf(fail_name.c_str());
			first->clean(first->root);
			int val;
			outputf >> val;
			if (!outputf)
				suc = false;
			while (outputf) {
				first->inset(&first->root,val);
				outputf >> val;
			}
			outputf.close();
			suc = true;
				if (suc) {
					cout << "Дерево было успешно загружено" << endl;
					break;
				}
				else {
					cout << "Файл с заданным путем не существует " << endl;
					break;
				}
		}
		case 7:
		{
			cout << "Введите значение для поиска:";
			int value;
			cin >> value;
			if(first->tree::exist_if_elem(first->root, value))
				cout << "Узел найден\n";
			else
				cout << "Узел не найден\n";
			break;
		}
		case 8:
		{
			string answer;
			repeat = false;
			cout << "Вы уверены, что хотите выйти из программы? (Да|Нет): ";
			cin >> answer;
			if (answer == "да" || answer == "ДА" || answer == "Да" || answer == "yes" || answer == "Yes" || answer == "YES" || answer == "y" || answer == "Y")
			{
				cout << "\n" << "До свидания!" << "\n";
				repeat = false;
				break;
			}
			else if (answer == "НЕТ" || answer == "Нет" || answer == "нет" || answer == "no" || answer == "No" || answer == "NO" || answer == "n" || answer == "N")
			{
				repeat = true;
				break;
			}
			else
			{
			cout << "\n" << "Ошибка ввода" << "\n";
			repeat = true;
			break;
			}
			cin.get();
			cin.ignore(32, '\n');
		}
		}
	} while(repeat);
	delete first;
	std::cin.clear();
	std::cin.ignore(32, '\n');
	return 0;
}