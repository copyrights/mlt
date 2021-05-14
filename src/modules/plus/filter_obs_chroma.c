/*
 * filter_obs_chroma.c -- Maps a chroma key to the alpha channel
 * Copyright (C) 2021 Frank Adaemmer
 * Author: Frank Adaemmer <copyrights@mailbox.org>
 *
 * This code is base on
 * <https://github.com/obsproject/obs-studio/blob/master/plugins/obs-filters/chroma-key-filter.c>
 * and
 * <https://github.com/obsproject/obs-studio/blob/master/plugins/obs-filters/data/chroma_key_filter.effect>
 * licensed under GNU General Public License version 2.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>
 */

#include <framework/mlt_filter.h>
#include <framework/mlt_factory.h>
#include <framework/mlt_frame.h>
#include <framework/mlt_producer.h>

#include <stdlib.h>
#include <string.h>


static int filter_pass_1( mlt_frame frame, uint8_t **image, mlt_image_format *format, int *width, int *height, int writable )
{

}

static int filter_pass_2( mlt_frame frame, uint8_t **image, mlt_image_format *format, int *width, int *height, int writable )
{

}


/** Filter processing.
*/

static mlt_frame filter_process( mlt_filter filter, mlt_frame frame )
{
	mlt_frame_push_service( frame, filter );
	mlt_frame_push_service( frame, filter_pass_1 );
	mlt_frame_push_service( frame, filter_pass_2 );
	return frame;
}

/** Constructor for the filter.
*/

mlt_filter filter_obs_chroma_init( mlt_profile profile, mlt_service_type type, const char *id, char *arg )
{
	mlt_filter this = mlt_filter_new( );
	if ( this != NULL )
	{
		mlt_properties_set_int( MLT_FILTER_PROPERTIES( this ), "chroma", 0x00ff00 );
		mlt_properties_set_double( MLT_FILTER_PROPERTIES( this ), "similarity", 0.15 );
        mlt_properties_set_double( MLT_FILTER_PROPERTIES( this ), "smoothness", 80.0 );
        mlt_properties_set_double( MLT_FILTER_PROPERTIES( this ), "spill", 100.0 );
        mlt_properties_set_double( MLT_FILTER_PROPERTIES( this ), "opacity", 100.0 );
        mlt_properties_set_double( MLT_FILTER_PROPERTIES( this ), "contrast", 0.0 );
        mlt_properties_set_double( MLT_FILTER_PROPERTIES( this ), "brightness", 0.0 );
        mlt_properties_set_double( MLT_FILTER_PROPERTIES( this ), "gamma", 0.0 );

		this->process = filter_process;
	}
	return this;
}
