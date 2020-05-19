#include "Token.hpp"

Token::Token(std::string original, TipoToken tipo) {
  tipo_ = tipo;
  token_ = "";
  for (int i = 0; i < original.size(); i++) {
    token_.push_back(tolower(original[i]));
  }
}


bool Token::operator< (const Token& otherToken) const {
  int indice = 0;
  while (indice < token_.size() && indice < otherToken.token_.size()) {
    if (token_[indice] < otherToken.token_[indice]) {
      return true;
    }
    if (token_[indice] > otherToken.token_[indice]) {
      return false;
    }
    indice++;
  }
  return token_.size() < otherToken.token_.size();
}

std::ostream& operator<<(std::ostream& os, const Token& miToken) {
  os << miToken.token_;
  return os;
}