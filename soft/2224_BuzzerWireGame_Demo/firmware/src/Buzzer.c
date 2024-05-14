/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include "app.h"
#include "Buzzer.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */

void Melodie(int i)
{
    if (i >= 0 && i < 200)
    {
        SetNoteBuzzer(NOTE_DO);
        DRV_TMR1_Start();
    }
    else if (i >= 200 && i < 400)
    {
        SetNoteBuzzer(NOTE_MI);
        DRV_TMR1_Start();
    }
    else if (i >= 400 && i < 600)
    {
        SetNoteBuzzer(NOTE_SOL);
        DRV_TMR1_Start();
    }
    else if (i >= 600 && i < 800)
    {
        SetNoteBuzzer(NOTE_DO);
        DRV_TMR1_Start();
    }
    else if (i >= 800 && i < 1000)
    {
        SetNoteBuzzer(NOTE_RE);
        DRV_TMR1_Start();
    }
    else if (i >= 1000 && i < 1200)
    {
        SetNoteBuzzer(NOTE_SOL);
        DRV_TMR1_Start();
    }
    else if (i >= 1200 && i < 1400)
    {
        SetNoteBuzzer(NOTE_DO);
        DRV_TMR1_Start();
    }
    else if (i >= 1400 && i < 1600)
    {
        SetNoteBuzzer(NOTE_RE);
        DRV_TMR1_Start();
    }
    else if (i >= 1600 && i < 1800)
    {
        SetNoteBuzzer(NOTE_SOL);
        DRV_TMR1_Start();
    }
    else if (i >= 1800 && i < 2000)
    {
        SetNoteBuzzer(NOTE_DO);
        DRV_TMR1_Start();
    }
    else if (i >= 2000 && i < 2200)
    {
        SetNoteBuzzer(NOTE_MI);
        DRV_TMR1_Start();
    }
    else if (i >= 2200 && i < 2400)
    {
        SetNoteBuzzer(NOTE_SOL);
        DRV_TMR1_Start();
    }
    else if (i >= 2400 && i < 2600)
    {
        SetNoteBuzzer(NOTE_DO);
        DRV_TMR1_Start();
    }
    else if (i >= 2600 && i < 2800)
    {
        SetNoteBuzzer(NOTE_RE);
        DRV_TMR1_Start();
    }
    else if (i >= 2800 && i < 2950)
    {
        SetNoteBuzzer(NOTE_SOL);
        DRV_TMR1_Start();
    }
    else if (i >= 2950)
    {
        DRV_TMR1_Stop();
    }
}

void MelodieLoose(int i)
{
    if (i >= 0 && i < 200)
    {
        SetNoteBuzzer(NOTE_SI);
        DRV_TMR1_Start();
    }
    else if (i >= 200 && i < 400)
    {
        SetNoteBuzzer(NOTE_LA);
        DRV_TMR1_Start();
    }
    else if (i >= 400 && i < 600)
    {
        SetNoteBuzzer(NOTE_SOL);
        DRV_TMR1_Start();
    }
    else if (i >= 600 && i < 800)
    {
        SetNoteBuzzer(NOTE_FA);
        DRV_TMR1_Start();
    }
    else if (i >= 800 && i < 1000)
    {
        SetNoteBuzzer(NOTE_MI);
        DRV_TMR1_Start();
    }
    else if (i >= 1000 && i < 1200)
    {
        SetNoteBuzzer(NOTE_RE);
        DRV_TMR1_Start();
    }
    else if (i >= 1200 && i < 1400)
    {
        SetNoteBuzzer(NOTE_DO);
        DRV_TMR1_Start();
    }
    else if (i >= 1400 && i < 1600)
    {
        SetNoteBuzzer(NOTE_SI);
        DRV_TMR1_Start();
    }
    else if (i >= 1600 && i < 1800)
    {
        SetNoteBuzzer(NOTE_LA);
        DRV_TMR1_Start();
    }
    else if (i >= 1800 && i < 2000)
    {
        SetNoteBuzzer(NOTE_SOL);
        DRV_TMR1_Start();
    }
    else if (i >= 2000 && i < 2200)
    {
        SetNoteBuzzer(NOTE_FA);
        DRV_TMR1_Start();
    }
    else if (i >= 2200 && i < 2400)
    {
        SetNoteBuzzer(NOTE_MI);
        DRV_TMR1_Start();
    }
    else if (i >= 2400 && i < 2600)
    {
        SetNoteBuzzer(NOTE_RE);
        DRV_TMR1_Start();
    }
    else if (i >= 2600 && i < 2800)
    {
        SetNoteBuzzer(NOTE_DO);
        DRV_TMR1_Start();
    }
    else if (i == 2800)
    {
        DRV_TMR1_Stop();
    }
}

void SetNoteBuzzer (APP_NOTES newNotes)
{   
    DRV_TMR1_Stop(); 
    switch (newNotes)
    {
        case NOTE_DO:
            PLIB_TMR_Period16BitSet(TMR_ID_2, DO);
            break;
            
        case NOTE_RE:
            PLIB_TMR_Period16BitSet(TMR_ID_2, RE);
            break;
            
        case NOTE_MI:
            PLIB_TMR_Period16BitSet(TMR_ID_2, MI);
            break;
            
        case NOTE_FA:
            PLIB_TMR_Period16BitSet(TMR_ID_2, FA);
            break;
            
        case NOTE_SOL:
            PLIB_TMR_Period16BitSet(TMR_ID_2, SOL);
            break;
            
        case NOTE_LA:
            PLIB_TMR_Period16BitSet(TMR_ID_2, LA);
            break;    
            
        case NOTE_SI:
            PLIB_TMR_Period16BitSet(TMR_ID_2, SI);
            break;          
    }
   
}
/* *****************************************************************************
 End of File
 */
