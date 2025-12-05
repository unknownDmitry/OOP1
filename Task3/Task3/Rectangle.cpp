//Савин Дмитрий ИВТ-22
//Класс Прямоугольник

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
   cout << B->info() << endl << endl;

   cout << "A: " << A.info() << endl << endl;

   delete B;

   tests();
}
