section .text
bits 64
Default rel

global asmfunc
asmfunc:
    mov r15, 0
    mov r14, r8

    L1:
        movsd xmm1, QWORD[rcx+8*r15]
        movsd xmm2, QWORD[rdx+8*r15]

        mulsd xmm1, xmm2
        addsd xmm0, xmm1
        inc r15
        cmp r15, r14
    jnz L1

    movsd QWORD[r9], xmm0

    ret