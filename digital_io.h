/*
* digital_io.h
*
* Created: 5/04/2019 7:27:15 AM
*  Author: liam
*/


#ifndef DIGITAL_IO_H_
#define DIGITAL_IO_H_

#define PINMODE_OUTPUT(DDRx, PIN) ((DDRx) |= (1<<(PIN)))
#define PINMODE_INPUT(DDRx, PIN) ((DDRx) &= ~(1<<(PIN)))
#define DIGITAL_WRITE_HIGH(PORTx, PIN) ((PORTx) |= (1<<(PIN)))
#define DIGITAL_WRITE_LOW(PORTx, PIN) ((PORTx) &= ~(1<<(PIN)))
#define DIGITAL_WRITE_VALUE(PORTx, PIN, VAL) if (VAL) {DIGITAL_WRITE_HIGH(PORTx, PIN);} else {DIGITAL_WRITE_LOW(PORTx, PIN);}
#define DIGITAL_READ(PINx, PIN) (((PINx) & (1<<(PIN)))>>PIN)
#define GET_DIGITAL_WRITE_VALUE(PORTx, PIN) (((PORTx) & (1<<PIN))>>(PIN))


#endif