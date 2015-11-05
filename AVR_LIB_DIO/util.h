#ifndef _UTIL_H_
#define _UTIL_H_

/**  Bit manipulation  **/
#define SET_BIT(Reg,Bit) 			Reg|=(1<<Bit)
#define CLEAR_BIT(Reg,Bit) 			Reg&=~(1<<Bit)
#define TOGGLE_BIT(Reg,Bit) 		Reg^=(1<<Bit)

/**  Nibble manipulation  **/
#define SET_NIBBLE_H(Reg) 			Reg|=(0xf0)
#define CLEAR_NIBBLE_H(Reg) 		Reg&=(0x0f)
#define SET_NIBBLE_L(Reg) 			Reg|=(0x0f)
#define CLEAR_NIBBLE_L(Reg) 		Reg&=(0xf0)
#define ASSIGN_NIBBLE_H(Reg,Value) 	do{\
									  Reg&=(0x0f);\
									  Reg|=(Value<<4);\
									  }while(0)
#define ASSIGN_NIBBLE_L(Reg,Value) 	do{\
									  Reg&=(0xf0);\
									  Reg|=(Value);\
									  }while(0)

/**  Register manipulation  **/
#define SET_REG(Reg) 				Reg|=(0xff)
#define CLEAR_REG(Reg) 				Reg&=(0x00)
#define TOGGLE_REG(Reg)				Reg^=(0xFF)
#define ASSIGN_REG(Reg,Value) 		Reg=Value

/**  Get manipulation  **/
#define GET_BIT(Reg,Bit) 			(Reg>>Bit)&(1)
#define GET_NIBBLE_L(Reg) 			Reg&(0x0f)
#define GET_NIBBLE_H(Reg) 			( (Reg&0xf0) >> 4)

/*Initial Conditions*/
#define bit0 1
#define bit1 0
#define bit2 0
#define bit3 1
#define bit4 1
#define bit5 0
#define bit6 1
#define bit7 1

#define REG_VALUE FUN_HELPER(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0)
#define FUN_HELPER(a,b,c,d,e,f,g,h) FUN_CAT(a,b,c,d,e,f,g,h)
#define FUN_CAT(a,b,c,d,e,f,g,h) 0b##a##b##c##d##e##f##g##h 

#endif
