#include "AlgSoundSamples.h"


#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

namespace p = boost::python;
namespace np = boost::python::numpy;

#include "python.h"

static AlgebraicSound *as=nullptr;
static int frames_per_buffer=4096, channels=2, sample_rate=44100;
static float*buffer=nullptr;
static float amp=1, secs=1;

static vector<string> as_names={"relax", "relax1", "water phi", "wa diff", "yin yang", "insect", "flower", "default", "alien",
 "voice rhythm", "bowl", "harmonic expansion", "harmonic vibs"};

static int init(p::list par_list) { // alg sounds samples init (('name', channels, amp, secs, sample_rate, frames_per_buffer)

    int ix_name=-1;

    initPython();

    if (p::len(par_list)==6) {

        string name      = p::extract<string>   (par_list[0]); // name
        channels         = p::extract<int>      (par_list[1]); // channels
        amp              = p::extract<float>    (par_list[2]); // amp
        secs             = p::extract<float>    (par_list[3]); // secs
        sample_rate      = p::extract<int>      (par_list[4]); // sample_rate
        frames_per_buffer= p::extract<int>      (par_list[5]); // fpb

        buffer=new float[frames_per_buffer * channels]; // mono x 1 / stereo x 2 buffer size

        auto f = find(as_names.begin(), as_names.end(), name);
        ix_name = distance(as_names.begin(), f);

        switch (ix_name) {
            case 0: as=new Relax(secs, sample_rate);    break;
            case 1: as=new Relax01(secs, sample_rate);  break;
            case 2: as=new WaterPhi(secs, sample_rate); break;
            case 3: as=new WaWaDiff(secs, sample_rate); break;
            case 4: as=new YinYang(secs, sample_rate);  break;
            case 5: as=new Insect(secs, sample_rate);   break;
            case 6: as=new Flower(secs, sample_rate);   break;
            case 7: as=new MySound(secs, sample_rate);  break;
            case 8: as=new AlienMarch(secs, sample_rate); break;
            case 9: as=new VoiceRhythm(secs, sample_rate); break;
            case 10: as=new Bowl(secs, sample_rate); break;
            case 11: as=new HarmonicExpansion(secs, sample_rate); break;
            case 12: as=new HasrmonicVibs(secs, sample_rate); break;

            default: ix_name=-1; as=nullptr; break;
        }
        if (as) as->set_channels(channels);
    }
    return ix_name;
}

static np::ndarray generate() {
    auto rv=np::array(p::object());

    if (as!=nullptr) {
        switch (channels) {
        case 2: as->gen_stereo(amp, buffer, frames_per_buffer);
                rv = buff2numpy_stereo<float>(buffer, frames_per_buffer);
                break;
        case 1: as->gen_mono(amp, buffer, frames_per_buffer);
                rv = buff2numpy_mono<float>(buffer, frames_per_buffer);
                break;
        }
    }

    return rv;
}

BOOST_PYTHON_MODULE(AlgSoundSamples) {
    def("init", init);
    def("generate", generate);
}
