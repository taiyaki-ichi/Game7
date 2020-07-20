#include"GameLib/include/Resource/ResourceManager.hpp"
#include"GameLib/src/Windows/Graphics.hpp"
#include "..\..\include\Resource\ResourceManager.hpp"

namespace GameLib
{

	std::unordered_map<std::string, Texture*> ResourceManager::mTextures;
	std::unordered_map<std::string, Font*> ResourceManager::mFonts;

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

	Font* ResourceManager::GetFont(const std::string& fileName)
	{
		auto iter = mFonts.find(fileName);
		if (iter != mFonts.end()) {
			return iter->second;
		}
		else {
			auto ptr = LoadFont(fileName);
			mFonts.emplace(fileName, ptr);
			return ptr;
		}
	}
	Font* ResourceManager::GetFont(std::string&& fileName)
	{
		auto iter = mFonts.find(fileName);
		if (iter != mFonts.end()) {
			return iter->second;
		}
		else {
			auto ptr = LoadFont(fileName);
			mFonts.emplace(std::move(fileName), ptr);
			return ptr;
		}
	}

	void ResourceManager::ReleaseResources()
	{
		for (auto tex : ResourceManager::mTextures)
			delete tex.second;
		ResourceManager::mTextures.clear();

		for (auto i : ResourceManager::mFonts)
			delete i.second;
		ResourceManager::mFonts.clear();
	}
}