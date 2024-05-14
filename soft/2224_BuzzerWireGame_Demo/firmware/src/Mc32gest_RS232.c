// Mc32Gest_RS232.C
// Canevas manipulatio TP2 RS232 SLO2 2017-18
// Fonctions d'émission et de réception des message
// CHR 20.12.2016 ajout traitement int error
// CHR 22.12.2016 evolution des marquers observation int Usart
// SCA 03.01.2018 nettoyé réponse interrupt pour ne laisser que les 3 ifs

#include <xc.h>
#include <sys/attribs.h>
#include "system_definitions.h"
// Ajout CHR
#include <GenericTypeDefs.h>
#include "app.h"
#include "GesFifoTh32.h"
#include "Mc32gest_RS232.h"



// Definition pour les messages
#define MESS_SIZE  100
// avec int8_t besoin -86 au lieu de 0xAA
//#define STX_code  (-86)




// Struct pour émission des messages
//StruMess TxMess;
// Struct pour réception des messages
//StruMess RxMess;

// Declaration des FIFO pour réception et émission
#define FIFO_RX_SIZE ( MESS_SIZE + 1)  // 4 messages
#define FIFO_TX_SIZE ( MESS_SIZE + 1)  // 4 messages

int8_t fifoRX[FIFO_RX_SIZE];
// Declaration du descripteur du FIFO de réception
S_fifo descrFifoRX;


int8_t fifoTX[FIFO_TX_SIZE];
// Declaration du descripteur du FIFO d'émission
S_fifo descrFifoTX;


// Initialisation de la communication sérielle
void InitFifoComm(void)
{    
    // Initialisation du fifo de réception
    InitFifo ( &descrFifoRX, FIFO_RX_SIZE, fifoRX, 0 );
    // Initialisation du fifo d'émission
    InitFifo ( &descrFifoTX, FIFO_TX_SIZE, fifoTX, 0 );   
} // InitComm


 


//format de la trame : <MOVE><1><2> <STATUE><1>
bool GetMessage(uint8_t *data)
{
    int8_t NB_car_RX;
    int8_t count = 0;
    static char RMess[100];
    static int8_t MessWriteIndex = 0;
    
    //*data = 0xFF;
    bool statue = false;
    NB_car_RX = GetReadSize(&descrFifoRX);
    // On remplie un tableau avec les valeur reçu
    for (count=0;count<NB_car_RX; count++)
    {
        GetCharFromFifo(&descrFifoRX, (int8_t*)&RMess[MessWriteIndex]);
        MessWriteIndex++;
    }
    // On regarde le minimum de car reçu besoin pour traduire
    if (MessWriteIndex>=10)
    {   
        if (strchr(RMess,'\r') != NULL || strchr(RMess,'\n')!= NULL)
        {
            RMess[MessWriteIndex]=0; //met fin de chaine
            MessWriteIndex = 0;   
            // On regarde si nouveau reçu une commande move
            if(strstr(RMess,"MOVE><1>")!= NULL)
            {
                *data = atoi((strstr(RMess,"MOVE")+9));
            }
            // On regarde si nouveau reçu une commande statue
            if(strstr(RMess,"STATUE><1>")!= NULL)
            {
                statue = true;
            }
        ClearTb (&RMess[0],  15);       
        }//si fin de chaine trouvée
        
    }
    return (statue);
} // GetMessage

void ClearTb (char *tb, char sizeTb){
    int i;
    for(i = 0; i < sizeTb; i++){
        *tb = 0;
        tb ++;
    }
}


void Send_Message(char *buffer/*Message à envoyé*/)
{
    //Reset variable buffer
    int n = 0;
    while ((buffer[n] != 0) && (n<30)) // envoyer tant que pas de fin de chaine mais pas plux de 8 car.
    {   
        while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1)); //attente tx buf. dispo
        //Envoie d'une case du buffer de transmission
        PLIB_USART_TransmitterByteSend(USART_ID_1, buffer[n]);
        //Incrémentation case buffer
        n++;
    }    
}

/*
void __ISR(_UART_1_VECTOR, ipl5AUTO) _IntHandlerDrvUsartInstance0(void)
{   
    USART_ERROR UsartStatus; 
    int8_t c_receive;

    // Is this an Error interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_1_ERROR) &&
                 PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_2_ERROR) ) {
        //Clear pending interrupt 
        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_ERROR);
        // Traitement de l'erreur à la réception.
    }
    // Is this an RX interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_1_RECEIVE) &&
                 PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_1_RECEIVE) ) {

        // Oui Test si erreur parité ou overrun
        UsartStatus = PLIB_USART_ErrorsGet(USART_ID_1);

        if ( (UsartStatus & (USART_ERROR_PARITY |
                             USART_ERROR_FRAMING | USART_ERROR_RECEIVER_OVERRUN)) == 0) {

            while (PLIB_USART_ReceiverDataIsAvailable(USART_ID_1) && GetWriteSpace(&descrFifoRX)>0)
            {
                c_receive= PLIB_USART_ReceiverByteReceive(USART_ID_1);
                PutCharInFifo(&descrFifoRX, c_receive);
            }
            // buffer is empty, clear interrupt flag
            PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_RECEIVE);
        } else {
            // Suppression des erreurs
            // La lecture des erreurs les efface sauf pour overrun
            if ( (UsartStatus & USART_ERROR_RECEIVER_OVERRUN) == USART_ERROR_RECEIVER_OVERRUN) {
                   PLIB_USART_ReceiverOverrunErrorClear(USART_ID_1);
            }
        }        
    } 
    
}
*/



