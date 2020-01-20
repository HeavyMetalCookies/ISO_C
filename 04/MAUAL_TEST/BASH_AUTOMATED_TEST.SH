

full_path_to_exe="E:\NV\SDK\VK\111300\Bin\glslangValidator.exe"
if [ -f "$full_path_to_exe" ] ; 
then

    echo "EXISTS" ;

    ## .vert : REQUIRED: Shader type extension on source file.
    ##    -V : REQUIRED: Use vulkan flavored glsl
    ##    -e : Optional: Entry point function name
    ##    -o : Optional: Output filename
    $full_path_to_exe   \
        -V shader.vert  \
        -e main         \
        -o test.spv     #

else
    
    echo "NOT_EXIST" ;

fi


read -p "[Press_Enter_To_Continue]:"



