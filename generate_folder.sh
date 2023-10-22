#!/bin/bash

# Recursily call ./.bld_cpp/bin/main on all files of the given folder

# $1: folder to process
# $2: depth of the folder

depth=$2
base=$(basename "$1" ".png")
for file in $1/*; do
	if [ -d "$file" ]; then
		../generate_folder.sh "$file" $((depth+1))
	elif [ -f "$file" ]; then
		echo "Processing file $file"
		name=$(basename "$file.jpg")
		png_name=$(basename "$file.png")
		./../.bld_cpp/bin/main "$file" "$png_name"
		echo "Output file: $png_name"
	fi
done
