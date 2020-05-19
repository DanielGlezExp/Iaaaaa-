#pragma once
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "../Token/Token.hpp"

class Registro {
 private:
  int frecCebo_;
  int frecNoCebo_;
  int numPalabrasTotales_;
  int numPalabrasUnicas_;
  Token miToken_;

 public:
  Registro(const Token& token): miToken_(token) { 
    frecCebo_ = 0;
    frecNoCebo_ = 0;
    numPalabrasTotales_ = 0;
    numPalabrasUnicas_ = 0;
  }
  
  ~Registro() {}

  int getNumApariciones() const {return frecCebo_ + frecNoCebo_;}

  bool operator == (const Token& token) {
    return token == miToken_;
  }

  void aumentarCebo() {frecCebo_++;}

  void aumentarNoCebo() {frecNoCebo_++;}

  void setTotalesUnicas(int totales, int unicas) {numPalabrasTotales_ = totales; numPalabrasUnicas_ = unicas;}

  std::ostream& mostrarFrecTotales (std::ostream& os) const {
    os << std::setw(20) << std::left << miToken_ << std::setw(20) << std::left << frecCebo_ << std::setw(20) << std::left << frecNoCebo_ << std::endl;
    return os;
  }

  std::ostream& mostrarLogProbLap (std::ostream& os) const {
    double ceboValor = (frecCebo_ + 1.0) / (numPalabrasTotales_ + numPalabrasUnicas_);
    /*if (miToken_.getToken() == "unkown") {
      std::cout << ceboValor << std::endl;
    }*/
    double noCeboValor = (frecNoCebo_ + 1.0) / (numPalabrasTotales_ + numPalabrasUnicas_);
    os << std::setw(20) << std::left << miToken_ << std::setw(20) << std::left << log(ceboValor) << std::setw(20) << std::left << log(noCeboValor) << std::endl;
  }
};