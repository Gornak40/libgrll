/*
 * Beware!
 * This library is only authorized for use by giant silverback gorillas at programming contests.
 *
 * File: libgrll.h
 * Author: Alexander Gornak
 * Copyright (c) 2024 Alexander Gornak
 *
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* vec;

typedef struct {
	size_t len;
	size_t cap;
	size_t sz1;
} __vec_Meta;

#define __vec_meta(v) ((__vec_Meta*)(v))[-1]

#define __vec_SZOF_META sizeof(__vec_Meta)

#define __vec_void(v) ((v)-__vec_SZOF_META)

vec vec_new(size_t len, size_t cap, size_t sz1) {
	__vec_Meta meta = {.cap = cap, .len = len, .sz1 = sz1};
	void* data = malloc(__vec_SZOF_META + cap * sz1);
	*(__vec_Meta*)data = meta;
	return data + __vec_SZOF_META;
}

#define vec_delete(v) free(__vec_void(v))

#define vec_i(v, i, t) ((t*)(v))[i]

#define vec_len(v) (__vec_meta(v).len)

#define vec_cap(v) (__vec_meta(v).cap)

#define vec_sz1(v) (__vec_meta(v).sz1)

#define __vec_sz(v) (__vec_SZOF_META + vec_cap(v) * vec_sz1(v))

#define vec_copy(v) (memcpy(malloc(__vec_sz(v)), __vec_void(v), __vec_sz(v)) + __vec_SZOF_META)

#define vec_clear(v) (vec_sz(v) = 0)

#define __vec_scale(v) (realloc(__vec_void(v), __vec_SZOF_META + (vec_cap(v) <<= 1) * vec_sz1(v)) + __vec_SZOF_META)

#define vec_push(v, x, t) (vec_len(v) == vec_cap(v) ? (v = __vec_scale(v)) : (NULL), vec_i(v, vec_len(v)++, t) = (x))

#define vec_pop(v) (--vec_len(v))

#define vec_top(v, t) (vec_i(v, vec_len(v) - 1, t))
