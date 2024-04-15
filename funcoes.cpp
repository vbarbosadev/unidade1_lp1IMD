#include <iostream>
#include <string>
#include <vector>
#include "voo.h"
#include "astronauta.h"

class Astronauta;
class Voo;


Voo criarVoo(vector<Astronauta> Astronautas){
  vector<Astronauta> Passageiros;
  
  int cod, qnt, opc;
  cout << tab << "Digite o codigo de cadastro do voo: ";
  cin >> cod;
  cout << "Quantidade de passageiros do voo" << endl;
  cin >> qnt;
  cout << tab << "Astronautas cadastrados: " << endl;
  for(int i = 0; i < Astronautas.size(); i++){
    if(Astronautas[i].getEstado() == true){
      cout << tab << i+1 << " - " << Astronautas[i].nome << endl;
    }
  }
  if(qnt > 1){
    for(int i = 0; i<qnt; i++){
      cout << "Escolha o " << i+1 << "º passageiro: ";
      cin >> opc;
      Passageiros.push_back(Astronautas[opc-1]);
    }
  }  else {
        cout << "Escolha o Astronauta: ";
        cin >> opc;
        Passageiros.push_back(Astronautas[opc-1]);
  }
  Voo voo(cod, Passageiros);
  return voo;
}

void estado_do_voo(vector<Voo> Voos, int i){
    switch (Voos[i].getEstado()){
      case 0:
        cout << "aguardando ";
        break;
      case 1:
        cout << "em execussão ";
        break;
      case 2:
        cout << "finalizado ";
        break;
      case 3:
        cout << "cancelado ";
        break;
    }
}
void listar_voos(vector<Voo> Voos, int tipo){
  // casos: 0 - todos os voos | 1 - voos agendados | 2 - voos em execussão | 3 - voo finalizado | 4 - voos cancelados
  cout << "\033[2J\033[1;1H";
  switch(tipo){
    case 0:
      if (Voos.size() > 0){
        cout << "Todos os voos:" << endl << endl;
        for(int i = 0; i < Voos.size(); i++){
          cout << tab << "Voo " << Voos[i].getCod();
          cout << tab << Voos[i].modeloNave;        
          cout << tab; estado_do_voo(Voos, i);
          cout << endl;
        //   for (int i = 0; i<Voos[i].qntPassageiros; i++){
        //     Voos[i].Passageiros[i].imprimirCompleto();
        //   }
        }
      } else {
        cout << "Nenhum voo cadastrado";
      }
      
      break;
    case 1:
      cout << "Voos agendados" << endl;
      for(int i = 0; i < Voos.size(); i++){
        if(Voos[i].getEstado() == 0){
          cout << "Voo " << Voos[i].getCod();
          cout << Voos[i].modeloNave;
          estado_do_voo(Voos, i);
          cout << endl;
        }
      }
      break;
    case 2:
      cout << "Voos em execussão" << endl; 
      for(int i = 0; i < Voos.size(); i++){
        if(Voos[i].getEstado() == 1){
          cout << "Voo " << Voos[i].getCod();
          cout << Voos[i].modeloNave;
          estado_do_voo(Voos, i);
          cout << endl;
        }
      }
      break;
    case 3:
      cout << "Voos finalizados" << endl;
      for(int i = 0; i < Voos.size(); i++){
        if(Voos[i].getEstado() == 2){
          cout << "Voo " << Voos[i].getCod();
          cout << Voos[i].modeloNave;
          estado_do_voo(Voos, i);
          cout << endl;
        }
      }
      break;
    case 4:
      cout << "Voos cancelados" << endl;
      for(int i = 0; i < Voos.size(); i++){
        if(Voos[i].getEstado() == 3){
          cout << "Voo " << Voos[i].getCod();
          cout << Voos[i].modeloNave;
          estado_do_voo(Voos, i);
          cout << endl;
        }
      }
  }

  cout << endl << endl << "Pressione qualquer tecla para continuar...";
  cin.ignore();
  cin.get();

}
void menu_lista_voos(vector<Voo> Voos){
  cout << "Quais voos você quer lançar?" << endl;
  cout << "1 - todos os voos" << endl
    << "2 - Voos agendados" << endl
    << "3 - Voos em execussão" << endl
    << "4 - Voos finalizados" << endl
    << "5 - Voos cancelados" << endl;
  int opc;
  cin >> opc;
  listar_voos(Voos, opc-1);
}

int checar_astronauta(vector<Astronauta> Astronautas){
  // checa se os astronautas presentes na lista de passageiros estão disponíveis para o lançamento do voo
  int cont = 0;
  for(int i = 0; i<Astronautas.size(); i++){
    if(Astronautas[i].disp == true){
      cont++;
    }
  }
  return cont;
} 

void voosParaLancar(vector<Voo> Voos){
  for(int i = 0; i < Voos.size(); i++){
    //int d = checar_astronauta(Voos[i].Passageiros);
    if(Voos[i].qntPassageiros == checar_astronauta(Voos[i].Passageiros)){
      listar_voos(Voos, 1);
    }
  }
}




void lancar_voo(vector<Voo> Voos){



  
  
  
}

int voos_em_execussao(vector<Voo> Voos){
  int cont = 0;
  cout << "Voos em execussao:" << endl;
  for(int i = 0; i<Voos.size(); i++){
    if(Voos[i].getEstado() == 1){
      cont++;
      cout << tab << "Voo " << Voos[i].getCod() << endl;
    }
  }
  return cont;
}

void finalizar_voo(vector<Voo> Voos){
  int qnt;
  //int voosExecussao = voos_em_execussao(Voos);  
  cout << "Quantos voos serão finalizados?";
  cin >> qnt;
  
  
  for(int i = 0; i<qnt; i++){
    cout << "Digite o codigo do voo: ";
    Voos[i].setEstado(2);
    for(int j = 0; j<Voos[i].qntPassageiros; j++){
      Voos[i].Passageiros[j].disp = true;
    }
  }
}

void imprimirCompletoAstronautas(vector<Astronauta> astronautas){
  cout << "Astronautas cadastrados:" << endl << endl;
  cout << tab << "======================" << endl;
  for(int i = 0; i < astronautas.size(); i++){
    // cout << "Astronauta " << i+1 << ":" << endl;
    astronautas[i].imprimirCompleto();
    
  }
}

Astronauta criarAstronauta(){

  string nome;
  string CPF;
  int idade;
  string nacionalidade; 
  string sexo;

  cout << "Vamos criar um novo astronauta!" << endl;
  cout << "Digite o nome do astronauta: ";
  cin.ignore();
  getline(cin, nome);
  cout << "Digite o CPF do astronauta: ";
  cin.ignore();
  getline(cin, CPF);
  cout << "Digite a idade do astronauta: ";
  cin >> idade;
  cout << "Digite a nacionalidade do astronauta: ";
  cin >> nacionalidade;
  cout << "Digite o sexo do astronauta: ";
  cin >> sexo;

  Astronauta astronauta(nome, CPF, idade, nacionalidade, sexo);

  return astronauta;
}


vector<Astronauta> reorganizarAstronautas(vector<Astronauta> &astronautas){
  for(int i = 0; i < astronautas.size(); i++){
    if(astronautas[i].getEstado() == false){
      astronautas.push_back(astronautas[i]);
      astronautas.erase(astronautas.begin()+i);
    }
  }

  return astronautas;
}
