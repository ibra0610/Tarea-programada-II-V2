#ifndef EMPLEADONOMINA_H 
#define EMPLEADONOMINA_H 

#include <vector>
#include <iostream> 
#include "empleado.h"

using namespace std; 

class EmpleadoNomina : public Empleado{
    int  id_empleado, tipo_empleado, id_supervisor; 
    string nombre, apellido, email; 
    vector<Empleado *> subordinados;

    public: 
        EmpleadoNomina(int,string,string,string,int,int);
        void agregarSubordinado(Empleado *subordinado);
        virtual int de_id_empleado(); 
        virtual string de_Nombre();

        friend ostream& operator << (ostream &output, const Empleado &empleado);
}; 

#endif