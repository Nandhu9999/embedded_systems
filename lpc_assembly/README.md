# Assembly Notes

BASIC

```asm
  AREA     RESET, CODE, READONLY
                     
  ENTRY                   
start
  MOV R0, #10   		; Move value 10(0x0A) to register 0
  ADD R0, R0, #1      ; ADD 1 to register 0 value | ADC = addition + carry
  SUB R0, R0, #-1     ; SUBC = subtract + carry
  RSB R0, #20			; RSB = reverse subtract | RSC = reverse subtract + carry
  ; program loops between 0x08 AND 0X0C
  ; needs stopping condition

stop B stop

  END             		; end of file
```
