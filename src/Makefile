.SUFFIXES: .erl .beam .yrl

BINDIR :=../bin
R_INCLUDE_DIR := /usr/share/R/include
ERL_BASE := /usr/lib/erlang/lib/erl_interface-3.7.13
R_HOME := /usr/lib/R

.erl.beam:
	erlc -W -o${BINDIR} eri.erl rErlang.erl

CSRC=$(shell ls *.c)
HED=$(shell ls *.h)
CC := gcc
RM := rm
MODS = eri
VERSION := 0.1
PRODUCT_ERI := ERI-${VERSION}
PRODUCT_RE := rErlang-${VERSION}
NODE_SHELL := *.sh
R_FILE := rErlang.R
CFLAGS := -Wall -I${R_INCLUDE_DIR} -I${ERL_BASE}/include -I${ERL_BASE}
#CFLAGS := -Wall -I${} -I${ERI_LIB}/include
LFLAGS := -L${R_HOME}/lib -L${ERL_BASE}/lib -lR -lerl_interface_st -lei_st -lerl_interface -lei

all:	${MODS:%=%.beam} eri

eri:	${HED} ${CSRC}
	${CC} ${CFLAGS} -o ${BINDIR}/${PRODUCT_ERI} ${HED} ${CSRC} ${LFLAGS}
	${CC} -std=gnu99 ${CFLAGS} -fpic  -g -O2 -c rErlang.c -o ${BINDIR}/${PRODUCT_RE}.o
	${CC} -std=gnu99 -shared  -o ${BINDIR}/${PRODUCT_RE}.so ${BINDIR}/${PRODUCT_RE}.o ${LFLAGS}
	cp ${NODE_SHELL} ${R_FILE} ${BINDIR}

clean:
	${RM} -rf ${BINDIR}/${R_FILE} ${BINDIR}/${PRODUCT_ERI} ${BINDIR}/${PRODUCT_RE} ${BINDIR}/*.beam ${BINDIR}/*.sh ${BINDIR}/*.o ${BINDIR}/*.so *~ *# *.o *.so
