#pragma once
#include "../Token/Token.hpp"
#include <set>
#include <fstream>
#include <vector>
#include "../Registro/Registro.hpp"

class Vocabulario {
 private:
  std::set<Token> tokens_;

 public:
  Vocabulario ();
  virtual ~Vocabulario () {}

  void addTokens (const std::vector<Token>& newTokens);

  inline std::set<Token>& getTokens_() {return tokens_;}

  std::ostream& mostrarVocabulario(std::ostream& os) const;

  std::vector<Registro> construirRegistros() const;
};