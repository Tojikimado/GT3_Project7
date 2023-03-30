float4x4 WorldViewProj;
float Time; 

float4 lowColor = (0.0f, 1.0f, 0.0f,1.0f);
float4 midColor = (0.0f, 0.0f, 1.0f, 1.0f);
float4 highColor = (1.0f, 0.0f, 0.0f, 1.0f);

// Vertex shader
struct VS_INPUT {
    float4 position : POSITION;
    float4 color : COLOR0;
};

struct VS_OUTPUT
{
    float4 position   : POSITION;   // vertex position 
    float4 color : COLOR0;
};

VS_OUTPUT vs_main(VS_INPUT input) {
    VS_OUTPUT output;

    float4 pos = float4(input.position.x, input.position.y, input.position.z, 1.0f);
    output.position = mul(pos ,WorldViewProj);
    output.color = input.color;

    return output;
}

//pixel shader
struct PS_OUTPUT {
    float4 color : COLOR0;
};

PS_OUTPUT ps_main(VS_OUTPUT input) {
    PS_OUTPUT output;

    output.color = input.color;

    return output;
}

technique Default
{
	pass p0
	{
		VertexShader = compile vs_3_0 vs_main();
		PixelShader = compile ps_3_0 ps_main();
	}
}