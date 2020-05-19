#include <iostream>
#include "DataBase/DataBase.hpp"

int main(void) {
  int K = 4;
  DataBase miBase("../examples/cebo_train.csv", K);
  std::cout << "Exportando vocabulario..." << std::endl;
  miBase.exportarVocabulario("../vocabulario.txt");
  std::cout << "Proceso completado!, puede ver el fichero de salida en el fichero 'vocabulario.txt' en la raíz del proyecto" << std::endl;
  std::cout << "Exportando aprendizaje.txt..." << std::endl;
  miBase.exportarFrecuencias("../aprendizaje.txt");
  std::cout << "Proceso completado!, puede ver el fichero de salida en el fichero 'aprendizaje.txt' en la raíz del proyecto" << std::endl;
   std::cout << "Exportando aprendizajelog.txt..." << std::endl;
  miBase.exportarLogProb("../aprendizajelog.txt");
  std::cout << "Proceso completado!, puede ver el fichero de salida en el fichero 'aprendizajelog.txt' en la raíz del proyecto" << std::endl;
}