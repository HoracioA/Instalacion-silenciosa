
#ifndef DEFINE_H
#define DEFINE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <unistd.h>

#include<signal.h>
#include<errno.h>
#include <sys/types.h>
#include <dirent.h>

#include <windows.h>
#include <winreg.h>
#include <fstream>
#include <iostream>

using namespace std;

#define BUFFER_SIZE 32768

#define STATUS_OK 0
#define STATUS_ERROR 1
#define STATUS_NO_DISK_SPACE 2


//#define		DEPURAR					
//#define		SILENCIOSA
#define		BORRAR_ARCHIVOS						
#define		COPIAR_ARCHIVOS

#define 	STRING_MAX				400				//define la cantidad de caracteres para los comandos de instalación


//Direcciones 
//									"\\fs.frba.utn.edu.ar\DiTIC\Programas\Publico\Modelo PC (basico)"\ccsetup507.exe
#define 	DIR_FS_BASICO  			"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\Publico\\Modelo PC (basico)"
#define 	DIR_FS_OFFISE2013		"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Microsoft Office\\Microsoft Office Professional Plus 2013\\SW_DVD5_Office_Professional_Plus_2013_64Bit_Spanish_MLF_X18-55348"
#define 	DIR_FS_OFFISE2010		"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Microsoft Office\\Microsoft Office 2010"
#define		DIR_FS_AUXILIAR			"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\Publico\\Modelo PC (basico)\\auxiliar"
#define 	DIR_FS_NOD32			"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\ESET Endpoint Antivirus 5"
#define 	DIR_FS_x64  			"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\Publico\\Modelo PC (basico)\\x64"
#define 	DIR_FS_PAPEL_TAPIZ		"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\Publico\\Modelo PC (basico)\\Fondos de pantalla"
#define 	DIR_FS_PAPEL_INI		"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\Publico\\Modelo PC (basico)\\Fondos de inicio"
#define		DIR_FS_AUTODESCK2015	"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Autodesk 2015"
#define		DIR_FS_UNITY5			"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Unity5"
#define		DIR_FS_BLENDER			"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\blender"
#define     DIR_FS_SUBLIME          "\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Sublime Text 2"
#define     DIR_FS_SAP				"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\SAP"
#define		DIR_FS_PUBLICO			"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\Publico"
#define		DIR_FS_GENIMOTION		"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Genymotion 2.4"
#define		DIR_FS_ECLIPSE			"\\\\fs.frba.utn.edu.ar\\DiTIC\\SCEU\\Aula 6\\Android\\eclipse"
#define		DIR_FS_PROJECT			"\\\\fs.frba.utn.edu.ar\\DiTIC\\Programas\\DiTIC\\Aplicaciones\\Microsoft Office\\Microsoft Project 2013 SP1 x86-x64\\es_project_professional_2013_with_sp1_x86_and_x64_dvd_3911376"

//									C:\Temp\"instalacion silenciosa"
#define 	DIR_PC_BASICO			"C:\\Temp\\instalacion silenciosa"
#define 	DIR_PC_OFFICE2013		"C:\\Temp\\instalacion silenciosa\\office2013"
#define 	DIR_PC_OFFICE2010		"C:\\Temp\\instalacion silenciosa\\office2010"
#define 	DIR_PC_NOD32			"C:\\Temp\\instalacion silenciosa\\nod32"
#define 	DIR_PC_x64				"C:\\Temp\\instalacion silenciosa\\x64"
#define 	DIR_PC_PAPEL_TAPIZ		"C:\\Users\\Public\\Pictures\\Fondos de pantalla"
#define 	DIR_PC_PAPEL_INI		"%windir%\\System32\\oobe\\info\\backgrounds"
#define 	DIR_PC_AUXILIAR			"C:\\Temp\\instalacion silenciosa\\auxiliar"
#define 	DIR_PC_AUTOSESCK2015	"C:\\Temp\\instalacion silenciosa\\autodesck2015"
#define		DIR_PC_UNITY5			"C:\\Temp\\instalacion silenciosa\\Unity5"
#define		DIR_PC_BLENDER			"C:\\Temp\\instalacion silenciosa\\blender"
#define     DIR_PC_SUBLIME          "C:\\Temp\\instalacion silenciosa\\Sublime"
#define     DIR_PC_SAP				"C:\\Temp\\instalacion silenciosa\\SAP"
#define		DIR_PC_PUBLICO			"C:\\Temp\\instalacion silenciosa"
#define		DIR_PC_GENIMOTION		"C:\\Temp\\instalacion silenciosa"
#define		DIR_PC_ECLIPSE			"C:\\eclipse"
#define		DIR_PC_PROJECT			"C:\\Temp\\instalacion silenciosa\\project2013"



struct programa {
	char Nombre[100];
	char Instalador[100];
	int  Tipo;								//1 Reguistros, 2 Basico, 3 Otros
	char dir_fs[200];
	char dir_pc[100];
	char comando_silencioso[300];
	char flag_instalar;
	char flag_instalando;
	char flag_instalo;
	char flag_error;
}; 



struct programa programas[]= {	//Nombre( identificacon menu)//Instalador (a no ser que tenga carpeta propia)//dir_fs			//dir_PC			//comando_silencioso 							//flag_instalar//flag_instalando//flag_instalo//flag_error
									"Fondo              "	, " "										, 1	, DIR_FS_PAPEL_TAPIZ	, DIR_PC_PAPEL_TAPIZ	, "reg add \"HKEY_CURRENT_USER\\Control Panel\\Desktop\" /v Wallpaper /t REG_SZ /d \"C:\\Users\\Public\\Pictures\\Fondos de pantalla\\WallpaperDomRojo.jpg\" /f >nul", 0, 0, 0, 0,
									//"Fondo              "	, " "										, 1	, DIR_FS_PAPEL_TAPIZ	, DIR_PC_PAPEL_TAPIZ	, "copy \"C:\\Users\\Public\\Pictures\\Fondos de pantalla\\img0.jpg\"  \"C:\\Windows\\Web\\Wallpaper\\Windows\\\" ", 0, 0, 0, 0,
									"Proxy              "   , " "                                       , 1 , " "                   , " "                   , "reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\" /v ProxyServer /t REG_SZ /d \"proxy.frba.utn.edu.ar:8080\" /f >nul && reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\" /v ProxyEnable /t REG_DWORD /d 1 /f >nul", 0, 0, 0, 0,																								       
								    "Actualizaciones    "   , " "                                       , 1 , " "                   , " "                   , "reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\"   /v WUServer /t REG_SZ /d \"http:////wsus.frba.utn.edu.ar:8530\" /f >nul"  , 0, 0, 0, 0,
									"Actualizaciones 1  "   , " "                                       , 1 , " "                   , " "                   , "reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\"   /v WUStatusServer /t REG_SZ /d \"http:////wsus.frba.utn.edu.ar:8530\" /f >nul"  , 0, 0, 0, 0,
									"Imagen Inicio      "   , " "										, 1 , DIR_FS_PAPEL_INI	    , DIR_PC_PAPEL_INI      , "reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\LogonUI\\Background\" /v OEMBackground /t REG_DWORD /d 1 /f >nul" 			, 0, 0, 0, 0,
									"Servidor Time      "   , " "                                       , 1 , " "                   , " "                   , "reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\services\\W32Time\\Parameters\" /v NtpServer /t REG_SZ /d \"time.frba.utn.edu.ar,0x9\" /f >nul"        , 1, 0, 0, 0,
									"Chrome             "	, "ChromeStandaloneSetup.exe"				, 2	, DIR_FS_BASICO 		, DIR_PC_BASICO			, " /silent /install "							, 0, 0, 0, 0,
									"Firefox            "	, "Firefox"                 				, 2	, DIR_FS_BASICO 		, DIR_PC_BASICO			, " -ms "										, 0, 0, 0, 0,
									"Internet explorer  " 	, "IE11-Windows6.1-x64-es-es.exe"			, 2	, DIR_FS_x64 			, DIR_PC_x64			, " /passive /no-default /norestart "			, 0, 0, 0, 0,
									"Adobe Reader       "	, "AdbeRdr"									, 2	, DIR_FS_BASICO 		, DIR_PC_BASICO			, " /sPB /rs /rps "								, 0, 0, 0, 0,
									"Adobe flash        "	, "install_flash_player_19_active_x.exe"	, 2 , DIR_FS_BASICO 		, DIR_PC_BASICO			, " /install "									, 0, 0, 0, 0,
									"Adobe flash plugin " 	, "install_flash_player_19_plugin.exe" 		, 2	, DIR_FS_BASICO 		, DIR_PC_BASICO			, " /install "									, 0, 0, 0, 0,
									"Java               "	, "jre"                      				, 2	, DIR_FS_BASICO		 	, DIR_PC_BASICO			, "	/s "										, 0, 0, 0, 0,
									"K-Lite             "	, "K-Lite"	                             	, 2	, DIR_FS_BASICO 		, DIR_PC_BASICO			, " /silent "									, 0, 0, 0, 0,
									"ccliner            "	, "ccsetup"									, 2	, DIR_FS_BASICO 		, DIR_PC_BASICO 		, " /S /L=1034 "								, 1, 0, 0, 0,
									"Defrag             "	, "dfsetup"									, 2	, DIR_FS_BASICO 		, DIR_PC_BASICO			, " /S /L=1034 "								, 0, 0, 0, 0,
									"WinRar             "	, "winrar"									, 2	, DIR_FS_x64	 		, DIR_PC_x64			, " /s "										, 0, 0, 0, 0,
									"Office 2013        "	, " "										, 2	, DIR_FS_OFFISE2013 	, DIR_PC_OFFICE2013		, "  setup.exe /Config  \"C:\\Temp\\instalacion silenciosa\\auxiliar\\office2013\\Config.xml\""									, 0, 0, 0, 0,
									"NOD32 (antivirus)  "	, " "										, 2	, DIR_FS_NOD32	 		, DIR_PC_NOD32			, " msiexec.exe /i eea_nt64_esl.msi /qb  /NORESTART"							, 0, 0, 0, 0,
									"Tightvnc           "	, "tightvnc-2.7.10-setup-64bit.msi"			, 2	, DIR_FS_x64 			, DIR_PC_x64			, " "										    , 0, 0, 0, 0,
									"CDBurns            "   , "cdbxp"          		 				    , 3 , DIR_FS_BASICO     	, DIR_PC_BASICO 		, " /silent"                                     , 0, 0, 0, 0,
									"Office 2010        "	, " "										, 3	, DIR_FS_OFFISE2010 	, DIR_PC_OFFICE2010		, "  setup.exe /Config  \"C:\\Temp\\instalacion silenciosa\\auxiliar\\office2010\\Config.xml\""		, 0, 0, 0, 0,
//									"Autodesck 2015(esp)"	, "Autodesk_Civil_2015_R1_Spanish_Win_64bit_DLM.sfx.exe"		, 3 , DIR_FS_AUTODESCK2015	, DIR_PC_AUTOSESCK2015 	, " -s2 "	, 0, 0, 0, 0,
									"Unity              "   , "UnitySetup64-5.2.1f1.exe"                , 3 , DIR_FS_UNITY5         , DIR_PC_UNITY5         , " /S "                                        , 0, 0, 0, 0,
									"Blender            "	, " "                                       , 3 , DIR_FS_BLENDER		, DIR_PC_BLENDER		, "msiexec.exe /i blender-2.76-rc1-win64.msi /qb  /NORESTART"										, 0, 0, 0, 0,
									"sublime text 2.0   "   , "Sublime Text 2.0.2 x64 Setup.exe"        , 3 , DIR_FS_SUBLIME        , DIR_PC_SUBLIME        , "/silent /norestart"                          , 0, 0, 0, 0,
									"SAP                "	, "SAPGUI_740C1P4_LITE.exe" 				, 3 , DIR_FS_SAP    		, DIR_PC_SAP			, " /p:SAP_personalizado /Silent "				, 0, 0, 0, 0,	
									"JDK-Java           "   , "jdk"										, 3 , DIR_FS_PUBLICO		, DIR_PC_PUBLICO		, "	/s "										, 0, 0, 0, 0,
									"Genimotion 2.4.0   "   , "genymotion-2.4.0.exe"					, 3 , DIR_FS_GENIMOTION     , DIR_PC_GENIMOTION     , " /silent "									, 0, 0, 0, 0,
									"Eclipse            "   , " "										, 3 , DIR_FS_ECLIPSE        , DIR_PC_ECLIPSE        , " C: & cd C:\\eclipse & copy eclipse.lnk C:\\Users\\Public\\Desktop"	, 0, 0, 0, 0,
									"Project 2013       "   , " "										, 3 , DIR_FS_PROJECT	    , DIR_PC_PROJECT        , "  setup.exe /Config  \\\"C:\\Temp\\instalacion silenciosa\\auxiliar\\project2013\\Config.xml\""		, 0, 0, 0, 0,
								};
								
								
								
#endif
