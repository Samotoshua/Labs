section .data
    fmt_in  db "%lld", 0
    fmt_out db "Sum: %lld", 10, 0

section .bss
    n    resq 1
    temp resq 1

section .text
    global main
    extern scanf, printf, ExitProcess

main:
    ; Зберігаємо регістри (додано r12 для лічильника індексу)
    push rbx
    push rsi
    push rdi
    push r12
    ; Виділяємо 40 байтів, щоб зберегти вирівнювання стека (16-byte alignment)
    sub rsp, 40               

    ; Зчитуємо n
    lea rcx, [rel fmt_in]
    lea rdx, [rel n]
    call scanf

    mov rbx, [rel n]    ; rbx = кількість елементів (n)
    cmp rbx, 0
    jle .exit_program

    mov rsi, 0          ; rsi = max_odd (ініціалізуємо 0, бо натуральні числа > 0)
    mov rdi, -1         ; rdi = min_even (-1 як прапорець, що парних ще не було)
    mov r12, 1          ; r12 = поточний індекс (починаємо з 1)

.read_loop:
    cmp rbx, 0
    jle .print_result

    ; Зчитуємо наступне число
    lea rcx, [rel fmt_in]
    lea rdx, [rel temp]
    call scanf

    mov rax, [rel temp]

    ; Перевіряємо, парний індекс чи непарний
    test r12, 1         ; Побітове І: якщо r12 непарне, результат 1
    jz .is_even         ; Якщо 0 (парне) - стрибаємо до .is_even

.is_odd:
    ; Логіка для непарних індексів (max_odd)
    cmp rax, rsi
    jle .next_iter      ; Якщо поточне <= max_odd, пропускаємо
    mov rsi, rax        ; Інакше оновлюємо max_odd
    jmp .next_iter

.is_even:
    ; Логіка для парних індексів (min_even)
    cmp rdi, -1         ; Якщо це перше парне число, зберігаємо його без порівняння
    je .set_first_even
    cmp rax, rdi
    jge .next_iter      ; Якщо поточне >= min_even, пропускаємо
.set_first_even:
    mov rdi, rax        ; Оновлюємо min_even

.next_iter:
    inc r12             ; Збільшуємо індекс (1, 2, 3...)
    dec rbx             ; Зменшуємо лічильник залишених елементів
    jmp .read_loop

.print_result:
    ; Якщо n = 1, парних елементів не було взагалі (min_even лишився -1)
    cmp rdi, -1
    jne .calc_sum
    mov rdi, 0          ; Вважаємо мінімум відсутніх елементів за 0

.calc_sum:
    ; Обчислюємо фінальну суму: max_odd + min_even
    mov rdx, rsi        ; rdx = max_odd
    add rdx, rdi        ; rdx = max_odd + min_even

    ; Виводимо результат
    lea rcx, [rel fmt_out]
    call printf

.exit_program:
    ; Відновлюємо стек та регістри
    add rsp, 40
    pop r12
    pop rdi
    pop rsi
    pop rbx
    
    xor rcx, rcx
    call ExitProcess