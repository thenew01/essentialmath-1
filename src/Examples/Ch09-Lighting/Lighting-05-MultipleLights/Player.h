//===============================================================================
// @ Player.h
// ------------------------------------------------------------------------------
// Main player
//
// Copyright (C) 2008-2015 by James M. Van Verth and Lars M. Bishop.
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
//
//
//===============================================================================

#ifndef __PlayerDefs__
#define __PlayerDefs__

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include <IvMatrix33.h>
#include <IvVector2.h>
#include <IvVector3.h>
#include <IvVector4.h>

//-------------------------------------------------------------------------------
//-- Classes --------------------------------------------------------------------
//-------------------------------------------------------------------------------

class IvIndexBuffer;
class IvShaderProgram;
class IvUniform;
class IvVertexBuffer;

class Player
{
public:
    Player();
    ~Player();

    void Update( float dt );
    void Render();

private:
    void ComputeMaterialComponents();
    
    float mRadius;

    IvShaderProgram* mShader;

    enum { NUM_LIGHTS = 2 };
    unsigned int mCurrentLight;
    IvVector3 mLightPos[NUM_LIGHTS];
    
    float mSpecularPercentage;
    float mAmbientFactor;
    float mEmissiveFactor;

    IvUniform* mLightPosUniform;
    IvUniform* mViewPosUniform;
};

#endif
