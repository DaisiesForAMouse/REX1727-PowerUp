#!/bin/bash

echo "deploy.sh: Starting deploy process..."

team=1727

# Only works for four digit teams
team_ip="${team:0:2}.${team:2}"

if [ ! -f "FRCUserProgram" ]; then
    echo "FRCUserProgram not found!"
    exit 1
fi

echo "First trying to connect on mDNS..."
ping -n 4 "roboRIO-$team-FRC.local" > /dev/null 2>&1 ; mDNS=$?
if [ $mDNS -ne 0 ]; then
    echo "roboRIO not found on mDNS at roboRIO-$team-FRC.local, falling back to static USB"
    ping -n 4 "172.22.11.2" > /dev/null 2>&1 ; static=$?
    if [ $static -ne 0 ] ; then
        echo "Failed to connect via static USB, falling back to static ethernet..."
        ping -n 4 "10.$team_ip.2" > /dev/null 2>&1 ; ethernet=$?
        if [ $ethernet -ne 0 ] ; then
            echo "Connection failed on 10.$team_ip.2."
            echo "Connection to roboRIO failed."
            echo "deploy.sh: Exiting deploy process..."
            exit 1
        else
            ssh "lvuser@10.$team_ip.2" "killall -9 FRCUserProgram && rm ~/FRCUserProgram && exit"

            scp "FRCUserProgram" "lvuser@10.$team_ip.2:~/FRCUserProgram"

            echo "Deployed via static ethernet."
        fi
    else
	ssh "lvuser@172.22.11.2" "killall -9 FRCUserProgram && rm ~/FRCUserProgram && exit"

	scp "FRCUserProgram" "lvuser@172.22.11.2:~/FRCUserProgram"
        echo "Deployed via static USB."
    fi
else
    ssh "lvuser@roboRIO-$team-FRC.local" "killall -9 FRCUserProgram && rm ~/FRCUserProgram && exit"

    scp "FRCUserProgram" "lvuser@roboRIO-$team-FRC.local:~/FRCUserProgram"
    echo "Deployed via mDNS."
fi

echo "deploy.sh: Exiting deploy process..."
exit
