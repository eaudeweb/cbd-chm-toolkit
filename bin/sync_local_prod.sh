#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[1;37m'

echo -e "${GREEN}      _               _              _ _    _ _   "
echo -e " THE | | CBD         | |            | | |  (_) |  "
echo -e "  ___| |__  _ __ ___ | |_ ___   ___ | | | ___| |_ "
echo -e " / __| '_ \| '_ \` _ \| __/ _ \ / _ \| | |/ / | __|"
echo -e "| (__| | | | | | | | | || (_) | (_) | |   <| | |_ "
echo -e " \___|_| |_|_| |_| |_|\__\___/ \___/|_|_|\_\_|\__|"
echo -e "                        kool stuff is happenning..."
echo -e ""

env=`drush vget --exact environment`
if [ $env != 'dev' ]; then
  echo -e "${RED}ERROR: Refusing to drop the current database. Please set environment to 'dev' (drush vset environment dev)\n";
  exit -1
fi

cd ../docroot/
drush sql-drop -y
drush sql-sync @prod @self -y
drush vset environment dev
drush prepare-dev -y
# drush rsync @prod:%files @self:%files -y
drush cc all
