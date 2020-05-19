#include "Titulo.hpp"

Titulo::Titulo(const std::string& lineaEntrada) {
  originalTitle_ = lineaEntrada;
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

Titulo::Titulo(const std::string& lineaEntrada, bool prueba) {
  originalTitle_ = lineaEntrada.substr(0, lineaEntrada.size()-1);;
  Tokenizer tokenizer;
  tituloTokens_ = tokenizer.getTokens(lineaEntrada);
}

std::ostream& operator<< (std::ostream& os, const Titulo miTitulo) {
  for (int i = 0; i < miTitulo.tituloTokens_.size(); i++) {
    os <<  miTitulo.tituloTokens_[i] << " ";
  }
  //os << miTitulo.originalTitle_;
  if (miTitulo.esCebo()) {
    os << " cebo";
  } else {
    os << " no cebo";
  }
  return os;
}

void Titulo::clasificar(const std::vector<std::pair<std::string, std::pair<float, float> > >& registers) {
  probCebo_ = 0;
  probNoCebo_ = 0;
  for (int i = 0; i < tituloTokens_.size(); i++) {
    if (tituloTokens_[i].getTipo() == PALABRA) {
      bool found = false;
      for (int j = 0; j < registers.size() - 1; j++) {
        if (registers[j].first == tituloTokens_[i].getToken()) {
          found = true;
          probCebo_ += registers[j].second.first;
          probNoCebo_ += registers[j].second.second;
          break;
        }
      }
      if (!found) {
        probCebo_ += registers[registers.size() - 1].second.first;
        probNoCebo_ += registers[registers.size() - 1].second.second;
      }
    }
  }
  esCebo_ = probCebo_ > probNoCebo_;
}

void Titulo::mostrarClasificado(std::ostream& os) {
  /*for (int i = 0; i < tituloTokens_.size(); i++) {
    os <<  tituloTokens_[i] << " ";
  }*/
  os << originalTitle_;
  os << ";" << probCebo_ << ";" << probNoCebo_ << ";";
  if (esCebo()) {
    os << "cebo";
  } else {
    os << "no cebo";
  }
  os << std::endl;
}