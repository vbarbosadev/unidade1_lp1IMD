#include <iostream>
#include <string>
#include <vector>
#include "astronauta.h"
#include "voo.h"


using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"

class Voo;
//class Astronauta;


Astronauta::Astronauta(){
  //Total++;
  Estado = true;
}

void Astronauta::setCPF(string CPF){
  this->CPF = CPF;
}

string Astronauta::getCPF(){
  return CPF;
}

void Astronauta::setEstado(bool estado){
  Estado = estado;
}

bool Astronauta::getEstado(){
  return Estado;
}

void Astronauta::imprimirCompleto(){
  cout << tab << "Nome: " << this->nome << endl;
  cout << tab << "CPF: " << this->CPF << endl;
  cout << tab << "Idade: " << this->idade << endl;
  cout << tab << "Nacionalidade: " << this->nacionalidade << endl;
  cout << tab << "Sexo: " << this->sexo << endl;
  cout << tab << "Situação: ";
  this->dispo(disp); cout << endl;
  if (this->Estado == true){
    cout << tab << "Estado: Ativo" << endl;
  }  else{
    cout << tab << "Estado: Inativo" << endl;
    // add voo de morte
  }
  cout << tab << "======================" << endl;
}


Astronauta::Astronauta(string nome, string CPF, int idade, string nacionalidade, string sexo){
  this->nome = nome;
  this->CPF = CPF;
  this->idade = idade;
  this->nacionalidade = nacionalidade;
  this->sexo = sexo;
  this->Estado = true;
}

