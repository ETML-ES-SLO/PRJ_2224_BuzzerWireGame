#ifndef Mc32Gest_RS232_H
#define Mc32Gest_RS232_H
/*--------------------------------------------------------*/
// Mc32Gest_RS232.h
/*--------------------------------------------------------*/
//	Description :	emission et reception sp�cialis�e
//			        pour TP2 2016-2017
//
//	Auteur 		: 	C. HUBER
//
//	Version		:	V1.3
//	Compilateur	:	XC32 V1.42 + Harmony 1.08
//
/*--------------------------------------------------------*/

#include <stdint.h>
#include "GesFifoTh32.h"
//#include "gestPWM.h"

/*--------------------------------------------------------*/
// D�finition des fonctions prototypes
/*--------------------------------------------------------*/

// prototypes des fonctions
void InitFifoComm(void);
bool GetMessage(uint8_t *data);
void Send_Message(char *buffer/*Message � envoy�*/);
void ClearTb (char *tb, char sizeTb);


// Descripteur des fifos
extern S_fifo descrFifoRX;
extern S_fifo descrFifoTX;

#endif
