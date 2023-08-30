#include <iostream>
#include <string>
#include <vector>

class Empleado
{
private:
    std::string clave;
    std::string nombre;
    std::string domicilio;
    double sueldo;
    std::string reportaA;

public:
    Empleado(const std::string &Clave, const std::string &Nombre, const std::string &Domicilio, double Sueldo, const std::string &ReportaA)
        : clave(Clave), nombre(Nombre), domicilio(Domicilio), sueldo(Sueldo), reportaA(ReportaA) {}

    std::string getClave() const { return clave; }
    std::string getNombre() const { return nombre; }
    std::string getDomicilio() const { return domicilio; }
    double getSueldo() const { return sueldo; }

    void setReportaA(const std::string &ReportaA) { reportaA = ReportaA; }

    void setDomicilio(const std::string &Domicilio) { domicilio = Domicilio; }
    void actualizarSueldo(double porcentaje) { sueldo *= (1 + porcentaje / 100); }

    void imprimirDatos() const
    {
        std::cout << "Clave: " << clave << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Domicilio: " << domicilio << std::endl;
        std::cout << "Sueldo: " << sueldo << std::endl;
        std::cout << "Reporta a: " << reportaA << std::endl;
    }
};

int main()
{
    std::vector<Empleado> empleados;
    std::string reportaA;
    int opcion;
    std::string domicilio;
    Empleado JefePlanta("1", "Jefe Planta", "Domicilio1", 80000.00, "reporte1");
    Empleado JefePersonal("2", "Jefe Personal", "Domicilio2", 50000.00, "reporte2");

    do
    {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Cambiar el domicilio de un empleado" << std::endl;
        std::cout << "2. Cambiar el sueldo de un empleado" << std::endl;
        std::cout << "3. Imprime los datos de un empleado" << std::endl;
        std::cout << "4. Cambiar reporte" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "\nElija una opcion: ";
        std::cin >> opcion;

        std::string clave;
        double porcentaje;

        switch (opcion)
        {
        case 1:
            std::cout << "\nIngrese la clave del empleado(1,2): ";
            std::cin >> clave;
            std::cout << "\nIngrese el nuevo domicilio: ";
            std::cin.ignore();
            std::getline(std::cin, domicilio);
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
                std::cout << "\nClave de empleado no valida." << std::endl;
            }
            break;
        case 2:
            std::cout << "\nIngrese la clave del empleado: ";
            std::cin >> clave;
            std::cout << "\nIngrese el porcentaje de incremento: ";
            std::cin >> porcentaje;
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
                std::cout << "\nClave de empleado no valida." << std::endl;
            }
            break;
        case 3:
            std::cout << "\nIngrese la clave del empleado: ";
            std::cin >> clave;
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
                std::cout << "\nClave de empleado no valida." << std::endl;
            }
            break;
        case 4:
            std::cout << "\nIngrese la clave del empleado: ";
            std::cin >> clave;
            std::cout << "\nIngrese a quien reporta el empleado: ";
            std::cin.ignore();
            std::getline(std::cin, reportaA);
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
                std::cout << "\nClave de empleado no valida." << std::endl;
            }
            break;
        case 5:
            std::cout << "Saliendo del programa." << std::endl;
            break;
        default:
            std::cout << "Opción no valida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 5);

    return 0;
}
