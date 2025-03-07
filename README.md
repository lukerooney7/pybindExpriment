To install python dependencies (copied from pyPMT)
```
pip install .
```
To compile the package run:
```
cd build
cmake -Dpybind11_DIR=/path/to/pybind11/share/cmake/pybind11 ..
cmake --build .
```
```
python example.py
```