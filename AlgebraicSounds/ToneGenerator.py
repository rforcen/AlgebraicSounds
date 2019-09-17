import pyaudio
from math import ceil


class ToneGenerator(object):

    def __init__(self, sample_rate, frames_per_buffer, channels):
        self.p = pyaudio.PyAudio()

        self.sample_rate = sample_rate
        self.frames_per_buffer = frames_per_buffer
        self.channels = channels
        self.streamOpen = False

    def get_data(self, _from, _to):  # derivate
        pass

    def generation_callback(self, in_data, frame_count, time_info, status):
        if self.buffer_offset < self.x_max:
            data = self.get_data()  # generated data()
            self.buffer_offset += self.frames_per_buffer  # inc offset
            return (data.tobytes(), pyaudio.paContinue)
        else:
            return (None, pyaudio.paComplete)

    def is_playing(self):
        if self.stream.is_active():
            return True
        else:
            if self.streamOpen:
                self.stream.stop_stream()
                self.stream.close()
                self.streamOpen = False
            return False

    def play(self, duration, amplitude):
        self.amplitude = amplitude
        self.buffer_offset = 0
        self.streamOpen = True
        self.x_max = ceil(self.sample_rate * duration) - 1
        self.stream = self.p.open(format=pyaudio.paFloat32,
                                  channels=self.channels,
                                  rate=self.sample_rate,
                                  output=True,
                                  frames_per_buffer=self.frames_per_buffer,
                                  stream_callback=self.generation_callback)
        return self

    def wait_finish(self):
        while self.is_playing():
            pass
        return  self
