#include "BSTree.hpp"
#include "BSTree.cpp"
using BSTree::node;
using BSTree::tree;
using std::cin;
using std::cout;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	tree<int> first;
	if (argc == 1)
	{
		;//first.root=nullptr;
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
		if (num_of_digits == 0);
			//first.root = nullptr;
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
			first.insert(mass_of_elem[i]);
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
			first.print();
			break;
		}
		case 2:
		{
			std::cout << "    a. Прямо обход\n";
			std::cout << "    b. Поперечный обход\n";
			std::cout << "    c. Обратный обход\n";
			string answer;
			while ( !(std::cin >> answer) || ((answer != "a") && (answer != "b") && (answer != "c")) )
			{
				std::cin.clear();
				std::cin.ignore(32, '\n');
				std::cout << " Выберите вариант ответа из предоставленного списка\n";
			}
			if (answer == "a")
				first.print(BSTree::traversal_order::pre);
			else if (answer == "b")
				first.print(BSTree::traversal_order::in);
			else if (answer == "c")
				first.print(BSTree::traversal_order::post);
			std::cout << "\n";
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
			if(first.exists(new_elem))
					std::cout << "Узел уже существует в дереве\n";
			else
					first.insert(new_elem);
			break;
		}
		case 4:
		{

			int del_elem;
			std::cout << "Введите значение узла, который хотите удалить:\n";
			while (!(std::cin >> del_elem))
			{
				std::cin.clear();
				std::cin.ignore(32, '\n');
				std::cout << "Введите число\n";
			}
			if (first.remove(del_elem))
				std::cout << "Успешно\n";

			break;
		}
		case 5:
		{
			cout << "Введите название файла: ";
			string path;
			while (!(std::cin >> path))
			{
				std::cin.clear();
				std::cin.ignore(32, '\n');
				cout << "Ошибка ввода\n";
			}
			if (first.save(path));
			else
				cout << "Дерево пусто\n";
			break;
		}
		case 6:
		{
			cout << "Введите название файла: ";
			string path;
			while (!(std::cin >> path))
			{
				std::cin.clear();
				std::cin.ignore(32, '\n');
				cout << "Ошибка ввода\n";
			}
			if (first.load(path))
				cout << "\n";
			else
				cout << "Файл с заданным путем не существует\n";
		break;
		}
		case 7:
		{
			cout << "Введите значение для поиска:";
			int value;
			while (!(std::cin >> value))
			{
				std::cin.clear();
				std::cin.ignore(32, '\n');
				cout << "Ошибка ввода\n";
			}
			if(first.exists(value))
				cout << "Узел найден\n";
			else
				cout << "Узел не найден\n";
			break;
		}
		case 8:
		{
			string answer;
			cout << "Вы уверены, что хотите выйти из программы? (Да|Нет): ";
			std::cin >> answer;
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
			std::cin.get();
			std::cin.ignore(32, '\n');
		}
		}
	} while(repeat);
	std::cin.clear();
	std::cin.ignore(32, '\n');
	return 0;
}
