//Савин Дмитрий ИВТ-22
//Класс Прямоугольник

#include "Rectangle_class.h"
#include <cmath>
#include <cassert>

// Конструктор по умолчанию
Rectangle::Rectangle() {
   width = 0.0;
   height = 0.0;
}

// Конструктор с параметрами
Rectangle::Rectangle(float w, float h) {
   width = (w < 0.0) ? 0.0 : w;
   height = (h < 0.0) ? 0.0 : h;
}

// Возвращает значение ширины
float Rectangle::get_width() const {
   return width;
}

// Возвращает значение высоты
float Rectangle::get_height() const {
   return height;
}

// Устанавливает новое значение ширины
void Rectangle::set_width(const float& w) {
   width = (w < 0.0) ? 0.0 : w;
}

// Устанавливает новое значение высоты
void Rectangle::set_height(const float& h) {
   height = (h < 0.0) ? 0.0 : h;
}

// Вычисляет площадь
float Rectangle::area() const {
   return width * height;
}

// Вычисляет периметр
float Rectangle::perimeter() const {
   return 2 * (width + height);
}

void tests() {
   Rectangle A(4, 5);

   assert(fabs(A.area() - 20) < eps);
   assert(fabs(A.perimeter() - 18) < eps);

   Rectangle B(4, 4);
   assert(fabs(B.area() - 16) < eps);
   assert(fabs(B.perimeter() - 16) < eps);

   Rectangle C(0, 5);
   assert(fabs(C.area() - 0) < eps);
   assert(fabs(C.perimeter() - 10) < eps);

   Rectangle D(3.5, 2.5);
   assert(fabs(D.area() - 8.75) < eps);
   assert(fabs(D.perimeter() - 12) < eps);
}
