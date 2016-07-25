#!/bin/bash

echo "      _               _              _ _    _ _   "
echo " THE | | CBD         | |            | | |  (_) |  "
echo "  ___| |__  _ __ ___ | |_ ___   ___ | | | ___| |_ "
echo " / __| '_ \| '_ \` _ \| __/ _ \ / _ \| | |/ / | __|"
echo "| (__| | | | | | | | | || (_) | (_) | |   <| | |_ "
echo " \___|_| |_|_| |_| |_|\__\___/ \___/|_|_|\_\_|\__|"
echo "                        kool stuff is happenning..."
echo ""

cd ../docroot/
drush sql-drop -y
drush sql-sync @prod @self -y
drush vset environment dev
drush prepare-dev -y
# drush rsync @prod:%files @self:%files -y
drush cc all
