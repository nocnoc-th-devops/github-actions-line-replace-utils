FROM ubuntu:latest
WORKDIR /

COPY main.cxx .
COPY entry-point.sh .

RUN apt update
RUN apt install -y g++ 
RUN g++ -o replace -g -O3 main.cxx

ENTRYPOINT [ "/entry-point.sh" ]
