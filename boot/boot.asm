[bits 16]
[org 0x7c00]

start:
    mov ax, 0x3
    int 0x10    ; Set video mode
    
    mov si, msg
    call print_string
    
    ; Load kernel
    mov ah, 0x02
    mov al, 15   ; Số sector cần đọc
    mov ch, 0    ; Cylinder
    mov cl, 2    ; Sector bắt đầu
    mov dh, 0    ; Head
    mov bx, 0x1000
    mov es, bx
    mov bx, 0x0
    int 0x13
    
    jmp 0x1000:0x0  ; Nhảy đến kernel

print_string:
    lodsb
    or al, al
    jz .done
    mov ah, 0x0e
    int 0x10
    jmp print_string
.done:
    ret

msg db "Booting Quadratic OS...", 0

times 510-($-$$) db 0
dw 0xaa55