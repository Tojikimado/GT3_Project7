#include "TexturedGameObject.h"
TexturedGameObject::TexturedGameObject()
{
}

TexturedGameObject::TexturedGameObject(Transform transform, TexturedMeshRenderer* meshRenderer)
{
	m_transform = transform;
	SetTexturedMeshRenderer(meshRenderer);
}

TexturedGameObject::~TexturedGameObject()
{
	delete m_meshRenderer;
}

void TexturedGameObject::SetTexturedMeshRenderer(TexturedMeshRenderer* _meshRenderer)
{
	m_meshRenderer = _meshRenderer;
}

bool TexturedGameObject::Init(IDirect3DDevice9* m_pDevice3D)
{
	m_meshRenderer->Init(m_pDevice3D);
	return true;
}

void TexturedGameObject::Update(float dt)
{
}

void TexturedGameObject::Render(IDirect3DDevice9* m_pDevice3D, D3DXMATRIX _worldMatrix)
{
	float t = timeGetTime();
	//m_transform.SetRotation(D3DXVECTOR3(t*0.001f, t * 0.001f,0));
	m_pDevice3D->SetTransform(D3DTS_WORLD, &m_transform.GetWorld());
	m_meshRenderer->Render(m_pDevice3D, m_transform.GetWorld());
}