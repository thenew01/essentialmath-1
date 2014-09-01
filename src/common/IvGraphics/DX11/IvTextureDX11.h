//===============================================================================
// @ IvTextureDX11.h
// 
// Description
// ------------------------------------------------------------------------------
// Copyright (C) 2008  Elsevier, Inc.
//
// Usage notes
//===============================================================================

#ifndef __IvTextureDX11__h__
#define __IvTextureDX11__h__

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include "IvTexture.h"
#include <d3d11.h>

//-------------------------------------------------------------------------------
//-- Typedefs, Structs ----------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Classes --------------------------------------------------------------------
//-------------------------------------------------------------------------------

class IvTextureDX11: public IvTexture
{
public:
    friend class IvResourceManagerDX11;
    friend class IvUniformDX11;

    // interface routines
    virtual void* BeginLoadData(unsigned int level = 0);
    virtual bool  EndLoadData(unsigned int level = 0);

    virtual void SetAddressingU(IvTextureAddrMode mode);
    virtual void SetAddressingV(IvTextureAddrMode mode);

    virtual void SetMagFiltering(IvTextureMagFilter filter);
    virtual void SetMinFiltering(IvTextureMinFilter filter);

    virtual void GenerateMipmapPyramid();

protected:
    // constructor/destructor
    IvTextureDX11();
    virtual ~IvTextureDX11();

    // creation
	bool Create(unsigned int width, unsigned int height, IvTextureFormat format, ID3D11Device* device);

	// destruction
	void Destroy();

	// activation
	void MakeActive(unsigned int unit, ID3D11Device* device);

    unsigned int mLevelCount;

    struct Level
    {
        void* mData;
        unsigned int mSize;
        unsigned int mWidth;
        unsigned int mHeight;
    };

    Level* mLevels;

private:
    // copy operations (unimplemented so we can't copy)
    IvTextureDX11(const IvTextureDX11& other);
	IvTextureDX11& operator=(const IvTextureDX11& other);

	// D3D objects
	ID3D11ShaderResourceView* mTexturePtr;

	unsigned int		mUAddrMode;
	unsigned int		mVAddrMode;
	unsigned int		mMagFilter;
	unsigned int		mMinFilter;
	unsigned int		mMipFilter;

	DXGI_FORMAT			mD3DFormat;

}; 

#endif