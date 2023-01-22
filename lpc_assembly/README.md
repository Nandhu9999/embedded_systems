# Assembly Notes

## ARM Instruction Format

MNEUMONIC{S}{condition} {Rd}, {Operand1}, {Operand2}
 - {S} : optional suffix
      * example: ADDS, ADDS ensures the carry gets saved because normal ADD is unstable

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

CMP
CMN
TST
TEQ
```
