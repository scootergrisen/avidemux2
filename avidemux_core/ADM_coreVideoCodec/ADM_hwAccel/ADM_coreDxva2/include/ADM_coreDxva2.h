/***************************************************************************
    \file             : ADM_coreDxva2.cpp
    \brief            : Wrapper around dxva functions
    \author           : (C) 2016 by mean fixounet@free.fr
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#pragma once
#include "ADM_image.h"
#include "ADM_windowInfo.h"
#include "ADM_coreD3D.h"
#include "dxva2api.h"
#include "ADM_coreDxva2_export.h"
extern "C"
{
 #include "libavcodec/avcodec.h"
}
/**
 */
class ADM_COREVIDEOCODEC6_EXPORT admDx2Surface
{
public:
                          admDx2Surface(void *parent,int alignment);
                          ~admDx2Surface();
    void                 *parent;
    LPDIRECT3DSURFACE9    surface;
    IDirectXVideoDecoder *decoder;

    bool                  surfaceToAdmImage(ADMImage *out);
    int                   refCount;
public:
    bool                  addRef();
    bool                  removeRef();
protected:
    int                   alignment;
} ;
/**
    \class admVdpau
*/
class ADM_COREVIDEOCODEC6_EXPORT admDxva2
{
public:
        static bool init(GUI_WindowInfo *x);
        static bool isOperationnal(void);
        static bool cleanup(void);
        static bool supported(AVCodecID codec);
        static IDirectXVideoDecoder *createDecoder(AVCodecID codec,int width, int height,int numSurface, LPDIRECT3DSURFACE9 *surface,int align);
        static bool destroyDecoder(IDirectXVideoDecoder *decoder);
        static DXVA2_ConfigPictureDecode *getDecoderConfig(AVCodecID codec);
        static bool allocateD3D9Surface(int num,int width, int height,void *array,int align);
        static bool destroyD3DSurface(int num,void *surfaces);
        static bool decoderAddRef(IDirectXVideoDecoder *decoder);
        static bool decoderRemoveRef(IDirectXVideoDecoder *decoder);
};

bool ADM_COREVIDEOCODEC6_EXPORT admDxva2_exitCleanup(void);

