#include "header.h"
#include <cassert>
#include <cmath>

namespace array_operations {

	// Вычисление произведения элементов
	double array_mult(vector<double>& a) {
		if (a.empty()) throw "Array is empty!";
		double result = 1.0;
		for (double x : a) result *= x;
		return result;
	}

	// Печать массива
	void print_array(const vector<double>& a) {
		iterate_array(a, [](double val) { cout << val << " "; });
		cout << endl;
	}

	// Заполнение случайными числами
	void fill_rand_array(vector<double>& a, double max, double min) {
		srand(static_cast<unsigned int>(time(nullptr)));
		double range = max - min;
		for (auto& x : a)
			x = static_cast<double>(rand()) / RAND_MAX * range + min;
	}

	// Подсчёт строк в текстовом файле
	uint32_t file_size(const string& file_name) {
		uint32_t count = 0;
		bool success = safe_file_operation<ifstream>(file_name, [&count](ifstream& file) {
			string line;
			while (getline(file, line)) count++;
		}, ios::in);
		
		if (!success) {
			cout << "Cannot read file " << file_name << " for size calculation" << endl;
		}
		return count;
	}

	// Универсальное сохранение (текст/бинарный)
	void save_array_unified(const vector<double>& a, const string& file_name, bool binary) {
		bool success = false;
		if (binary) {
			success = safe_file_operation<ofstream>(file_name, [&a](ofstream& file) {
				size_t size = a.size();
				file.write(reinterpret_cast<const char*>(&size), sizeof(size));
				file.write(reinterpret_cast<const char*>(a.data()), sizeof(double) * a.size());
			}, ios::binary | ios::out);
		}
		else {
			success = safe_file_operation<ofstream>(file_name, [&a](ofstream& file) {
				iterate_array(a, [&file](double val) { file << val << endl; });
			}, ios::out);
		}
		
		if (success) {
			cout << "Array successfully saved to " << file_name << endl;
		} else {
			cout << "Failed to save array to " << file_name << endl;
		}
	}

	// Универсальная загрузка (текст/бинарный)
	void load_array_unified(vector<double>& a, const string& file_name, bool binary) {
		a.clear();
		bool success = false;
		if (binary) {
			success = safe_file_operation<ifstream>(file_name, [&a](ifstream& file) {
				size_t size;
				file.read(reinterpret_cast<char*>(&size), sizeof(size));
				a.resize(size);
				file.read(reinterpret_cast<char*>(a.data()), sizeof(double) * size);
			}, ios::binary | ios::in);
		}
		else {
			success = safe_file_operation<ifstream>(file_name, [&a](ifstream& file) {
				string line;
				while (getline(file, line)) a.push_back(stod(line));
			}, ios::in);
		}
		
		if (!success) {
			cout << "Failed to load array from " << file_name << ". Creating new array instead." << endl;
			create_new_array(a);
		} else {
			cout << "Array successfully loaded from " << file_name << endl;
		}
	}

	// Получение имени файла
	string get_file_name_from_user() {
		string name;
		cout << "Enter file name: ";
		cin >> name;

		if (name.size() < 4) {
			cout << "Too short, using default 'save.txt'\n";
			return "save.txt";
		}

		if (name.substr(name.size() - 4) != ".txt") {
			cout << "No .txt extension, added automatically.\n";
			name += ".txt";
		}
		return name;
	}

	// Загрузка массива из файла (в зависимости от формата)
	void load_array_from_file(vector<double>& a, const string& file_name) {
		cout << "Load from BIN (B/b)? ";
		char c; cin >> c;

		bool binary = (c == 'B' || c == 'b');
		string fname = file_name;
		if (binary) fname.replace(fname.size() - 3, 3, "bin");

		load_array_unified(a, fname, binary);
	}

	// Создание нового массива
	void create_new_array(vector<double>& a) {
		uint32_t n;
		double min, max;
		cout << "Array size: "; cin >> n;
		cout << "Min value: "; cin >> min;
		cout << "Max value: "; cin >> max;

		a.resize(n);
		fill_rand_array(a, max, min);
	}

	// Вывод результатов
	void display_results(const vector<double>& a) {
		cout << "Your array:\n";
		print_array(a);
		try {
			vector<double> copy = a;
			cout << "Product = " << array_mult(copy) << endl;
		}
		catch (const char* err) {
			cout << err << endl;
		}
	}

	// Сохранение сразу в оба формата
	void save_array_to_files(const vector<double>& a, const string& file_name) {
		string bin_name = file_name;
		bin_name.replace(bin_name.size() - 3, 3, "bin");
		save_array_unified(a, file_name, false);
		save_array_unified(a, bin_name, true);
	}

	// Тестирование функции array_mult
	void tests() {
		
		// Тест 1: Простые единицы
		{
			vector<double> t = {1, 1, 1}; // Проверка assert'ом
			assert(abs(array_mult(t) - 1) <= 1e-9);
		}
		
		// Тест 2: Положительные числа
		{
			vector<double> t = {2, 2, 3};
			assert(abs(array_mult(t) - 12) <= 1e-9);
		}
		
		// Тест 3: Последовательные числа
		{
			vector<double> t = {1, 2, 3};
			assert(abs(array_mult(t) - 6) <= 1e-9);
		}
		
		// Тест 4: Десятичные дроби
		{
			vector<double> t = {0.5, 2, 4};
			assert(abs(array_mult(t) - 4) <= 1e-9);
		}
		
		// Тест 5: Отрицательные числа
		{
			vector<double> t = {-1, 2, -3};
			assert(abs(array_mult(t) - 6) <= 1e-9);
		}
		
		cout << "All tests passed!" << endl;
	}
}
