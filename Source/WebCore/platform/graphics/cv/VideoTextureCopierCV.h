/*
 * Copyright (C) 2016 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef VideoTextureCopierCV_h
#define VideoTextureCopierCV_h

#import "GraphicsContext3D.h"

typedef struct __CVBuffer* CVImageBufferRef;
typedef CVImageBufferRef CVOpenGLTextureRef;
typedef CVImageBufferRef CVOpenGLESTextureRef;

namespace WebCore {

class VideoTextureCopierCV {
public:
    VideoTextureCopierCV(GraphicsContext3D&);
    ~VideoTextureCopierCV();

#if PLATFORM(IOS)
    typedef CVOpenGLESTextureRef TextureType;
#else
    typedef CVOpenGLTextureRef TextureType;
#endif

    bool copyVideoTextureToPlatformTexture(TextureType, size_t width, size_t height, Platform3DObject outputTexture, GC3Denum outputTarget, GC3Dint level, GC3Denum internalFormat, GC3Denum format, GC3Denum type, bool premultiplyAlpha, bool flipY);

    GraphicsContext3D& context() { return m_context.get(); }

private:
    class GC3DStateSaver {
    public:
        GC3DStateSaver(GraphicsContext3D&);
        ~GC3DStateSaver();

        void saveVertexAttribState(GC3Duint index);

    private:
        GraphicsContext3D& m_context;
        GC3Dint m_texture { 0 };
        GC3Dint m_framebuffer { 0 };
        GC3Dint m_program { 0 };
        GC3Dint m_arrayBuffer { 0 };
        GC3Dint m_viewport[4] { 0, 0, 0, 0 };

        GC3Duint m_vertexAttribIndex { 0 };
        GC3Dint m_vertexAttribEnabled { 0 };
        GC3Dint m_vertexAttribSize { 0 };
        GC3Dint m_vertexAttribType { 0 };
        GC3Dint m_vertexAttribNormalized { 0 };
        GC3Dint m_vertexAttribStride { 0 };
        GC3Dsizeiptr m_vertexAttribPointer { 0 };
    };

    bool initializeContextObjects();

    Ref<GraphicsContext3D> m_context;
    Platform3DObject m_framebuffer { 0 };
    Platform3DObject m_program { 0 };
    Platform3DObject m_vertexBuffer { 0 };
    GC3Dint m_textureUniformLocation { -1 };
    GC3Dint m_textureDimensionsUniformLocation { -1 };
    GC3Dint m_flipYUniformLocation { -1 };
    GC3Dint m_premultiplyUniformLocation { -1 };
    GC3Dint m_positionAttributeLocation { -1 };
};

}

#endif // VideoTextureCopierCV_h
