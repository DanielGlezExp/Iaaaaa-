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

 public:
  Titulo(const std::string& lineaEntrada);
  ~Titulo() {}

  bool esCebo() const { return esCebo_;}
  std::vector<Token> getTitulo() const { return tituloTokens_;}
  std::vector<Token>& getTitulo() { return tituloTokens_;}
};