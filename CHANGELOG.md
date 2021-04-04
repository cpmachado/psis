# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

On versoning:

- Patch version: Exercise/Bug fixes
- Minor version: Week Set
- Major version: Finish the semester at v1.0.0.

## [Unreleased]

### Fixed
- week2: Function Definition header, not consistent
  + lib1.c
  + lib2.c
  + prog1.c
  + prog2.c
- week2:
  + README.md

### Added
- week3
  + README.md
  + Makefile
  + infinite-loop.c
  + char-conv.c
  + producer
  + consumer

- week3(copy from week2)
  + include/randarray.h
  + libSingleStep.c
  + randarray.c


## [0.2.1] - 2021-04-03

### Fixed
- week2/README.md
  + Fix incomplete dependency graph


## [0.2.0] - 2021-04-03

### Fixed
- week1/lab0.c
  + Fixed error printing
  + Removed unused math.h
- DECLARATION/DEFINITION convention in comments
  + All legacy source and header file

### Added
- CPPLINT.cfg
- week2
  + Makefile
  + README.md
  + ex1.c
  + ex2.c
  + ex6.c
  + ex7.c
  + include/lib.h
  + include/randarray.h
  + lib1.c
  + lib2.c
  + libMultiStep.c
  + libSingleStep.c
  + prog1.c
  + prog2.c
  + randarray.c

### Changed
- .gitignore
  + Ignore week2/ex1
  + Ignore week2/ex2
  + Ignore week2/prog1
- config.mk
  + Removed -I./include from INC variable
  + Added recipe for .so files


## [0.1.1] - 2021-04-03

### Fixed
- .gitignore
  + Ignore .DS_STORE
- week1/lab0.c
  + Correct magic number to EXIT_FAILURE


## [0.1.0] - 2021-04-03

### Added
- CHANGELOG
- config.mk
- week1

### Changed
- .gitignore
  + Ignore binary regarding week1.
  + Ignore a folder where resources are stored.


## [0.0.0] - 2021-03-27

### Added
- .editorconfig
- .gitignore
- LICENSE
- README


[Unreleased]: https://github.com/cpmachado/psis/compare/v0.2.1...HEAD
[0.2.1]: https://github.com/cpmachado/psis/compare/v0.2.0...v0.2.1
[0.2.0]: https://github.com/cpmachado/psis/compare/v0.1.1...v0.2.0
[0.1.1]: https://github.com/cpmachado/psis/compare/v0.1.0...v0.1.1
[0.1.0]: https://github.com/cpmachado/psis/compare/v0.0.0...v0.1.0
[0.0.0]: https://github.com/cpmachado/psis/releases/tag/v0.0.0
