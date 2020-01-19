

doc=$(cat << HEREDOC_INTO_FILE_00

    $( cat "SRC/H._" )
    $( cat "SRC/T._" )

    int main( void ){ 
    printf("[M.C11:BEG:main]\n");
        
        $( cat "SRC/01._" )
        $( cat "SRC/02._" )
        $( cat "SRC/03._" )
        $( cat "SRC/04._" )

    printf("[M.C11:END:main]\n"); 
    } 

HEREDOC_INTO_FILE_00
)


touch all.txt
> all.txt
echo "$doc" >> "all.txt"


read -p "[Press_Enter_To_Continue]:"