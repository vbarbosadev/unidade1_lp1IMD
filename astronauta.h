#ifndef ASTRONAUTA_H_INCLUDED
#define ASTRONAUTA_H_INCLUDED 

#include <iostream>
#include <string>
#include <vector>



using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"

class Voo;

class Astronauta {
  private:
    bool Estado;
    string CPF;

  public:
    Astronauta();
    Astronauta(string nome, string CPF, int idade, string nacionalidade, string sexo);

    void imprimirCompleto();
    void dispo(bool disp){
      if(disp == false){
        cout << "disponível";
      } else{
        cout << "em voo";
        // mostrar voo em execussão que ele está
      }
    }

    string nome;  // nome do astronauta
    int idade;
    bool disp;  // disponibilidade do astronauta

    
    void setEstado(bool);
    bool getEstado();
    void setCPF(string);
    string getCPF();

    // extras;
    string sexo;
    string nacionalidade;


    vector<Voo> Voos;
};



#endif