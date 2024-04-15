#include <iostream>
#include <string>
#include <vector>
#include "voo.h"
#include "astronauta.h"
#include "funcoes.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"

class Voo;
class Astronauta;

int main() {

  vector<Astronauta> Astronautas;
  vector<Voo> Voos;
  

  
  Astronauta Astronauta("astroIN", "123.456.789-10", 55, "br", "M");
  Astronautas.push_back(Astronauta);
  Voo Voo(012, Astronautas);
  imprimirCompletoAstronautas(Astronautas);
  Voos.push_back(Voo);
  //Voo.criar(762, Astronautas[0]);
    
  int opc;

  do{
    Astronautas = reorganizarAstronautas(Astronautas);
    cout << endl << tab << "1 - Cadastrar Astronauta" << endl;
    cout << tab << "2 - Cadastrar Voo" << endl;
    cout << tab << "3 - Listar Astronautas" << endl;
    cout << tab << "4 - Listar Voos" << endl;
    cout << tab << "5 - Finalizar Voo" << endl;
    cout << tab << "9 - Sair" << endl;
    cout << endl << tab << "Opção: ";
    cin >> opc;


    switch(opc){
      case 1:
        cout << "\033[2J\033[1;1H";
        Astronautas.push_back(criarAstronauta());
        cout << "\033[2J\033[1;1H";
        break;
      case 2:
        cout << "\033[2J\033[1;1H";
        Voos.push_back(criarVoo(Astronautas));
        break;
      case 3: // Listar astronautas
        cout << "\033[2J\033[1;1H";
        imprimirCompletoAstronautas(Astronautas);

        cout << endl << endl << "Pressione qualquer tecla para continuar..." << endl;
        cin.ignore();
        cin.get();
        cout << "\033[2J\033[1;1H";
        break;
      
      case 4: // Listar voos
        cout << "\033[2J\033[1;1H";
        menu_lista_voos(Voos);
        break;
      
      case 5: //
        Astronautas[1].setEstado(false);
        break;
      case 6:
        break;
      case 9: // sair
        break;
      default:
        cout << "Opção inválida!" << endl;     
    }
    


    
  } while (opc != 9);

  
  
  std::cout << "Hello World!\n";
}
