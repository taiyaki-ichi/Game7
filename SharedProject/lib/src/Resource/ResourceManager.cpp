#include"lib/include/Resource/ResourceManager.hpp"
#include"lib/src/Windows/Graphics.hpp"
#include "..\..\include\Resource\ResourceManager.hpp"
namespace GameLib
{

	std::unordered_map<std::string, Texture*> ResourceManager::mTextures;

	Texture* ResourceManager::GetTexture(const std::string& fileName)
	{
		Texture* tex = nullptr;
		auto iter = mTextures.find(fileName);
		if (iter != mTextures.end()) {
			tex = iter->second;
		}
		else
		{
			tex = LoadTexture(fileName);
			if (tex)
				mTextures.emplace(fileName, tex);
		}

		return tex;
	}
	Texture* ResourceManager::GetTexture(std::string&& fileName)
	{
		Texture* tex = nullptr;
		auto iter = mTextures.find(fileName);
		if (iter != mTextures.end()) {
			tex = iter->second;
		}
		else
		{
			tex = LoadTexture(fileName);
			if (tex)
				mTextures.emplace(fileName, tex);
		}

		return tex;
	}
	void ResourceManager::ReleaseResources()
	{
		for (auto tex : ResourceManager::mTextures)
			delete tex.second;
		ResourceManager::mTextures.clear();
	}
}