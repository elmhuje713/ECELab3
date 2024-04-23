/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/


#include "grlib/grlib.h"

static const unsigned char pixel_LPRocket_96x37_1BPP_UNCOMP[] =
{
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x7f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x0f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x01, 0xff, 0x87, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x03, 0xe0, 0x01, 0xff, 0xe7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xf8, 0x00, 0x00, 0xff, 0xf7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xfc, 0x10, 0x00, 0xff, 0xe7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xe0, 0xf8, 0x00, 0x7f, 0xc7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xc3, 0xfc, 0x00, 0x7f, 0x8f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x1f, 0xfc, 0x00, 0x7f, 0x1f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xfe, 0x00, 0x7c, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0x1e, 0x00, 0x38, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xfb, 0xfc, 0x1e, 0x00, 0x23, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xfb, 0xe0, 0x1e, 0x00, 0x07, 0xff, 
0xff, 0xff, 0xff, 0xf0, 0xff, 0xfe, 0x1c, 0x01, 0xfe, 0x00, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0x87, 0xff, 0x80, 0x78, 0x1f, 0xfe, 0x00, 0xff, 0xff, 
0xff, 0xff, 0xfe, 0x3f, 0xf0, 0x3f, 0x80, 0xff, 0xfe, 0x03, 0xff, 0xff, 
0xff, 0xff, 0xf8, 0xff, 0x87, 0xfe, 0x0c, 0xff, 0xf0, 0x1f, 0xff, 0xff, 
0xff, 0xff, 0xe7, 0xfc, 0x7f, 0xff, 0xfe, 0xf8, 0x01, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x9f, 0xe3, 0xff, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xff, 0xff, 
0xff, 0xfe, 0x7f, 0x8f, 0xff, 0xf9, 0xfe, 0x1f, 0xdf, 0xff, 0xff, 0xff, 
0xff, 0xf8, 0xfe, 0x7f, 0xff, 0xe7, 0xcf, 0x7f, 0xbf, 0xff, 0xff, 0xff, 
0xff, 0xe3, 0xf9, 0xff, 0xff, 0x8f, 0x9f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
0xff, 0xcf, 0xe7, 0xff, 0xfe, 0x3f, 0x3e, 0xfc, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x1f, 0x9f, 0xff, 0xf8, 0xfc, 0xfc, 0xf1, 0xff, 0xff, 0xff, 0xff, 
0xfe, 0x7e, 0x3f, 0xff, 0xc7, 0xf1, 0xf3, 0x0f, 0xff, 0xff, 0xff, 0xff, 
0xfc, 0xfe, 0xff, 0xf8, 0x3f, 0xe7, 0xc0, 0x7f, 0xff, 0xff, 0xff, 0xff, 
0xf9, 0xff, 0xff, 0x81, 0xff, 0x9f, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xf7, 0xff, 0xff, 0xbf, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xef, 0xff, 0x9f, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xc0, 0x00, 0x3f, 0xff, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfe, 0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfe, 0xfe, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfc, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static const unsigned long palette_LPRocket_96x37_1BPP_UNCOMP[]=
{
	0x000000, 	0xffffff
};

const tImage  LPRocket_96x37_1BPP_UNCOMP=
{
	IMAGE_FMT_1BPP_UNCOMP,
	96,
	37,
	2,
	palette_LPRocket_96x37_1BPP_UNCOMP,
	pixel_LPRocket_96x37_1BPP_UNCOMP,
};
