#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

Voo criarVoo(vector<Astronauta> Astronautas);

void estado_do_voo(vector<Voo> Voos, int i);

void listar_voos(vector<Voo> Voos, int tipo);

void menu_lista_voos(vector<Voo> Voos);

void voosParaLancar(vector<Voo> Voos);

int checar_astronauta(vector<Astronauta> Astronautas);

void lancar_voo(vector<Voo> Voos);

int voos_em_execussao(vector<Voo> Voos);

void finalizar_voo(vector<Voo> Voos);

void imprimirCompletoAstronautas(vector<Astronauta> astronautas);

Astronauta criarAstronauta();

vector<Astronauta> reorganizarAstronautas(vector<Astronauta> &astronautas);



#endif