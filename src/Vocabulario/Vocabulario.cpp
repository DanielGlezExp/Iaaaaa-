#include "Vocabulario.hpp"

Vocabulario::Vocabulario() {
  
}

void Vocabulario::addTokens (const std::vector<Token>& newTokens) {
  for (int i = 0; i < newTokens.size(); i++) {
    if (newTokens[i].getTipo() == PALABRA)
    tokens_.insert(newTokens[i]);
  }
}


std::ostream& Vocabulario::mostrarVocabulario(std::ostream& os) const {
  os << "Numero de palabras:" << tokens_.size() << std::endl;
  for (std::set<Token>::iterator it = tokens_.begin(); it != tokens_.end(); it++) {
    os << *it << std::endl;
  }
  return os;
}

std::vector<Registro> Vocabulario::construirRegistros() const {
  std::vector<Registro> devolver;
  for (std::set<Token>::iterator it = tokens_.begin(); it != tokens_.end(); it++) {
    devolver.push_back(Registro(*it));
  }
  return devolver;
}