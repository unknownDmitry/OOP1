#include "header.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

// Импортируем только нужные типы
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::getline;
using std::stod;
using std::rand;
using std::srand;
using std::time;
using std::size_t;

namespace array_operations {

	vector<double> a;

	// Вычисляет произведение всех элементов массива
	static double array_mult(vector<double>& a) {
		if (a.size() == 0) {
			throw "Cause of zero length, array doesn't exist";
		}

		double result = 1.0;
		for (int i = 0; i < a.size(); i++) {
			result *= a[i];
		}
		return result;
	}

	// Выводит элементы массива в консоль
	void print_array(const vector<double>& a) {
		iterate_array(a, [](const double& element) {
			cout << element << " ";
		});
	}

	// Сохраняет массив в текстовый файл
	void save_array(const vector<double>& a, const string & file_name) {
		safe_file_operation<ofstream>(file_name, [&a](ofstream& file) {
			iterate_array(a, [&file](const double& element) {
				file << element << endl;
			});
		});
	}

	// Заполняет массив случайными числами в заданном диапазоне
	void fill_rand_array(vector<double>& a, double max, double min) {
		srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел
		double range = max - min;
		for (int i = 0; i < a.size(); i++) {
			cout << i << endl;
			a[i] = (static_cast<double>(rand()) / RAND_MAX * range + min);
		}
	}

	// Определяет количество строк в файле
	uint32_t file_size(const string& file_name) {
		uint32_t result = 0;
		safe_file_operation<ifstream>(file_name, [&result](ifstream& file) {
			string empty_line;
			while (getline(file, empty_line)) {
				result++;
			}
		});
		return result;
	}

	// Загружает массив из текстового файла
	void load_array(vector<double>& a, const string& file_name)
	{
		safe_file_operation<ifstream>(file_name, [&a](ifstream& file) {
			string load_line;
			while (getline(file, load_line)) {
				a.push_back(stod(load_line));
			}
		});
	}

	// Сохраняет массив в бинарный файл
	void save_array_bin(const vector<double>& a, const string& file_name) {
		ofstream file(file_name, ios::binary);
		if (!file.is_open()) {
			cout << "File opening error: " << endl;
		}
		else {
			size_t size = a.size();
			file.write(reinterpret_cast<const char*>(&size), sizeof(size));
			file.write(reinterpret_cast<const char*>(a.data()), sizeof(double) * a.size());
			file.close();
		}
	}

	// Загружает массив из бинарного файла
	void load_array_bin(vector<double>& a, const string & file_name) {
		ifstream file(file_name, ios::binary);
		if (!file.is_open()) {
			cout << "File not found: " << endl;
		}
		else {
			size_t size;
			file.read(reinterpret_cast<char*>(&size), sizeof(size));
			a.resize(size);
			file.read(reinterpret_cast<char*>(a.data()), sizeof(double) * size);
			file.close();
		}
	}
	// Обрабатывает операции с массивом (загрузка/создание, вывод, сохранение)
	void process_array_operations(vector<double>& a) {
		string file_output, file_output_bin, test_on_txt;
		char load_check;
		uint32_t array_size;
		double max, min;

		cout << "Please, input file name: " << endl;
		cin >> file_output;

		if (file_output.length() < 4) {
			file_output = "save.txt";
			cout << "File name is too short, file name set by default as 'save.txt'" << endl;
		}
		test_on_txt = file_output.substr(file_output.length() - 4);
		if (test_on_txt != ".txt") {
			cout << "Your file doesn't have .txt extension, adding it automatically" << endl;
			file_output.append(".txt");
		}
		file_output_bin = file_output;
		file_output_bin.replace(file_output_bin.length() - 3, 3, "bin");

		cout << "For load from file write Y or y: " << endl;
		cin >> load_check;

		if (load_check == 'Y' || load_check == 'y') {
			cout << "For load from BIN write B or b: " << endl;
			cin >> load_check;
			if (load_check == 'B' || load_check == 'b') {
				load_array_bin(a, file_output_bin);
			}
			else {
				load_array(a, file_output);
			}
		}
		else {
			cout << "Input array length: " << endl;
			cin >> array_size;
			a.resize(array_size);
			cout << "Input min value: " << endl;
			cin >> min;
			cout << "Input max value: " << endl;
			cin >> max;
			fill_rand_array(a, max, min);
		}

		cout << "Your array: " << endl;
		print_array(a);
		cout << endl;

		try {
			cout << "The result is: " << array_mult(a) << endl;
		}
		catch (const char* error_message) {
			cout << error_message << endl;
		}

		save_array(a, file_output);
		save_array_bin(a, file_output_bin);
	}

}
