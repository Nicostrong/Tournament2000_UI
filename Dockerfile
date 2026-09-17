FROM silkeh/clang:latest

ENV DEBIAN_FRONTEND=noninteractive
ENV LANG=fr_FR.UTF-8
ENV LANGUAGE=fr_FR:fr
ENV LC_ALL=fr_FR.UTF-8

USER root

# Installation de Qt, QtCreator, CMake et des dépendances graphiques (Mesa/X11)
RUN apt-get update && apt-get install -y \
    locales \
    valgrind \
    build-essential \
    gdb \
    cmake \
    make \
    qtcreator \
    qttranslations5-l10n \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    qtbase5-dev \
    qttools5-dev \
    qttools5-dev-tools \
    libgl1-mesa-dev \
    libgl1-mesa-dri \
    mesa-utils \
    libxcb-xinerama0 \
    libxcb-icccm4 \
    libxcb-image0 \
    libxcb-keysyms1 \
    libxcb-render-util0 \
    libdbus-1-3 \
    && rm -rf /var/lib/apt/lists/*

RUN locale-gen fr_FR.UTF-8

# Optionnel : Forcer CMake à utiliser Clang par défaut
ENV CC=clang
ENV CXX=clang++

WORKDIR /workspace

CMD ["qtcreator"]
