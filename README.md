### Prerequisites:

Download and install Emscripten SDK following [these
instructions](https://emscripten.org/docs/getting_started/downloads.html).

### How to run

After cloning the repository, run:

```
git submodule update --init
```

Build:

```
cd build
 
emcmake cmake ..

cmake --build .
```

This will generate ai.wasm and ai.mjs files inside the build folder.

TODO: Write example on how to use the generated files.
