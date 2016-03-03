
#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "define.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <stdio.h>

char  *BuscarArchivo(char *dir, char *archivo);
void procesoArchivo(char *archivo);
int copiar(char *archivo_origen,char *archivo_destino);
void gotoXY(int x, int y);
int Copiar_Archivo(const char *src, const char *dst);
int Copiar_Directorio(const char *src, const char *dst);
int Nombre_archivo(char Dir[],char Nombre[]);

//int tamanio_Archivo(char *Archivo);
//int tamanio_Directorio(char *Carpeta);

int Crear_Cuenta_Usuario(char *usuario,char *pass);							//Crea un usuario en la PC
int Crear_Cuenta_Administrador(char *usuario,char *pass);					//Crea un usuario Administrador en la PC

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
  char archivo2[500], archivo3[500], retorno[500];
  // Empezaremos a leer en el directorio actual 
  dir1 = opendir (dir);
  
  strcpy(archivo2, "" );
  strcpy(archivo3, "" );
  
  	for(i=0;i<strlen(archivo);i++)						//Los pone todas en mayusculas
  	{
    	archivo2[i]=toupper(archivo[i]);
	}
	archivo2[i]=(char)NULL;								//Lo nesecita para serrar la cadena
	
	//printf("archivo2: %s \n",archivo2);
  
  	archivo3[0]=toupper(archivo[0]);				//pone la primenta en mayuscula
	for(i=1;i<strlen(archivo);i++)
  	{
    	archivo3[i]=archivo[i];
	}
  archivo3[i]=(char)NULL;									//Lo nesecita para serrar la cadena
  
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
    	//retorno=(char*)malloc(strlen(ent->d_name));
	  	strcpy(retorno,ent->d_name);
    }
    else if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) && strstr(ent->d_name, archivo2) != NULL )
    {
      // Una vez tenemos el archivo, lo pasamos a una función para procesarlo. 
    	//procesoArchivo(ent->d_name);
    	//retorno=(char*)malloc(strlen(ent->d_name));
	  	strcpy(retorno,ent->d_name);
    }
    else if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) && strstr(ent->d_name, archivo3) != NULL )
    {
      // Una vez tenemos el archivo, lo pasamos a una función para procesarlo. 
    	//procesoArchivo(ent->d_name);
    	//retorno=(char*)malloc(strlen(ent->d_name));
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
		printf("\nA copiar: %s", string);
		system("pause");
	#endif
	
	
	strcpy(string, "xcopy " );
	strcat(string, "\"");
	
	strcat(string, "C:\\Temp\\instalacion silenciosa\\auxiliar\\NOD32\\config.xml");
	
	strcat(string, "\"");
	strcat(string, " ");
	strcat(string, "\"");
	strcat(string, "C:\\Temp\\instalacion silenciosa\\nod32\\config.xml");
	strcat(string, "\\\" /s/c/y/f >null " );
	
	system(string);
	
	#ifdef DEPURAR
		printf("\nA copiar: %s", string);
		system("pause");
	#endif
	
}


off64_t getfilesize(FILE *f)
{
    off64_t result = -1;
    off64_t p=ftello64(f);   // obtiene la posición actual

    if(fseeko64(f, 0, SEEK_END)==0)		// ir a la final
    {
        result=ftello64(f);			// obtener la posición actual = tamaño de archivo!
        fseeko64(f, p, SEEK_SET);	// retroceder antigua posición
    }
    
    return result;
}

int Tamanio_Archivo(char *fname)
{
    FILE *f = fopen64(fname, "r");
    off64_t file_size = getfilesize(f);
    fclose(f);
    return file_size;
}

void gotoXY(int x, int y)
{
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(hStdOut, coord);
}


int Copiar_Archivo(const char *src, const char *dst)
 {
  /* Adds a single file */
  ifstream                          infile;
  ofstream                          outfile;
  char                              *buffer;
  int                               src_size;
  int                               status;
  int                               count;
  printf("Copying %s to %s\n", src, dst);
  count = 0;
  status = STATUS_OK;
  // open at end so tellg() gets file size
  infile.open(src, ios::binary|ios::ate);
  outfile.open(dst, ios::binary);
  src_size = infile.tellg();
  // seek to beginning since we opened at end
  infile.seekg (0, ios::beg);
  //printf("Source size: %d\n", src_size);
  
  buffer = new char[BUFFER_SIZE];
  while ( (status == STATUS_OK) && (!infile.eof()) ) {
    // reads BUFFER_SIZE of data info buffer
    infile.read(buffer, BUFFER_SIZE);
    outfile.write(buffer, infile.gcount());
    count += infile.gcount();
    //gotoXY(0,25);
	printf("Current progress: %dMB de %dMB\n", (count/1024/1024),(src_size/1024/1024));
  }
  infile.close();
  outfile.close();
  // deletes buffer and its contents
  delete[] buffer;
  return(status);
}

int Copiar_Directorio(const char *DirOrigen, const char *DirDestino)
{
	DIR *dir1, *dir2;
	struct dirent *ent;
	char *retorno,stringOrigen[500],stringDestino[500];
	FILE *ptrdatos;
	
	// Empezaremos a leer en el directorio actual 
	dir1 = opendir (DirOrigen);
	
	mkdir(DirDestino);
	
	if (dir1 == NULL){
	   	printf("No puedo abrir el directorio\n");
	   	return 1;
	}
    
     while ((ent = readdir(dir1)) != NULL)
    {
      	// Nos devolverá el directorio actual (.) y el anterior (..), como hace ls 
    	if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0))
   		{
      		// Una vez tenemos el archivo, lo pasamos a una función para procesarlo. 
    
    		retorno=(char*)malloc(strlen(ent->d_name));
    		strcpy(retorno,ent->d_name);
			strcpy(stringOrigen, DirOrigen );
			strcat(stringOrigen, "\\");
			strcat(stringOrigen, retorno);
	  		if(ptrdatos=fopen(stringOrigen,"r")){
			  	strcpy(stringDestino, DirDestino );
				strcat(stringDestino, "\\");
				strcat(stringDestino, retorno);
				Copiar_Archivo(stringOrigen,stringDestino);
	
			}
	   		else
	   		{
				strcpy(stringDestino, DirDestino );
				strcat(stringDestino, "\\");
				strcat(stringDestino, retorno);
				Copiar_Directorio(stringOrigen, stringDestino);
			}
		 		
    	}
	}
    closedir(dir1);
	return 0;
}

int copiar(char *archivo_origen,char *archivo_destino)
{

	FILE *ptrdatos;	
	char *retorno,stringDestino[100],Nombre[255];
	
	
	if(ptrdatos=fopen(archivo_origen,"r"))
	{
		mkdir(archivo_destino);
		strcpy(stringDestino,archivo_destino);
		strcat(stringDestino, "\\");
		Nombre_archivo(archivo_origen,Nombre);
		strcat(stringDestino, Nombre);
		printf("Origen:%s Destino:%s",archivo_origen,stringDestino);
    	Copiar_Archivo(archivo_origen,stringDestino);
	}
	else
		Copiar_Directorio(archivo_origen,archivo_destino);
		
}

int Nombre_archivo(char Dir[],char Nombre[])
{
	int Tamanio=0,i,b=0;
	char aux='a';
	char a[100],N[100];
	
	Tamanio=strlen(Dir);
	i=Tamanio-1;				// el ultimo es /0 no sirve
	while(aux!='\\')
	{
		aux=Dir[i];
		a[b]=Dir[i];
		b++;
		i--;
	}
	a[b]='\0';
	
	for(i=0;i<b;i++)
	{
		Nombre[i]=a[b-i-2];
	}
	Nombre[i]='\0';
	
	
	return Tamanio;
}

int tamanio_Archivo(char *Archivo)
{
	int tamanio;
	ifstream infile;
	infile.open(Archivo, ios::binary|ios::ate);
	
	tamanio= infile.tellg();
	infile.close();
	
	return tamanio;
	
}

int tamanio_Directorio(char *Carpeta)
{
DIR *dir1;
	struct dirent *ent;
	char *retorno,stringOrigen[1000];
	FILE *ptrdatos;
	int tamanio=0;
	
	// Empezaremos a leer en el directorio actual 
	dir1 = opendir (Carpeta);
	
	//mkdir(DirDestino);
	
	if (dir1 == NULL){
	   	printf("No puedo abrir el directorio\n");
	   	return 1;
	}
    
     while ((ent = readdir(dir1)) != NULL)
    {
      	
		// Nos devolverá el directorio actual (.) y el anterior (..), como hace ls 
    	if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0))
   		{
      		// Una vez tenemos el archivo, lo pasamos a una función para procesarlo. 
    
    		retorno=(char*)malloc(strlen(ent->d_name));
    		strcpy(retorno,ent->d_name);
			strcpy(stringOrigen, Carpeta );
			strcat(stringOrigen, "\\");
			strcat(stringOrigen, retorno);
				if(ptrdatos=fopen(stringOrigen,"r")){
			  		tamanio=tamanio+tamanio_Archivo(stringOrigen);
	
				}
	   			else
	   			{
				
				tamanio=tamanio+tamanio_Directorio(stringOrigen);
				
				}
		 		
    	}
	}
	closedir(dir1);
    return tamanio;	
}

int Crear_Cuenta_Usuario(char *usuario,char *pass)						//Crea un usuario en la PC
{
	char string[20];
	system("net accounts /minpwlen:0");									//Para que el pass minimo cea de 0 caaracteres (permite contraceña nula)
	strcpy(string,"net user ");
	strcat(string, usuario);
	strcat(string, " ");
	strcat(string, pass);
	strcat(string, " ");
	strcat(string, " /add");
	system(string);
	return 0;
	
}

int Crear_Cuenta_Administrador(char *usuario,char *pass)					//Crea un usuario Administrador en la PC
{
	char string[40];
	Crear_Cuenta_Usuario(usuario,pass);
	
	
	
	
	strcpy(string,"net localgroup administradores ");
	strcat(string, usuario);
	//strcat(string, pass);
	strcat(string, " ");
	strcat(string, " /add");
	system(string);
	
}


#endif

