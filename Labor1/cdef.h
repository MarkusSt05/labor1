/********************************************************************
 *
 *  Name:           cdef.h
 *  Beschreibung:   grundlegende Typdefinitionen
 *  Autor:
 *  Erstellung:     23.10.2012
 *
 *  Revisionsliste
 *  Datum       | Autor         | ├änderung
 *  ------------+---------------+--------------------------
 *  23.10.2012  | Altenburg     | Ersterstellung
 *  ------------+---------------+--------------------------
 *
 ********************************************************************/
#ifndef CDEF_H
#define CDEF_H

/**************************************************************************/
/* Definitions                                                            */
/**************************************************************************/
typedef unsigned char byte;        /* vorzeichenlose 8-Bit-Zahl */
typedef unsigned short word;       /* vorzeichenlose 16-Bit-Zahl */
typedef signed char int8;          /* vorzeichenbehaftete 8-Bit-Zahl */
typedef signed short int16;        /* vorzeichenbehaftete 16-Bit-Zahl */
//typedef byte bool;                 /* True/False Aussage */
typedef unsigned long dword;       /* Long-Zahl */
typedef signed long int32;


#define True                1
#define False               0
#define true                1
#define false               0
#define On                  1
#define Off                 0
#define Yes                 1
#define No                  0

#define Bit0    0x01                /* Bit-Definitionen */
#define Bit1    0x02
#define Bit2    0x04
#define Bit3    0x08
#define Bit4    0x10
#define Bit5    0x20
#define Bit6    0x40
#define Bit7    0x80
#define Bit8    (unsigned long)(1 << 8)            /* Bit-Definitionen */
#define Bit9    (unsigned long)(1 << 9)
#define Bit10   (1 << 10)
#define Bit11   (unsigned long)(1 << 11)
#define Bit12   (1 << 12)
#define Bit13   (unsigned long)(1 << 13)
#define Bit14   (1 << 14)
#define Bit15   (unsigned long)(1 << 15)
#define Bit16   (unsigned long)(1 << 16)           /* Bit-Definitionen */
#define Bit17   (unsigned long)(1 << 17)
#define Bit18   (unsigned long)(1 << 18)
#define Bit19   (unsigned long)(1 << 19)
#define Bit20   (unsigned long)(1 << 20)
#define Bit21   (unsigned long)(1 << 21)
#define Bit22   (unsigned long)(1 << 22)
#define Bit23   (unsigned long)(1 << 23)
#define Bit24   (unsigned long)(1 << 24)           /* Bit-Definitionen */
#define Bit25   (unsigned long)(1 << 25)
#define Bit26   (unsigned long)(1 << 26)
#define Bit27   (unsigned long)(1 << 27)
#define Bit28   (unsigned long)(1 << 28)
#define Bit29   (unsigned long)(1 << 29)
#define Bit30   (unsigned long)(1 << 30)
#define Bit31   (unsigned long)(1 << 31)

#define nDirectTFT

//void vDontCheat( void );

#endif
/********************************************************************/

