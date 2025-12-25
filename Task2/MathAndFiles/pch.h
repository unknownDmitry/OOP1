// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
//Савин Дмитрий ИВТ-22
//Задача 136н: Даны натуральное число n, действительные числа a1,..., an. Вычислить Σ((√|a[i]| - a[i])^2)


#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <cassert>
#include <memory>

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
	std::unique_ptr<double[]> f_read_arr(int* n, const std::string& file_name);

	//Запись массива arr длины n в файл с именем file_name
	void f_save_arr(std::vector<double>& arr, const std::string& file_name);
	void f_save_arr(double arr[], int n, const std::string& file_name);

	// Чтение массива из бинарного файла
	std::vector<double> f_read_arr_bin(const std::string& file_name);
	std::unique_ptr<double[]> f_read_arr_bin(int* n, const std::string& file_name);

	// Запись массива в бинарный файл
	void f_save_arr_bin(std::vector<double>& arr, const std::string& file_name);
	void f_save_arr_bin(double arr[], int n, const std::string& file_name);

	void test();
}

#endif //PCH_H
