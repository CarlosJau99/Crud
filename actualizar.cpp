#include<iostream>
using namespace std;
//ambito global
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void leer();
void Crear();
void Actualizar();
void Borrar();
main(){
	leer();
//Crear();
//Actualizar();
	Borrar();
	system("pause");	
}
	void leer(){
		system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	//! para cuando sea true o false se pone !
	if(!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	do{
		cout<<"id"<<","<<estudiante.codigo<<","<<estudiante.nombres<<","<<estudiante.apellidos<<estudiante.telefono<<endl;
	}while(feof(archivo)==0);
	fclose(archivo);
}


void Crear (){
	FILE* archivo = fopen(nombre_archivo,"a+b");
	char res;
	Estudiante estudiante;
	do{
			fflush(stdin);
			cout<<"ingrese codigo:";
			cin>>estudiante.codigo;
			cin.ignore();
			cout<<"ingrese nombres:";
			cin.getline(estudiante.nombres,50);
			cout<<"ingrese apellidos:";
			cin.getline(estudiante.apellidos,50);
			cout<<"ingrese telefono:";
			cin>>estudiante.telefono;
			//un archvopuede leeer y datos=estudiante,tamaño estructura,bandera(0.1 para leer o modificar.2.3.4),archivo que se esta abriendo
			//
			fwrite(&estudiante,sizeof(Estudiante),1,archivo);
			cout<<"Desea ingresar otro estudiante(s/n):";
			cin>>res;
				}while(res=='s' || res=='s');
				fclose(archivo);
				leer();
				
}
void Actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	Estudiante estudiante;
	int id=0;
	cout<<"ingrese el ID que desea modificar:";
	cin>>id;
fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
			cout<<"ingrese codigo:";
			cin>>estudiante.codigo;
			cin.ignore();
			cout<<"ingrese nombres:";
			cin.getline(estudiante.nombres,50);
			cout<<"ingrese apellidos:";
			cin.getline(estudiante.apellidos,50);
			cout<<"ingrese telefono:";
			cin>>estudiante.telefono;
			//un archvopuede leeer y datos=estudiante,tamaño estructura,bandera(0.1 para leer o modificar.2.3.4),archivo que se esta abriendo
			//
			fwrite(&estudiante,sizeof(Estudiante),1,archivo);
			
				
				fclose(archivo);
				leer();
}
void Borrar(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
		FILE* archivo = fopen(nombre_archivo,"rb");
		FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
		Estudiante estudiante;
		int id=0,id_n=0;
		cout<<"ingrese el ID a eliminar:";
		cin>>id;
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
		if (id_n !=id){
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
		}
		id_n++;
		
	}
			
		fclose(archivo);
		fclose(archivo_temp);
		
		 archivo = fopen(nombre_archivo,"wb");
		 archivo_temp = fopen(nombre_archivo_temp,"rb");
		 	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
			fwrite(&estudiante,sizeof(Estudiante),1,archivo);
			 }
			 fclose(archivo);
			 fclose(archivo_temp);
			 leer();
}
