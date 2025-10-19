#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

// Импортируем только нужные типы
using std::vector;
using std::string;

namespace array_operations {

	// Шаблонная функция для итерации по массиву
	template<typename T, typename Func>
	void iterate_array(const vector<T>& a, Func operation) {
		for (int i = 0; i < a.size(); i++) {
			operation(a[i]);
		}
	}

	// Шаблонная функция для безопасной работы с файлами
	template<typename T, typename FileOperation>
	bool safe_file_operation(const string& file_name, FileOperation operation) {
		T file(file_name);
		if (!file.is_open()) {
			std::cout << "File not found: " << file_name << std::endl;
			return false;
		}
		operation(file);
		file.close();
		return true;
	}

	// Вычисляет произведение всех элементов массива
	static double array_mult(vector<double>& a);

	// Выводит элементы массива в консоль
	void print_array(const vector<double>& a);
	
	// Сохраняет массив в текстовый файл
	void save_array(const vector<double>& a, const string& file_name);
	
	// Заполняет массив случайными числами в заданном диапазоне
	void fill_rand_array(vector<double>& a, double max, double min);
	
	// Определяет количество строк в файле
	uint32_t file_size(const string& file_name);
	
	// Загружает массив из текстового файла
	void load_array(vector<double>& a, const string& file_name);
	
	// Загружает массив из бинарного файла
	void load_array_bin(vector<double>& a, const string& file_name);
	
	// Сохраняет массив в бинарный файл
	void save_array_bin(const vector<double>& a, const string& file_name);

	// Обрабатывает операции с массивом (загрузка/создание, вывод, сохранение)
	void process_array_operations(vector<double>& a);

}