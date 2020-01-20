



M_c=$( cat << MAIN_PROGRAM_HEREDOC

//: [Headers/Libraries] and types:

$(cat  "SRC/H  ")

$(cat  "SRC/T.1")

$(cat  "SRC/T.2")

int main( void ){
	printf("[BEG:main]\n");

    //:SECTION: Get Function Pointers ///////////////////////://

    $( cat  "SRC/1" )  

    //:SECTION: Create Argument List ////////////////////////://

    $( cat  "SRC/2" )  

    //:SECTION: Build+Invoke: ShellExecuteExW Call //////////://

    $( cat  "SRC/3" )  

    //:SECTION: Spinlock till S.exe finished ////////////////://

    $( cat  "SRC/4" )  

    //:SECTION: Read from file created by S.exe /////////////://

    $( cat  "SRC/5" )  
                                 
	printf("[END:main]\n");
}//[;main;]//

MAIN_PROGRAM_HEREDOC
)

        touch "./PASTE_BIN/M.c"
            > "./PASTE_BIN/M.c"
echo $M_C >>  "./PASTE_BIN/M.c"