#include <iostream>
#include <string>
using namespace std;

class Empleado
{
public:
    string nombre;
    int clave;
    string domicilio;
    double sueldo;
    string reportaA;

    Empleado(const string &Nombre, int Clave, const string &Domicilio, double Sueldo, const string &ReportaA)
        : nombre(Nombre), clave(Clave), domicilio(Domicilio), sueldo(Sueldo), reportaA(ReportaA) {}

    bool operator==(const Empleado &p) const
    {
        return (nombre == p.nombre && clave == p.clave && domicilio == p.domicilio && sueldo == p.sueldo && reportaA == p.reportaA);
    }

    friend ostream &operator<<(ostream &os, const Empleado &empleado)
    {
        os << "Clave: " << empleado.clave << endl;
        os << "Nombre: " << empleado.nombre << endl;
        os << "Domicilio: " << empleado.domicilio << endl;
        os << "Sueldo: " << empleado.sueldo << endl;
        os << "Reporta a: " << empleado.reportaA << endl;
        return os;
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

    void setDomicilio(const string &Domicilio)
    {
        domicilio = Domicilio;
    }

    void actualizarSueldo(double porcentaje)
    {
        sueldo *= (1 + porcentaje / 100);
    }

    void setReportaA(const string &ReportaA)
    {
        reportaA = ReportaA;
    }

    int getClave() const
    {
        return clave;
    }

    void imprimirDatos() const
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Clave: " << clave << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta a: " << reportaA << endl;
    }
};

int main()
{
    int opcion;
    int clave;
    double porcentaje;
    string domicilio;
    string reportaA;

    Empleado JefePlanta("Jefe Planta", 1, "Domicilio1", 80000.00, "reporte1");
    Empleado JefePersonal("Jefe Personal", 2, "Domicilio2", 50000.00, "reporte2");

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Cambiar el domicilio de un empleado" << endl;
        cout << "2. Cambiar el sueldo de un empleado" << endl;
        cout << "3. Imprimir los datos de un empleado" << endl;
        cout << "4. Cambiar a quien reporta el empleado" << endl;
        cout << "5. Salir" << endl;
        cout << "\nElija una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\nIngrese la clave del empleado (1 o 2): ";
            cin >> clave;
            cout << "\nIngrese el nuevo domicilio: ";
            cin.ignore();
            getline(cin, domicilio);
            if (clave == JefePlanta.getClave())
            {
                JefePlanta.setDomicilio(domicilio);
            }
            else if (clave == JefePersonal.getClave())
            {
                JefePersonal.setDomicilio(domicilio);
            }
            else
            {
                cout << "\nClave de empleado no valida." << endl;
            }
            break;
        case 2:
            cout << "\nIngrese la clave del empleado (1 o 2): ";
            cin >> clave;
            cout << "\nIngrese el porcentaje de incremento: ";
            cin >> porcentaje;
            if (clave == JefePlanta.getClave())
            {
                JefePlanta.actualizarSueldo(porcentaje);
            }
            else if (clave == JefePersonal.getClave())
            {
                JefePersonal.actualizarSueldo(porcentaje);
            }
            else
            {
                cout << "\nClave de empleado no valida." << endl;
            }
            break;
        case 3:
            cout << "\nIngrese la clave del empleado (1 o 2): ";
            cin >> clave;
            if (clave == JefePlanta.getClave())
            {
                JefePlanta.imprimirDatos();
            }
            else if (clave == JefePersonal.getClave())
            {
                JefePersonal.imprimirDatos();
            }
            else
            {
                cout << "\nClave de empleado no valida." << endl;
            }
            break;
        case 4:
            cout << "\nIngrese la clave del empleado (1 o 2): ";
            cin >> clave;
            cout << "\nIngrese a quien reporta el empleado: ";
            cin.ignore();
            getline(cin, reportaA);
            if (clave == JefePlanta.getClave())
            {
                JefePlanta.setReportaA(reportaA);
            }
            else if (clave == JefePersonal.getClave())
            {
                JefePersonal.setReportaA(reportaA);
            }
            else
            {
                cout << "\nClave de empleado no valida." << endl;
            }
            break;
        case 5:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}
