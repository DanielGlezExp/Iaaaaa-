#include "Tokenizer.hpp"

std::vector<Token> Tokenizer::getTokens(const std::string& input) {
  currentIndex_ = 0;
  tokens_ = std::vector<Token>();
  while (currentIndex_ < input.size()) {
    char startChar = input[currentIndex_];
    if (isalpha(startChar)) {
      saveWord(input);
    } else if (isdigit(startChar)) {
      saveNumber(input);
    } else if (esMarcador(input[currentIndex_])) {
      std::string dummy = "";
      dummy.push_back(input[currentIndex_]);
      const Token newToken(dummy, MARCADOR);
      tokens_.push_back(newToken);
    }
    currentIndex_++;
    
  }
  return tokens_;
}

bool Tokenizer::esSeparador(char c) const {
  return (c == ' ' || c == '\n');
}

bool Tokenizer::esMarcador(char c) const {
  return (!esSeparador(c) && !isalpha(c) && !isdigit(c));
}

void Tokenizer::saveNumber(const std::string& input) {
  std::string strToken = "";
  while (currentIndex_ < input.size() && !esSeparador(input[currentIndex_]) && !esMarcador(input[currentIndex_]) && isdigit(input[currentIndex_]) ) {
    strToken.push_back(input[currentIndex_]);
    currentIndex_++;
  }
  if (!strToken.empty()) {
      const Token newToken(strToken, NUMERO);
      tokens_.push_back(newToken);
  }
}

void Tokenizer::saveWord(const std::string& input) {
  std::string strToken = "";
    
  while (currentIndex_ < input.size() && !esSeparador(input[currentIndex_]) && !esMarcador(input[currentIndex_]) && isalpha(input[currentIndex_]) ) {
    strToken.push_back(input[currentIndex_]);
    currentIndex_++;
  }
  if (!strToken.empty()) {
      const Token newToken(strToken, PALABRA);
      tokens_.push_back(newToken);
  }
}