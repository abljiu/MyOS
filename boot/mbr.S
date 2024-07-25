;主引导程序
SECTION MBR vstart=0x7c00
    mov ax,cs   ;cs最初为0 其实是初始化ax
    mov ds,ax
    mov es,ax
    mov ss,ax
    mov fs,ax
    mov sp,0x7c00   ;sp是x86的默认栈顶指针

;输入:
;AH 功能号= 0x06
;AL = 上卷的行数(如果为 0,表示全部)
;BH = 上卷行属性
;(CL,CH) = 窗口左上角的(X,Y)位置
;(DL,DH) = 窗口右下角的(X,Y)位置
;无返回值:
    mov ax,0x600
    mov bx,0x700
    mov cx,0
    mov dx,0x184f

    int 0x10

    mov ah,3    ; 输入: 3 号子功能是获取光标位置,需要存入 ah 寄存器
    mov bh,0    ; bh 寄存器存储的是待获取光标的页号
    
    int 0x10    ; 输出: ch=光标开始行,cl=光标结束行
                ; dh=光标所在行号,dl=光标所在列号
    
    mov ax,message  ;
    mov bp,ax
    
    mov cx,5
    mov ax,0x1301
    
    mov bx,0x2
    int 0x10
    
    jmp $
    
    message db "1 MBR"
    times 510-($-$$) db 0
    db 0x55,0xaa