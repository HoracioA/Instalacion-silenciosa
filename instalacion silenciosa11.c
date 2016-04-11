//#include "define.h"
#include "archivos.h"
#include "menu.h"


int instalacion(void);
	
int main ()
{
	

	int i,N_Max,aux;
	char string [500],cadena[5],*st,nombre[50];
	
	N_Max=sizeof(programas)/sizeof(struct programa);					//Determina cuantos programas par ainstalar hay

	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),0x30); 	//Le da a la consola color
	system("cls");
	//Control_Cuenta_Usuario();
	//prueba par copiar archivos
	
	//Copiar_Archivo("\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\ESET Endpoint Antivirus 5\\eea_nt64_esl.msi", "D:\\Horacio\\Escritorio\\Copiar archivos\\prueba\\eea_nt64_esl.msi");
	//Copiar_Directorio("\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\ESET Endpoint Antivirus 5", "D:\\Horacio\\Escritorio\\Copiar archivos\\prueba");
	//Copiar_Directorio("D:\\Horacio\\Escritorio\\Copiar archivos\\prueba","D:\\Horacio\\Escritorio\\Copiar archivos\\prueba2");
	//copiar("\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Microsoft Office\\SW_DVD5_Office_Professional_Plus_2013_64Bit_Spanish_MLF_X18-55348\\leame.htm","D:\\Horacio\\Escritorio\\Copiar escritorio");
	//Copiar_Archivo("\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Microsoft Office\\SW_DVD5_Office_Professional_Plus_2013_64Bit_Spanish_MLF_X18-55348\\leame.htm","D:\\Horacio\\Escritorio\\Copiar escritorio\\leame.htm");
	//Nombre_archivo("D:\\Horacio\\Escritorio\\Copiar archivos\\prueba\\eea_nt64_esl.msi",nombre);
	//printf("Nombre: %s \n",nombre);
	//printf("%d Mb \n",tamanio_Directorio("\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Microsoft Office\\SW_DVD5_Office_Professional_Plus_2013_64Bit_Spanish_MLF_X18-55348")/1024/1024);
	//printf("%d Mb \n",Tamanio_Archivo("\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Microsoft Office\\SW_DVD5_Office_Professional_Plus_2013_64Bit_Spanish_MLF_X18-55348\\leame.htm"));
	//printf("%d Mb \n",tamanio_Archivo("\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Microsoft Office\\SW_DVD5_Office_Professional_Plus_2013_64Bit_Spanish_MLF_X18-55348\\leame.htm"));
	//printf("%d Mb \n",tamanio_Archivo("D:\\Horacio\\Escritorio\\Copiar archivos\\prueba\\eea_nt64_esl.msi")/1024/1024);
	//strcpy(nombre,"fire");
	//BuscarArchivo("\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\Publico\\Modelo PC (basico)",nombre);
	//printf("\nEl archivo es: %s \n",BuscarArchivo("\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\Publico\\Modelo PC (basico)",nombre));
	//system("REG ADD HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v EnableLUA /t REG_DWORD /d 0 /f >>null");
	//printf("Control cuenta de usuario");
	//system("pause");
	
	//crear una cuenta de usuario
	//system("net accounts /minpwlen:0");
	//system("net user Nombre /add");
	//Crear_Cuenta_Usuario("Camioneros","1234");					//Nombre y password
	//Crear_Cuenta_Administrador("Nombre1","\0");				//Nombre y password
		
	#ifndef SILENCIOSA
	//menu(0);
	do																	//confirmacion de programas elejidos
	{
		for(i=0;i<N_Max;i++)
			{
				programas[i].flag_instalar=0;
			}
		menu(1);
		Seleccion();
		menu(2);
		printf("Son los programas que desea instalar? [y/n]: ");
		scanf("%s",cadena);
	}while(strcmp(cadena,"y"));
	#endif
	

	
	menu(2);

	copiar_carpetas((char*)DIR_FS_AUXILIAR, (char*)DIR_PC_AUXILIAR);				//ver si tiene problemas
	
	instalacion();
	
	system("pause");
	#ifdef BORRAR_ARCHIVOS
		printf("\nBorrando carpeta auxiliar\n");
		system("rd /S/Q C:\\Temp\\\"instalacion silenciosa\"\\ " );
	#endif
	return 0;
} 

int instalacion(void)
{
	char string[500];
	int a,N_Max,id;
	
	N_Max=sizeof(programas)/sizeof(struct programa);					//Determina cuantos programas para instalar hay
	for(id=0;id<N_Max;id++)
	{
		
		menu_instalacion(0);
		if (programas[id].flag_instalar==1)
		{
			#ifdef COPIAR_ARCHIVOS
				copiarprogramas(id);
			#endif
			menu_instalacion(0);												// 0 escribe Copiando archivos
			instalar_Programa(id);	
			#ifdef DEPURAR
				system("pause");
			#endif
			programas[id].flag_instalo=1;
			programas[id].flag_instalando=0;
		}
		
		menu_instalacion(1);
	}
	
	#ifdef DEPURAR
		system("pause");
	#endif
	
	return 0;
}




