/*
 * Copyright (C) 2010, 2011 Apple Inc. All rights reserved.
 * Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies)
 * Copyright (C) 2012 Company 100, Inc.
 * Copyright (C) 2017 Sony Interactive Entertainment Inc.
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

#ifndef CoordinatedGraphicsArgumentCoders_h
#define CoordinatedGraphicsArgumentCoders_h

#if USE(COORDINATED_GRAPHICS)
#include "ArgumentCoders.h"

namespace WebCore {
struct CoordinatedGraphicsLayerState;
struct CoordinatedGraphicsState;
class FloatPoint3D;
class TextureMapperAnimation;
class TextureMapperAnimations;
class SurfaceUpdateInfo;
struct TileCreationInfo;
struct TileUpdateInfo;
class TransformationMatrix;
class TransformOperations;
struct Length;
struct DebugVisuals;

class FilterOperations;
}

namespace IPC {

template<> struct ArgumentCoder<WebCore::FilterOperations> {
    static void encode(Encoder&, const WebCore::FilterOperations&);
    static bool decode(Decoder&, WebCore::FilterOperations&);
};

template<> struct ArgumentCoder<WebCore::TransformOperations> {
    static void encode(Encoder&, const WebCore::TransformOperations&);
    static bool decode(Decoder&, WebCore::TransformOperations&);
};

template<> struct ArgumentCoder<WebCore::TextureMapperAnimations> {
    static void encode(Encoder&, const WebCore::TextureMapperAnimations&);
    static bool decode(Decoder&, WebCore::TextureMapperAnimations&);
};

template<> struct ArgumentCoder<WebCore::TextureMapperAnimation> {
    static void encode(Encoder&, const WebCore::TextureMapperAnimation&);
    static std::optional<WebCore::TextureMapperAnimation> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::SurfaceUpdateInfo> {
    static void encode(Encoder&, const WebCore::SurfaceUpdateInfo&);
    static bool decode(Decoder&, WebCore::SurfaceUpdateInfo&);
};

template<> struct ArgumentCoder<WebCore::CoordinatedGraphicsLayerState> {
    static void encode(Encoder&, const WebCore::CoordinatedGraphicsLayerState&);
    static std::optional<WebCore::CoordinatedGraphicsLayerState> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TileUpdateInfo> {
    static void encode(Encoder&, const WebCore::TileUpdateInfo&);
    static std::optional<WebCore::TileUpdateInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::TileCreationInfo> {
    static void encode(Encoder&, const WebCore::TileCreationInfo&);
    static std::optional<WebCore::TileCreationInfo> decode(Decoder&);
};

template<> struct ArgumentCoder<WebCore::CoordinatedGraphicsState> {
    static void encode(Encoder&, const WebCore::CoordinatedGraphicsState&);
    static bool decode(Decoder&, WebCore::CoordinatedGraphicsState&);
};

template<> struct ArgumentCoder<WebCore::DebugVisuals> {
    static void encode(Encoder&, const WebCore::DebugVisuals&);
    static bool decode(Decoder&, WebCore::DebugVisuals&);
};

} // namespace IPC

#endif // USE(COORDINATED_GRAPHICS)

#endif // CoordinatedGraphicsArgumentCoders_h
