#include <iostream>
#include <string>
#include <vector>
const int TAM = 100;

using namespace std;
class Empleado
{
private:
    string clave;
    string nombre;
    string domicilio;
    double sueldo;
    string reportaA;

public:
    Empleado() : clave("Clave"), nombre("Nombre"), domicilio("Domicilio"), sueldo(100000), reportaA("Reportado") {}
    void operator=(Empleado &x)
    {
        clave = x.clave;
        nombre = x.nombre;
        domicilio = x.domicilio;
        sueldo = x.sueldo;
        reportaA = x.reportaA;
    }

    Empleado(const string &Clave, const string &Nombre, const string &Domicilio, double Sueldo, const string &ReportaA)
        : clave(Clave), nombre(Nombre), domicilio(Domicilio), sueldo(Sueldo), reportaA(ReportaA) {}

    string getClave() const { return clave; }
    string getNombre() const { return nombre; }
    string getDomicilio() const { return domicilio; }
    double getSueldo() const { return sueldo; }

    bool operator==(const Empleado &p) const
    {
        return (nombre == p.nombre && clave == p.clave && domicilio == p.domicilio && sueldo == p.sueldo && reportaA == p.reportaA);
    }

    friend ostream &operator<<(ostream &o, Empleado &p)
    {
        o << "Clave: " << p.clave << "\t Nombre: " << p.nombre << "\t Domicilio: " << p.domicilio << "\t Sueldo: " << p.sueldo << "\t ReportaA: " << p.reportaA << endl;
        return o;
    }
    friend istream &operator>>(istream &is, Empleado &empleado)
    {
        is >> empleado.clave >> empleado.nombre >> empleado.domicilio >> empleado.sueldo >> empleado.reportaA;
        return is;
    }

    bool operator!=(const Empleado &p) const
    {
        return !(*this == p);
    }

    bool operator<(const Empleado &p) const
    {
        return nombre < p.nombre;
    }

    bool operator>(const Empleado &p) const
    {
        return nombre > p.nombre;
    }

    Empleado operator+(const Empleado &p) const
    {
        return Empleado(nombre + p.nombre, clave, domicilio + p.domicilio, sueldo + p.sueldo, reportaA + p.reportaA);
    }
};
class Lista
{
private:
    Empleado datos[TAM];
    int ult;

public:
    Lista() : ult(-1) {}
    bool vacia() const
    {
        if (ult == -1)
            return true;
        return false;
    }
    bool llena() const
    {
        if (ult == TAM - 1)
            return true;
        return false;
    }
    int inserta(Empleado elem, int pos)
    {
        if (llena() || pos < 0 || pos > ult + 1)
        {
            std::cout << "\n Error de insercion";
            return 0;
        }
        int i = ult + 1;
        while (i > pos)
        {
            datos[i] = datos[i - 1];
            i--;
        }
        datos[pos] = elem;
        ult++;
        return 1;
    }
    void muestra()
    {
        if (vacia())
        {
            cout << "La lista está vacia." << endl;
            return;
        }
        for (int i = 0; i <= ult; i++)
        {
            cout << datos[i] << endl;
        }
    }

    void buscar(const string &clave)
    {
        for (int i = 0; i <= ult; i++)
        {
            if (datos[i].getClave() == clave)
            {
                cout << "Empleado encontrado: " << datos[i] << endl;
                return;
            }
        }
        cout << "La clave no coincide" << endl;
    }

    bool elimina(int pos)
    {
        if (vacia() || pos < 0 || pos > ult)
        {
            cout << "\n error de eliminacion";
            return true;
        }
        int i = pos;
        while (i < ult)
        {
            datos[i] = datos[i + 1];
            i++;
        }
        ult--;
        return false;
    }

    int ultimo() const
    {
        return ult;
    }

    friend ostream &operator<<(ostream &o, Lista &L)
    {
        int i = 0;
        cout << "\n";
        while (i <= L.ultimo())
        {
            ;
            o << L.datos[i];
            i++;
        }
        return o;
    }
};
int main()
{
    vector<Empleado> empleados;
    string reportaA;
    int opcion;
    string domicilio;
    Lista listaEmpleados;
    Empleado nuevoEmpleado("13", "Pedro Maromas", "Sabino #23", 15000.00, "Solin");
    Empleado x;
    Empleado JefePlanta("1", "Jefe Planta", "Domicilio1", 80000.00, "reporte1");
    Empleado JefePersonal("2", "Jefe Personal", "Domicilio2", 50000.00, "reporte2");
    Empleado Godin1("3", "Godin 1", "Domicilio3", 10000.00, "reporte3");
    Empleado Godin2("4", "Godin 2", "Domicilio4", 12000.00, "reporte4");
    Empleado Godin3("5", "Godin 3", "Domicilio5", 8000.00, "reporte5");
    Empleado Godin4("6", "Godin 4", "Domicilio6", 14000.00, "reporte6");
    listaEmpleados.inserta(JefePlanta, 0);
    listaEmpleados.inserta(JefePersonal, 1);
    listaEmpleados.inserta(Godin1, 2);
    listaEmpleados.inserta(Godin2, 3);
    listaEmpleados.inserta(Godin3, 4);
    listaEmpleados.inserta(Godin4, 5);

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Agregar a la lista" << endl;
        cout << "2. Buscar en la lista" << endl;
        cout << "3. Eliminar de la lista" << endl;
        cout << "4. Insertar en la lista " << endl;
        cout << "5. Mostrar la lista" << endl;
        cout << "6. Salir" << endl;
        cout << "\nElija una opcion: ";
        cin >> opcion;

        string clave;

        switch (opcion)
        {
        case 1:
            listaEmpleados.inserta(x, listaEmpleados.ultimo() + 1);
            break;

        case 2:
            cout << "Ingrese la clave del empleado a buscar: ";
            cin >> clave;
            listaEmpleados.buscar(clave);
            break;
        case 3:
            int pos;
            cout << "Ingrese la posicion del empleado a eliminar: ";
            cin >> pos;
            if (!listaEmpleados.elimina(pos))
            {
                cout << "Empleado eliminado correctamente." << endl;
            }
            break;
        case 4:
            int posicion;
            cout << "Ingrese la posición en la que desea insertar el empleado: ";
            cin >> posicion;
            listaEmpleados.inserta(nuevoEmpleado, posicion);
            break;
        case 5:
            listaEmpleados.muestra();
            break;
        case 6:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);  

    return 0;
}