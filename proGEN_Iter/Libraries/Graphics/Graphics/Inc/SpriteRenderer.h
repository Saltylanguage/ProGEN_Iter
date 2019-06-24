//#pragma once
//#include "MathLibrary/Inc/Vector2.h"
//
//namespace DirectX
//{
//	class CommonStates;
//	class SpriteBatch;
//}
//
//namespace Graphics
//{
//
//	class Texture;
//	class GraphicsSystem;
//	//====================================================================================================
//	// Class Declarations
//	//====================================================================================================
//
//	class SpriteRenderer
//	{
//	public:
//		static void StaticInitialize();
//		static void StaticTerminate();
//		static SpriteRenderer* Get();
//
//	public:
//		SpriteRenderer();
//		~SpriteRenderer();
//
//		void Initialize();
//		void Terminate();
//
//		void BeginRender();
//		void EndRender();
//
//		void Draw(Texture& texture, const Math::Vector2& position);
//
//		DirectX::SpriteBatch* GetSpriteBatch() { return mpSpriteBatch; }
//
//	private:
//		
//		friend class Font;
//
//		DirectX::CommonStates* mpStateObjects;
//		DirectX::SpriteBatch* mpSpriteBatch;
//	};
//}