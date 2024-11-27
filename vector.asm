section .text
    bits 64
    default rel
    global calculate_distance

calculate_distance:
    ; Windows x64 calling convention:
    ; rcx = n (number of points)
    ; rdx = x1 array pointer
    ; r8  = x2 array pointer
    ; r9  = y1 array pointer
    ; [rsp+40] = y2 array pointer
    ; [rsp+48] = z array pointer
    
    push rbp
    mov rbp, rsp
    
    ; We need to allocate shadow space (32 bytes) for Windows x64
    sub rsp, 64  ; 32 bytes shadow space + 32 bytes for local variables
    
    ; Save non-volatile registers we'll use
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    
    ; Save parameters we need from stack
    mov rsi, [rbp+48]    ; y2 array pointer
    mov rdi, [rbp+56]    ; z array pointer
    
    ; Initialize loop counter
    xor rbx, rbx        ; rbx = 0 (loop counter)
    
.loop:
    ; Check if we've processed all points
    cmp rbx, rcx
    jge .done
    
    ; Calculate index offset (rbx * 4 for float arrays)
    mov r12, rbx
    shl r12, 2          ; multiply by 4
    
    ; Load x1[i] and x2[i]
    movss xmm0, [rdx + r12]  ; x1[i]
    movss xmm1, [r8 + r12]   ; x2[i]
    
    ; Load y1[i] and y2[i]
    movss xmm2, [r9 + r12]   ; y1[i]
    movss xmm3, [rsi + r12]  ; y2[i]
    
    ; Calculate (x2-x1)
    subss xmm1, xmm0         ; xmm1 = x2[i] - x1[i]
    
    ; Calculate (y2-y1)
    subss xmm3, xmm2         ; xmm3 = y2[i] - y1[i]
    
    ; Square the differences
    mulss xmm1, xmm1         ; (x2-x1)^2
    mulss xmm3, xmm3         ; (y2-y1)^2
    
    ; Add the squares
    addss xmm1, xmm3         ; (x2-x1)^2 + (y2-y1)^2
    
    ; Calculate square root
    sqrtss xmm0, xmm1
    
    ; Store result in z[i]
    movss [rdi + r12], xmm0
    
    ; Increment counter and continue loop
    inc rbx
    jmp .loop
    
.done:
    ; Restore non-volatile registers
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    
    ; Clean up stack frame
    mov rsp, rbp
    pop rbp
    ret