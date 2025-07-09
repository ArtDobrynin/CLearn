#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_FILE="$SCRIPT_DIR/../CounterAllSymbols.c"
BIN_DIR="$SCRIPT_DIR/../bin"

mkdir -p "$BIN_DIR"
gcc -o "$BIN_DIR/allSymbols" "$SRC_FILE" || { echo "❌ Compilation failed"; exit 1; }

inputs=(
  "1234567890"
  $'  \t \n'
  "abc!@#"
  $'1a 2b\t3c\n'
)

expected_outputs=(
  "digits = 1 1 1 1 1 1 1 1 1 1, white space = 1, other = 0"
  "digits = 0 0 0 0 0 0 0 0 0 0, white space = 6, other = 0"
  "digits = 0 0 0 0 0 0 0 0 0 0, white space = 1, other = 6"
  "digits = 0 1 1 1 0 0 0 0 0 0, white space = 4, other = 3"
)

for i in "${!inputs[@]}"; do
  input="${inputs[$i]}"
  expected="${expected_outputs[$i]}"
  output=$(echo -e "$input" | "$BIN_DIR/allSymbols")

  if [ "$output" = "$expected" ]; then
    echo "Test $((i+1)) passed ✅"
  else
    echo "Test $((i+1)) failed ❌"
    echo "Input:    '$input'"
    echo "Expected: '$expected'"
    echo "Got:      '$output'"
  fi
done
