

## MAIN:
################################################################

main_program_source=$( cat << MAIN_PROGRAM_HEREDOC

//:         VIDEO: https://www.youtube.com/watch?v=TnrRkzC1_RU
//:       CHANNEL: CODE_TOLD_FAST
//: PASTEBIN_NAME: ISO_C/03/M.c
//:  PASTEBIN_URL: ( See Youtube Video Description For Link )

//: SECTION: [Headers/Libraries] and types: /////////////////://

$(cat  "SRC/H"  )

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
echo "$main_program_source" >>  "./PASTE_BIN/M.c"

## SUB:
################################################################


sub_program_header_comment=$( cat << HEREDOC_SUBCOM

//:         VIDEO: https://www.youtube.com/watch?v=TnrRkzC1_RU
//:       CHANNEL: CODE_TOLD_FAST
//: PASTEBIN_NAME: ISO_C/03/S.c
//:  PASTEBIN_URL: ( See Youtube Video Description For Link )

HEREDOC_SUBCOM
)

                                touch "./PASTE_BIN/S.c"
                                    > "./PASTE_BIN/S.c"
echo "$sub_program_header_comment" >> "./PASTE_BIN/S.c"
cat "./S.c"                        >> "./PASTE_BIN/S.c"

## BUILD:
################################################################

build_script_comment=$( cat << HEREDOC_BUILDCOM

##:         VIDEO: https://www.youtube.com/watch?v=TnrRkzC1_RU
##:       CHANNEL: CODE_TOLD_FAST
##: PASTEBIN_NAME: ISO_C/03/B.SH
##:  PASTEBIN_URL: ( See Youtube Video Description For Link )

HEREDOC_BUILDCOM
)

                          touch "./PASTE_BIN/B.SH"
                              > "./PASTE_BIN/B.SH"
echo "$build_script_comment" >> "./PASTE_BIN/B.SH"
cat "./B.SH"                 >> "./PASTE_BIN/B.SH"

################################################################