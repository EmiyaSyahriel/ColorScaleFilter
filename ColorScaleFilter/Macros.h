#pragma once

/* Simple Linear Interpolation */
#define lerp(a,b,t) (a + ((b-a) * t))
/* Simple Inverse Linear Interpolation */
#define invlerp(a,b,v) ((v - a) / (b - a))