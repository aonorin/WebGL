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
#pragma once

#include "IParserInput.hxx"

//+-----------------------------------------------------------------------------
//
//  Class:      CGLSLStringParserInput
//
//  Synopsis:   This class encapsulates the logic for pulling input into the
//              Bison / Flex code from a given ASCII string.
//
//------------------------------------------------------------------------------
class CGLSLStringParserInput : public IParserInput
{
public:
    CGLSLStringParserInput();

    HRESULT Initialize(__in_ecount(uInputSize + 1) char* pszInput, UINT uInputSize);

    // IParserInput implementation
    int PullInput(__out_ecount(1) char* buf) override;

private:
    // Bison / flex integration
    UINT _uReadPos;                                                 // Our read position
    TSmartArray<char> _spInput;                                     // Our input string
    UINT _uInputSize;                                               // Length of the input
};
