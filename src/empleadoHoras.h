#ifndef EMPLEADOHORAS_H 
#define EMPLEADOHORAS_H

#include <vector>
#include <iostream> 
#include "empleado.h"

using namespace std;

class EmpleadoHoras : public Empleado {

    int  id_empleado, tipo_empleado, id_supervisor; 
    string nombre, apellido, email; 
    vector<Empleado *> subordinados;

    public: 
        EmpleadoHoras(int,string,string,string,int,int);
        ~EmpleadoHoras();

        void agregarSubordinado(Empleado *subordinado);
        virtual int de_id_empleado(); 
        virtual string de_Nombre();

        friend ostream& operator << (ostream &output, const EmpleadoHoras &empleado);
}; 
#endif


