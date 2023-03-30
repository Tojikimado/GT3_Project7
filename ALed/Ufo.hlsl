float4x4 WorldViewProj;

float Time = 1.0f;

float Speed = 5.0f;

struct VS_INPUT {
    float4 position : POSITION;
};

struct VS_OUTPUT {
    float4 position : POSITION;
};

// Vertex shader
VS_OUTPUT vs_main(VS_INPUT input) {
    VS_OUTPUT output;
    output.position = mul(input.position, WorldViewProj);
    return output;
}

struct PS_INPUT {
    float4 position : POSITION;
};

struct PS_OUTPUT {
    float4 color : COLOR;
};

// Pixel shader
PS_OUTPUT ps_main(PS_INPUT input) {
    PS_OUTPUT output;
    
    float r = Speed * sin(Time);
    float g = 1.0f;
    float b = Speed * cos(Time);

    output.color = float4(r, g, b, 1.0f);

    return output;
}

technique Default
{
    pass p0
    {
        VertexShader = null;
        PixelShader = compile ps_3_0 ps_main();
    }
}