#include <iostream>
#include <ctime>
#include <time.h>

clock_t t0, t1;

using namespace std;

int comparaciones;
int asignaciones;
void generador(int lista[],int copia[],int tam){
	for (int i = 0; i < tam; ++i)
	{
	    lista[i]=rand()% (tam*2 );
	    copia[i]=lista[i];


	}
}
//funcion para saber si el ordenando sera de forma creciente o decreciente
char CoD (int a, int b){
    return a>b?'c':'d'; // 'c' es creciente y 'd' es decreciente
}

void InsertionSort(int arr[], int arr_size,char orden){
    t0=clock();
    int asignaciones=0;
	int comparaciones=0;

    for(int i = 1; i < arr_size; ++i){
      int j = i - 1;
      asignaciones++;
      int key = arr[i];
      asignaciones++;
       comparaciones++;
      while(j >= 0 && CoD(arr[j], key)==orden){

        arr[j+1] = arr[j];
        asignaciones++;
        --j;
      }
      arr[j+1] = key;
      asignaciones++;
    }

  t1 = clock();
  double tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
	cout << "Tiempo real de ejecucion por insercion: " << tiempo << endl;
  cout<<"tiempo retornado: "<<comparaciones+asignaciones<<endl<<endl;
}
//MERGESORT-----------------------------------------
void merge(int arr[], int l, int m, int r)
{
    asignaciones=0;
	comparaciones=0;

    int i, j, k;
    int n1 = m - l + 1;
    asignaciones++;
    int n2 =  r - m;
    asignaciones++;

    /* creamos arrays temporales */
    int L[n1], R[n2];

    /* copiamos los datos a los arreglos temporales L y R */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
        asignaciones++;
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
        asignaciones++;

    /* combina los arreglos temporales de nuevo en arr[l..r]*/
    i = 0; // incdice inicial del primer subarreglo
    j = 0; // indice inicial del segundo subarreglo
    k = l; // indice inicial del subarreglo combinado
    asignaciones+=3;
    comparaciones++;
    while (i < n1 && j < n2)
    {
        comparaciones++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            asignaciones++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            asignaciones++;
            j++;
        }
        k++;
    }

    /* copia los elementos restantes de L[] si hay alguno */
    comparaciones++;
    while (i < n1)
    {
        arr[k] = L[i];
        asignaciones++;
        i++;
        k++;
    }

    /*Copia los elementos restantes de R[] si hay alguno*/
    comparaciones++;
    while (j < n2)
    {
        arr[k] = R[j];
        asignaciones++;
        j++;
        k++;
    }

}

/*
l es para el índice izquierdo y r es el índice derecho del subarreglo de arr que se ordenará */
void mergeSort(int arr[], int l, int r)
{
   	comparaciones++;
    if (l < r)
    {
        // Igual que (l + r) / 2, pero evita el desbordamiento de
        // grandes l y h
        int m = l+(r-l)/2;
        asignaciones++;

        // ordenar primera y segunda mitad
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void show(int *arr,int t){
		for(int i=0;i<t;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}





int main(){

    int *lista,*copia;

    for (int i=1;i<=1000;i++){
        lista=new int[i];
        copia=new int[i];

        generador(lista,copia,i);
        InsertionSort(lista,i,'c');
         cout<<"................................................................."<<endl;
         t0= clock();
        mergeSort(copia,0,i-1);

        t1= clock();
        cout<<"timpo real  "<< (double)(t1-t0) / CLOCKS_PER_SEC<<endl;
        cout <<"tiempo retornado  "<< comparaciones+asignaciones <<endl;
       
        

    }

}
