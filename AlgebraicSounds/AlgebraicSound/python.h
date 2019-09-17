// python stuff

static inline void initPython() {
    static bool must_init=true;
    if (must_init) {
        Py_Initialize(); // init boost & numpy boost
        np::initialize();
        must_init=false;
    }
}

template <class T>
void*clone_data(T *v, size_t sz) { //   data clone
    return memcpy(malloc(sz*sizeof(T)), v, sz*sizeof(T));
}


// create a cloned data numpy array
template <class T>
static np::ndarray buff2numpy_mono(T*v, size_t sz) { // shape=frames_per_buffer
    initPython();

    return np::from_data(clone_data(v, sz),   // data -> clone
                         np::dtype::get_builtin<T>(),  // dtype -> float
                         p::make_tuple(sz),             // shape -> size
                         p::make_tuple(sizeof(T)), p::object()); // stride
}

template <class T>
static np::ndarray buff2numpy_stereo(T*v, size_t sz) { // shape=(frames_per_buffer, 2)
    initPython();
    return np::from_data(clone_data(v, sz*2),   // data -> clone 2 chann -> sz x 2
                         np::dtype::get_builtin<T>(),  // dtype -> float
                         p::make_tuple(sz, 2),       // shape -> size
                         p::make_tuple(sizeof(T)*2, sizeof(T)), p::object()); // stride
}

