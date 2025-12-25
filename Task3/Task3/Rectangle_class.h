//Савин Дмитрий ИВТ-22
//Класс Прямоугольник (сокращённая версия)

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>

using std::string;

// Declare tests function
void tests();

const float eps = 1e-4f; 

class Rectangle {
private:
   float width;  // Ширина 
   float height; // Высота

public:
   // Конструкторы
   Rectangle();                       // Конструктор по умолчанию
   Rectangle(float w, float h);       // Конструктор с параметрами

   // Геттеры
   float get_width() const;           // Возвращает ширину
   float get_height() const;          // Возвращает высоту

   // Сеттеры
   void set_width(const float& w);    // Устанавливает ширину
   void set_height(const float& h);   // Устанавливает высоту

   // Геометрические функции
   float area() const;                // Вычисляет площадь
   float perimeter() const;           // Вычисляет периметр
};
