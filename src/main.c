#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

int main(int argc, char** argv) {
	if (argc != 3) {
		printf("Usage: %s <filename> <output_name>", argv[0]);
	}
	const char* filename = argv[1];
	const char* outfile = argv[2];

	uint8_t buf;
	uint8_t prev = 0;

	uint8_t data[256 * 256 * 3] = { 0 };

	FILE* file = fopen(filename, "rb");
	size_t res = fread(&buf, 1, sizeof(buf), file);
	if (res == 0) {
		printf("Error reading file");
		return 1;
	}
	prev = buf;
	res = fread(&buf, 1, sizeof(buf), file);
	size_t i = 0;
	while (res != 0) {
		uint8_t x = prev;
		uint8_t y = buf;
		size_t index = x + y * 256;
		data[index * 3 + 0] = prev;
		data[index * 3 + 1] = buf;
		if (data[index * 3] != 0) {
			if(data[index * 3 + 2] == 0) {
				data[index * 3 + 2] = 1;
			}
			else {
				data[index * 3 + 2] = data[index * 3 + 2] + 1;
			}
		}
		prev = buf;
		i++;
		res = fread(&buf, 1, sizeof(buf), file);
	}
	
	int write_res = stbi_write_png(outfile, 256, 256, 3, data, 256 * 3);
	if (write_res == 0) {
		printf("Error writing file");
	}

	return 0;
}
