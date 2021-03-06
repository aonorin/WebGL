//--------------------------------------------------------------
//
// Microsoft Edge Implementation
// Copyright(c) Microsoft Corporation
// All rights reserved.
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files(the ""Software""),
// to deal in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS
// OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
// OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//--------------------------------------------------------------
#include "PreComp.hxx"
#include "GLSLPreParser.hxx"
#include "MemoryStream.hxx"

//+----------------------------------------------------------------------------
//
//  Function:   GLSLPreProcess
//
//  Synopsis:   Global function that takes an input GLSL string as ASCII and
//              outputs a preprocessed version of the string.
//
//-----------------------------------------------------------------------------
HRESULT GLSLPreprocess(
    __in IParserInput* pInput,                                  // Input to preprocessor
    __in IErrorSink* pErrorSink,                                // Where to store errors if you have them
    UINT uOptions,                                              // Translation options
    GLSLShaderType::Enum shaderType,                            // Type of shader
    __deref_out CMemoryStream** ppOutput,                       // Preprocessed output
    __deref_out CGLSLLineMap** ppLineMap,                       // Line map from preprocessor
    __deref_out CGLSLExtensionState** ppExtensionState          // Extension state from preprocessor
    )
{
    CHK_START;

    CGLSLPreParser parser;
    
    CHK(parser.Initialize(pInput, pErrorSink, uOptions, shaderType));

    (*ppOutput) = parser.UseOutput();
    (*ppOutput)->AddRef();

    (*ppLineMap) = parser.UseLineMap();
    (*ppLineMap)->AddRef();

    (*ppExtensionState) = parser.UseExtensionState();
    (*ppExtensionState)->AddRef();

    CHK_RETURN;
}
