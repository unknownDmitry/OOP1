//Савин Дмитрий ИВТ-22
//Класс Прямоугольник

#pragma once

void tests();

const float eps = 1e-4f; // Точность для тестов

class Rectangle {
private:
   float width;  // Ширина 
   float height; // Высота
   float x;
   float y;

public:
   // Конструкторы
   Rectangle();                              // Конструктор по умолчанию
   Rectangle(float w, float h);              // Конструктор с параметрами
   Rectangle(float w, float h, float x, float y); // Конструктор с параметрами (включая координаты)

   // Геттеры
   float get_width() const;           // Возвращает ширину
   float get_height() const;          // Возвращает высоту
   float get_x() const;               // Возвращает координату x
   float get_y() const;               // Возвращает координату y

   // Сеттеры
   void set_width(const float& w);    // Устанавливает ширину
   void set_height(const float& h);   // Устанавливает высоту
   void set_x(const float& x);        // Устанавливает координату x
   void set_y(const float& y);        // Устанавливает координату y

   // Геометрические функции
   float area() const;                // Вычисляет площадь
   float perimeter() const;           // Вычисляет периметр
   float diagonal() const;            // Вычисляет длину диагонали
   bool is_square() const;            // Проверяет, является ли квадратом

};
