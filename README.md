
# JSON File Splitter

This project provides a C++ program that reads a large JSON file (1GB in this example) where each record is separated by a **newline**. 

The program splits the file into multiple smaller and larger JSON files with predefined sizes ranging from 32MB to 32GB.
1. If the requested size is smaller than the JSON file, we will split it.
2. If the requested size is larger than the JSON file, we will repeat the process until the corresponding size is achieved.

## Features
- Supports splitting a large JSON file into multiple smaller and larger files of varying sizes.
- Handles files with sizes of:
  - 32MB
  - 64MB
  - 128MB
  - 256MB
  - 512MB
  - 1GB
  - 2GB
  - 4GB
  - 8GB
  - 16GB
  - 32GB
- Loops through the input file if it is smaller than the target file sizes, ensuring that each output file reaches the desired size.

## Requirements

- A C++11 compliant compiler (e.g., GCC, Clang, MSVC)
- CMake (for building the project if using an IDE like CLion)

## Compilation and Usage

### Using CMake (Recommended)

1. Clone the repository:

   ```bash
   git clone https://github.com/ashkanvg/scalability_json_dataset
   cd your-repo-name
   ```

2. Create a `build` directory and navigate into it:

   ```bash
   mkdir build
   cd build
   ```

3. Run CMake to generate build files:

   ```bash
   cmake ..
   ```

4. Build the project:

   ```bash
   make
   ```

5. Run the program with your input JSON file:

   ```bash
   ./json_splitter input.json
   ```

   Replace `input.json` with the path to your JSON file.

### Direct Compilation (Without CMake)

If you'd rather compile the program directly using `g++`, use the following command:

```bash
g++ -std=c++11 -o json_splitter main.cpp
./json_splitter input.json
```

### Output Files

The program generates output files with the following names based on the target sizes:

- `output_32MB.json`
- `output_64MB.json`
- `output_128MB.json`
- `output_256MB.json`
- `output_512MB.json`
- `output_1024MB.json`
- `output_2048MB.json`
- `output_4096MB.json`
- `output_8192MB.json`
- `output_16384MB.json`
- `output_32768MB.json`

Each output file will contain JSON records until the specified size is reached. If the input file's content is smaller than the target size, the program will repeat from the beginning of the input file.

## Code Overview

- `fileSizes`: A vector of file sizes (in bytes) that the program will use to create the output files.
- `createFiles`: This function handles reading from the input file line by line, writing the content into the output files, and looping back to the beginning of the input file if needed.
- `main`: The entry point of the program, which takes the input JSON file as an argument and calls `createFiles`.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

Feel free to reach out if you have any issues or suggestions! 😊
