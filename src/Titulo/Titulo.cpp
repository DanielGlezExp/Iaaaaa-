#include "Titulo.hpp"

Titulo::Titulo(const std::string& lineaEntrada) {
  int indexLastComma = -1;
  for (int i = lineaEntrada.size() - 1; i > 0; --i) {
    if (lineaEntrada[i] == ',') {
      indexLastComma = i;
      break;
    }
  }
  if (indexLastComma == -1) {
    std::cout << "Error en el constructor de Titulo, no contiene ninguna , para separar titulo de si es cebo o no" << std::endl;
    std::cout << "Fuente: " << lineaEntrada << std::endl;
  } else {
    const std::string ceboCadena = lineaEntrada.substr(indexLastComma + 1);
    esCebo_ = (ceboCadena == "cebo\r")? true : false;
    const std::string cadenaTitulo = lineaEntrada.substr(0, indexLastComma);
    Tokenizer tokenizer;
    tituloTokens_ = tokenizer.getTokens(cadenaTitulo);
  }
}

std::ostream& operator<< (std::ostream& os, const Titulo miTitulo) {
  for (int i = 0; i < miTitulo.tituloTokens_.size(); i++) {
    os <<  miTitulo.tituloTokens_[i] << " ";
  }
  if (miTitulo.esCebo()) {
    os << " cebo";
  } else {
    os << " no cebo";
  }
  return os;
}
