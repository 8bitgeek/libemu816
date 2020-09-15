#include <dbg816.h>
#include <stdio.h>
#include <string>

dbg816::opcode_t     dbg816::opcode_map[256] = 
{
 	/* 00 */ { "brk", 2 },
	/* 01 */ { "ora", 1 },
	/* 02 */ { "cop", 2 },
	/* 03 */ { "ora", 1 },
	/* 04 */ { "tsb", 1 },
	/* 05 */ { "ora", 1 },
	/* 06 */ { "asl", 1 },
	/* 07 */ { "ora", 1 },
	/* 08 */ { "php", 1 },
	/* 09 */ { "ora", 2 },
	/* 0a */ { "asla", 1 },
	/* 0b */ { "phd", 1 },
	/* 0c */ { "tsb", 1 },
	/* 0d */ { "ora", 1 },
	/* 0e */ { "asl", 1 },
	/* 0f */ { "ora", 1 },

	/* 10 */ { "bpl", 1 },
	/* 11 */ { "ora", 1 },
	/* 12 */ { "ora", 1 },
	/* 13 */ { "ora", 1 },
	/* 14 */ { "trb", 1 },
	/* 15 */ { "ora", 1 },
	/* 16 */ { "asl", 1 },
	/* 17 */ { "ora", 1 },
	/* 18 */ { "clc", 1 },
	/* 19 */ { "ora", 1 },
	/* 1a */ { "inca", 1 },
	/* 1b */ { "tcs", 1 },
	/* 1c */ { "trb", 1 },
	/* 1d */ { "ora", 1 },
	/* 1e */ { "asl", 1 },
	/* 1f */ { "ora", 1 },

	/* 20 */ { "jsr", 1 },
	/* 21 */ { "and", 1 },
	/* 22 */ { "jsl", 1 },
	/* 23 */ { "and", 1 },
	/* 24 */ { "bit", 1 },
	/* 25 */ { "_and", 1 },
	/* 26 */ { "rol", 1 },
	/* 27 */ { "and", 1 },
	/* 28 */ { "plp", 1 },
	/* 29 */ { "and", 2 },
	/* 2a */ { "rola", 1 },
	/* 2b */ { "pld", 1 },
	/* 2c */ { "bit", 1 },
	/* 2d */ { "_and", 1 },
	/* 2e */ { "rol", 1 },
	/* 2f */ { "_and", 1 },

	/* 30 */ { "bmi", 1 },
	/* 31 */ { "_and", 1 },
	/* 32 */ { "_and", 1 },
	/* 33 */ { "_and", 1 },
	/* 34 */ { "bit", 1 },
	/* 35 */ { "_and", 1 },
	/* 36 */ { "rol", 1 },
	/* 37 */ { "_and", 1 },
	/* 38 */ { "sec", 1 },
	/* 39 */ { "_and", 1 },
	/* 3a */ { "deca", 1 },
	/* 3b */ { "tsc", 1 },
	/* 3c */ { "bit", 1 },
	/* 3d */ { "_and", 1 },
	/* 3e */ { "rol", 1 },
	/* 3f */ { "_and", 1 },

	/* 40 */ { "rti", 1 },
	/* 41 */ { "eor", 1 },
	/* 42 */ { "wdm", 2 },
	/* 43 */ { "eor", 1 },
	/* 44 */ { "mvp", 1 },
	/* 45 */ { "eor", 1 },
	/* 46 */ { "lsr", 1 },
	/* 47 */ { "eor", 1 },
	/* 48 */ { "pha", 1 },
	/* 49 */ { "eor", 2 },
	/* 4a */ { "lsra", 1 },
	/* 4b */ { "phk", 1 },
	/* 4c */ { "jmp", 1 },
	/* 4d */ { "eor", 1 },
	/* 4e */ { "lsr", 1 },
	/* 4f */ { "eor", 1 },

	/* 50 */ { "bvc", 1 },
	/* 51 */ { "eor", 1 },
	/* 52 */ { "eor", 1 },
	/* 53 */ { "eor", 1 },
	/* 54 */ { "mvn", 1 },
	/* 55 */ { "eor", 1 },
	/* 56 */ { "lsr", 1 },
	/* 57 */ { "eor", 1 },
	/* 58 */ { "cli", 1 },
	/* 59 */ { "eor", 1 },
	/* 5a */ { "phy", 1 },
	/* 5b */ { "tcd", 1 },
	/* 5c */ { "jmp", 1 },
	/* 5d */ { "eor", 1 },
	/* 5e */ { "lsr", 1 },
	/* 5f */ { "eor", 1 },

	/* 60 */ { "rts", 1 },
	/* 61 */ { "adc", 1 },
	/* 62 */ { "per", 1 },
	/* 63 */ { "adc", 1 },
	/* 64 */ { "stz", 1 },
	/* 65 */ { "adc", 1 },
	/* 66 */ { "ror", 1 },
	/* 67 */ { "adc", 1 },
	/* 68 */ { "pla", 1 },
	/* 69 */ { "adc", 2 },
	/* 6a */ { "rora", 1 },
	/* 6b */ { "rtl", 1 },
	/* 6c */ { "jmp", 1 },
	/* 6d */ { "adc", 1 },
	/* 6e */ { "ror", 1 },
	/* 6f */ { "adc", 1 },

	/* 70 */ { "bvs", 1 },
	/* 71 */ { "adc", 1 },
	/* 72 */ { "adc", 1 },
	/* 73 */ { "adc", 1 },
	/* 74 */ { "stz", 1 },
	/* 75 */ { "adc", 1 },
	/* 76 */ { "ror", 1 },
	/* 77 */ { "adc", 1 },
	/* 78 */ { "sei", 1 },
	/* 79 */ { "adc", 1 },
	/* 7a */ { "ply", 1 },
	/* 7b */ { "tdc", 1 },
	/* 7c */ { "jmp", 1 },
	/* 7d */ { "adc", 1 },
	/* 7e */ { "ror", 1 },
	/* 7f */ { "adc", 1 },

	/* 80 */ { "bra", 1 },
	/* 81 */ { "sta", 1 },
	/* 82 */ { "brl", 1 },
	/* 83 */ { "sta", 1 },
	/* 84 */ { "sty", 1 },
	/* 85 */ { "sta", 1 },
	/* 86 */ { "stx", 1 },
	/* 87 */ { "sta", 1 },
	/* 88 */ { "dey", 1 },
	/* 89 */ { "biti", 1 },
	/* 8a */ { "txa", 1 },
	/* 8b */ { "phb", 1 },
	/* 8c */ { "sty", 1 },
	/* 8d */ { "sta", 1 },
	/* 8e */ { "stx", 1 },
	/* 8f */ { "sta", 1 },

	/* 90 */ { "bcc", 1 },
	/* 91 */ { "sta", 1 },
	/* 92 */ { "sta", 1 },
	/* 93 */ { "sta", 1 },
	/* 94 */ { "sty", 1 },
	/* 95 */ { "sta", 1 },
	/* 96 */ { "stx", 1 },
	/* 97 */ { "sta", 1 },
	/* 98 */ { "tya", 1 },
	/* 99 */ { "sta", 1 },
	/* 9a */ { "txs", 1 },
	/* 9b */ { "txy", 1 },
	/* 9c */ { "stz", 1 },
	/* 9d */ { "sta", 1 },
	/* 9e */ { "stz", 1 },
	/* 9f */ { "sta", 1 },

	/* a0 */ { "ldy", 1 },
	/* a1 */ { "lda", 1 },
	/* a2 */ { "ldx", 1 },
	/* a3 */ { "lda", 1 },
	/* a4 */ { "ldy", 1 },
	/* a5 */ { "lda", 1 },
	/* a6 */ { "ldx", 1 },
	/* a7 */ { "lda", 1 },
	/* a8 */ { "tay", 1 },
	/* a9 */ { "lda", 2 },
	/* aa */ { "tax", 1 },
	/* ab */ { "plb", 1 },
	/* ac */ { "ldy", 1 },
	/* ad */ { "lda", 1 },
	/* ae */ { "ldx", 1 },
	/* af */ { "lda", 1 },

	/* b0 */ { "bcs", 1 },
	/* b1 */ { "lda", 1 },
	/* b2 */ { "lda", 1 },
	/* b3 */ { "lda", 1 },
	/* b4 */ { "ldy", 1 },
	/* b5 */ { "lda", 1 },
	/* b6 */ { "ldx", 1 },
	/* b7 */ { "lda", 1 },
	/* b8 */ { "clv", 1 },
	/* b9 */ { "lda", 1 },
	/* ba */ { "tsx", 1 },
	/* bb */ { "tyx", 1 },
	/* bc */ { "ldy", 1 },
	/* bd */ { "lda", 1 },
	/* be */ { "ldx", 1 },
	/* bf */ { "lda", 1 },

	/* c0 */ { "cpy", 1 },
	/* c1 */ { "cmp", 1 },
	/* c2 */ { "rep", 2 },
	/* c3 */ { "cmp", 1 },
	/* c4 */ { "cpy", 1 },
	/* c5 */ { "cmp", 1 },
	/* c6 */ { "dec", 1 },
	/* c7 */ { "cmp", 1 },
	/* c8 */ { "iny", 1 },
	/* c9 */ { "cmp", 2 },
	/* ca */ { "dex", 1 },
	/* cb */ { "wai", 1 },
	/* cc */ { "cpy", 1 },
	/* cd */ { "cmp", 1 },
	/* ce */ { "dec", 1 },
	/* cf */ { "cmp", 1 },

	/* d0 */ { "bne", 1 },
	/* d1 */ { "cmp", 1 },
	/* d2 */ { "cmp", 1 },
	/* d3 */ { "cmp", 1 },
	/* d4 */ { "pei", 1 },
	/* d5 */ { "cmp", 1 },
	/* d6 */ { "dec", 1 },
	/* d7 */ { "cmp", 1 },
	/* d8 */ { "cld", 1 },
	/* d9 */ { "cmp", 1 },
	/* da */ { "phx", 1 },
	/* db */ { "stp", 1 },
	/* dc */ { "jmp", 1 },
	/* dd */ { "cmp", 1 },
	/* de */ { "dec", 1 },
	/* df */ { "cmp", 1 },

	/* e0 */ { "cpx", 1 },
	/* e1 */ { "sbc", 1 },
	/* e2 */ { "sep", 2 },
	/* e3 */ { "sbc", 1 },
	/* e4 */ { "cpx", 1 },
	/* e5 */ { "sbc", 1 },
	/* e6 */ { "inc", 1 },
	/* e7 */ { "sbc", 1 },
	/* e8 */ { "inx", 1 },
	/* e9 */ { "sbc", 2 },
	/* ea */ { "nop", 1 },
	/* eb */ { "xba", 1 },
	/* ec */ { "cpx", 1 },
	/* ed */ { "sbc", 1 },
	/* ee */ { "inc", 1 },
	/* ef */ { "sbc", 1 },

	/* f0 */ { "beq", 1 },
	/* f1 */ { "sbc", 1 },
	/* f2 */ { "sbc", 1 },
	/* f3 */ { "sbc", 1 },
	/* f4 */ { "pea", 1 },
	/* f5 */ { "sbc", 1 },
	/* f6 */ { "inc", 1 },
	/* f7 */ { "sbc", 1 },
	/* f8 */ { "sed", 1 },
	/* f9 */ { "sbc", 1 },
	/* fa */ { "plx", 1 },
	/* fb */ { "xce", 1 },
	/* fc */ { "jsr", 1 },
	/* fd */ { "sbc", 1 },
	/* fe */ { "inc", 1 },
	/* ff */ { "sbc", 1 }
};

using namespace std;
#define inherited vm816

dbg816::dbg816()
{ 
    home();
    clear();
}

dbg816::~dbg816()
{ 
}

void dbg816::step()
{
    dump();
    inherited::step();
}

void dbg816::dump()
{
    uint8_t op = inherited::load8(join(pbr, pc));
    home();
    printf( "CK:%08X:\n", cycles() );
    printf( "F:%c%c%c%c%c%c%c%c\n",
            p.f_n ? 'N' : ' ',
            p.f_v ? 'V' : ' ',
            p.f_m ? 'M' : ' ',
            p.f_x ? 'X' : ' ',
            p.f_d ? 'D' : ' ',
            p.f_i ? 'I' : ' ',
            p.f_z ? 'Z' : ' ',
            p.f_c ? 'C' : ' '
            );
    printf( "PC:%02X:%04X OP:%02X [%s]\n", pbr, pc, op, opcode_map[op].op );
    printf( "SP:%02X:%04X  D:%02X\n", 0, sp.w, inherited::load8(sp.w) );
    printf( "DR:%02X:%04X\n", 0, dp.w );
    printf( " Y:%02X:%04X\n", dbr, y.w );
    printf( " X:%02X:%04X\n", dbr, x.w );
}

void dbg816::csi()
{
    printf("%c[",0x1B);
}

void dbg816::home()
{
    csi();
    printf("1;1H");
}

void dbg816::clear()
{
    csi();
    putchar('J');
}

void dbg816::move(uint8_t x, uint8_t y)
{
    x+=1;
    y+=1;
    csi();
    printf("%d;%dH",y,x);
}


uint8_t dbg816::load8(emu816_addr_t ea)
{
    uint8_t data = inherited::load8(ea);
    move(0,7);
    printf( "RD:%02X:%04X  D:%02X\n",ea>>16,ea&0xFFFF,data );
    return data;
}

void dbg816::store8(emu816_addr_t ea, uint8_t data)
{
    move(0,8);
    printf( "WR:%02X:%04X  D:%02X\n",ea>>16,ea&0xFFFF,data );
    inherited::store8(ea,data);
}


