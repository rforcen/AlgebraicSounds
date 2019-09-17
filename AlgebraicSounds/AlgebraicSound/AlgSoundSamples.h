#ifndef AlgSoundSamplesH
#define AlgSoundSamplesH
#include "AlgebraicSound.h"

class Template : public AlgebraicSound {
public:
    Template(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "template") {
        scale(); // scale vals always here
    }
    // use  param 't'
    float evalLeft() {   return sinf(444 / sinf(3 / (t + 1))) * sinf(2 * t);    }
    float evalRight() {   return sinf(440 / sinf(3 / (t + 1))) * sinf(2 * t);   }
};

class Relax01 : public AlgebraicSound {
    float pitch;
    
public:
    Relax01(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "relax1") {
        pitch = 440;
        scale(); // scale vals always here
    }
    
    // use  param 't'
    float evalLeft() {  return sinf(444 * t * expf(-0.00051 * t)) * cosf(4 * t) * expf(-0.05 * t);   }
    float evalRight() { return sinf(440 * t * expf(-0.00051 * t)) * cosf(4 * t) * expf(-0.05 * t);   }
};

class Relax : public AlgebraicSound {
    
    float pitch;
    
public:
    Relax(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "relax") {
        pitch = 440;
        scale(); // scale vals always here
    }
    
    float evalLeft()  { return sinf(2 * t) * expf(-0.2 * t) * sinf(pitch * t);    }
    float evalRight() { return sinf(2 * t) * expf(-0.2 * t) * sinf((pitch + 2) * t);  }
};

class WaterPhi : public AlgebraicSound {
    float f0, div, fact1, fact2, diff;
    
public:
    WaterPhi(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "water phi") {
        f0 = 440; div = 5; fact1 = 1.618; fact2 = 0.618; diff = 4;
        scale(); // scale vals always here
    }
    
    float evalLeft() { // use  param 't'
        return fact1*sinf(2 * t) * sinf(t * f0) * sinf(div / (t + 1)) +
        sinf(2 * t) * sinf(t * fact1 * f0) * sinf(div / (t + 1)) +
        fact2 * sinf(2 * t) * sinf(t * fact2 * f0) * sinf(div / (t + 1)) +
        0.3 * sinf(2 * t) * sinf(t * 140) * sinf(div / (t + 1));
    }
    
    float evalRight() {
        return fact1*sinf(2 * t) * sinf(t * (f0 + diff)) * sinf(div / (t + 1)) +
        sinf(2 * t) * sinf(t * fact1 * (f0 + diff)) * sinf(div / (t + 1)) +
        fact2 * sinf(2 * t) * sinf(t * fact2 * (f0 + diff)) * sinf
        (div / (t + 1)) + 0.3 * sinf(2 * t) * sinf(t * 140) * sinf
        (div / (t + 1));
        
    }
    
};

class WaWaDiff : public AlgebraicSound {
    float f0, div, fact1, fact2, diff;
    
public:
    WaWaDiff(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "wa diff") {
        f0 = 440; div = 10; fact1 = 1.618; fact2 = 0.618; diff = 4;
        scale(); // scale vals always here
    }
    
    float evalLeft() { // use  param 't'
        return fact1*sinf(3 * t) * sinf(t * f0) * sinf(div / (t + 1)) +
        sinf(3 * t) * sinf(t * fact1 * f0) * sinf(div / (t + 1)) +
        fact2 * sinf(3 * t) * sinf(t * fact2 * f0) * sinf(div / (t + 1)) +
        0.3 * sinf(3 * t) * sinf(t * 140) * sinf(div / (t + 1));
    }
    
    float evalRight() {
        return fact1*sinf(3 * t) * sinf(t * (f0 + diff)) * sinf(div / (t + 1)) +
        sinf(3 * t) * sinf(t * fact1 * (f0 + diff)) * sinf(div / (t + 1)) +
        fact2 * sinf(3 * t) * sinf(t * fact2 * (f0 + diff)) * sinf
        (div / (t + 1)) + 0.3 * sinf(3 * t) * sinf(t * 140) * sinf
        (div / (t + 1));
    }
    
};

class YinYang : public AlgebraicSound {
    float f0, f1;
    
public:
    YinYang(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "yin yang") {
        f0 = 440; f1 = 444;
        scale();
        // scale vals always here
    }
    
    float evalLeft() { // use  param 't'
        return 1.0 * sinf(t * f0) * sinf
        (f0 / (t + sec(3)) + 0.6 * sinf(t * f0 * 2 / 3) * sinf
         (f0 * 2 / 3 / (t + sec(3)) + 0.2 * sinf(t * f0 / 6) * sinf
          ((f0 / 6) / (t + sec(2)))));
    }
    
    float evalRight() {
        return 1.0 * sinf(t * f1) * sinf
        (f1 / (t + sec(3)) + 0.6 * sinf(t * f1 * 2 / 3) * sinf
         (f1 * 2 / 3 / (t + sec(3)) + 0.2 * sinf(t * f1 / 6) * sinf
          ((f1 / 6) / (t + sec(2)))));
    }
};

class Insect : public AlgebraicSound {
public:
    Insect(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "insect") {
        scale(); // scale vals always here
    }
    
    float eval() {
        return sinf(phi * t) * sinf((1 / powf(phi, 6)) * t) * sinf
        ((1 / powf(phi, 15)) * t);
    }
    
    float evalLeft() { // use  param 't'
        return eval();
    }
    
    float evalRight() {
        return eval();
    }
};

//class DoMajorMetallic : public AlgebraicSound {
//public:
//    float f0;
//
//    DoMajorMetallic(float secs, int sampleRate)
//        : AlgebraicSound(secs, sampleRate, "do major metallic") {
//        f0 = 440;
//        scale();
//        // scale vals always here
//    }
//
//    float evalLeft() { // use  param 't'
//        return osc(hz2oct(f0, -8) * osc(lap(0, 1) * f0 + lap(1, 2) * f0 * 0.79 +
//                                        lap(2, 5) * f0 * 0.66));
//    }
//
//    float evalRight() {
//        return osc(hz2oct(f0, -8) * osc(lap(0, 1) * f0 + lap(1, 2) * f0 * 0.79 +
//                                        lap(2, 5) * f0 * 0.66));
//    }
//};

class Test : public AlgebraicSound {
public:
    Test(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "test") {
        name="test";
        scale(); // scale vals always here
    }
    
    float evalLeft() {   return sinf(444 * t) * sinf(2 * t);    }
    float evalRight() {  return sinf(440 * t) * sinf(2 * t);    }
};

// * Sample usage Demo a=new Demo(secs);

class Flower : public AlgebraicSound {
public:
    Flower(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "flower") {
        am = 3.14; f = 409.27; d = 10; f1 = 411; rc = pi; name="Flower";
        scale();
    } // play 'secs' seconds
    
    float am, f, d, f1, rc;
    
    float flowerR() {
        // return sinf(440 * t);
        return sinf(am * t) * sinf(t * f) * sinf((f / d) / (t + 1.)) +
        phi * sinf(am * t) * sinf(t * f * phi) * sinf((f * phi / d) / (t + 1.))
        + (phi / 3.) * sinf(am * t) * sinf(t * f * 2.) * sinf
        ((f * 2. / d) / (t + 1.));
    }
    
    float flowerL() {
        // return sinf(444 * t);
        return sinf(am * t) * sinf(t * (f + rc)) * sinf(((f + rc) / d) / (t + 1.))
        + phi * sinf(am * t) * sinf(t * (f + rc) * phi) * sinf
        (((f + rc) * phi / d) / (t + 1.)) + (phi / 3.) * sinf(am * t) * sinf
        (t * (f + rc) * 2.) * sinf(((f + rc) * 2. / d) / (t + 1.));
    }
    
    float evalLeft() {
        return flowerL();
    } // use  param 'x' must be in the range +-Short.Max_VALUE
    
    float evalRight() {
        return flowerR();
    }
};

class MySound : public AlgebraicSound { // default ETG sound
    
public:
    float f0, f1;
    
    MySound(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "default") {
        f0 = 440; f1 = 294;
        float mult = 1;
        f0 *= mult; f1 *= mult;
        scale();
    }
    
    float evalLeft() {
        return 1.0 * sinf(t * 440) * sinf(440 / (t + sec(3)) + 0.6 * sinf(t * 294)
                                          * sinf(294 / (t + sec(3)) + 0.2 * sinf(t * 294 / 4) * sinf
                                                 ((294 / 4) / (t + sec(2)))));
    }
    
    float evalRight() {
        return 1.0 * sinf(t * 440) * sinf(440 / (t + sec(3)) + 0.6 * sinf(t * 294)
                                          * sinf(294 / (t + sec(3)) + 0.2 * sinf(t * 294 / 4) * sinf
                                                 ((294 / 4) / (t + sec(2)))));
    }
    
};

class AlienMarch : public AlgebraicSound {
public:
    AlienMarch(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "alien") {
        scale();
    }
    
    float alienMarch() {
        return sinf(10 / (t + 1)) * (sinf(t * (1 + sinf(t * 80))) +
                                     sinf(t * (1 + sinf(t * 180)))) * osc(2.5);
    }
    
    float evalLeft() {
        return alienMarch();
    } // use  param 'x' must be in the range +-Short.Max_VALUE
    
    float evalRight() {
        return alienMarch();
    }
};

class VoiceRhythm : public AlgebraicSound {
public:
    VoiceRhythm(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "voice rhythm")
    {
        f = 350;
        scale();
    } // play 'secs' seconds
    
    float f;
    
    float voiceRithm() {
        return 1.6 * sinf(3 * t) * sinf(t * f) * sinf(44 / (t + 1)) +
        sinf(3 * t) * sinf(t * 1.6 * f) * sinf(44 / (t + 1)) + 0.6 * sinf(3 * t)
        * sinf(t * 0.6 * f) * sinf(44 / (t + 1));
    }
    
    float evalLeft() {
        return voiceRithm();
    } // use  param 'x' must be in the range +-Short.Max_VALUE
    
    float evalRight() {
        return voiceRithm();
    }
};

class Bowl : public AlgebraicSound {
public:
    Bowl(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate, "bowl") {
        f0 = 440; f1 = 293.7; delay = 3; bal = 0.3;
        scale();
    } // play 'secs' seconds
    
    float f0, f1, delay, bal;
    
    float bowlR() {
        return (1 + osc(bal)) *
        (osc(f0) * sinf(f0 / (t + sec(delay)) + phi * osc(f1) * sinf
                        (f1 / (t + sec(delay)))));
    }
    
    float bowlL() {
        return osc(bal) * (osc(f0) * sinf(f0 / (t + sec(delay)) +
                                          phi * osc(f1) * sinf(f1 / (t + sec(delay)))));
    }
    
    float evalLeft() {
        return bowlL();
    } // use  param 'x' must be in the range +-Short.Max_VALUE
    
    float evalRight() {
        return bowlR();
    }
};

class HarmonicExpansion : public AlgebraicSound {
public:
    HarmonicExpansion(float secs, int sampleRate)
    : AlgebraicSound(secs, sampleRate, "harmonic expansion") {
        f0 = 194.18; rc = 3;
        scale();
    } // play 'secs' seconds
    
    float f0, rc;
    
    float aexR() {
        return expf(-0.3 * t) * (sinf(sinf(f0 * t) * t) +
                                 phi * sinf(sinf(f0 * t) * t));
    }
    
    float aexL() {
        return expf(-0.3 * t) * (sinf(sinf((f0 + rc) * t) * t) +
                                 phi * sinf(sinf((f0 + rc) * t) * t));
    }
    
    float evalLeft() {
        return aexR();
    } // use  param 'x' must be in the range +-Short.Max_VALUE
    
    float evalRight() {
        return aexL();
    }
};

class HasrmonicVibs : public AlgebraicSound { // too complex for an arm cpu
    
public:
    HasrmonicVibs(float secs, int sampleRate)
    : AlgebraicSound(secs, sampleRate, "harmonic vibs") {
        fact1 = 1.6; fact2 = .6; f0 = 194; div = 10; diff = 4;
        scale();
    } // play 'secs' seconds
    
    float fact1, fact2, f0, div, diff;
    
    float hvR() {
        return fact1*sinf(3 * t) * sinf(t * f0) * sinf(div / (t + 1)) +
        sinf(3 * t) * sinf(t * fact1 * f0) * sinf(div / (t + 1)) +
        fact2 * sinf(3 * t) * sinf(t * fact2 * f0) * sinf(div / (t + 1)) +
        0.3 * sinf(3 * t) * sinf(t * 140) * sinf(div / (t + 1));
    }
    
    float hvL() {
        return fact1*sinf(3 * t) * sinf(t * (f0 + diff)) * sinf(div / (t + 1)) +
        sinf(3 * t) * sinf(t * fact1 * (f0 + diff)) * sinf(div / (t + 1)) +
        fact2 * sinf(3 * t) * sinf(t * fact2 * (f0 + diff)) * sinf
        (div / (t + 1)) + 0.3 * sinf(3 * t) * sinf(t * 140) * sinf
        (div / (t + 1));
    }
    
    float evalLeft() {
        return hvL();
    } // use  param 'x' must be in the range +-Short.Max_VALUE
    
    float evalRight() {
        return hvR();
    }
};

class Demo : public AlgebraicSound {
public:
    float fp;
    float am, f, d, f1, rc;
    
    Demo(float secs, int sampleRate) : AlgebraicSound(secs, sampleRate) {
        fp = 194.18;
        am = 3.14; f = 409.27; d = 10; f1 = f + 2; rc = pi;
        scale();
    } // play 'secs' seconds
    
    float evalSin440() {  return maxVol*sinf(440 * x);   } // evaluators samples, remember 'maxVol'
    float evalSin444() {  return maxVol*sinf(444 * x);    }
    float eval1()      {  return evalSin440();    }
    float eval2()      {  return wave(maxVol, 480);    }
    //    float eval3()      {  return maxVol*note(0, 0);    }
    //    float eval4()      {  return wave(1, 1, 3) * wave(490 * (1 + wave(2, 1, 14)));   }
    float eval5()      {  return evalSin444();    }
    float bwL()        {  return wave(0, 440);    }
    float bwR()        {  return wave(1, 444);    }
    //    float planetL()    {  return osc(hz2oct(fp, -7)) * osc(fp);   }
    //    float planetR()    {  return osc(hz2oct(fp, -7)) * osc(fp * (1 + expf(-1 / (2 * x + 1)))) +
    //                phi * osc(hz2oct(fp * phi, -1)) + phi * osc(hz2oct(fp * phi, 1));    }
    float alienMarch() {  return sinf(10 / (t + 1)) * (sinf(t * (1 + sinf(t * 80))) +
                                                       sinf(t * (1 + sinf(t * 180)))) * osc(2.5);    }
    float voiceRithm() {  return 1.6 * sinf(3 * t) * sinf(t * 440) * sinf(44 / (t + 1)) +
        sinf(3 * t) * sinf(t * 1.6 * 440) * sinf(44 / (t + 1)) +
        0.6 * sinf(3 * t) * sinf(t * 0.6 * 440) * sinf(44 / (t + 1));}
    float flowerR() {     return sinf(am * t) * sinf(t * f) * sinf((f / d) / (t + 1)) +
        phi * sinf(am * t) * sinf(t * f * phi) * sinf((f * phi / d) / (t + 1))
        + (phi / 3) * sinf(am * t) * sinf(t * f * 2) * sinf
        ((f * 2 / d) / (t + 1));}
    float flowerL() {
        return sinf(am * t) * sinf(t * (f + rc)) * sinf(((f + rc) / d) / (t + 1)) +
        phi * sinf(am * t) * sinf(t * (f + rc) * phi) * sinf
        (((f + rc) * phi / d) / (t + 1)) + (phi / 3) * sinf(am * t) * sinf
        (t * (f + rc) * 2) * sinf(((f + rc) * 2 / d) / (t + 1));
    }
    
    //    float evalLeft()   {   return planetL();   } // use  param 'x' must be in the range +-Short.Max_VALUE
    //    float evalRight()  {   return planetR();   }
};

// Hans Cousto Cosmic Octave implementation
class CosmicOctave {
public:
    string sCosmicOctave[3*13]= {
        "Earth-day",        "194.18", "dynamic, vitalizing",
        "Earth-year",       "136.10", "relaxing, soothing, balancing",
        "Platonic Year",    "172.06", "cheerfulness, clarity of spirit",
        "Moon (synodic)",   "210.42", "erotic communication, sexual energy",
        "Sun",              "126.22", "feeling of centering and magic",
        "Mercury",          "141.27", "intellectual communication",
        "Venus",            "221.23", "higher love energy, aspiration for harmony",
        "Mars",             "144.72", "strenght of will and fucused energy",
        "Jupiter",          "183.58", "creative power and continous construction",
        "Saturn",           "147.85", "concentration, becoming conscious",
        "Uranus",           "207.36", "power of surprise and renewal",
        "Neptun",           "211.44", "intuition, dream experience",
        "Pluto",            "140.25", "magic group dynamic"};
    
    string getPlanet(int i) {  return sCosmicOctave[i * 3];    }
    float getFreq(int i)    {  return stof(sCosmicOctave[i * 3 + 1]);    }
    string getDesc(int i)   {  return sCosmicOctave[i * 3 + 2];    }
};


/*
 * hans cousto planet freq. table (http://www.planetware.de/octave/cosmic-octave.html)
 * The Cosmic Octave
 
 In 1978 Hans Cousto, a Swiss mathematician and musicologist discovered the natural law of the "Cosmic Octave"
 as the link between different kinds of perodically occurring natural phenomena,
 such as the orbit of the planets, the weather, colors, rhythms and tones.
 
 cycle			Hertz	effects (keywords).
 Earth-day		194.18	dynamic, vitalizing
 Earth-year		136.10	relaxing, soothing, balancing
 Platonic Year          172.06	cheerfulness, clarity of spirit
 Moon (synodic)         210.42	erotic communication, sexual energy
 Sun                    126.22	feeling of centering and magic
 Mercury		141.27	intellectual communication
 Venus			221.23	higher love energy, aspiration for harmony
 Mars			144.72	strenght of will and fucused energy
 Jupiter		183.58	creative power and continous construction
 Saturn			147.85	concentration, becoming conscious
 Uranus			207.36	power of surprise and renewal
 Neptun			211.44	intuition, dream experience
 Pluto			140.25	magic group dynamic
 */
#endif
