#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "../Titulo/Titulo.hpp"
#include "../Token/Token.hpp"
#include "../Vocabulario/Vocabulario.hpp"
#include "../Registro/Registro.hpp"

class DataBase {
 private:
  int titularesCebo_;
  int titularesNoCebo_;
  std::vector<Titulo> titulos_;
  std::vector<Registro> registros_;

  Vocabulario miVocabulario_;
 
  /**
   * @brief Numero de apariciones necesarias para que un elemento pase a ser distinto de UNKOWN
   * 
   */
  int aparicionesNecesarias_;

  void crearVocabulario(void);

  int actualizarRegistros(void);

  void incrementar(const Token& miToken, bool esCebo);

 public:
  DataBase(std::string inputFile, int aparicionesNecesarias);
  ~DataBase() {}

  std::ostream& mostrarTitulos(std::ostream& os) const;
  std::ostream& mostrarVocabulario(std::ostream& os) const { miVocabulario_.mostrarVocabulario(os); return os;}
  void exportarVocabulario(const std::string& ficheroSalida) const;
  void exportarFrecuencias(const std::string& ficheroSalida) const;
  void exportarLogProb(const std::string& ficheroSalida) const;
};