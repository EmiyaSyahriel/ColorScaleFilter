#pragma once
#include <windows.h>
#include <avisynth.h>

namespace PSW {
	class ColorScale : public GenericVideoFilter {
	private:
		int oldMin, oldMax, newMin, newMax;
		void doScaleColor(int& r, int& g, int& b);
	public :
		ColorScale(PClip _child, int omin, int omax, int nmin, int nmax, IScriptEnvironment* env);
		~ColorScale();
		PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
	};
}

AVSValue __cdecl Create_SimpleSample(AVSValue args, void* user_data, IScriptEnvironment* env) {
	return new PSW::ColorScale(args[0].AsClip(),
		args[1].AsInt(0),
		args[2].AsInt(255),
		args[3].AsInt(16),
		args[4].AsInt(240),
		env);
}

const AVS_Linkage* AVS_linkage = 0;

extern "C" __declspec(dllexport) const char* __stdcall AvisynthPluginInit3(
	IScriptEnvironment * env, 
	const AVS_Linkage* const vectors
) {
	AVS_linkage = vectors;
	env->AddFunction("PSWColorScaler", "c[old_min]i[old_max]i[new_min]i[new_max]i", Create_SimpleSample, 0);
	return "PSW ColorScaler plugin";
}