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

class Pila
{
private:
    Empleado datos[TAM];
    int ult;

    int inserta(Empleado elem, int pos)
    {
        if (llena() || pos < 0 || pos > ult + 1)
        {
            cout << "\n Error de insercion";
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

public:
    Pila() : ult(-1) {}
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

    int ultimo() const
    {
        return ult;
    }

    void push(Empleado p)
    {
        inserta(p, ultimo() + 1);
    }
    void pop()
    {
        elimina(ultimo());
    }
    Empleado top()
    {
        if (vacia())
        {
            throw runtime_error("La pila está vacía.");
        }
        return datos[ult];
    }

    friend ostream &operator<<(ostream &o, Pila &L);
};
int main()
{
    
    //vector<Empleado> empleados;
    string reportaA;
    int opcion;
    string domicilio;
    Pila PilaEmpleados;
    Empleado nuevoEmpleado("13", "Pedro Maromas", "Sabino #23", 15000.00, "Solin");
    Empleado x;
    Empleado JefePlanta("1", "Jefe Planta", "Domicilio1", 80000.00, "reporte1");
    Empleado JefeEmpleadol("2", "Jefe Empleadol", "Domicilio2", 50000.00, "reporte2");
    Empleado Godin1("3", "Godin 1", "Domicilio3", 10000.00, "reporte3");
    Empleado Godin2("4", "Godin 2", "Domicilio4", 12000.00, "reporte4");
    Empleado Godin3("5", "Godin 3", "Domicilio5", 8000.00, "reporte5");
    Empleado Godin4("6", "Godin 4", "Domicilio6", 14000.00, "reporte6");
    PilaEmpleados.push(JefePlanta);
    PilaEmpleados.push(JefeEmpleadol);
    PilaEmpleados.push(Godin1);
    PilaEmpleados.push(Godin2);
    PilaEmpleados.push(Godin3);
    PilaEmpleados.push(Godin4);

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Salir " << endl;
        cout << "\nElija una opcion: ";
        cin >> opcion;

        string clave;

        switch (opcion)
        {
        case 1:
            PilaEmpleados.push(nuevoEmpleado);
            break;
        case 2:
            PilaEmpleados.pop();
            cout << "Elemento eliminado de la pila." << endl;
            break;
        case 3:
            try
            {
                Empleado empleadoEnTop = PilaEmpleados.top();
                cout << "Elemento en la cima de la pila:" << endl;
                cout << empleadoEnTop << endl;
            }
            catch (const runtime_error &e)
            {
                cout << "Error: " << e.what() << endl;
            }
        case 4:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}