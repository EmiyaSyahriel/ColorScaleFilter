# PSW ColorScale Filter
### A Simple AviSynth 2.6.0 Filter to Scale Color

## Usage
```avisynth
LoadPluglin("ColorScaleFilter.dll")
clip = DirectShowSource("K:\SAMPLES\kururiuta_720p60.mp4",video=true,audio=true)
PSWColorScale(clip, 0, 255, 16, 235)
```

## Filter Functions
`PSWColorScale(clip, old_min, old_max, new_min, new_max)` :
Scale color ranging from (old_max - old_min) to (new_max - new_min)

## License
Free for Public Use!