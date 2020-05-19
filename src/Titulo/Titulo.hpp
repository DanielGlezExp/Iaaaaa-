#pragma once
#include "../Token/Token.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include <vector>
#include <string>
#include <iostream>

class Titulo {
  friend std::ostream& operator<< (std::ostream& os, const Titulo miTitulo);
 private:
  bool esCebo_;
  std::vector<Token> tituloTokens_;
  float probCebo_;
  float probNoCebo_;
  std::string originalTitle_;

 public:
  Titulo(const std::string& lineaEntrada);
  Titulo(const std::string& lineaEntrada, bool prueba);
  ~Titulo() {}

  bool esCebo() const { return esCebo_;}
  std::vector<Token> getTitulo() const { return tituloTokens_;}
  std::vector<Token>& getTitulo() { return tituloTokens_;}

  void clasificar (const std::vector<std::pair<std::string, std::pair<float, float> > >& registers);

  void mostrarClasificado (std::ostream& os);
};