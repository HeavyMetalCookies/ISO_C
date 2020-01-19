
//:         VIDEO: https://www.youtube.com/watch?v=kSsQtozz4iA
//:       CHANNEL: CODE_TOLD_FAST
//: PASTEBIN_NAME: 02/BUILD.SH
//:  PASTEBIN_URL: https://pastebin.com/Xz3ZQm1B

##: Summary: Build both programs and call main program.

gcc -std=c11 -x c   M.C11 -o   M.exe  ## Main Program
gcc -std=c11 -x c   S.C11 -o   S.exe  ##  Sub Program

./M.exe ## Run Main Program

read -p "[Press_Enter_To_Continue]:"

