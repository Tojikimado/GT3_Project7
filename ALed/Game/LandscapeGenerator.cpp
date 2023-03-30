#include "LandscapeGenerator.h"


LandscapeGenerator::LandscapeGenerator(Transform _transform, int _XSize, int _YSize, float _Scale) :
XSize(_XSize), YSize(_YSize), Scale(_Scale)
{
	m_transform = _transform;
	m_name = "land";
}

bool LandscapeGenerator::CreateMesh()
{
	if (XSize < 1 || YSize < 1)
	{
		return false;
	}

	VertexPositionColor* vertices = new VertexPositionColor[XSize * YSize];

	int vertex = 0;
	for (int x =0; x < XSize; x++)
	{
		for (int y = 0; y < YSize; y++)
		{
			D3DCOLOR color = d3dColors::Yellow;

			float z = 0.f + std::rand() % 2;
			if (z > 0.4f)
			{
				color = d3dColors::CornFlowerBlue;
			}
			vertices[vertex] = VertexPositionColor(x - XSize/2, y - YSize/2, -z , color);
			vertex++;
		}
	}

	int nbIndice = 6 * ((XSize - 1) * (YSize - 1));
	short* baseIndices = new short[nbIndice];

	int indiceIndex = 0;
	for (int i = 0; i < (XSize * YSize) - YSize; i++)
	{
		if (i % YSize != YSize - 1) {
			baseIndices[indiceIndex] = i; 
			baseIndices[indiceIndex + 1] = i + 1; 
			baseIndices[indiceIndex + 2] = i + 1 + YSize;   // side 1
			baseIndices[indiceIndex + 3] = i; 
			baseIndices[indiceIndex + 4] = i + 1 + YSize;
			baseIndices[indiceIndex + 5] = i + YSize;
			indiceIndex += 6;
		}
	}
	ColoredMesh* newMesh = new ColoredMesh(vertices, XSize * YSize, baseIndices,nbIndice);

	m_meshRenderer = new ColoredMeshRenderer(newMesh, "../Landscape.hlsl");

	if (m_meshRenderer == nullptr)
	{
		return false;
	}

	return true;
}


