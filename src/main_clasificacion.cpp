#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "Tokenizer/Tokenizer.hpp"
#include "Titulo/Titulo.hpp"

#define CEBO 0
#define NO_CEBO 1

std::vector<std::pair<std::string, std::pair<float, float> > > readRegisters (const std::string& inputFile);
void readTitulares (std::vector<Titulo>& result, const std::string& inputFile);
void readOriginales (std::vector<Titulo>& result, const std::string& inputFile);

int main(void) {
  // Nombre de la cadena, y otro pair con primero valor cebo segundo valor no cebo
  std::vector<std::pair<std::string, std::pair<float, float> > > registers = readRegisters("../aprendizajelog.txt");

  // Leer los titulares
  std::vector<Titulo> titulares;
  readTitulares(titulares, "../examples/cebo_train_no_class.csv");

  //Exportar resultado
  std::ofstream myfile;
  myfile.open ("../clasificacion_alu0100894479.csv");
  for (int i = 0; i < titulares.size(); i++) {
    titulares[i].clasificar(registers);
    titulares[i].mostrarClasificado(myfile);
  }
  myfile.close();

  //Comprobar acierto
  std::vector<Titulo> originales;
  int aciertos = 0;
  int total = 0;
  readOriginales(originales, "../examples/cebo_train.csv");
  for (int i = 0; i < originales.size() ; i++) {
    if (originales[i].esCebo() == titulares[i].esCebo()) {
      aciertos++;
    }
    total++;
  }
  std::cout << "la precision es " << ((float)(aciertos)) / ((float)(total)) << std::endl;
}

std::vector<std::pair<std::string, std::pair<float, float> > > readRegisters (const std::string& inputFile) {
  std::vector<std::pair<std::string, std::pair<float, float> > > registers;
  std::ifstream ficheroEntrada;
  ficheroEntrada.open(inputFile);
  if (ficheroEntrada.is_open()) {
    std::string nombre;
    while (ficheroEntrada >> nombre) {
      float cebo;
      float noCebo;
      ficheroEntrada >> cebo;
      ficheroEntrada >> noCebo;
      registers.push_back(std::pair<std::string, std::pair<float, float> >(nombre, std::pair<float, float>(cebo, noCebo)));
    }
    ficheroEntrada.close();
  } else {
    std::cout << "Error al abrir fichero de entrada aprendizajelog.txt" << std::endl;
  }
  return registers;
}

void readTitulares (std::vector<Titulo>& result, const std::string& inputFile) {
  std::ifstream ficheroEntrada;
  ficheroEntrada.open(inputFile);
  if (ficheroEntrada.is_open()) {
    std::string lineaActual;
    bool prueba = true;
    while (std::getline(ficheroEntrada, lineaActual)) {
      Titulo tituloActual(lineaActual, prueba);
      result.push_back(tituloActual);
    }
    ficheroEntrada.close();
  } else {
    std::cout << "Error al abrir fichero de entrada aprendizajelog.txt" << std::endl;
  }
}

void readOriginales (std::vector<Titulo>& result, const std::string& inputFile) {
  std::ifstream ficheroEntrada;
  ficheroEntrada.open(inputFile);
  if (ficheroEntrada.is_open()) {
    std::string lineaActual;
    while (std::getline(ficheroEntrada, lineaActual)) {
      Titulo tituloActual(lineaActual);
      result.push_back(tituloActual);
    }
    ficheroEntrada.close();
  } else {
    std::cout << "Error al abrir fichero de entrada aprendizajelog.txt" << std::endl;
  }
}
