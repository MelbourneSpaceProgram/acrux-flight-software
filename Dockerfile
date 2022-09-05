FROM debian:latest as fprime
WORKDIR /usr/src/

# This is a massive install, avoid putting lines above
RUN apt-get update
RUN apt-get -y install gcc-arm-none-eabi

# Install fprime deps
RUN apt-get update
RUN apt install -y cmake default-jre default-jdk python3 python3-pip python-setuptools curl wget scala

RUN echo "deb https://repo.scala-sbt.org/scalasbt/debian all main" | tee /etc/apt/sources.list.d/sbt.list
RUN echo "deb https://repo.scala-sbt.org/scalasbt/debian /" | tee /etc/apt/sources.list.d/sbt_old.list
RUN curl -sL "https://keyserver.ubuntu.com/pks/lookup?op=get&search=0x2EE0EA64E40A89B84B2DF73499E82A75642AC823" | apt-key add
RUN apt update
RUN apt install -y sbt

RUN wget https://github.com/fprime-community/fpp/archive/refs/tags/v1.0.2.tar.gz
RUN tar -xvzf v1.0.2.tar.gz
#RUN cd fpp-1.0.2/compiler && ./install /usr/bin/fpp/

RUN export FPP_INSTALL_DIR=/usr/bin/
RUN PATH=$PATH:$FPP_INSTALL_DIR


COPY "./requirements.txt" .

RUN pip install -r "/usr/src/requirements.txt"

ENV PATH=${PATH}:~/.local/bin
RUN git config --global --add safe.directory /usr/src

COPY . .


