#!/bin/bash

INPUT_FILE=$1
LINE_PATTERN=$2
REPLACE_VALUE=$3
REPLACE_FILE=$4

if [ "$REPLACE_FILE" == "blank.txt" ]; then
  #echo "text<<EOF" >> $GITHUB_OUTPUT
  /replace "$INPUT_FILE" "$LINE_PATTERN" value "$REPLACE_VALUE" 
  #echo "EOF" >> $GITHUB_OUTPUT
else
  #echo "text<<EOF" >> $GITHUB_OUTPUT
  /replace "$INPUT_FILE" "$LINE_PATTERN" file "$REPLACE_FILE" 
  #echo "EOF" >> $GITHUB_OUTPUT
fi
