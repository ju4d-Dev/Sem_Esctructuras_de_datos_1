#include <stdio.h>
#include <string.h>

struct CD
{
    int codigo;
    char artista[30];
    char album[30];
    int no_canciones;
    float precio;
    int existencias;
};

void agregarCD(struct CD cds[], int *numCDs);
void mostrarCDs(struct CD cds[], int numCDs);
void buscarPorCodigo(struct CD cds[], int numCDs);
void modificarCD(struct CD cds[], int numCDs);
void realizarVenta(struct CD cds[], int numCDs);

int main()
{
    struct CD cds[50];
    int numCDs = 0;
    int opcion;

    do
    {
        printf("\nMenu:\n");
        printf("1. Agregar CD\n");
        printf("2. Mostrar todos los CD's\n");
        printf("3. Buscar por codigo\n");
        printf("4. Modificar\n");
        printf("5. Venta\n");
        printf("6. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarCD(cds, &numCDs);
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
            printf("Cerrando el programa.\n");
            break;
        default:
            printf("Opción invalida.\n");
        }
    } while (opcion != 6);

    return 0;
}
void agregarCD(struct CD cds[], int *numCDs)
{
    if (*numCDs < 50)
    {
        printf("Ingrese el codigo: ");
        scanf("%d", &cds[*numCDs].codigo);

        printf("Ingrese el artista: ");
        scanf(" %[^\n]", cds[*numCDs].artista); 

        printf("Ingrese el nombre del album: ");
        scanf(" %[^\n]", cds[*numCDs].album); 

        printf("Ingrese el numero de canciones: ");
        scanf("%d", &cds[*numCDs].no_canciones);

        printf("Ingrese el precio: ");
        scanf("%f", &cds[*numCDs].precio);

        printf("Ingrese las existencias: ");
        scanf("%d", &cds[*numCDs].existencias);

        (*numCDs)++;
        printf("CD agregado.\n");
    }
    else
    {
        printf("No se pueden agregar mas CD's\n");
    }
}

void mostrarCDs(struct CD cds[], int numCDs)
{
    printf("\nLista de CDs:\n\n");
    for (int i = 0; i < numCDs; i++)
    {
        printf(" Codigo: %d \n Artista: %s \n Album: %s \n Precio: %.2f \n Existencias: %d\n\n",
               cds[i].codigo, cds[i].artista, cds[i].album, cds[i].precio, cds[i].existencias);
    }
}

void buscarPorCodigo(struct CD cds[], int numCDs)
{
    int codigoBuscar;
    printf("Ingrese el codigo a buscar: ");
    scanf("%d", &codigoBuscar);

    for (int i = 0; i < numCDs; i++)
    {
        if (cds[i].codigo == codigoBuscar)
        {
            printf("\nCD encontrado:\n\n");
            printf(" Codigo: %d \n Artista: %s \n Album: %s \n Precio: %.2f \n Existencias: %d\n",
                   cds[i].codigo, cds[i].artista, cds[i].album, cds[i].precio, cds[i].existencias);
            return;
        }
    }

    printf("CD con codigo %d no encontrado.\n", codigoBuscar);
}

void modificarCD(struct CD cds[], int numCDs)
{
    int codigoModificar;
    printf("Ingrese el codigo del CD a modificar: ");
    scanf("%d", &codigoModificar);

    for (int i = 0; i < numCDs; i++)
    {
        if (cds[i].codigo == codigoModificar)
        {
            printf("Ingrese el nuevo precio: ");
            scanf("%f", &cds[i].precio);
            printf("Ingrese las nuevas existencias: ");
            scanf("%d", &cds[i].existencias);
            printf("CD modificado con exito.\n");
            return;
        }
    }

    printf("CD con codigo %d no encontrado.\n", codigoModificar);
}

void realizarVenta(struct CD cds[], int numCDs)
{
    int codigoVenta;
    printf("Ingrese el codigo del CD a vender: ");
    scanf("%d", &codigoVenta);

    for (int i = 0; i < numCDs; i++)
    {
        if (cds[i].codigo == codigoVenta)
        {
            if (cds[i].existencias > 0)
            {
                cds[i].existencias--;
                printf("Venta realizada. Existencias restantes: %d\n", cds[i].existencias);
            }
            else
            {
                printf("No hay existencias disponibles para este CD.\n");
            }
            return;
        }
    }

    printf("CD con codigo %d no encontrado.\n", codigoVenta);
}


