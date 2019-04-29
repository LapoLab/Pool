#!/bin/bash
# Restart the pseudo cron screens...

LOG_DIR=/var/log
WEB_DIR=/var/web

#screen -X -S gdb-watch
screen -X -S main quit
screen -X -S loop2 quit
screen -X -S blocks quit
screen -X -S debug quit

screen -dmS main $WEB_DIR/main.sh
screen -dmS loop2 $WEB_DIR/loop2.sh
screen -dmS blocks $WEB_DIR/blocks.sh

screen -dmS debug tail -f $LOG_DIR/debug.log

service nginx restart

#screen -dmS gdb-watch gdb -p $(pgrep stratum)
