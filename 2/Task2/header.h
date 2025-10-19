#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

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

	// Универсальный проход по массиву
	template<typename T, typename Func>
	void iterate_array(const vector<T>& a, Func operation) {
		for (const auto& element : a)
			operation(element);
	}

	// Безопасная работа с файлом
	template<typename T, typename FileOperation>
	bool safe_file_operation(const string& file_name, FileOperation operation, ios::openmode mode = ios::in) {
		T file(file_name, mode);
		if (!file.is_open()) {
			cout << "File error: " << file_name << endl;
			return false;
		}
		operation(file);
		file.close();
		return true;
	}

	// Основные функции
	double array_mult(vector<double>& a);
	void print_array(const vector<double>& a);
	void fill_rand_array(vector<double>& a, double max, double min);
	uint32_t file_size(const string& file_name);

	// Универсальные функции сохранения и загрузки
	void save_array_unified(const vector<double>& a, const string& file_name, bool binary = false);
	void load_array_unified(vector<double>& a, const string& file_name, bool binary = false);

	// Пользовательский ввод и логика работы
	string get_file_name_from_user();
	void load_array_from_file(vector<double>& a, const string& file_name);
	void create_new_array(vector<double>& a);
	void display_results(const vector<double>& a);
	void save_array_to_files(const vector<double>& a, const string& file_name);
	
	// Тестирование функций
	void tests();
}
