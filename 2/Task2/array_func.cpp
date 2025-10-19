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

namespace ArrayFuncs {

	vector<double> a;

	// Вычисление результата
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

	//Вывод массива
	void print_array(const vector<double>& a) {
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " ";
		}
	}

	//Сохранение массива с файл
	void save_array(const vector<double>& a, const string & file_name) {
		ofstream file(file_name);
		// Если файл открыт
		if (file.is_open()) {
			for (int i = 0; i < a.size(); i++) {
				file << a[i] << endl;
			}
			file.close();
		}
		else {
			cout << "Unable to open file";
		}
	}

	//Заполнение массива случайными числами 
	void fill_rand_array(vector<double>& a, double max, double min) {
		srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел
		double range = max - min;
		for (int i = 0; i < a.size(); i++) {
			cout << i << endl;
			a[i] = (static_cast<double>(rand()) / RAND_MAX * range + min);
		}
	}

	//Определение размера файла в виде числа строк. На входе имя файла в кавычках
	uint32_t file_size(const string& file_name) {
		string empty_line;
		uint32_t result = 0;
		ifstream file(file_name);
		if (!file.is_open()) {
			cout << "File not found:" << endl;
			return 0;
		}
		while (getline(file, empty_line)) {
			result++;
		}
		file.close();
		return result;
	}

	//Загрузка массива из файла
	void load_array(vector<double>& a, const string& file_name)
	{
		string load_line;
		ifstream file(file_name);
		if (!file.is_open()) {
			cout << "File not found: " << endl;
		}
		else {
			while (getline(file, load_line)) {
				a.push_back(stod(load_line));
			}
			file.close();
		}
	}

	// Сохранение массива из бинарного файла
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

	// Создание и заполнение массива из бинарного файла 
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
};


namespace print_array_operations {
	void process_array_operations(vector<double>& a) {
		using namespace ArrayFuncs;
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
