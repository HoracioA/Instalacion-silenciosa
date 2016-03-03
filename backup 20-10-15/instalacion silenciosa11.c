//#include "define.h"
#include "archivos.h"
#include "menu.h"


int instalacion(void);
	
int main ()
{
	

	int i,N_Max,aux;
	char string [500],cadena[5],*st;
	
	N_Max=sizeof(programas)/sizeof(struct programa);					//Determina cuantos programas par ainstalar hay

	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),0x30); 
	//prueba par copiar archivos
	//copiar("\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\ESET Endpoint Antivirus 5\\eea_nt64_esl.msi","prueba\\nod32.exe");
	//copiar("prueba\\prueba.exe","prueba\\prueba2.exe");
	
	
		
	#ifndef SILENCIOSA
	menu(0);
	do																	//confirmacion de programas elejidos
	{
		for(i=0;i<N_Max;i++)
			{
				programas[i].flag_instalar=0;
			}
		menu(1);
		Seleccion();
		menu(2);
		printf("Son los programas que decea instalar? [y/n]: ");
		scanf("%s",cadena);
	}while(strcmp(cadena,"y"));
	#endif
	

	
	menu(2);

	copiar_carpetas((char*)DIR_FS_AUXILIAR, (char*)DIR_PC_AUXILIAR);
	instalacion();
	
	system("pause");
	if(BORRAR_ARCHIVOS==1)
	{
		printf("\nBorrando carpeta auxiliar\n");
		system("rd /S/Q C:\\Temp\\\"instalacion silenciosa\"\\ " );
	}
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


