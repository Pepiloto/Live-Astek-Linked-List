#!/bin/bash

SRC_FOLDER=src
PROJECT=tchoutchou
TEMPLATE_FOLDER=.csf_template

function new () {
    FOLDER=$SRC_FOLDER/$1
    MODULE=$1
    mkdir $FOLDER

    export MODULE=$MODULE
    export PROJECT=$PROJECT
    for f in `ls ${TEMPLATE_FOLDER}`
    do
        (envsubst < $TEMPLATE_FOLDER/$f) > $FOLDER/$f
    done
    unset MODULE
    unset PROJECT
}

function remove () {
    rm -rf $SRC_FOLDER/$1
}

$@
