#include <iostream>
#include <string>

class CD
{
public:
    int codigo;
    std::string artista;
    std::string album;
    int no_canciones;
    float precio;
    int existencias;
};

void agregarCD(CD cds[], int &numCDs);
void mostrarCDs(const CD cds[], int numCDs);
void buscarPorCodigo(const CD cds[], int numCDs);
void modificarCD(CD cds[], int numCDs);
void realizarVenta(CD cds[], int numCDs);

int main()
{
    CD cds[50];
    int numCDs = 0;
    int opcion;

    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Agregar CD\n";
        std::cout << "2. Mostrar todos los CD's\n";
        std::cout << "3. Buscar por codigo\n";
        std::cout << "4. Modificar\n";
        std::cout << "5. Venta\n";
        std::cout << "6. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarCD(cds, numCDs);
            break;
        case 2:
            mostrarCDs(cds, numCDs);
            break;
        case 3:
            buscarPorCodigo(cds, numCDs);
            break;
        case 4:
            modificarCD(cds, numCDs);
            break;
        case 5:
            realizarVenta(cds, numCDs);
            break;
        case 6:
            std::cout << "Cerrando el programa.\n";
            break;
        default:
            std::cout << "Opción invalida.\n";
        }
    } while (opcion != 6);

    return 0;
}

void agregarCD(CD cds[], int &numCDs)
{
    if (numCDs < 50)
    {
        std::cout << "Ingrese el codigo: ";
        std::cin >> cds[numCDs].codigo;

        std::cout << "Ingrese el artista: ";
        std::cin.ignore();
        std::getline(std::cin, cds[numCDs].artista);

        std::cout << "Ingrese el nombre del album: ";
        std::getline(std::cin, cds[numCDs].album);

        std::cout << "Ingrese el numero de canciones: ";
        std::cin >> cds[numCDs].no_canciones;

        std::cout << "Ingrese el precio: ";
        std::cin >> cds[numCDs].precio;

        std::cout << "Ingrese las existencias: ";
        std::cin >> cds[numCDs].existencias;

        numCDs++;
        std::cout << "CD agregado.\n";
    }
    else
    {
        std::cout << "No se pueden agregar mas CD's\n";
    }
}

void mostrarCDs(const CD cds[], int numCDs)
{
    std::cout << "\nLista de CDs:\n\n";
    for (int i = 0; i < numCDs; i++)
    {
        std::cout << " Codigo: " << cds[i].codigo << "\n Artista: " << cds[i].artista
                  << "\n Album: " << cds[i].album << "\n Precio: " << cds[i].precio
                  << "\n Existencias: " << cds[i].existencias << "\n\n";
    }
}

void buscarPorCodigo(const CD cds[], int numCDs)
{
    int codigoBuscar;
    std::cout << "Ingrese el codigo a buscar: ";
    std::cin >> codigoBuscar;

    for (int i = 0; i < numCDs; i++)
    {
        if (cds[i].codigo == codigoBuscar)
        {
            std::cout << "\nCD encontrado:\n\n";
            std::cout << " Codigo: " << cds[i].codigo << "\n Artista: " << cds[i].artista
                      << "\n Album: " << cds[i].album << "\n Precio: " << cds[i].precio
                      << "\n Existencias: " << cds[i].existencias << "\n";
            return;
        }
    }

    std::cout << "CD con codigo " << codigoBuscar << " no encontrado.\n";
}

void modificarCD(CD cds[], int numCDs)
{
    int codigoModificar;
    std::cout << "Ingrese el codigo del CD a modificar: ";
    std::cin >> codigoModificar;

    for (int i = 0; i < numCDs; i++)
    {
        if (cds[i].codigo == codigoModificar)
        {
            std::cout << "Ingrese el nuevo precio: ";
            std::cin >> cds[i].precio;
            std::cout << "Ingrese las nuevas existencias: ";
            std::cin >> cds[i].existencias;
            std::cout << "CD modificado con exito.\n";
            return;
        }
    }

    std::cout << "CD con codigo " << codigoModificar << " no encontrado.\n";
}

void realizarVenta(CD cds[], int numCDs)
{
    int codigoVenta;
    std::cout << "Ingrese el codigo del CD a vender: ";
    std::cin >> codigoVenta;

    for (int i = 0; i < numCDs; i++)
    {
        if (cds[i].codigo == codigoVenta)
        {
            if (cds[i].existencias > 0)
            {
                cds[i].existencias--;
                std::cout << "Venta realizada. Existencias restantes: " << cds[i].existencias << "\n";
            }
            else
            {
                std::cout << "No hay existencias disponibles para este CD.\n";
            }
            return;
        }
    }

    std::cout << "CD con codigo " << codigoVenta << " no encontrado.\n";
}
