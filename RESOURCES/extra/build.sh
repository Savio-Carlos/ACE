#!/bin/bash

# 1. Check if a file was provided
if [ -z "$1" ]; then
  echo "Usage: $0 <source_file.cpp>"
  exit 1
fi

SOURCE_FILE="$1"

# 2. Extract the filename without the extension to name the output binary
# Example: "main.cpp" becomes "main"
OUTPUT_BINARY="${SOURCE_FILE%.*}"

# 3. Define your compiler and flags
CXX="g++"
CXXFLAGS="-fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++23 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts"

echo "Compiling $SOURCE_FILE..."

# 4. Execute the compile command
# Note: CXXFLAGS is intentionally unquoted so Bash reads each flag as a separate argument
$CXX $CXXFLAGS "$SOURCE_FILE" -o "$OUTPUT_BINARY"

# 5. Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Success! Run it with: ./$OUTPUT_BINARY"
else
    echo "Compilation failed."
fi
