
//:         VIDEO: https://www.youtube.com/watch?v=TnrRkzC1_RU
//:       CHANNEL: CODE_TOLD_FAST
//: PASTEBIN_NAME: ISO_C/03/M.c
//:  PASTEBIN_URL: ( See Youtube Video Description For Link )

//: SECTION: [Headers/Libraries] and types: /////////////////://



#include <stdio.h>   //:printf(...)
#include <windows.h> //:LoadLibraryA, GetProcAddress



struct DAT_ShellExecuteInfoW { /////////////////////////////////
    unsigned long     cbSize; //:---------------: U_32 / 8_BYTES
    unsigned long      fMask; //:---------------: U_32 / 8_BYTES
             void*      hwnd; //:---------------: VOID

    const unsigned short *         lpVerb; //:--: U_16 / 2_BYTES
    const unsigned short *         lpFile; //:--: U_16 / 2_BYTES
    const unsigned short *   lpParameters; //:--: U_16 / 2_BYTES
    const unsigned short *    lpDirectory; //:--: U_16 / 2_BYTES

    int       nShow;
    void*  hInstApp;
    void*  lpIDList;
                    const unsigned short *   lpClass;
                    void*                  hkeyClass;  
                    unsigned long           dwHotKey;
    union /** anonymous **/ {
        void*    hIcon; 
        void* hMonitor;
    } dummy_union_member_aka_DUMMYUNIONNAME;

    void*    hProcess;
}; /////////////////////////////////////////////////////////////



typedef
    int
    (*PFN_ShellExecuteExW)(
        struct DAT_ShellExecuteInfoW *pExecInfo
    );

typedef
    unsigned long
    (*PFN_WaitForSingleObject)(
        /**/    void* hHandle 
        ,       unsigned long  dwMilliseconds
    );

typedef
    int
    (*PFN_CloseHandle)(
        void* hObject
    );

int main( void ){
	printf("[BEG:main]\n");

    //:SECTION: Get Function Pointers ///////////////////////://

    

    //:Load DLL (Dynamic Link Library) Files:
    void* dll_Shell32  = LoadLibraryA( "shell32.dll"   );
    void* dll_Kernel32 = LoadLibraryA( "kernel32.dll"  );
	
	//:Pull function pointer(s) from DLL(s):
    ////////////////////////////////////////////////////////////
    #define T1 PFN_ShellExecuteExW      // ################## //
    #define T2 PFN_WaitForSingleObject  // ################## //
    #define T3 PFN_CloseHandle          // ################## //

    T1 pfn_ShellExecuteExW=(T1)(GetProcAddress(dll_Shell32, 
          "ShellExecuteExW" ));;

    T2 pfn_WaitForSingleObject=(T2)(GetProcAddress(dll_Kernel32, 
          "WaitForSingleObject" ));;

    T3 pfn_CloseHandle=(T3)(GetProcAddress(dll_Kernel32, 
          "CloseHandle" ));

    #undef  T1   // ######################################### //
    #undef  T2   // ######################################### //
    #undef  T3   // ######################################### //
    ////////////////////////////////////////////////////////////  

    //:SECTION: Create Argument List ////////////////////////://

    

    //:Check for null function pointers:
    if( NULL == pfn_ShellExecuteExW     ){ printf("[01]\n"); };
    if( NULL == pfn_WaitForSingleObject ){ printf("[02]\n"); };
    if( NULL == pfn_CloseHandle         ){ printf("[03]\n"); };

    //:Create Argument List (Using WIDE strings)
    const short* lpParameters=(
        L"ARG01"
        L" "     //:SPACE_BETWEEN_ARGS!
        L"ARG02"
        L" "     //:SPACE_BETWEEN_ARGS!
        L"ARG03"
        L"\0" //:Extra null terminator to be safe
    );;  

    //:SECTION: Build+Invoke: ShellExecuteExW Call //////////://

    

//[ SEE_MASK_NOCLOSEPROCESS (0x00000040) --------------------]//
//| Makes ShellExecuteExW put process handle into hProcess   |//
//| so you can detect when launched program terminates.      |//

struct DAT_ShellExecuteInfoW info = { 0 };

info      .cbSize = sizeof( struct DAT_ShellExecuteInfoW );
info       .fMask = 0x00000040 /** SEE_MASK_NOCLOSEPROCESS **/;
info      .lpFile = L"S.exe"; //:L for "Wide String"
info.lpParameters = lpParameters;

//:DONT_NEED_TO_SUPPLY, but here for completeness:
info      .lpVerb = L"open"; //:Defaults to "open" if not given.
info        .hwnd =    NULL; //:No parent window.
info .lpDirectory =    NULL; //:For: working dir != current dir
info       .nShow =    0   ; //:Not windowed program
info    .hInstApp =    NULL; //:hInstApp >= 32 if success
info    .lpIDList =    NULL; //:Identify exe to run via PIDL 
info     .lpClass =    NULL; //:Misc  String. SEE_MASK_CLASSNAME
info   .hkeyClass =    NULL; //:Registry Key. SEE_MASK_CLASSKEY
info    .dwHotKey =    0   ; //:Shortcut Key. SEE_MASK_HOTKEY
info    .hProcess =    NULL; //:output. SEE_MASK_NOCLOSEPROCESS  

    //:SECTION: Spinlock till S.exe finished ////////////////://

        

    //:Launch Sub Program : S.exe
    pfn_ShellExecuteExW( &info );

    //: The handle must have the SYNCHRONIZE access right. 
    //: -MSDN: WatiForSingleObject
    if(NULL == info.hProcess ){
        printf("[ShellExecuteInfoW:Problems]");
        fflush(stdout); exit(666);
    };;

    //:SpinLock
    pfn_WaitForSingleObject( 
        info.hProcess 
    ,   0xFFffFFff /** INFINITE : winbase.h **/
    );;

    pfn_CloseHandle( info.hProcess );  

    //:SECTION: Read from file created by S.exe /////////////://

        

    //:Because we are certain that the sub program is
    //:finished, we can read the file that sub program
    //:created without introducing a race condition.

    //:Open File:
    FILE* file = fopen( "txt.txt", "r" /** r:read **/ );
    if(NULL==file){
        printf("[FailedToOpen:txt.txt]\n");
        fflush(stdout); exit(666);
    }else{
        printf("[FileOpened:txt.txt]\n");
        fflush(stdout);
    };;

    //:Print contents and close file:
    char line[64] = { 0 };
    int  max_len  = 64;
    while( fgets(line,max_len,file) != NULL ){
        printf("[LN]:%s\n", line);
    };;
    fclose( file );  
                                 
	printf("[END:main]\n");
}//[;main;]//
