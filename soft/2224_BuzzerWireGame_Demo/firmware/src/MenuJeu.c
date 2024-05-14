// Tp3  manipulation MenuGen avec PEC12
// C. HUBER  10/02/2015 pour SLO2 2014-2015
// Fichier MenuGen.c
// Gestion du menu  du générateur
// Traitement cyclique à 10 ms

#include <stdint.h>                   
#include <stdbool.h>
#include "MenuJeu.h"
#include "app.h" 
#include "Jeux.h"



MENU_JEUX modeJeu;
E_Menu_State menuState = Main_Menu;
E_Menu_State menuAffichage = Main_Menu;
int mode;
static char cursor[2] = {NAVIGATION, BLANK};

// Initialisation du menu et des paramètres
void MENU_Initialize()
{
    lcd_init();
    lcd_bl_on();
    lcd_gotoxy(1,1);
    printf_lcd("BuzzerWireGame");
    lcd_gotoxy(1,2);
    printf_lcd("Santiago Valiante");
    mode = NORMAL;
}

// Execution du menu, appel cyclique depuis l'application
void MENU_Execute()
{
    static int flag = TRUE;
    static uint8_t position = 0;
    
    //uint8_t i;
    
    // =========================================================================
    //                           Gestion du menu
    // =========================================================================
    switch(menuState)
    {
        // ===========================================================
        //                      Menu principal
        // ===========================================================
        case Main_Menu:
        
            // ===========================================
            //      Position du curseur avec l'encodeur
            // ===========================================
            // Incrementation du curseur (Descendre le curseur)
            // si il n'est pas dans la derniere ligne
            if((Pec12IsPlus()== 1) && (position < 1))
            {
                cursor[position + 1] = cursor[position];
                cursor[position]=BLANK;
                position++;
                Pec12ClearPlus();
                flag = TRUE;
            }
            // Reset le flag si le curseur est dans la derniere ligne
            else
            {
                Pec12ClearPlus();
            }
            // Decrementation du curseur (monter le curseur)
            // si il n'est pas dans la premiere ligne
            if((Pec12IsMinus() == 1) && (position > 0))
            {
                cursor[position - 1] = cursor[position];
                cursor[position]=BLANK;
                position--;
                Pec12ClearMinus();
                flag = TRUE;
            }
            // Reset le flag si le curseur est dans la premiere ligne
            else
            {
                Pec12ClearMinus();
            }
            // ===========================================
            //            Bouton de selection
            // ===========================================
            if((Pec12.OK == TRUE))
            {
                if(position == 1)
                {
                    menuState = Mode_Jeu;
                    menuAffichage = Mode_Jeu;
                }
                else
                {
                    menuState = Play;
                    menuAffichage = Play;
                }
                lcd_ClearLine(2); 
                flag = TRUE;
                Pec12ClearOK();
            }
            break;
        // ===========================================================
        //               Menu Selection du Mode de Jeu
        // ===========================================================
        case Mode_Jeu:
            // ===========================================
            //              Changement de Mode
            // ===========================================
            // Incrementation du curseur (Descendre le curseur)
            // si il n'est pas dans la derniere ligne
            if((Pec12IsPlus()== 1) && (mode < 2))
            {
                mode++;
                Pec12ClearPlus();
                flag = TRUE;
            }
            // Reset le flag si le curseur est dans la derniere ligne
            else
            {
                Pec12ClearPlus();
            }
            // Decrementation du curseur (monter le curseur)
            // si il n'est pas dans la premiere ligne
            if((Pec12IsMinus() == 1) && (mode > 0))
            {
                mode--;
                Pec12ClearMinus();
                flag = TRUE;
            }
            // Reset le flag si le curseur est dans la premiere ligne
            else
            {
                Pec12ClearMinus();
            }
            // ===========================================
            //            Bouton de selection
            // ===========================================
            if(Pec12.OK == TRUE)
            {

                menuState = Main_Menu;
                menuAffichage = Main_Menu;
                flag = TRUE;
                lcd_ClearLine(3);
                Pec12ClearOK();
            }
             break;
             
        case Play:
             //Ne rien faire
             break;                  
    }
    // =========================================================================
    //                     Mise a jour des parametres d'affichages
    // =========================================================================
    switch(menuAffichage)
    {
        case Main_Menu:
            if (flag == TRUE)
            {
                lcd_ClearLine(1);
                lcd_ClearLine(2);                
                lcd_gotoxy(1,2);
                printf_lcd("%cMode: ", cursor[0]);
                lcd_gotoxy(8,2);
                LcdAffichageMode();
                lcd_gotoxy(1,3);
                printf_lcd("%cJOUER",cursor[1]);
                lcd_ClearLine(4);
                flag = FALSE;
            }
            break;
        
        case Mode_Jeu:
            if (flag == TRUE)
            {               
                lcd_ClearLine(3);
                lcd_gotoxy(1,1);
                printf_lcd("Choix Mode");
                lcd_gotoxy(8,3);
                LcdAffichageMode();
                ChoixMode();
                flag = FALSE;
            }
            
            break;
            
        case Play:
            if (modeJeu.state == MODE_NORMAL)
            {
                if (ModeNormal()== 1)
                {
                    menuAffichage = Main_Menu;
                    menuState = Main_Menu;
                }
            }
            else if (modeJeu.state == MODE_CHRONO)
            {
                
            }
            else if (modeJeu.state == MODE_ONETUCH)
            {
                
            }
            break;
            
        
    }
}

void LcdAffichageMode ()
{
    if (mode == NORMAL)
    {
        printf_lcd("Normal");
    }
    else if (mode == CHRONO)
    {
        printf_lcd("Chrono");
    }
    else if (mode == TUCH)
    {
        printf_lcd("1Tuche");
    }
}

void ChoixMode ()
{
    if (mode == NORMAL)
    {
        modeJeu.state = MODE_NORMAL;
    }
    else if (mode == CHRONO)
    {
        modeJeu.state = MODE_CHRONO;
    }
    else if (mode == TUCH)
    {
        modeJeu.state = MODE_ONETUCH;
    }
}
