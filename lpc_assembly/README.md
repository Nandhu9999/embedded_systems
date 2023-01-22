# Assembly Notes

## ARM Instruction Format

MNEUMONIC{S}{condition} {Rd}, {Operand1}, {Operand2}
 - {S} : optional suffix
      * example: ADDS, 
      * ADDS ensures the carry gets saved because normal ADD is unstable in saving the carry value

 - {condition} : needed to be met to execute instruction (GT, LES, EQ, GTE, LESEQ)
 - {Rd} : destination register
 - {Operand1} : first operand
 - {Operand2} : second(flexible) operand. Can be immediate value OR a register with an optional shift


BASIC

```asm
  AREA     somename, CODE, READONLY
                     
  ENTRY                   
start

  MOV R0, #10         ; Move value 10(0x0A) to register 0
  MVN R0, #10         ; negates 10(1010b) -> 5(0101b)
  ADD R0, R0, #1      ; ADD 1 to register 0 value | ADC = addition + carry
  SUB R0, R0, #-1     ; SUBC = subtract + carry
  RSB R0, #20         ; RSB = reverse subtract | RSC = reverse subtract + carry
  ; program loops between 0x08 AND 0X0C
  ; needs stopping condition

stop B stop

  END             		; end of file
```

LOGICAL

```asm

AND R0, #0, #0
ORR ... ... ...
EOR ... ... ...     ; eXclusive OR    
BIC ... ... ...     ; BIt Clear (AND operation on the bits in Rn with the corresponding bits in Operand2)
```

COMPARE

```asm

CMP R0 , R1         ; op1 - op2
CMN ... ...         ; op1 + op2
TST ... ...         ; op1 AND op2
TEQ ... ...         ; op1 EOR op2
```

BARREL SHIFTER

* Why? It is usually used for multiplication and division by 2
* Barrel shifter can shift or rotate data in a single cycle

```asm

LSL R0, R0, #4      ; multiply by 2^4
LSR R0, R0, #2      ; divide by 2^2
ASR R0, R0, #2      ; divides by 2^2 AND preserves sign bit(for 2's complement operations)

; Multiplication using MUL

	MUL R2, R1, R0

; Custom Division Algo
; (no division in ARM)

	MOV R0, #16 ; DIVIDEND
	MOV R1, #4  ; DIVISOR
	MOV R9, #0  ; QUOTIENT
	
WHILE
	CMP R0, #0
	ADDGT R9, R9, #1
	SUBGT R0, R0, R1
	
	BEQ stop
	B WHILE

```

LOAD/STORE

- Single register data transfer

   - BASIC ONES: LDR / STR / LDRM / STRB
	
   - HALF WORDS: LDRH / STRH
	
- Block data transfer (LDM, STM)

- Single data swap (SWP)

```asm

    MOV R0, #4294967295 ; it shouldn't work but it does (range should be 0-255)
    LDR R1, =0x40000000
    STR R0, [R1]

    ; to save data to the next part of the memory address
    LDR R2, [R1]
    STR R2, [R1], #4
    STR R12, [R1]

```

```asm

    LDR R0, [R1], #4      ; R0 = value at R1, R1 = R1 + 4
    LDR R0, [R1, #4]      ; R0 = value at R1 + 4, R1 = R1
    LDR R0, [R1, #4]!     ; R0 = value at R1 + 4, R1 = R1 + 4
```

BRANCH
```asm
    
    B      ; Branch
    BNE    ; Branch Not Equals
    BEQ    ; Branch Equals
    
    BL     ; Branch Link
    BX     ; Branch Exchange
    BLX    ; Branch Link Exchange

```

## DATA
```asm

  AREA data1, DATA, READONLY
	  
	numARR DCD 1,2,3,4        ; Define Constant Data
	strARR DCB "DEFINE BYTE"  ; string array

  AREA RESET, CODE, READONLY
                     
  ENTRY                   
start

    LDR R1, =numARR
    LDR R2, =strARR

    LDR R3,[R1]
    LDRB R4,[R2]

stop B stop

    END
	  
   
```


