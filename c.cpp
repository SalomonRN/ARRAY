#include <iostream>
using namespace std;

/**
 * @param num Numero que se desea bsucar en el arreglo
 * @param size Tamaño del arreglo
 * @param infer Posicion minima del Array que se va a buscar. LIMITE INFERIOR
 * @param super Posicion maxima del Array que se va a buscar. LIMITE SUPERIOR
 * @param mid Numero de la mitad, referencia para ir dividiendo
 * @param return Retorno de boleano, TRUE está en el Array, FALSE no se encuentra
 */
string Search(int arr[], int size, int num)
{

    int infer = 0;
    int super = size - 1;
    int mid = 0;
    while (infer <= super)

    {
        // Calcular la mitad del Array segun los limites
        mid = infer + (super - infer) / 2;
        // Pregunta si mid correspondes al numero que se busca
        if (arr[mid] == num)
        {
            // Número encontrado en el array
            return "SI";
        }

        // Pregunta para saber si el numero que se busca es menor a la posicion actual de mid en el Array
        else if (arr[mid] < num)
        {
            // Se actualiza el LIMITE INFERIOR para empezar ahora a buscar por la derecha.
            infer = mid + 1;
        }
        // Se toma que el numero que se busca es mayor
        else
        {
            // Se actualiza el LIMITE SUPERIOR para empezar ahora a buscar por la IZQUIERDA.
            super = mid - 1; // Buscar en la mitad izquierda
        }
    }
    // Número NO encontrado en el array
    return "NO";
}

/**
 * @param arr1 Array con 15 posiciones
 * @param arr2 Array con 15 posiciones
 * @param arr3 Array con 15 posiciones
 * @param num Numero que sea se buscará en los Array's
 */
int main()
{
    // Declaracion de Array's con datos int
    int arr1[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
    int arr2[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
    int arr3[] = {31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59};
    int num = 20;

    // Se llama a la funcioon Search() pasando los parametros necesarios, se guarda el Retorno.
    string foundInArr1 = Search(arr1, 15, num);
    string foundInArr2 = Search(arr2, 15, num);
    string foundInArr3 = Search(arr3, 15, num);

    // Imprimir
    cout << "El número: " << num << " " << foundInArr1 << " fue encontrado en el arr1" << endl;
    cout << "El número: " << num << " " << foundInArr2 << " fue encontrado en el arr2" << endl;
    cout << "El número: " << num << " " << foundInArr3 << " fue encontrado en el arr3" << endl;

    system("pause");
    return 0;
}
