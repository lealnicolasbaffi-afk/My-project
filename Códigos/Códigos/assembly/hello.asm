bits 64
default rel

global main
extern puts
extern ExitProcess

section .data
    message db "Hello, World!", 0

section .text
main:
    ; Reserva espaço na pilha (Shadow Space exigido pela convenção do Windows x64)
    sub rsp, 40

    ; Passa o endereço da mensagem para o primeiro argumento (RCX no Windows x64)
    lea rcx, [message]
    call puts

    ; Limpa a pilha e encerra a execução
    xor ecx, ecx
    call ExitProcess