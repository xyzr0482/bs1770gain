/*
 * pbu_s2w.c
 * Copyright (C) 2014 Peter Belkner <pbelkner@users.sf.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2.0 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301  USA
 */
#if defined (_WIN32) // {
#include <pbutil_priv.h>

wchar_t *pbu_s2w(const char *s)
{
  size_t size;
  wchar_t *w;

  w=NULL;

  if (NULL==s)
    goto w;

  size=MultiByteToWideChar(
    CP_UTF8,      // __in       UINT CodePage,
    0,            // __in       DWORD dwFlags,
    s,            // __in       LPCSTR lpMultiByteStr,
    -1,           // __in       int cbMultiByte,
    NULL,         // __out_opt  LPWSTR lpWideCharStr,
    0             // __in       int cchWideChar
  );

  if (NULL==(w=MALLOC(size*(sizeof *w))))
    goto w;

  size=MultiByteToWideChar(
    CP_UTF8,      // __in       UINT CodePage,
    0,            // __in       DWORD dwFlags,
    s,            // __in       LPCSTR lpMultiByteStr,
    -1,           // __in       int cbMultiByte,
    w,            // __out_opt  LPWSTR lpWideCharStr,
    size          // __in       int cchWideChar
  );
w:
  return w;
}
#endif // }
