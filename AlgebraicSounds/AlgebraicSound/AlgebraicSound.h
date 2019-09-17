// ---------------------------------------------------------------------------

#ifndef AlgebraicSoundH
#define AlgebraicSoundH

#include <stdlib.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <cfloat>
#include <memory>
#include <vector>

using std::string, std::stof, std::min, std::max, std::vector, std::distance;

class AlgebraicSound  {
public:

    float x=0, t=0, tlap=0, deltaLap=0;
    float delta, secs;
    int sampleRate, channels=2;
    float maxVol, midVol, phi=0.618033988749895, pi=M_PI;
    float yL=0, yR=0, maxL, minL, maxR, minR, diffL, diffR, scaleL, scaleR;

public:
    AlgebraicSound(float secs, int sampleRate) : secs(secs), sampleRate(sampleRate) { // secs <=0 infinite
        init();
    }
    AlgebraicSound(float secs, int sampleRate, string name) : secs(secs), sampleRate(sampleRate), name(name) { // secs <=0 infinite
        init();
    }

    void set_channels(int channels) { this->channels=channels; init(); }
    string name;

    // works with  'x'
    virtual float evalLeft() = 0; // pure virtual
    virtual float evalRight() = 0;

    float *gen_mono(float amp, float*fbuff, int bs) {
        for (int i = 0; i < bs; i++) { // mono float
            yL = scaleL * evalLeft();
            yR = scaleR * evalRight();
            fbuff[i] = amp*(yL+yR)/2.;
            nextX();
        }
        return fbuff;
    }
    float *gen_stereo(float amp, float*fbuff, int bs) { // stereo -> buffer[bs*2]
        for (int i = 0; i < bs*2; i += 2) { // stereo float
            fbuff[i + 0] = amp * scaleL * evalLeft();
            fbuff[i + 1] = amp * scaleR * evalRight();
            nextX();
        }
        return fbuff;
    }

    float *generate(float amp, float*buff, int bs) {  return (channels==2) ? gen_stereo(amp, buff, bs) : gen_mono(amp, buff, bs);    }

    void init() {
        yL = yR = 0;
        tlap = x = t = 0;
        delta = (2. * M_PI) / (float)sampleRate;
        deltaLap = 1. / (float)sampleRate;
        maxVol = 1;
        midVol = maxVol / 2;

        diffL = diffR = 0;
        scaleL = scaleR = 1;
    }

    void reset() {
        tlap = x = t = 0;
    }

    int setSampleRate(int sampleRate) {
        this->sampleRate = sampleRate;
        init();
        return sampleRate;
    }

    float nextX() {
        if ((secs > 0) && (tlap += deltaLap) > secs)
            reset();
        x += delta;
        t = x;
        return t;
    }

    float getX() {
        return t = x;
    }

    void updateMinMax() {
        minL = min(yL, minL);        maxL = max(yL, maxL);        diffL = fabs(maxL - minL);
        minR = min(yR, minR);        maxR = max(yR, maxR);        diffR = fabs(maxR - minR);
    }

    void scale() {
        minL = minR = +FLT_MAX;
        maxL = maxR = -FLT_MAX;

        for (int i=0; i<1000; i++) {
            yL = evalLeft(); yR = evalRight();
            updateMinMax();
            for (int j = 0; j < 5; j++) nextX();
        }
        x = t = tlap = 0;
        scaleL =  maxVol / diffL;
        scaleR =  maxVol / diffR;
    }

    float wave(float vol, float freq) { return vol * sin(freq); }
    int secs2nBuff(float secs, int buffSize) { // secs2nBuff for stereo -> x2
        return (int)(2. * secs * (float)sampleRate / (float)buffSize);
    }
//    float note(int note, int octave) {        return sin(x * NoteOct2Freq(note, octave));    }
    float osc(float f) {          		return sin(x * f);	}
//    float hz2oct(float f, int o) {        return FreqInOctave(f, o);    }
    float sec(float x) {          		return x * 2 * pi;	}
    float lap(float tfrom, float tto) {  return (tlap > tfrom && tlap < tto) ? 1 : 0;	}
};
#endif
