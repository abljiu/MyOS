#include "init.h"
#include "print.h"
#include "interrupt.h"
#include "../device/timer.h"
#include "../kernel/memory.h"
#include "../thread/thread.h"
#include "../device/console.h"
#include "../device/keyboard.h"
#include "../userprog/tss.h"
#include "../userprog/syscall-init.h"
#include "ide.h"
#include "fs.h"

/*负责初始化所有模块 */
void init_all()
{
   put_str("init_all\n");
   idt_init();      // 初始化中断
   timer_init();    // 初始化 PIT
   mem_init();      // 初始化内存管理系统
   thread_init();   // 初始化线程环境
   console_init();  // 控制台初始化最好放在开中断之前
   keyboard_init(); // 初始化键盘
   tss_init();      // 初始化tss
   syscall_init();  // 初始化系统调用
   ide_init();      // 初始化硬盘驱动
   filesys_init();  // 初始化文件系统
}