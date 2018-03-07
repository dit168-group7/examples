#!/bin/sh

docker run --rm -ti --net=host -p 8080:8080 chrberger/dit168-signal-viewer --cid=111
