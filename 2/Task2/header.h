#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

namespace ArrayFuncs {

	static double array_mult(std::vector<double>& a);

	void print_array(const std::vector<double>& a);
	void save_array(const std::vector<double>& a, const std::string& file_name);
	void fill_rand_array(std::vector<double>& a, double max, double min);
	uint32_t file_size(const std::string& file_name);
	void load_array(std::vector<double>& a, const std::string& file_name);
	void load_array_bin(std::vector<double>& a, const std::string& file_name);
	void save_array_bin(const std::vector<double>& a, const std::string& file_name);

}

namespace print_array_operations {
	void process_array_operations(std::vector<double>& a);
}