//Савин Дмитрий ИВТ-22
//Класс Прямоугольник

#include "Rectangle_class.h"

// Конструкторы

// Конструктор по умолчанию
Rectangle::Rectangle() { 
   width = 0.0;
   height = 0.0;
}

// Конструктор с параметрами
Rectangle::Rectangle(float w, float h) { 
   width = w;
   height = h;
}

// Геттеры

// Возвращает значение ширины
float Rectangle::get_width() const { 
   return width;
}

// Возвращает значение высоты
float Rectangle::get_height() const { 
   return height;
}

// Сеттеры

// Устанавливает новое значение ширины
void Rectangle::set_width(const float& w) { 
   width = w;
}

// Устанавливает новое значение высоты
void Rectangle::set_height(const float& h) { 
   height = h;
}

// Геометрические функции

// Вычисляет площадь
float Rectangle::area() const { 
   return width * height;
}

// Вычисляет периметр
float Rectangle::perimeter() const { 
   return 2 * (width + height);
}

// Вычисляет диагональ по теореме Пифагора
float Rectangle::diagonal() const { 
   return sqrt(width * width + height * height);
}

// Вычисляет соотношение сторон
float Rectangle::aspect_ratio() const { 
   if (height == 0) return 0;
   return width / height;
}

// Проверяет, равны ли ширина и высота с точностью до eps
bool Rectangle::is_square() const { 
   return fabs(width - height) < eps;
}

// Операции изменения размеров

// Увеличивает ширину и высоту на значения из r
void Rectangle::add_size(const Rectangle& r) {
   width += r.width;
   height += r.height;
}

// Уменьшает ширину и высоту на значения из r
void Rectangle::subtract_size(const Rectangle& r) { 
   width -= r.width;
   height -= r.height;
}

// Умножает ширину и высоту на коэффициент k
void Rectangle::scale(const float& k) { 
   width *= k;
   height *= k;
}

// Функции сравнения

// Сравнивает ширину и высоту с прямоугольником r
bool Rectangle::equal_size(const Rectangle& r) const { 
   return fabs(width - r.width) < eps &&
      fabs(height - r.height) < eps;
}

// Сравнивает площади: текущая > площади 
bool Rectangle::bigger_than(const Rectangle& r) const { 
   return area() > r.area();
}

// Строковое представление

// Возвращает строку
string Rectangle::to_str() const { 
   return "(width = " + std::to_string(width) +
      "; height = " + std::to_string(height) + ")";
}

// Информация
string Rectangle::info() const { 
   return "Rectangle: " + to_str() +
      "\nArea: " + std::to_string(area()) +
      "\nPerimeter: " + std::to_string(perimeter()) +
      "\nDiagonal: " + std::to_string(diagonal()) +
      "\nIs square: " + (is_square() ? "yes" : "no");
}

// Тесты
void tests() {
   Rectangle A(4, 5);

   assert(fabs(A.area() - 20) < eps);
   assert(fabs(A.perimeter() - 18) < eps);
   assert(fabs(A.diagonal() - sqrt(41)) < eps);

   Rectangle B(4, 4);
   assert(B.is_square());
   assert(!A.is_square());

   A.scale(2);
   assert(fabs(A.get_width() - 8) < eps);
   assert(fabs(A.get_height() - 10) < eps);

   Rectangle C(8, 10);
   assert(A.equal_size(C));

   Rectangle D(1, 1);
   assert(A.bigger_than(D));
}