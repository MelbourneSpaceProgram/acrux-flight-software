ARG VARIANT="22.04"
FROM --platform=linux/amd64 ubuntu:${VARIANT} as base

ARG DEBIAN_FRONTEND=noninteractive

# Install required packages as well as setup the prettier bash prompt and a
# Python virtual environment.
RUN apt-get update && apt-get install -y --no-install-recommends \
    openssh-server \
    curl \
    wget \
    gnupg \
    git \
    build-essential \
    cmake \
    gdb-multiarch \
    default-jre \
    python3 \
    python3-setuptools \
    python3-pip \
    python3-venv \
    # gcc-arm-none-eabi \
    # gcc-arm-linux-gnueabihf \
    # g++-arm-linux-gnueabihf \
    && git config --global --add safe.directory /workspaces/fprime \
    && rm -rf /var/lib/apt/lists/* \
    && python3 -m venv /tmp/fprime-venv \
    && . /tmp/fprime-venv/bin/activate \
    && python3 -m pip install -U --upgrade pip setuptools setuptools_scm wheel \
    && printf '\n[ -d "%s" ] && . %s/bin/activate\n' /tmp/fprime-venv /tmp/fprime-venv >> ~/.bashrc \
    && echo 'eval "$(register-python-argcomplete fprime-cli)"' >> ~/.bashrc

# recommended arm cross compiler version over the apt repository, remove the relative apt install if using this
# see https://github.com/nasa/fprime/discussions/1922
RUN wget --no-check-certificate "https://releases.linaro.org/components/toolchain/binaries/latest-7/arm-linux-gnueabihf/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf.tar.xz"
RUN tar xvJf gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf.tar.xz -C /usr/local/bin
ENV RPI_TOOLCHAIN_DIR=/usr/local/bin/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/
