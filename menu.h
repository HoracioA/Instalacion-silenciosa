#ifndef _MENU_H						//evita que la libreria sea compilada mas de 1 vez
#define _MENU_H
#include "archivos.h"
				

int convertir_cadena_a_entero(const char *cad);				//Combierte un string a entero
int menu(int estado);
int menu_instalacion(int estado);
int Estado(char *string, int i);
void Seleccion(void);
void procesoArchivo(char *archivo);
void copiarprogramas(int id);
void instalar_Programa(int id);
int Control_Cuenta_Usuario(void);


int menu_instalacion(int estado)
{
	int aux,i,contador,indice=0,N_Max;
	char string[50];
	N_Max=sizeof(programas)/sizeof(struct programa);
	menu(2);	
	for(i=0;i<N_Max+1;i++)
		if(programas[i].flag_instalando==1)
		{
			
			printf("\n\n\n");
						
			if(estado==0)
				printf("Copiando archivos %s",programas[i].Nombre);
			else
				printf("Instalando %s",programas[i].Nombre);
		}
	
}

void Seleccion(void)
{
	int i=1,aux;
	char cadena[5];
	int N_Max;
	N_Max=sizeof(programas)/sizeof(struct programa);					//Determina cuantos programas par ainstalar hay
	printf("\nDefina que programas quiere instalar (numero y enter, 0 para terminar): ");
	
	while(i!=0)
	{
		scanf("%s",cadena);
		
		if(!strcmp(cadena,"a") || !strcmp(cadena,"A"))
		{
			for(i=0;i<N_Max;i++)
			{
				if(programas[i].Tipo==1)
					programas[i].flag_instalar=1;
			}
		}
		if(!strcmp(cadena,"b") || !strcmp(cadena,"B"))
		{
			for(i=0;i<N_Max;i++)
			{
				if(programas[i].Tipo==2)
				{
					programas[i].flag_instalar=1;
				}
					
			}
		}
		else if(!strcmp(cadena,"c") || !strcmp(cadena,"C"))
		{
			for(i=0;i<N_Max;i++)
			{
				if(programas[i].Tipo==3)
					programas[i].flag_instalar=1;
			}
		}
		
		else if(convertir_cadena_a_entero(cadena)<=N_Max)
		{
			i=convertir_cadena_a_entero(cadena);
			programas[i-1].flag_instalar=1;
		}
		i=convertir_cadena_a_entero(cadena);
	} 
	
}

int menu(int estado)										//Menu indicativo 
{
	
	
	int i,ID,N_Max=0;
	char string[50];
	char logo[]={"\n\
	===================================== \n \
	=                                   = \n\
	= Instalando programas desatendidos = \n\
	=                                   = \n\
	===================================== \n\n"};
	
	system("cls");
	printf("%s",logo);

	N_Max=sizeof(programas)/sizeof(struct programa);					//Determina cuantos programas par ainstalar hay
	
	if(estado==0)
	{
		printf("\n\n Berificar si el control de cuentas de Usuario esta desactibado.\n Si no desactivar y reiniciar el equipo\n\n Enter para continuar");
		getchar();
	}
	
	else if (estado==1)
	{
			i=0;
			
			if(programas[i].Tipo==1)
			{
				printf("\n\n A) Configuracion de registros\n\n");
				while( i<N_Max)
				{
					if(programas[i].Tipo==1)
					{
						//Estado(string,i);
						printf("%2i)%s %s   ",i+1,programas[i].Nombre,string);	
					}	
					i++;
					
					if(programas[i].Tipo==1 && i<N_Max )
					{
						//Estado(string,i);
						printf("%2i)%s %s   ",i+1,programas[i].Nombre,string);	
						i++;
					}
					
					
					if(programas[i].Tipo==1 && i<N_Max )
					{
						//Estado(string,i);
						printf("%2i)%s %s\n",i+1,programas[i].Nombre,string);	
						i++;
					}
					
					
				}
			}
			
	//		if(programas[i].Tipo==2)
			{
				i=0;
				printf("\n\n B) Programas basicos\n\n");
				while( i<N_Max)
				{
					if(programas[i].Tipo==2)
					{
						//Estado(string,i);
						printf("%2i)%s %s   ",i+1,programas[i].Nombre,string);	
					}	
					i++;
					
					if(programas[i].Tipo==2 && i<N_Max )
					{
						//Estado(string,i);
						printf("%2i)%s %s   ",i+1,programas[i].Nombre,string);	
						i++;
					}
					
					
					if(programas[i].Tipo==2 && i<N_Max )
					{
						//Estado(string,i);
						printf("%2i)%s %s\n",i+1,programas[i].Nombre,string);	
						i++;
					}	
					
				}
			}
			
//			if(programas[i].Tipo==3)
			{
				i=0;
				printf("\n\n C) Otros programas\n\n");
				while(i<N_Max)
				{
				
					if(programas[i].Tipo==3)
					{
						//Estado(string,i);
						printf("%2i)%s %s   ",i+1,programas[i].Nombre,string);	
					}	
					i++;
					
					if(programas[i].Tipo==3 && i<N_Max )
					{
						//Estado(string,i);
						printf("%2i)%s %s   ",i+1,programas[i].Nombre,string);	
						i++;
					}
										
					if(programas[i].Tipo==3 && i<N_Max )
					{
						//Estado(string,i);
						printf("%2i)%s %s\n",i+1,programas[i].Nombre,string);	
						i++;
					}
				}
			}
			
		
	}
	
	else if (estado==2)
	{
			i=0;
			

			{
				printf("\n\n A) Programas basicos\n\n");
				i=0;
				while(i<N_Max)
				{
					if(programas[i].Tipo==1)
					{
						
						if(programas[i].flag_instalar==1)
						{
							Estado(string,i);	
							printf("   %2i)%s %s\n",i+1,programas[i].Nombre,string);	
							
						}
					}
					i++;
				}
			}
			
		
			{
				printf("\n\n B) Programas basicos\n\n");
				i=0;
				while(i<N_Max)
				{
					if(programas[i].Tipo==2)
					{
						
						if(programas[i].flag_instalar==1)
						{
							Estado(string,i);	
							printf("   %2i)%s %s\n",i+1,programas[i].Nombre,string);	
						}
							
					}
					i++;
				}
			}
			

			{
				printf("\n\n C) Otros programas\n\n");
				i=0;
				while(i<N_Max)
				{
					if(programas[i].Tipo==3)
					{
						if(programas[i].flag_instalar==1)
						{
							Estado(string,i);	
							printf("   %2i)%s %s\n",i+1,programas[i].Nombre,string);	
						}	
					}
					i++;
				}
			}
		
		
		
	}

}

int Estado(char *string, int i)								//permite colocar en el menu el estado (a intalar, intalando, instalado)
{
		strcpy(string, "" );

		if(programas[i].flag_instalando==1)
			{
				strcpy(string, "                    Instalandose " );
			}
			else if(programas[i].flag_error!=0)
			{
				strcpy(string, "                    Error al instalarlo " );		
			}
			else if(programas[i].flag_instalo==1 && programas[i].flag_error==0)
			{
				strcpy(string, "                    Instalo exitosamente " );
			}
			else if(programas[i].flag_instalar==1)
			{
				strcpy(string, "                    a instalar " );
			}
	
}

int convertir_cadena_a_entero(const char *cad)				//Combierte un string a entero
{
    long num = 0;
    int tam  = strlen(cad);  /* Longitud de la cadena recibida */
    int digito;
    int i;

    for (i = tam ; i > 0; --i) {
        digito = (int) (cad[i - 1] - 48);
        num += digito * pow(10.0, tam - i);
    }

    return num;
}

void instalar_Programa(int id)
{

	char string[STRING_MAX];
	if(programas[id].flag_error==0)										//Si no hubo error al copiar
			{
				//strcpy(programas[id].Instalador,BuscarArchivo(programas[id].dir_pc, programas[id].Instalador));			//esto sirve para no tener que definir la vercion.
				//printf("pronbamdo: %s", programas[id].Instalador);
				//system("pause");
				
				programas[id].flag_error=1;
				strcpy(string, " " );
				strcpy(string, "C: & cd " );
				strcat(string,"\"");
				strcat(string,programas[id].dir_pc);
				strcat(string,"\\");
				strcat(string,"\"");
				strcat(string," & ");
				
				if(strcmp(programas[id].Instalador," "))								//si lo que se necesita copiar no son carpetas
			{
				//strcat(string,"\\");
				strcat(string,"\"");
				strcat(string,programas[id].Instalador);
				strcat(string,"\"");
			}
				
			//	strcat(string,"\"");
			//	strcat(string,programas[id].Instalador);
			//	strcat(string,"\" ");
				menu_instalacion(1);
				strcat(string,programas[id].comando_silencioso);			
				
																//1 escrive instalando archivos
				#ifdef DEPURAR
					printf("\nInstalando: %s\n", string);
					system("pause");
				#endif
				programas[id].flag_error=system(string);     						//ejecuta la instalacion silenciosa
				programas[id].flag_instalando=0;
				programas[id].flag_instalo=1;
			}

}

void copiarprogramas(int id)
{
	char string[STRING_MAX];
	if((strcmp(programas[id].dir_fs," ")))																	//si se requiere copiar algo
	{
		programas[id].flag_error=1;
		programas[id].flag_instalo=0;
		programas[id].flag_instalando=1;
	
		if(strcmp(programas[id].Instalador," "))																	
			strcpy(programas[id].Instalador,BuscarArchivo(programas[id].dir_fs, programas[id].Instalador));			//esto sirve para no tener que definir la vercion.
	//system("pause");
		strcpy(string, "xcopy " );												//Dejo espacio al final intencionalmente
		strcat(string,"\"");
		strcat(string, programas[id].dir_fs);
		if(strcmp(programas[id].Instalador," "))								//si lo que se necesita copiar no son carpetas
		{
			strcat(string,"\\");
			strcat(string,programas[id].Instalador);
		}
	
		strcat(string,"\"");							//fin direccion de origen
	
		strcat(string," ");
		strcat(string,"\"");
		strcat(string, programas[id].dir_pc);
		strcat(string,"\\");
		strcat(string,"\"");							//fin direccion de destino
		
		strcat(string,  " /s/c/y >null ");
	
				
		#ifdef DEPURAR
			printf("\nprobamdo: %s", string);
			system("pause");
		#endif	
	
		menu_instalacion(0);												// 0 escribe Copiando archivos
		programas[id].flag_error=system(string);     						//Copia los archivos
	}
}

int Control_Cuenta_Usuario(void)
{
	char cadena[10];
	char logo[]={"\n\
	===================================== \n \
	=                                   = \n\
	= Instalando programas desatendidos = \n\
	=                                   = \n\
	===================================== \n\n"};
	
	char szKeyPath[]  = "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"; 
    char szKeyName[]  = "EnableLUA"; 
    char szNewValue[] = "about:blank"; 
 
    HKEY hIESettings = NULL; 
    LONG lRes = RegOpenKeyEx(HKEY_LOCAL_MACHINE, szKeyPath, 0, KEY_READ | KEY_WRITE, &hIESettings); 
 
    if (lRes != ERROR_SUCCESS) 
    { 
        printf("%s",logo);
		printf("\n\nDesactive el control de cuentas de usuario.\nDe esta forma no pedira autorizacion cada vez que intente intalar un progarama");
		system("pause");
        return -1;
    } 
 
    // Read the current value. 
    BYTE  abyOldValue[MAX_PATH]; 
    DWORD dwBufSize = MAX_PATH; 
    lRes = RegQueryValueEx(hIESettings, szKeyName, 0, NULL, abyOldValue, &dwBufSize); 
 
 
    if (lRes != ERROR_SUCCESS)  // TODO: Handle ERROR_MORE_DATA. 
    { 
        cerr << "Error reading the value"<< endl; 
        //return -1; 
    } 
 
  		
	if(abyOldValue[0]!=0){
		system("REG ADD HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v EnableLUA /t REG_DWORD /d 0 /f >>null");
		printf("%s",logo);
		printf("Se recomineda reiniciar el equipo y volver a correr el programa\nMotivo: Que no pida autorizacion cada ves que va a instalar un programa\nDesea reiniciar?[s/n]: ");
			scanf("%s",cadena);
		if(!strcmp(cadena,"s") || !strcmp(cadena,"S")){
		
				printf("reiniciando...");
				system("SHUTDOWN /R /F /T 0");
				system("pause");
		}
	}
						
	
	//return 1;
}



#endif   
