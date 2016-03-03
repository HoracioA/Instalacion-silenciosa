
#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "define.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

char  *BuscarArchivo(char *dir, char *archivo);
void procesoArchivo(char *archivo);
int copiar(char *archivo_origen,char *archivo_destino);

//void copiarprogramas(int id);

void procesoArchivo(char *archivo)
{
  /* Para "procesar", o al menos, hacer algo con el archivo, vamos a decir su tamaño en bytes */
  /* para ello haremos lo que vemos aquí: http://totaki.com/poesiabinaria/2010/04/tamano-de-un-fichero-en-c/ */
  FILE *fich;
  long ftam;

  fich=fopen(archivo, "r");
  if (fich)
    {
      fseek(fich, 0L, SEEK_END);
      ftam=ftell(fich);
      fclose(fich);
      /* Si todo va bien, decimos el tamaño */
      printf ("%30s (%ld bytes)\n", archivo, ftam);
    }
  else
    /* Si ha pasado algo, sólo decimos el nombre */
    printf ("%30s (No info.)\n", archivo);
}

char *BuscarArchivo(char *dir, char archivo[])
{
	int i;	
  // Con un puntero a DIR abriremos el directorio 
  DIR *dir1;
  // en *ent habrá información sobre el archivo que se está "sacando" a cada momento 
  struct dirent *ent;
  char archivo2[100], archivo3[100],*retorno;
  // Empezaremos a leer en el directorio actual 
  dir1 = opendir (dir);
  
  strcpy(archivo2, "" );
  strcpy(archivo3, "" );
  
  	for(i=0;i<strlen(archivo);i++)
  	{
    	archivo2[i]=toupper(archivo[i]);
	}
	archivo2[i]=NULL;								//Lo nesecita para serrar la cadena
	
	//printf("archivo2: %s \n",archivo2);
  
  	archivo3[0]=toupper(archivo[0]);				//pone la promenta en mayusc
	for(i=1;i<strlen(archivo);i++)
  	{
    	archivo3[i]=archivo[i];
	}
  archivo3[i]=NULL;									//Lo nesecita para serrar la cadena
  
  // Miramos que no haya error 
  if (dir1 == NULL)
    printf("No puedo abrir el directorio");
 
  // Una vez nos aseguramos de que no hay error, ¡vamos a jugar! 
  // Leyendo uno a uno todos los archivos que hay 
  while ((ent = readdir(dir1)) != NULL)
    {
      // Nos devolverá el directorio actual (.) y el anterior (..), como hace ls 
    if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) && strstr(ent->d_name, archivo) != NULL )
    {
      // Una vez tenemos el archivo, lo pasamos a una función para procesarlo. 
    	//procesoArchivo(ent->d_name);
    	retorno=(char*)malloc(strlen(ent->d_name));
	  	strcpy(retorno,ent->d_name);
    }
    else if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) && strstr(ent->d_name, archivo2) != NULL )
    {
      // Una vez tenemos el archivo, lo pasamos a una función para procesarlo. 
    	//procesoArchivo(ent->d_name);
    	retorno=(char*)malloc(strlen(ent->d_name));
	  	strcpy(retorno,ent->d_name);
    }
    else if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) && strstr(ent->d_name, archivo3) != NULL )
    {
      // Una vez tenemos el archivo, lo pasamos a una función para procesarlo. 
    	//procesoArchivo(ent->d_name);
    	retorno=(char*)malloc(strlen(ent->d_name));
	  	strcpy(retorno,ent->d_name);
    }
    }
  closedir (dir1);
  return retorno;
}

int copiar_carpetas(char *origen, char *destino)
{
	char string[500];
	
	//Copia la carpeta auxiliar
	printf("Copiando carpeta auxiliar");
	strcpy(string, "xcopy " );
	strcat(string, "\"");
	
	strcat(string, origen );
	
	strcat(string, "\"");
	strcat(string, " ");
	strcat(string, "\"");
	
	strcat(string, destino );
	strcat(string, "\\\" /s/c/y >null " );
	#ifdef DEPURAR
		printf("\nprobamdo: %s", string);
		system("pause");
	#endif
	system(string);
	
	
}

int copiar(char archivo_origen[],char archivo_destino[])
{
	char letra;
	int tamanio=0;
	FILE *ficheroL, *ficheroE;
	
	// modo "rb" binario lectura, si no especificas b lo abre en modo texto
    // (modo por defecto) como si escribieras "rt"
   	if ((ficheroL = fopen(archivo_origen, "rb"))==NULL)
		printf("No se pudo abrir archivo origen"); //return 1;
    // modo "wb" binario escritura, igual que antes, si no especificas
    // binario, lo abre en modo texto, como si escribieras "wt"
    if ((ficheroE = fopen(archivo_destino, "wb"))==NULL)
    	printf("No se pudo abrir archivo destino"); //return 1;
        
//	while (feof(ficheroL)==0)
//    {
//    	fgetc(ficheroL);
//    	tamanio++;
//	}
//	printf("tamanio = %d",tamanio);
//	
//	rewind(ficheroL);							//revovina, vuelve el cursor al inicio
//	
	letra=getc(ficheroL);
//	while (feof(ficheroL)==0)
//    {
//    letra=(int)fgetc(ficheroL);	
//	fprintf(ficheroE, "%i", letra);
//	}
//	
//	printf("\n\n a ver");
//	system("pause");
	
	while (feof(ficheroL)==0)
    {
        
		fputc(letra,ficheroE);
        letra=fgetc(ficheroL);
		//printf("%c", letra);
        
    }
 
    fclose(ficheroL);
    fclose(ficheroE);
 
    system("pause");
    return 0;
}


#endif

