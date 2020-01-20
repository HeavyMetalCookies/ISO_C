

#include "SRC/H"   //:headers/libraries
#include "SRC/T.1" //:.... types
#include "SRC/T.2" //:more types

int main( void ){
	printf("[BEG:main]\n");

    #include "SRC/1"  //:Get Function Pointers
    
    #include "SRC/2"  //:Create Argument List

    #include "SRC/3"  //:Build+Invoke: ShellExecuteExW Call.

    #include "SRC/4"  //:Spinlock till S.exe finished.

    #include "SRC/5"  //:Read from file created by S.exe

	printf("[END:main]\n");
}//[;main;]//