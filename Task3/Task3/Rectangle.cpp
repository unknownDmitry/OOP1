//Савин Дмитрий ИВТ-22
//Класс Прямоугольник (сокращённая версия)

#include "Rectangle_class.h"

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

int main() {
   Rectangle A(7.2, 7.2);
   Rectangle* B = new Rectangle();

   {   // Работа с файлом
      float tmp{};
      string file_name{ "Rectangle.txt" };
      ofstream file_write(file_name);

      file_write << A.get_width() << " " << A.get_height();
      file_write.close();

      ifstream file_read(file_name);

      file_read >> tmp;
      B->set_width(tmp);

      file_read >> tmp;
      B->set_height(tmp);
   }

   cout << "Rectangle B:" << endl;
   cout << "Area: " << B->area() << endl;
   cout << "Perimeter: " << B->perimeter() << endl << endl;

   cout << "A: " << endl;
   cout << "Area: " << A.area() << endl;
   cout << "Perimeter: " << A.perimeter() << endl << endl;

   delete B;

   tests(); // Now this will compile and link correctly
   return 0;
}
