# Assembly Notes

## ARM Instruction Format

MNEUMONIC{S}{condition} {Rd}, {Operand1}, {Operand2}
 - {S} : optional suffix
      * example: ADDS, 
      * ADDS ensures the carry gets saved because normal ADD is unstable in saving the carry value

 - {condition} : needed to be met to execute instruction (GT,LES,EQ)
 - {Rd} : destination register
 - {Operand1} : first operand
 - {Operand2} : second(flexible) operand. Can be immediate value OR a register with an optional shift


BASIC

```asm
  AREA     somename, CODE, READONLY
                     
  ENTRY                   
start

  MOV R0, #10         ; Move value 10(0x0A) to register 0
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
; Multiplication using MUL(no division in ARM)

	MUL R2, R1, R0

; Custom Division Algo

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

-Single register data transfer
	* BASIC ONES: LDR / STR / LDRM / STRB
	* HALF WORDS: LDRH / STRH
-Block data transfer (LDM, STM)
-Single data swap (SWP)

```asm

```
