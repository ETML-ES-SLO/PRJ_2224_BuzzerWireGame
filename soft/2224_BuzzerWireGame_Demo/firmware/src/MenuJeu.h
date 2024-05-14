#ifndef MenuGen_h
#define MenuGen_h

// Tp3  manipulation MenuGen avec PEC12
// C. HUBER  03.02.2016
// Fichier MenuGen.h
// Gestion du menu  du générateur
// Traitement cyclique à 1 ms du Pec12


#include <stdbool.h>
#include <stdint.h>

#include "Mc32DriverLcd.h"

#include "GesPec12.h"


#define TRUE 1
#define FALSE 0

//Mode de jeu
#define NORMAL 0
#define CHRONO 1
#define TUCH   2

/*---- LCD Symbol customisation ----*/
// Separation caracter between option and value "Frequ [Hz] X 1000"
#define SEPARATOR 246	// =>
//#define SEPARATOR 61	// = (Specification sheet)


// Cursor for navigation
#define NAVIGATION 126	// ->
//#define NAVIGATION 42	// * (Specification sheet)

#define REMOTE_SYMBOL 206

#define BLANK 32	//Blank caracter DO NOT CHANGE

#define CONFIRM_TIME 200 //Time out in [10ms] when there's no activity



// Enumeration pour la machine d'etat de la gestion du menu
typedef enum{Main_Menu, Mode_Jeu, Play}E_Menu_State;

// Enumeration pour la machine d'etat de la gestion du sous-menu (mode)
typedef enum{MODE_CHRONO, MODE_ONETUCH, MODE_NORMAL}E_ModeJeu_State;

typedef struct
{
    /* The application's current state */
    E_ModeJeu_State state;
    int timesec;
    int timemin;
    //APP_NOTES notes;
    /* TODO: Define any additional data used by the application. */

} MENU_JEUX;


S_Pec12_Descriptor Pec12;

void ChoixMode();

void MENU_Initialize();

void MENU_Execute();

void LcdAffichageMode ();


#endif




  
   







