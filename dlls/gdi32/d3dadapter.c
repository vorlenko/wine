/*
 * d3dadapter function forwarding to the display driver
 *
 * Copyright (c) 1999 Lionel Ulmer
 * Copyright (c) 2005 Raphael Junqueira
 * Copyright (c) 2006 Roderick Colenbrander
 * Copyright (c) 2013 Joakim Sindholt
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "gdi_private.h"

/***********************************************************************
 *      __wine_get_d3dadapter_driver  (GDI32.@)
 */
struct d3dadapter_funcs * CDECL __wine_get_d3dadapter_driver( HDC hdc, UINT version )
{
    struct d3dadapter_funcs *ret = NULL;
    DC * dc = get_dc_ptr( hdc );

    if (dc)
    {
        PHYSDEV physdev = GET_DC_PHYSDEV( dc, wine_get_d3dadapter_driver );
        ret = physdev->funcs->wine_get_d3dadapter_driver( physdev, version );
        release_dc_ptr( dc );
    }
    return ret;
}