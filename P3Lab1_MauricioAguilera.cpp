#include <stdio.h>
#include <iostream>

using namespace std;

int ** matriz;
char * arreglo;

void imprimir (int, int);

int main(){
	char resp='s';
	
	while (resp=='s'){
		int op;
		cout<<"1. Punto de silla"<<endl<<
				"2. Numeros triangulares"<<endl<<
				"3. Arreglo de caracteres"<<endl<<
				"4. Salir"<<endl<<
				"Ingrese una opcion: ";
		cin>>op;
		
		switch (op){
			case 1:{
				matriz= new int*[5];
				for (int i=0; i<5; i++){
					matriz[i]=new int[5];
				}
				for	(int i=0; i<5; i++){
					for (int j=0; j<5 ;j++){
						cout<<"Ingrese el valor del espacio ["<<i<<"]["<<j<<"]: ";
						cin>>matriz[i][j];
					}
				}
				
				char resp2='s';
				while (resp2=='s'){
					int op2;
					cout<<"1. Imprimir matriz"<<endl<<
							"2. Mostrar puntos de silla"<<endl<<
							"3. Mostrar la cantidad de puntos de silla"<<endl<<
							"4. Salir"<<endl<<
							"Ingrese una opcion: ";
					cin>>op2;
					
					switch (op2){
						case 1:{
							imprimir (0, 0);
							break;
						}
						case 2:{
							for	(int i=0; i<5; i++){
								for (int j=0; j<5; j++){
									int temp=matriz[i][j];
									int max=0;
									int min=100;
									bool val1=false;
									bool val2=false;
									for (int k=0; k<5; k++){//sacar el menor de la fila en la que se encuentra el numero actual
										if (matriz[i][k]<min){
											min=matriz[i][k];
										}
									}
									if (min==temp){
										val1=true;
									}
									for (int l=0; l<5; l++){//sacar el mayor de la columna en la que se encuentra el numero actual
										if (matriz[l][j]>max){
											max=matriz[l][j];
										}
									}
									if (max==temp){
										val2=true;
									}
									
									if (val1==true && val2==true){
										cout<<"["<<i<<"]["<<j<<"]: "<<temp<<endl;
									}
								}
							}
							cout<<endl;
							break;
						}
						case 3:{
							int c=0;
							for	(int i=0; i<5; i++){
								for (int j=0; j<5 ;j++){
									int temp=matriz[i][j];
									int max=0;
									int min=100;
									bool val1=false;
									bool val2=false;
									for (int k=0; k<5; k++){//sacar el menor de la fila en la que se encuentra el numero actual
										if (matriz[i][k]<min){
											min=matriz[i][k];
										}
									}
									if (min==temp){
										val1=true;
									}
									for (int l=0; l<5; l++){//sacar el mayor de la columna en la que se encuentra el numero actual
										if (matriz[l][j]>max){
											max=matriz[l][j];
										}
									}
									if (max==temp){
										val2=true;
									}
									
									if (val1==true && val2==true){
										c++;
									}
								}
							}
							cout<<"La cantidad de puntos de sillas presentes en la matriz es: "<<c<<endl<<endl;
							break;
						}
						default:{
							resp2='n';
							cout<<endl<<endl;
							break;
						}
					}
				}
				break;
			}
			
			case 2:{
				int num;
				cout<<"Ingrese un numero(mayor que 0): ";
				cin>>num;
				while (num<=0){//validacion para evitar cualquier error por negativos
					cout<<"El numero no puede ser negativo o 0, intentelo de nuevo: ";
					cin>>num;
				}
				int c=1;
				int temp2;
				int d=1;
				bool val=false;
				while (c<=num){
					if (c==num){//condicion si el numero es triangular
						val=true;
						cout<<"El numero ingresado si es triangular"<<endl<<endl;
						c+=100;
					}else{
						temp2=c;
						d++;
						c+=d;
					}
				}
				if (val==false){//resultado si el numero no es triangular
					cout<<"El numero ingresado no es triangular, el numero "<<temp2<<" es el mas cercano"<<endl<<endl;
				}
				break;
			}
			
			case 3:{
				int num;
				cout<<"Ingrese la longitud del arreglo(mayor que 1): ";
				cin>>num;
				while (num<=1){//validacion para evitar cualquier error
					cout<<"El numero no puede ser negativo o 0, intentelo de nuevo: ";
					cin>>num;
				}
				
				*arreglo = new char[num];
				
				for (int i=0; i<num; i++){
					cout<<"Ingrese el caracter en la posicion ["<<i<<"]: ";
					cin>>arreglo[i];
				}
				bool val=true;
				for (int i=0; i<num; i++){
					for (int j=i+1; j<num; j++){
						if (arreglo[i]==arreglo[j]){
							val=false;
						}
					}
				}
				if (val==true){
					for (int i=0;i<num*(num-1) ; i++ ){
						
					}
				}
				break;
			}
			default:{
				system("pause");
				return 0;
				break;
			}
		}
	}
}

void imprimir (int x, int y){//metodo recursivo para llenar la matriz
	if (x==4 && y==4){
		cout<<"["<<matriz[x][y]<<"]"<<endl;
	}else{
		if (y==4){
			cout<<"["<<matriz[x][y]<<"]"<<endl;
			imprimir (x+1, 0);
		}else{
			cout<<"["<<matriz[x][y]<<"]";
			imprimir (x, y+1);
		}
	}
}
