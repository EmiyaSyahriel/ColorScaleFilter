#pragma once

/* Simple Linear Interpolation */
#define lerp(a,b,t) (a + ((b-a) * t))
#define invlerp(a,b,v) ((v - a) / (b - a))