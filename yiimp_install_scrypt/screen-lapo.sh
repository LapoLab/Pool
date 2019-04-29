#!/bin/bash
 LOG_DIR=/var/log
 WEB_DIR=/var/web
 STRATUM_DIR=/var/stratum
 USR_BIN=/usr/bin


if ! screen -list | grep -q "main"; then
        screen -dmS main bash $WEB_DIR/main.sh
fi

if ! screen -list | grep -q "loop2"; then
        screen -dmS loop2 bash $WEB_DIR/loop2.sh
fi

if ! screen -list | grep -q "blocks"; then
        screen -dmS blocks bash $WEB_DIR/blocks.sh
fi

if ! screen -list | grep -q "debug"; then
        screen -dmS debug tail -f $LOG_DIR/debug.log
fi

if ! screen -list | grep -q "lyra2zz"; then
        screen -dmS lyra2zz $STRATUM_DIR/run.sh lyra2zz
fi
