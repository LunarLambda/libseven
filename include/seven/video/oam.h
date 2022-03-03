/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_OAM_H
#define _LIBSEVEN_VIDEO_OAM_H

#include <seven/base.h>
#include <seven/video/matrix.h>
#include <seven/video/object.h>

_LIBSEVEN_EXTERN_C

usize oamWriteObjects(usize oam_index, struct Object *objs, usize n_objs);
usize oamWriteObjectsUnchecked(usize oam_index, struct Object *objs, usize n_objs);

usize oamWriteMatrices(usize oam_index, struct Matrix *mats, usize n_mats);
usize oamWriteMatricesUnchecked(usize oam_index, struct Matrix *mats, usize n_mats);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_OAM_H */
