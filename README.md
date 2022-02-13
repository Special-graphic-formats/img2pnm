# Any image to PNM

Little tool to convert any image (JPEG, PNG, BMP, PSD, TGA, GIF, HDR, PIC, PNM) image to PNM. I made this project to practice my C skills and to learn how images works.

## To do

- [ ] Custom image input support
    - [ ] JPEG
    - [ ] PNG
    - [ ] BMP
    - [ ] PSD
    - [ ] TGA
    - [ ] GIF
    - [ ] HDR
    - [ ] PIC
    - [ ] PNM

- [ ] Custom PNM output support
    - [ ] PBM
    - [ ] PGM
    - [x] PPM

## Quick start

```console
# build
$ make

# build using shell script
$ ./build.sh

# run
$ cd build
$ ./img2pnm <args>
```

## How to use

Print usage *(exits with code 0)*
```console
$ ./img2pnm -h
Usage: build/img2pnm <input image> [-o[utput] output path] [-h[elp]]
```

### Examples

Convert `input.png` to `input.png.ppm`
```console
$ ./img2pnm input.png
```

Convert `input.jpg` to `output.ppm`
```console
$ ./img2pnm input.jpg -o output.ppm
```