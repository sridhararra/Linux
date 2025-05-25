#!/bin/bash
# Can trace anything at the level of the kernel via the really powerful
# raw *Ftrace* functionality baked into the kernel (typically enabled in
# standard distros).
# To make it easier to use, a front-end - trace-cmd - exists...
# To make it even easier :-) to use, let's employ our front-end to trace-cmd,
# trccmd - to ftrace our dear 'hello, world' program!
# (Get trccmd here: https://github.com/kaiwan/trccmd ).
#
# Author: Kaiwan N Billimoria
# MIT

function die 
{
    echo >&2 "$@"
    exit 1
}

TRCCMD=/home/sridhar/kaiwan/trccmd/trccmd
BIN=execl
hash ${TRCCMD} || {
  PFX=~/kaiwanTECH/trccmd  # where trccmd's installed; UPDATE as required
  TRCCMD=${PFX}/trccmd
  hash ${TRCCMD} || die "trccmd not found or not installed"
}
[[ ! -f ./${BIN} ]] && die "./${BIN} not found; build and retry"

#${TRCCMD} -F ./${BIN}
${TRCCMD} -e syscalls -F ./${BIN}
exit 0
