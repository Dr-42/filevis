# Filevis

A file type inspection tool.

This program was implented inspired by Tsoding's video on acheiving te same thing.
[Tsoding's Video](https://www.youtube.com/watch?v=AUWxl0WdiNI&t=310s)

I basically looked at is into and implemented it witout going in watch it's implementation.

## Usage

### Building

You can build it with builder_cpp
```console
$ cargo install builder_cpp
$ builder_cpp -b
```

Or just using the C compiler
```console
$ cc src/main.c -o filevis
```

### Using
Using builder_cpp
```console
$ builder_cpp -br --bin_args <filename> <output>
```
Using native compiled binary
```console
$ filevis <filename> <output>
```

To convert all files inside a folder
```console
$ mkdir out
$ ./../generate_folder.s <folder_path> 0
```
