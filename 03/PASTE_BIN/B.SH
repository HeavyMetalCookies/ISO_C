
##:         VIDEO: https://www.youtube.com/watch?v=TnrRkzC1_RU
##:       CHANNEL: CODE_TOLD_FAST
##: PASTEBIN_NAME: ISO_C/03/B.SH
##:  PASTEBIN_URL: ( See Youtube Video Description For Link )


################################################################
## B.SH  (B is for BUILD script  )
## M.C11 (M is for  MAIN program )
## S.C11 (S is for   SUB program )
################################################################

gcc -std=c11 -x c   M.c -o   M.exe  ## Main Program
gcc -std=c11 -x c   S.c -o   S.exe  ##  Sub Program

./M.exe ## Run Main Program

read -p "[Press_Enter_To_Continue]:"

################################################################
