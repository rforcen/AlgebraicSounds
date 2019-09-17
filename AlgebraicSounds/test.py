from ToneGenerator import ToneGenerator
import AlgebraicSound.AlgSoundSamples as alg_samples
from random import choice


class AlgSample(ToneGenerator):  # create a tone gen derived class

    def __init__(self, channels, sample_rate, frames_per_buffer):
        ToneGenerator.__init__(self, sample_rate, frames_per_buffer, channels)

    def get_data(self):
        return alg_samples.generate()


if __name__ == '__main__':

    def test():
        sound_samples = ['relax', 'relax1', 'water phi', 'wa diff', 'yin yang', 'insect', 'flower', 'default', 'alien',
                         'voice rhythm', 'bowl', 'harmonic expansion', 'harmonic vibs']

        name, channels, amp, secs, sample_rate, frames_per_buffer = choice(sound_samples), 2, 0.2, 6, 44100, 1024 * 8

        if alg_samples.init([name, channels, amp, secs, sample_rate, frames_per_buffer]) != -1:
            print(f'Playing sample: {name}')

            AlgSample(channels, sample_rate, frames_per_buffer). \
                play(duration=secs, amplitude=amp).\
                wait_finish()
        else:
            print('bad parameters')


    test()
