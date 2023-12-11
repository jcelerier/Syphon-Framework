cmake_minimum_required(VERSION 3.22)
project(Syphon
    LANGUAGES C OBJC
    VERSION 5.0
    HOMEPAGE_URL http://syphon.v002.info/
)

if(NOT APPLE)
  message(STATUS "Syphon is not supported outside of Apple platforms")
  return()
endif()

set(CMAKE_INCLUDE_CURRENT_DIRS ON)

set(SYPHON_PUBLIC_HEADERS
  Syphon.h
  SyphonClient.h
  SyphonClientBase.h
  SyphonImage.h
  SyphonImageBase.h
  SyphonOpenGLClient.h
  SyphonOpenGLImage.h
  SyphonOpenGLServer.h
  SyphonServerBase.h
  SyphonServerDirectory.h
  SyphonSubclassing.h
)

foreach(header ${SYPHON_PUBLIC_HEADERS})
  file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/include/Syphon/${header}" INPUT "${CMAKE_CURRENT_SOURCE_DIR}/${header}")
endforeach()

add_library(Syphon
    Syphon.h
    SyphonCFMessageReceiver.h
    SyphonCFMessageReceiver.m
    SyphonCFMessageSender.h
    SyphonCFMessageSender.m
    SyphonCGL.c
    SyphonCGL.h
    SyphonClient.h
    SyphonClient.m
    SyphonClientBase.h
    SyphonClientBase.m
    SyphonClientConnectionManager.h
    SyphonClientConnectionManager.m
    SyphonDispatch.c
    SyphonDispatch.h
    SyphonGLShader.h
    SyphonGLShader.m
    SyphonGLVertices.h
    SyphonGLVertices.m
    SyphonIOSurfaceImageCore.h
    SyphonIOSurfaceImageCore.m
    SyphonIOSurfaceImageLegacy.h
    SyphonIOSurfaceImageLegacy.m
    SyphonImage.h
    SyphonImage.m
    SyphonImageBase.h
    SyphonImageBase.m
    SyphonMessageQueue.h
    SyphonMessageQueue.m
    SyphonMessageReceiver.h
    SyphonMessageReceiver.m
    SyphonMessageSender.h
    SyphonMessageSender.m
    SyphonMessaging.h
    SyphonMessaging.m
    SyphonMetalClient.h
    SyphonMetalClient.m
    SyphonMetalServer.h
    SyphonMetalServer.m
    SyphonOpenGLClient.h
    SyphonOpenGLClient.m
    SyphonOpenGLFunctions.c
    SyphonOpenGLFunctions.h
    SyphonOpenGLImage.h
    SyphonOpenGLImage.m
    SyphonOpenGLServer.h
    SyphonOpenGLServer.m
    SyphonPrivate.h
    SyphonPrivate.m
    SyphonServer.h
    SyphonServer.m
    SyphonServerBase.h
    SyphonServerBase.m
    SyphonServerConnectionManager.h
    SyphonServerConnectionManager.m
    SyphonServerDirectory.h
    SyphonServerDirectory.m
    SyphonServerGLShader.h
    SyphonServerGLShader.m
    SyphonServerGLVertices.h
    SyphonServerGLVertices.m
    SyphonServerMetalTypes.h
    SyphonServerRendererCoreGL.h
    SyphonServerRendererCoreGL.m
    SyphonServerRendererGL.h
    SyphonServerRendererGL.m
    SyphonServerRendererLegacyGL.h
    SyphonServerRendererLegacyGL.m
    SyphonServerRendererMetal.h
    SyphonServerRendererMetal.m
    SyphonSubclassing.h
)

target_precompile_headers(Syphon
  PUBLIC
    Syphon_Prefix.pch
)

target_include_directories(Syphon
  PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
)

target_compile_options(Syphon
  PRIVATE
    -fobjc-arc
    -fobjc-arc-exceptions
    -fobjc-weak
)

target_compile_definitions(Syphon
  PRIVATE
    SYPHON_CORE_SHARE
    GL_SILENCE_DEPRECATION=1
)

target_link_libraries(Syphon
  PRIVATE
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOSurface"
)
