#include "DataBase.hpp"

int blablabla = 0;

DataBase::DataBase(std::string inputFile, int aparicionesNecesarias) {
  aparicionesNecesarias_ = aparicionesNecesarias;
  titularesCebo_ = 0;
  titularesNoCebo_ = 0;
  std::ifstream ficheroEntrada;
  ficheroEntrada.open(inputFile);
  if (ficheroEntrada.is_open()) {
    std::string lineaActual;
    while (std::getline(ficheroEntrada, lineaActual)) {
      Titulo tituloActual(lineaActual);
      titulos_.push_back(tituloActual);
    }
    ficheroEntrada.close();
    crearVocabulario();
    actualizarRegistros();
  } else {
    std::cout << "Error al abrir fichero de entrada en el constructor de DataBase" << std::endl;
  }
}

std::ostream& DataBase::mostrarTitulos(std::ostream& os) const {
  for (int i = 0; i < titulos_.size(); i++) {
    const std::string cebo = (titulos_[i].esCebo()) ? "cebo" : "nocebo";
    os << titulos_[i] << "," << cebo << std::endl;
  }
  return os;
}

void DataBase::exportarVocabulario(const std::string& ficheroSalida) const {
  std::ofstream outputStream;
  outputStream.open(ficheroSalida);
  if (outputStream.is_open()) {
    mostrarVocabulario(outputStream);
  } else {
    std::cout << "Error al abrir el fichero de salida" << std::endl;
  }
}

void DataBase::crearVocabulario(void) {
  for (int i = 0; i < titulos_.size(); i++){
    miVocabulario_.addTokens(titulos_[i].getTitulo());
  }
}

int DataBase::actualizarRegistros(void) {
  registros_ = miVocabulario_.construirRegistros();
  int totalPalabras = 0;
  for (int i = 0; i < titulos_.size(); i++) {
    for (int j = 0; j < titulos_[i].getTitulo().size(); j++) {
      if (titulos_[i].getTitulo()[j].getTipo() == PALABRA) {
        incrementar(titulos_[i].getTitulo()[j], titulos_[i].esCebo());
        totalPalabras++;
      }
      totalPalabras++;
    }
    if (titulos_[i].esCebo()) {
      titularesCebo_++;
    } else {
      titularesNoCebo_++;
    }
  }
  registros_.push_back(Registro(Token("UNKOWN", PALABRA)));
  totalPalabras += titulos_.size();
  for (int i = 0; i < registros_.size(); i++) {
    registros_[i].setTotalesUnicas(totalPalabras, registros_.size() + 1);
  }
  
  std::vector<Registro> dummy;
  int eliminadas = 0;
  int unkCebo = 0;
  int unkNoCebo = 0;
  for (int i = 0; i < registros_.size(); i++) {
    if (registros_[i].getNumApariciones() > aparicionesNecesarias_) {
      dummy.push_back(registros_[i]);
    } else {
      eliminadas++;
      unkCebo += registros_[i].getAparicionesCebo();
      unkNoCebo += registros_[i].getAparicionesNoCebo();
    }
  }

  Registro unkownRegister = Registro(Token("UNKOWN", PALABRA));
  unkownRegister.setAparicionesCebo(unkCebo);
  unkownRegister.setAparicionesNoCebo(unkNoCebo);

  dummy.push_back(unkownRegister);

  for (int i = 0; i < dummy.size(); i++) {
    dummy[i].setTotalesUnicas(totalPalabras, dummy.size() + 1);
  }

  registros_ = dummy;

  return totalPalabras;
}

void DataBase::incrementar(const Token& miToken, bool esCebo) {
  for (int i = 0; i < registros_.size(); i++) {
    if (registros_[i] == miToken) {
      if (esCebo) {
        registros_[i].aumentarCebo();
      } else {
        registros_[i].aumentarNoCebo();
        //registros_[i].mostrarFrecTotales(std::cout);
      }
      break;
    }
  }
}

void DataBase::exportarFrecuencias(const std::string& ficheroSalida) const {
  std::ofstream outputStream;
  outputStream.open(ficheroSalida);
  if (outputStream.is_open()) {
    outputStream << std::setw(20) << std::left <<  "numtitulares: " << std::setw(20) << std::left <<  titularesCebo_ << std::setw(20) << std::left << titularesNoCebo_ << std::endl;
    for (int i = 0; i < registros_.size(); i++) {
      registros_[i].mostrarFrecTotales(outputStream);
    }
  } else {
    std::cout << "Error al abrir el fichero de salida" << std::endl;
  }
}

void DataBase::exportarLogProb(const std::string& ficheroSalida) const {
  std::ofstream outputStream;
  outputStream.open(ficheroSalida);
  if (outputStream.is_open()) {
    double ceboProporcion = float(titularesCebo_) / titulos_.size();
    double noCeboProporcion = float(titularesNoCebo_) / titulos_.size();
    outputStream << std::setw(20) << std::left << "logprobtitulares: " << std::setw(20) << std::left << std::log(ceboProporcion) << std::setw(20) << std::left<< std::log(noCeboProporcion) << std::endl;
    for (int i = 0; i < registros_.size(); i++) {
      registros_[i].mostrarLogProbLap(outputStream);
    }
  } else {
    std::cout << "Error al abrir el fichero de salida" << std::endl;
  }
}