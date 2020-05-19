#pragma once
#include "../Token/Token.hpp"
#include <vector>
#include <stdio.h>
#include <stdlib.h>

class Tokenizer {
 private:
  std::vector<Token> tokens_;
  int currentIndex_;

  bool esSeparador(char c) const;

  bool esMarcador(char c) const;

  void saveNumber(const std::string& input);

  void saveWord(const std::string& input);

 public:
  Tokenizer() {currentIndex_ = 0;}
  virtual ~Tokenizer() = default;

  std::vector<Token> getTokens(const std::string& input);
};