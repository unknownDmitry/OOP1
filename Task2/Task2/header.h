//Савин Дмитрий ИВТ-22
//Задача 136н: Даны натуральное число n, действительные числа a1,..., an. Вычислить Σ((√|a[i]| - a[i])^2)

#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <cassert>

namespace math_and_files {

	//Заполнение массива arr длины n псевдослучайными числами
	void fill_arr(std::vector <double>& arr);
	void fill_arr(double arr[], int n);

	//Вывод массива arr длины n
	void output_arr(std::vector<double>& arr);
	void output_arr(double arr[], int n);

	//Вычисление результата по формуле
	double calc(std::vector <double>& arr);
	double calc(double arr[], int n);

	// Чтение массива длины n из файла с именем file_name
	std::vector<double> f_read_arr(const std::string& filename);
	double* f_read_arr(int& n, const std::string& file_name);

	//Запись массива arr длины n в файл с именем file_name
	void f_save_arr(std::vector<double>& arr, const std::string& file_name);
	void f_save_arr(float arr[], int n, const std::string& file_name);

	void test();
}