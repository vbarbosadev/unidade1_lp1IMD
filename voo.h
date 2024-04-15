#ifndef VOO_H
#define VOO_H

#include "astronauta.h"

class Voo {
    private:
        int Cod;
        bool Resultado; // resultado do vootrue = com sucesso, false = sem sucesso
        int Estado; // 0- planejado(aguardando) | 1- em execussão | 2- finaliado | 3- cancelado 

    public:
        Voo();
        Voo(int Cod, std::vector<Astronauta> Passageiros);

        // void lancar(int Cod, bool Execussao, int Estado, vector<Astronauta> Passageiros);


        std::string modeloNave;
        void setCod(int);
        int getCod();
        void setResultado(bool);
        bool getResultado();
        void setEstado(int);
        int getEstado();
        std::vector<Astronauta> Passageiros;
        int qntPassageiros;


        //static int Total;
        //static int getTotal();

};






#endif