#pragma once
#include <string>
#include <iostream>

enum TipoToken { PALABRA, MARCADOR, NUMERO };


class Token {
  friend std::ostream& operator<<(std::ostream& os, const Token& miToken);
 private:
  std::string token_;
  TipoToken tipo_;

 public:
  Token(std::string original, TipoToken tipo = PALABRA);
  Token(const Token& orginal) { token_ = orginal.token_; tipo_ = orginal.tipo_;}
  virtual ~Token() {}

  inline std::string getToken(void) const {return token_;}

  TipoToken getTipo(void) const {return tipo_;}

  bool operator< (const Token& otherToken) const;

  bool operator== (const Token& otherToken) const {return token_ == otherToken.token_;}
};