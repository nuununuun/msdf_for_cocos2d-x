varying vec4 v_fragmentColor;	
varying vec2 v_texCoord;	

uniform vec2 textureSize;
uniform float pxRange;
uniform vec4 bgColor;
uniform vec4 fgColor;

float median(float r, float g, float b) {
    return max(min(r, g), min(max(r, g), b));
}

void main() {
    vec2 msdfUnit = pxRange / textureSize;
    vec4 sample = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);
    float sigDist = median(sample.r, sample.g, sample.b) - 0.5;
    sigDist *= dot(msdfUnit, 0.5 / fwidth(v_texCoord));
    float opacity = clamp(sigDist + 0.5, 0.0, 1.0);
    gl_FragColor = mix(bgColor, fgColor, opacity);
}