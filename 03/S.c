

//# IDENTICAL CODE TO [SUB.C11 / SUB.EXE] in tutorial #2     #//

#include <stdio.h> //:for: printf(...)
//! -------------------------------------------------------- !//
//! Create and populate file with arguments passed to func   !//
//! to simulate the main program running a sub program that  !//
//! creates some type of meaningful data that the main       !//
//! program can further use. ------------------------------- !// 
int main( int argc, char** argv ){
	printf("[S.c:BEG:main]\n");
	
    FILE* file = fopen( "txt.txt", "w" );
    int data = 666;
    fprintf( file, "[HARD_CODED_DATA]:%d\n", data );
    for( int i = 0; i < argc; i++ ){

        fprintf( file, "[ARG]:%s\n", argv[ i ] );
        
    };;
    fclose( file );
    
	printf("[S.c:END:main]\n");
} 