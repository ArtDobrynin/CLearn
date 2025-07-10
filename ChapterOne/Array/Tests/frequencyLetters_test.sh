#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_FILE="$SCRIPT_DIR/../Ex/GetFrequencyLetters.c"
BIN_DIR="$SCRIPT_DIR/../bin"

mkdir -p "$BIN_DIR"
gcc -o "$BIN_DIR/frequencyLetters" "$SRC_FILE" || { echo "❌ Compilation failed"; exit 1; }

inputs="aabbccddaa"
expected_outputs="<=================Letters Gistogramm=================>
 a     b     c     d
 *     *     *     *
 *     *     *     *
 *
 *
"

output=$(echo "$inputs" | "$BIN_DIR/frequencyLetters" | grep -v "After Add" | grep -v "Counter letters")
output=$(echo "$output" | sed -e :a -e '/^\n*$/{$d;N;};/\n$/ba')

if [ "$output" = "$expected_outputs" ]; then
    echo "Main Test passed ✅"
else
    echo "Main Test failed ❌"
    echo "$output"
    echo "$expected_outputs"
fi
