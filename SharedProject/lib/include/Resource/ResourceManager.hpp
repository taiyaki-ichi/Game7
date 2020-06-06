#pragma once
#include<string>
#include<unordered_map>

namespace GameLib
{
	class Texture;

	class ResourceManager
	{
		static std::unordered_map<std::string, Texture*> mTextures;

	public:
		static Texture* GetTexture(const std::string& fileName);
		static Texture* GetTexture(std::string&& fileName);

		static void ReleaseResources();
	};
}