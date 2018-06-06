# Tekari

A BSDF-data visualization and editing tool.

## Usage

### Command Line

You can launch **Tekari** in the command line and specify data samples to be loaded as command-line arguments:

```
./tekari data_set1.txt data_set2.txt ...
```

This will launch **Tekari** and open the specified files, assuming they are in the correct format (see [file format][#File-Format]).

### Graphical User Interface
To get started using **Tekari**, you first need to load a file, either using the [command line](#Command-Line), pressing the open file button (folder icon), or using Ctrl-O. Once you have a data sample loaded, you can interact with it in many ways:
- look at it from any angle (by left-dragging the mouse on the canvas)
- zoom in and out (using the mouse wheel)
- translate it (by middle-dragging the mouse)
- or also slect points (by right-dragging the mouse) 

These are just the basics features that allow you to take a closer look at your data. If you want a more detailed explanation of the features (and associated shortcuts) supported by **Tekari**, you can just click the help button (top right of the tools window) or just press 'H' to bring up the help window.

## File-Format

The two file formats **Tekari** supports are standard and spectral data samples generated by ??. This devices analyses the reflected light intensity of a material by *scanning* it following a semi-sphere path. These measurements result in list of points with the format `theta phi intensity` (theta and phi being the angles, in degrees, at which the given intensity was measured). The format also includes some metadata at the beggining of the file, and even if most of it isn't required for **Tekari** to correctly load the file, the spectral data requires the first line (as there is no file extension distinguishing the two file formats).