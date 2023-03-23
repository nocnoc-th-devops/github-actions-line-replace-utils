FROM ubuntu:latest
WORKDIR /

#ARG INPUT_FILE
#ARG LINE_PATTERN
#ARG REPLACE_VALUE
#ARG REPLACE_FILE

COPY main.cxx .
COPY entry-point.sh .
#COPY $INPUT_FILE .
#COPY $REPLACE_FILE .

RUN apt update
RUN apt install -y g++ 
RUN g++ -o replace -g -O3 main.cxx

CMD [ "/entry-point.sh" ]
