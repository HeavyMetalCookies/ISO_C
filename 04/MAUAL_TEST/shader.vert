    
    //:Vertex Shader

    //: gl_VertexIndex is a Vulkan extension
    //: SOURCE: github.com/KhronosGroup/glslang/issues/229

    #version 450                                         
    #extension GL_ARB_separate_shader_objects : enable   
                                                                                                           
    layout(location = 0) out vec3 fragColor;             
                                                         
    out gl_PerVertex {                                   
        vec4 gl_Position;                                
    };                                                  
                                                         
    vec2 positions[3] = vec2[](                          
        vec2( 0.0, -0.5)                                      
    ,   vec2( 0.5,  0.5)                                       
    ,   vec2(-0.5,  0.5)                                     
    );                                                
                                                         
   //:SC[VKTUTPDF2018]BP[101]                            
   vec3 colors[3] =(                                     
       vec3[](                                           
           vec3(1.0, 0.0, 0.0)                           
       ,   vec3(0.0, 1.0, 0.0)                           
       ,   vec3(0.0, 0.0, 1.0)                           
       )                                                 
   );                                                 
                                                                                                          
    void main() {   
                                     
        gl_Position =(                                   
            vec4(                                        
                positions[ gl_VertexIndex ] //:[X,Y]           
            ,   0.0  //: Z --------------------[ Z ]                            
            ,   1.0  //: W --------------------[ W ]                            
            )                                            
        );;  

        fragColor =(
            colors[gl_VertexIndex]
        );;
                             
    }//[main]//