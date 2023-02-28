#pragma once
#include <string>

class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd;
	shared_ptr<Graphics> _graphics;

private:
	void CreateRasterizerState();
	void CreateSamplerState();
	void CreateBlendState();

private:
	//geometry
	shared_ptr<Geometry<VertexTextureData>> _geometry;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<InputLayout> _inputLayout;

	// VS
	shared_ptr<VertexShader> _vertexShader;

	//RS
	ComPtr<ID3D11RasterizerState> _rasterizerState = nullptr;

	// PS
	shared_ptr<PixelShader> _pixelShader;

	//srv
	shared_ptr<Texture> _texture1;
	shared_ptr<Texture> _texture2;

	ComPtr<ID3D11SamplerState> _samplerState = nullptr;
	ComPtr<ID3D11BlendState> _blendState = nullptr;

private:
	TransformData _transformData;
	shared_ptr<ConstantBuffer<TransformData>> _constantBuffer;

	Vec3 _localPosition = { 0.f, 0.f, 0.f };
	Vec3 _localRotation = { 0.f, 0.f, 0.f };
	Vec3 _localScale = { 1.f, 1.f, 1.f };
};

