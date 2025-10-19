#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

using std::vector; using std::string; using std::cout; using std::cin; using std::endl;
using std::ofstream; using std::ifstream; using std::ios; using std::getline; using std::stod;
using std::rand; using std::srand; using std::time; using std::size_t;

namespace array_operations {

	// Универсальный проход по массиву с применением функции к каждому элементу
	template<typename T, typename Func>
	void iterate_array(const vector<T>& a, Func operation) {
		for (const auto& element : a)
			operation(element);
	}

	// Безопасная работа с файлом с автоматическим закрытием
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
	double array_mult(vector<double>& a); // Вычисление произведения элементов массива
	void print_array(const vector<double>& a); // Вывод массива на экран
	void fill_rand_array(vector<double>& a, double max, double min); // Заполнение массива случайными числами
	uint16_t file_size(const string& file_name); // Подсчет количества строк в файле

	// Универсальные функции сохранения и загрузки
	void save_array_unified(const vector<double>& a, const string& file_name, bool binary = false); // Сохранение массива в файл
	void load_array_unified(vector<double>& a, const string& file_name, bool binary = false); // Загрузка массива из файла

	// Пользовательский ввод и логика работы
	string get_file_name_from_user(); // Получение имени файла от пользователя
	void load_array_from_file(vector<double>& a, const string& file_name); // Загрузка массива из файла с выбором формата
	void create_new_array(vector<double>& a); // Создание нового массива с пользовательскими параметрами
	void create_new_array(vector<double>& a, uint32_t n, double min, double max); // Создание массива с параметрами из аргументов
	void display_results(const vector<double>& a); // Вывод результатов работы с массивом
	void save_array_to_files(const vector<double>& a, const string& file_name); // Сохранение массива в оба формата

	// Работа с аргументами командной строки
	void print_help(); // Вывод справки по использованию
	bool parse_arguments(int argc, char* argv[], string& filename, bool& load_from_file,
		bool& binary_mode, bool& run_tests_only, uint32_t& array_size,
		double& min_val, double& max_val); // Обработка аргументов командной строки

	// Тестирование функций
	void tests(); // Запуск тестов для проверки корректности функций
}