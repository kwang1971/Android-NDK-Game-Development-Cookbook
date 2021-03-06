/*
 * Copyright (C) 2013 Sergey Kosarevsky (sk@linderdaum.com)
 * Copyright (C) 2013 Viktor Latypov (vl@linderdaum.com)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must display the names 'Sergey Kosarevsky' and
 *    'Viktor Latypov'in the credits of the application, if such credits exist.
 *    The authors of this work must be notified via email (sk@linderdaum.com) in
 *    this case of redistribution.
 *
 * 3. Neither the name of copyright holders nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

unsigned char* read_bmp_mem( const unsigned char* data, int* w, int* h )
{
	const unsigned char* head = data;
	*w = head[18] + ( ( ( int )head[19] ) << 8 ) + ( ( ( int )head[20] ) << 16 ) + ( ( ( int )head[21] ) << 24 );
	*h = head[22] + ( ( ( int )head[23] ) << 8 ) + ( ( ( int )head[24] ) << 16 ) + ( ( ( int )head[25] ) << 24 );
	const int fileSize = ( ( *w ) * 3 + ( ( *w ) % 4 ) ) * ( *h );
	unsigned char* img = ( unsigned char* )malloc( ( *w ) * ( *h ) * 3 );
	data += 54;
	int i, j, k, rev_j;

	for ( j = 0, rev_j = ( *h ) - 1; j < ( *h ) ; j++, rev_j-- )
	{
		for ( i = 0 ; i < ( *w ) ; i++ )
		{
			int fpos = j * ( ( *w ) * 3 + ( *h ) % 4 ) + i * 3, pos = rev_j * ( *w ) * 3 + i * 3;

			for ( k = 0 ; k < 3 ; k++ ) { img[pos + k] = data[fpos + ( 2 - k )]; }
		}
	}

	return img;
}
