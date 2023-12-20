uniform vec2 mouse_pos;
uniform sampler2D u_Texture;
uniform vec2 iResolution;
uniform float Timer;
uniform int is_shooting;
void main()
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv =  gl_TexCoord[0].xy;
    uv.x *= iResolution.x/iResolution.y;
    vec3 pixels = texture2D(u_Texture , uv).rgb;
    vec2 mouse = mouse_pos/iResolution;
    float d = 1.;
    float a = 0.;
    if(is_shooting ==0)
    {
        
        a  =  0.;
    }
    else
    {

         a = 1.;
    }
    gl_FragColor = vec4(d,d,d,a);
}