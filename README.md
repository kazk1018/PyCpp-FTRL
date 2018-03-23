# PyCpp-FTRL

**PyCpp-FTRL** is an implementation of FTRL Logistic Regression

## Requirements

- python3.6
- cmake
- eigen3
- pybind11 (submodule)

## Usage

### For macOS

* Install eigen3 via [Homebrew](https://brew.sh/index)

```
brew install eigen3
```

* Set python config

set `PYTHON_EXECUTABLE`  (default: pyenv path)

```
set(PYTHON_VERSION {your python3.6 path})
set(PYENV_VERSION_DIRECTORY $ENV{HOME}/.pyenv/versions/${PYTHON_VERSION})
set(PYTHON_EXECUTABLE ${PYENV_VERSION_DIRECTORY}/bin/python)
```

* Build

```
$ cd {reposigory home}

$ mkdir build && cd build

$ cmake ..

$ make
```

## References
* [Ad Click Prediction: a View from the Trenches](https://research.google.com/pubs/archive/41159.pdf)


## License

[MIT License](https://github.com/kazk1018/PyCpp-FTRL/blob/master/LICENSE)

## Author

[kazk1018](https://github.com/kazk1018)
