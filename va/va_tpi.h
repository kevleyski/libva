/*
 * Copyright (c) 2007-2009 Intel Corporation. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL INTEL AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* Wrap a CI (camera imaging) frame as a VA surface to share captured video between camear
 * and VA encode. With frame_id, VA driver need to call CI interfaces to get the information
 * of the frame, and to determine if the frame can be wrapped as a VA surface
 *
 * Application should make sure the frame is idle before the frame is passed into VA stack
 * and also a vaSyncSurface should be called before application tries to access the frame
 * from CI stack
 */

#include <va/va.h>
VAStatus vaCreateSurfaceFromCIFrame (
    VADisplay dpy,
    unsigned long frame_id,
    VASurfaceID *surface	/* out */
);

VAStatus vaCreateSurfaceFromV4L2Buf(
    VADisplay dpy,
    int v4l2_fd,         /* file descriptor of V4L2 device */
    struct v4l2_format *v4l2_fmt,       /* format of V4L2 */
    struct v4l2_buffer *v4l2_buf,       /* V4L2 buffer */
    VASurfaceID *surface	/* out */
);

VAStatus vaPutSurfaceBuf (
    VADisplay dpy,
    VASurfaceID surface,
    Drawable draw, /* Android Surface/Window */
    unsigned char* data,
    int* data_len,
    short srcx,
    short srcy,
    unsigned short srcw,
    unsigned short srch,
    short destx,
    short desty,
    unsigned short destw,
    unsigned short desth,
    VARectangle *cliprects, /* client supplied clip list */
    unsigned int number_cliprects, /* number of clip rects in the clip list */
    unsigned int flags /* de-interlacing flags */
);
