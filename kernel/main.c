#include "print.h"
#include "init.h"
#include "../thread/thread.h"
#include "interrupt.h"
#include "../device/console.h"

int main(void)
{
   put_str("I am kernel\n");
   init_all();

   // thread_start("k_thread_a", 31, k_thread_a, "argA ");
   // thread_start("k_thread_b", 8, k_thread_b, "argB ");

   intr_enable();
   while (1)
      ; //{
   // console_put_str("Main ");
   //  };
   return 0;
}