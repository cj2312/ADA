#include <iostream>
#include <ctime>
#include <time.h>

clock_t t0, t1;
using namespace std;
//1. Crear un generador de arreglos
void generador(int lista[],int tam){
	t0=clock();
	for (int i = 0; i < tam; ++i)
	{
		lista[i]= 1 + rand() % (tam*2 - 1);

	}
	t1=clock();
	double tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
	cout << "Tiempo de ejecucion "<<tam<<": " << tiempo << endl;

}
//2  medir tiempo.....esta en el main

//3 INSERTION SORT-------------------------
void InsertionSort(int arr[], int arr_size){
    int asignaciones=0;
	int comparaciones=0;

    for(int i = 1; i < arr_size; ++i){
      int j = i - 1;
      asignaciones++;
      int key = arr[i];
      asignaciones++;
      while(j >= 0 && arr[j] > key){
          comparaciones++;
        arr[j+1] = arr[j];
        asignaciones++;
        --j;
      }
      arr[j+1] = key;
      asignaciones++;
    }
  cout<<"asignaciones :"<<asignaciones<<" comparaciones: "<<comparaciones<<endl<<"-...."<<sizeof(arr)<<endl;
  cout<<"resultado : "<<comparaciones*2+asignaciones*8+4*200*50+10*4<<endl;
}
//4 BUBBLE SORT------------------------------
void bubbleSort(int arreglo[],int n){
    int asignaciones=0;
	int comparaciones=0;
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for (j=n-1;j>=i+1;j--){
            if(arreglo[j]<arreglo[j-1]){
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
    //analisar la cantidad de comparaciones y asignaciones
     cout<<"asignaciones :"<<asignaciones<<" comparaciones: "<<comparaciones<<endl;
     cout<<"resultado : "<<comparaciones*2+asignaciones*8+4*200*50+10*4<<endl;
}

void show(int *arr,int t){
		for(int i=0;i<t;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}





int main(){
	int *arr=new int[10];
	int *arr1=new int[1000];
	int *arr2=new int[100000];
	int *arr3=new int[1000000];


	generador(arr,10);
	//show(arr,10);


    generador(arr1,1000);
	//show(arr,1000);

	InsertionSort(arr1,1000);
	//show(arr1,1000);
	generador(arr2,100000);
	//show(arr,100000);
    bubbleSort(arr2,100000);

	generador(arr3,1000000);
	//show(arr3,1000000);
    //analisar la cantidad de asignacion de memoria
    //arr ocupa 40 bits
    //arr1 ocupa 4000 bits
    //arr2 ocupa 400000 bits
    //arr3 ocupa 4000000 bits

}


