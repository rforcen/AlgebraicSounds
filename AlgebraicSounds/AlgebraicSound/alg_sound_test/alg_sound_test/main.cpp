//
//  main.cpp
//  alg_sound_test
//
//  Created by asd on 15/09/2019.
//  Copyright © 2019 voicesync. All rights reserved.
//

#include "AlgSoundSamples.h"

void test01() {
    float secs=1;
    int sample_rate=44100;
    
    size_t sz=(size_t)(secs*sample_rate);
    auto buff=new float[sz+1];
    
    Relax relax(secs, sample_rate);
    auto r=relax.gen(buff, sz);
    delete[]buff;
}

int main(int argc, const char * argv[]) {
    const int bs=44100;
    float buff[44100];
    
    Relax relax(10, 44100);
    relax.gen(buff, bs);
    
    return 0;
}
