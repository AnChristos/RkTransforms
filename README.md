
# Clone

Assuming you want also the google bench mark code

``git clone --recursive https://github.com/AnChristos/RkTransforms.git``

``cd RkTransforms/``


The following Will install the benchmark under /user/.local

``source buildGoogleBenchmark.sh``

edit

``cmake -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_ENABLE_GTEST_TESTS=OFF -DCMAKE_INSTALL_PREFIX=${HOME}/.local ../ ``

to change location

else if you have already the google benchmark installed 

``git clone https://github.com/AnChristos/RkTransforms.git``

# Build with CMake 

``mkdir build; cd build``

``cmake ../RkTransforms``

``make``

``./findMinimumIndex_bench --benchmark_report_aggregates_only=true --benchmark_repetitions=20``

# What is included so far

- "C" style (2 variations)
- "STL" style
- Using SSE intrinsics
- Using AVX2 intrinsics
- Using SSE/AVX2 via compiler vector extension
