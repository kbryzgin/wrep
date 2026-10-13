# Weather Report
A simple CLI-utility written in C to fetch and display the current weather forecast using the **wttr.in** API.

## Features
* **Real-time Weather Data:** Downloads up-to-date weather reports in structured JSON format.
* **Cascading JSON Parsing:** Extracts precise parameters safely using the `cJSON` library.
* **Robust Error Handling:** Safely processes invalid locations, networking errors, and memory allocations without crashes.

## Prerequisites
* `gcc` compiler
* `make` build automation tool
* `libcurl` development library (install via `sudo apt install libcurl4-openssl-dev` on Ubuntu/WSL)

## Building the Project
To compile the utility using strict compliance flags (`-Wall -Wextra -Wpedantic -std=c11`), run the following command in the root directory:
```bash
make
```

To clean the repository by removing object files and the generated executable, use:
```bash
make clean
```

## Usage
Run the program by passing the target city name as a CLI-argument:
```bash
./wrep <city_name>
```

### Execution Examples:
```bash
./wrep Moscow
./wrep London
./wrep BBB
```
