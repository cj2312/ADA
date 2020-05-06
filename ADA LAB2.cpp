#include <iostream>
#include <ctime>
#include <time.h>

clock_t t0, t1;
using namespace std;

void generador(int lista[],int tam){
	for (int i = 0; i < tam; ++i)
	{
	    lista[i]=rand()% (tam*2 );


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
      while(j >= 0 && CoD(arr[j], key)==orden){
          comparaciones++;
        arr[j+1] = arr[j];
        asignaciones++;
        --j;
      }
      arr[j+1] = key;
      asignaciones++;
    }
  cout<<"asignaciones :"<<asignaciones<<" comparaciones: "<<comparaciones<<endl;
  t1 = clock();
  double tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
	cout << "Tiempo de ejecucion por insercion: " << tiempo << endl;
  cout<<"resultado : "<<comparaciones+asignaciones<<endl<<endl;
}

void bubbleSort(int arreglo[],int n, char orden){
    t0=clock();
    int asignaciones=0;
	int comparaciones=0;
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for (j=n-1;j>=i+1;j--){
            if(CoD(arreglo[j-1],arreglo[j])==orden){
                comparaciones++;
                temp=arreglo[j];
                asignaciones++;
                arreglo[j]=arreglo[j-1];
                asignaciones++;
                arreglo[j-1]=temp;
                asignaciones++;
            }
        }
    }
    t1 = clock();
  double tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
	cout << "Tiempo de ejecucion por burbuja: " << tiempo << endl;
    //analisar la cantidad de comparaciones y asignaciones
     cout<<"asignaciones :"<<asignaciones<<" comparaciones: "<<comparaciones<<endl;
     cout<<"resultado : "<<comparaciones+asignaciones<<endl<<endl;
}

void show(int *arr,int t){
		for(int i=0;i<t;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}





int main(){
	int *arr=new int[500];
	int *arr1=new int[1000];
	int *arr2=new int[2000];
	int *arr3=new int[10000];

	int *arra=new int[500];
	int *arr1b=new int[1000];
	int *arr2c=new int[2000];
	int *arr3d=new int[10000];


 // GENERANDO LOS ARREGLOS
	generador(arr,500);
	//show(arr,500);
    generador(arr1,1000);
    //show(arr1,1000);
    generador(arr2,2000);
    //show(arr2,2000);
    generador(arr3,10000);
    //show(arr3,10000);
    arra=arr;
    arr1b=arr1;
    arr2c=arr2;
    arr3d=arr3;

cout<<"INSERT SORT....................."<<endl;
// ORDENANDO POR INSERCION DE FORMA CRECIENTE
cout<<"INSERT SORT CRECIENTE....................."<<endl;
	InsertionSort(arr,500,'c');
	//show(arr,500);
	InsertionSort(arr1,1000,'c');
	//show(arr1,1000);
	InsertionSort(arr2,2000,'c');
	//show(arr2,2000);
	InsertionSort(arr3,10000,'c');
	//show(arr3,10000);

// ORDENANDO POR INSERCION DE FORMA DECRECIENTE
cout<<"INSERT SORT DECRECIENTE....................."<<endl;
	InsertionSort(arr,500,'d');
	//show(arr,500);
	InsertionSort(arr1,1000,'d');
	//show(arr1,1000);
	InsertionSort(arr2,2000,'d');
	//show(arr2,2000);
	InsertionSort(arr3,10000,'d');
	//show(arr3,10000);
//----------------------------------------------------------

cout<<"BUBBLE SORT  ..........................."<<endl;
// ORDENANDO POR BURBUJA DE FORMA CRECIENTE
cout<<"BUBBLE SORT CRECIENTE ..........................."<<endl;
	bubbleSort(arra,500,'c');
	//show(arra,500);
	bubbleSort(arr1b,1000,'c');
	//show(arr1b,1000);
	bubbleSort(arr2c,2000,'c');
	//show(arr2c,2000);
	bubbleSort(arr3d,10000,'c');
	//show(arr3d,10000);

// ORDENANDO POR BURBUJA DE FORMA DECRECIENTE
cout<<"BUBBLE SORT DECRECIENTE ..........................."<<endl;
	bubbleSort(arra,500,'d');
	//show(arra,500);
	bubbleSort(arr1b,1000,'d');
	//show(arr1b,1000);
	bubbleSort(arr2c,2000,'d');
	//show(arr2c,2000);
	bubbleSort(arr3d,10000,'d');
	//show(arr3d,10000);





}


