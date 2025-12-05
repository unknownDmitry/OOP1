//Савин Дмитрий ИВТ-22
//Класс Прямоугольник

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>

using std::string;

const float eps = 1e-4; // Константа для сравнения

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
   float diagonal() const;            // Вычисляет длину диагонали
   float aspect_ratio() const;        // Вычисляет соотношение сторон (ширина/высота)
   bool is_square() const;            // Проверяет, является ли прямоугольник квадратом

   // Операции изменения размеров
   void add_size(const Rectangle& r);     // Увеличивает размеры на размеры другого прямоугольника
   void subtract_size(const Rectangle& r); // Уменьшает размеры на размеры другого прямоугольника
   void scale(const float& k);             // Масштабирует размеры на коэффициент k

   // Функции сравнения
   bool equal_size(const Rectangle& r) const; // Сравнивает размеры с другим прямоугольником
   bool bigger_than(const Rectangle& r) const; // Сравнивает площади (текущий > другого)

   // Строковое представление
   string to_str() const;             // Возвращает строку с шириной и высотой
   string info() const;               // Возвращает детальную информацию о прямоугольнике
};

void tests(); // Тесты