# libemu816 - A C++ based 65C816 Emulator Library

Forked from https://github.com/andrew-jacobs/emu816

## Compiling

```
make
```

## Running a test

* The contents of 'test' are currently transient, a place holder for unit tests.

```
cd test
./run816 simple.s28
```

## Implementing application memory model

The following virtual methods are provided for application memory and I/O mapping.

* This issue is pending https://github.com/8bitgeek/libemu816/issues/1

```C++
        
        // FIXME - emu816 lib should not know about ROM/RAM and size.
        //         let's refactor this         
        virtual void setMemory (Addr memMask, Addr ramSize, const uint8_t *pROM);
        virtual void setMemory (Addr memMask, Addr ramSize, uint8_t *pRAM, const uint8_t *pROM);

        virtual uint8_t getByte(Addr ea);
        virtual Word getWord(Addr ea);
        virtual Addr getAddr(Addr ea);
        virtual void setByte(Addr ea, uint8_t data);
        virtual void setWord(Addr ea, Word data);
```
