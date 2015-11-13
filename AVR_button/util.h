#ifndef _UTIL_H_
#define _UTIL_H_

/**  Bit manipulation  **/
#define SET_BIT(Reg,Bit) 			Reg|=(1<<Bit)
#define CLEAR_BIT(Reg,Bit) 			Reg&=~(1<<Bit)
#define TOGGLE_BIT(Reg,Bit) 		Reg^=(1<<Bit)
#define NOT_BIT(Reg,Bit) 		    Reg=!(1<<Bit)

/**  Nibble manipulation  **/
#define SET_NIBBLE_H(Reg) 			Reg|=(0xF0)
#define CLEAR_NIBBLE_H(Reg) 		Reg&=(0x0F)
#define SET_NIBBLE_L(Reg) 			Reg|=(0x0F)
#define CLEAR_NIBBLE_L(Reg) 		Reg&=(0xF0)
#define SHIFT_NIBBLE_L(Reg)			(Reg<<4)
#define SHIFT_NIBBLE_R(Reg)			(Reg>>4)

#define ASSIGN_NIBBLE_H(Reg,Value) 	do{\
									  Reg&=(0x0F);\
									  Reg|=(Value<<4);\
									  }while(0)
#define ASSIGN_NIBBLE_L(Reg,Value) 	do{\
									  Reg&=(0xF0);\
									  Reg|=(Value&0xF0);\
									  }while(0)
#define ASSIGN_NIBBLE_DH(Reg,Value) 	do{\
									  Reg&=(0x0F);\
									  Reg|=(Value<<4);\
									  }while(0)
#define ASSIGN_NIBBLE_DL(Reg,Value) 	do{\
									  Reg&=(0x0F);\
									  Reg|=(Value);\
									  }while(0)

/**  Register manipulation  **/
#define SET_REG(Reg) 				Reg|=(0xFF)
#define CLEAR_REG(Reg) 				Reg&=(0x00)
#define TOGGLE_REG(Reg)				Reg^=(0xFF)
#define ASSIGN_REG(Reg,Value) 		Reg=Value

/**  Get manipulation  **/
#define GET_BIT(Reg,Bit) 			(Reg>>Bit)&(1)
#define GET_NIBBLE_L(Reg) 			Reg&(0x0F)
#define GET_NIBBLE_H(Reg) 			( (Reg&0xF0) >> 4)

#define GET_NIBBLE_HH(Reg) 			Reg&(0xF0)
#define GET_NIBBLE_LL(Reg)			Reg&(0x0F)
#define SHIFT_NIBBLE_L(Reg)			(Reg<<4)


/*Quick Functions*/
#define TO_DELAY(Value_ms)			_delay_ms(Value_ms)


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
