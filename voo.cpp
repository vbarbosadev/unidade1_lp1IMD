#include <iostream>
#include <string>
#include <vector>

#include "voo.h"


class Voo;
class Astronauta;

Voo::Voo(int cod, vector<Astronauta> Passageiros){
  this->Cod = cod;
  this->Passageiros = Passageiros;
  this->qntPassageiros = Passageiros.size();
  this->Estado = 0;
  this->modeloNave = "Padrão";
}

Voo::Voo(){
  modeloNave = "Padrão";
  //Total++;
}
void Voo::setCod(int cod){
  this->Cod = cod;
}

int Voo::getCod(){
  return Cod;
}

void Voo::setResultado(bool execussao){
  this->Resultado = execussao;
}

bool Voo::getResultado(){
  return Resultado;
}

void Voo::setEstado(int estado){
  this->Estado = estado;
}

int Voo::getEstado(){
  return Estado;
}

/*int Voo::getTotal(){
  return Total;
} */

// ==============================================
