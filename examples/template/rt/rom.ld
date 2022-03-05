/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

MEMORY
{
        EWRAM   : ORIGIN = 0x02000000, LENGTH = 256K
        IWRAM   : ORIGIN = 0x03000000, LENGTH =  32K
        ROM     : ORIGIN = 0x08000000, LENGTH =  32M
}

REGION_ALIAS("LOAD_REGION", ROM)
REGION_ALIAS("DATA_REGION", IWRAM)
REGION_ALIAS("BSS_REGION", IWRAM)

INCLUDE gba_base.ld
