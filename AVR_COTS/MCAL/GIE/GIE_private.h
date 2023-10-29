#ifndef GIE_PRIVATE_H
#define GIE_PRIVATE_H 

#define     SREG        *((volatile u8 *)0x5F)

#define     SREG_I_BIT       7
#define     SREG_T_BIT       6
#define     SREG_H_BIT       5
#define     SREG_S_BIT       4
#define     SREG_V_BIT       3
#define     SREG_N_BIT       2
#define     SREG_Z_BIT       1
#define     SREG_C_BIT       0

#endif