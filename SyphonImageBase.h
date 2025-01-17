/*
    SyphonImageBase.h
    Syphon

    Copyright 2010-2011 bangnoise (Tom Butterworth) & vade (Anton Marini).
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef SYPHONIMAGEBASE_H_A65FF8E1_DE27_40CA_8893_0BAC63A4FA5C
#define SYPHONIMAGEBASE_H_A65FF8E1_DE27_40CA_8893_0BAC63A4FA5C
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurface.h>

#define SYPHON_IMAGE_BASE_UNIQUE_CLASS_NAME SYPHON_UNIQUE_CLASS_NAME(SyphonImageBase)

@interface SYPHON_IMAGE_BASE_UNIQUE_CLASS_NAME : NSObject
/*!
 If you implement your own subclass of SyphonImageBase, you must call this designated initializer from your own initializer.

 Creates a new image with the provided IOSurface.

 @param surfaceRef A valid IOSurface with image data.
 @returns A newly intialized Syphon image. Nil on failure.
*/
- (id)initWithSurface:(IOSurfaceRef)surfaceRef NS_DESIGNATED_INITIALIZER;
@end

#if defined(SYPHON_USE_CLASS_ALIAS)
@compatibility_alias SyphonImageBase SYPHON_IMAGE_BASE_UNIQUE_CLASS_NAME;
#endif
#endif
