#ifndef noiseH
#define noiseH

float	noise3(const fVector3& vec);
float	fractalsum3(const fVector3& v, float freq, int octaves);
float	turbulence3(const fVector3& v, float freq, int octaves);

#endif
