#!/bin/bash

INPUT_FILE=$1
LINE_PATTERN=$2
REPLACE_VALUE=$3
REPLACE_FILE=$4

ls -rl /github/workspace

if [ "$REPLACE_FILE" == "blank.txt" ]; then
  /replace "$INPUT_FILE" "$LINE_PATTERN" value "$REPLACE_VALUE" >> $GITHUB_OUTPUT
else
  /replace "$INPUT_FILE" "$LINE_PATTERN" file "$REPLACE_FILE" >> $GITHUB_OUTPUT
fi
