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

# run
$ cd build
$ ./img2ppm <args>
```

## How to use

Print usage *(exits with code 0)*
```console
$ ./img2ppm -h
Usage: build/img2ppm <input image> [-o[utput] output path] [-h[elp]]
```

### Examples

Convert `input.png` to `input.png.ppm`
```console
$ ./img2ppm input.png
```

Convert `input.jpg` to `output.ppm`
```console
$ ./img2ppm input.jpg -o output.ppm
```