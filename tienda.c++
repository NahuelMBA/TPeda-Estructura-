#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

struct producto
{

    char nombre[10];
    double precio;
    int stock;
};

struct producto listaDeProductos[100];

int main()
{
    int seleccion;
    int j = 0;
    char buscar[10];
    char buscar1[10];
    int nuevostock;
    double nuevoprecio;
    int sumastock = 0;
    do
    {
        printf("Bienvenido de tu tienda \n");
        printf("Selecciona una de estas opciones..\n");
        printf("1. Dar de alta un producto nuevo\n");
        printf("2. Buscar un producto por su nombre\n");
        printf("3. Modificar el stock y precio de un producto dado\n");
        printf("4. Calcular y mostrar el monto total acumulado del stock\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &seleccion);

        switch (seleccion)
        {
        case 1:

            printf("Ingrese el nombre del producto a agregar: \n");
            scanf("%s", listaDeProductos[j].nombre);
            printf("Ingrese el precio del producto a agregar: \n");
            scanf("%lf", &listaDeProductos[j].precio);
            printf("Ingrese el stock del producto a agregar: \n");
            scanf("%d", &listaDeProductos[j].stock);
            j++;

            break;

        case 2:

            printf("Ingrese el nombre del producto a buscar:  \n");
            scanf("%s", &buscar);

            for (int i = 0; i < sizeof(listaDeProductos) / sizeof(listaDeProductos[0]); i++)
            {

                if (strcmp(listaDeProductos[i].nombre, buscar) == 0)
                {
                    printf(listaDeProductos[i].nombre, "\n");
                    cout << listaDeProductos[i].precio << endl;
                    cout << listaDeProductos[i].stock << endl;
                }
            }

            break;
        case 3:

            printf("Ingrese el nombre del producto a cambiar:  \n");
            scanf("%s", buscar1);
            for (int i = 0; i < j; i++)
            {

                if (strcmp(listaDeProductos[i].nombre, buscar1) == 0)
                {

                    printf("Este es el stock del producto.. \n");
                    cout << listaDeProductos[i].stock;

                    printf("Ingrese el nuevo stock para el producto.. \n");
                    scanf("%d", &nuevostock);

                    listaDeProductos[i].stock = nuevostock;

                    printf("Este es el precio del producto.. \n");
                    cout << listaDeProductos[i].precio;

                    printf("Ingrese el nuevo precio para el producto.. \n");
                    scanf("%lf", &nuevoprecio);

                    listaDeProductos[i].precio = nuevoprecio;
                }
            }

            break;
        case 4:

            sumastock = 0;
            for (int i = 0; i < j; i++)
            {

                sumastock = sumastock + listaDeProductos[i].stock;
            }
            printf("Esta es la suma de todo su stock.. \n");
            printf("%d", sumastock, "\n");

            break;

        default:
            break;
        }

    } while (seleccion != 5);

    return 0;
}
