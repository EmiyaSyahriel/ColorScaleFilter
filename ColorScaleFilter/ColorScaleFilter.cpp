// ColorScaleFilter.cpp : Defines the entry point for the application.
//

#include "ColorScaleFilter.h"
#include "Macros.h"

PSW::ColorScale::ColorScale(PClip _child, int omin, int omax, int nmin, int nmax, IScriptEnvironment* env)
	:GenericVideoFilter(_child), oldMin(omin), oldMax(omax), newMin(nmin), newMax(nmax)
{}

PSW::ColorScale::~ColorScale()
{}

PVideoFrame __stdcall PSW::ColorScale::GetFrame(int n, IScriptEnvironment* env)
{
	PVideoFrame src = child->GetFrame(n, env);
	env->MakeWritable(&src);

	unsigned char* srcp = src->GetWritePtr();
	int src_pitch = src->GetPitch();
	int src_width = src->GetRowSize();
	int src_height = src->GetHeight();

	int x, y;

    if (vi.IsRGB())
    {
        int cCount = vi.IsRGB32() ? 4 : 3;
        for (y = 0; y < src_height; y++) 
        {
            for (x = 0; x < src_pitch; x += cCount) 
            {
                int r = *(srcp + x + 0);
                int g = *(srcp + x + 1);
                int b = *(srcp + x + 2);
                doScaleColor(r, g, b);
                *(srcp + x + 0) = r;
                *(srcp + x + 1) = g;
                *(srcp + x + 2) = b;
            }
            srcp += src_pitch;
        }
    }

	return src;
}

void PSW::ColorScale::doScaleColor(int& r, int& g, int& b)
{
	float oR = invlerp(oldMin, oldMax, r * 1.0F), oG = invlerp(oldMin, oldMax, g * 1.0F), 
        oB = invlerp(oldMin, oldMax, b * 1.0F);
	r = (int)lerp(newMin * 1.0F, newMax* 1.0F, oR);
	g = (int)lerp(newMin * 1.0F, newMax* 1.0F, oG);
	b = (int)lerp(newMin * 1.0F, newMax* 1.0F, oB);
}
