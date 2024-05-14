/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _GEST_PORT_H    /* Guard against multiple inclusion */
#define _GEST_PORT_H 


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

//#define BSP_OSC_FREQUENCY 8000000   //8MHz


/*--------------------------------------------------------------------------------*/
// PEC12
/*--------------------------------------------------------------------------------*/

#define PEC12_A     PORTBbits.RB14
#define PEC12_B     PORTBbits.RB13
#define PEC12_PB    PORTBbits.RB15

/*--------------------------------------------------------------------------------*/
// ENTREE DU JEU
/*--------------------------------------------------------------------------------*/

#define PIN_START   PORTCbits.RC4
#define PIN_STOP    PORTCbits.RC5
#define PIN_WIRE    PORTCbits.RC6

/*--------------------------------------------------------------------------------*/
// LCD
/*--------------------------------------------------------------------------------*/
//On écrit dans le latch pour éviter les problèmes de R/W
#define LCD_RS_W       LATBbits.LATB0
#define LCD_RW_W       LATBbits.LATB1
#define LCD_E_W        LATBbits.LATB2
#define LCD_BL_W       LATBbits.LATB8
#define LCD_DB4_W      LATBbits.LATB3
#define LCD_DB5_W      LATBbits.LATB4
#define LCD_DB6_W      LATBbits.LATB5
#define LCD_DB7_W      LATBbits.LATB7

//On lit directement sur le port, sinon on obtient la valeur
//précédemment écrite dans le latch!!
#define LCD_RS_R       PORTBbits.RB0
#define LCD_RW_R       PORTBbits.RB1
#define LCD_E_R        PORTBbits.RB2
#define LCD_BL_R       PORTBbits.RB8
#define LCD_DB4_R      PORTBbits.RB3
#define LCD_DB5_R      PORTBbits.RB4
#define LCD_DB6_R      PORTBbits.RB5
#define LCD_DB7_R      PORTBbits.RB7

#define LCD_RS_T       TRISBbits.TRISB0
#define LCD_RW_T       TRISBbits.TRISB1
#define LCD_E_T        TRISBbits.TRISB2 
#define LCD_BL_T       TRISBbits.TRISB8
#define LCD_DB4_T      TRISBbits.TRISB3
#define LCD_DB5_T      TRISBbits.TRISB4
#define LCD_DB6_T      TRISBbits.TRISB5
#define LCD_DB7_T      TRISBbits.TRISB7

// Definitions pour fonctions PLIB_PORTS
#define LCD_RS_PORT    0x01
#define LCD_RS_BIT     0
#define LCD_RW_PORT    0x01
#define LCD_RW_BIT     1
#define LCD_E_PORT     0x01
#define LCD_E_BIT      2
#define LCD_BL_PORT    0x01
#define LCD_BL_BIT     3
#define LCD_DB4_PORT   0x01
#define LCD_DB4_BIT    4
#define LCD_DB5_PORT   0x01
#define LCD_DB5_BIT    5
#define LCD_DB6_PORT   0x01
#define LCD_DB6_BIT    6
#define LCD_DB7_PORT   0x01
#define LCD_DB7_BIT    7
  


    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************



    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    

#endif /* _GEST_PORT_H */

/* *****************************************************************************
 End of File
 */
